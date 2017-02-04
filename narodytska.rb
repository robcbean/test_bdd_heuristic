require 'os'
require "#{File.dirname(__FILE__)}//cygwin.rb"

class Edge
  attr_accessor :v1, :v2, :weight

  def initialize(_v1, _v2, _weight)
    self.v1 = _v1
    self.v2 = _v2
    self.weight = _weight
    self.v1.addEdge(self)
    self.v2.addEdge(self)
  end
end

class Vertex
  attr_accessor :id, :edges, :adjacent

  def initialize(_id, _edges=Array.new())
    self.id = _id
    if _edges.size > 0
      _edges.each do |edge|
        self.addEdge(edge)
      end
    else
      self.edges = _edges
      self.adjacent = Array.new()
    end
  end

  def addEdge(_edge)
    self.edges << _edge
    if _edge.v1.id != self.id
      self.adjacent << _edge.v1
    else
      self.adjacent << _edge.v2
    end
  end

  def ==(_vertex)
    ret = _vertex.id == self.id
  end
end

class PrimalConstraintGraph

  attr_accessor :vertices, :edges

  def initialize(_vertices=Array.new(), _edges=Array.new())
    self.vertices = _vertices
    self.edges = _edges
  end

  def addVertexWithId(_vertex_id)

    if not self.existsVertexId(_vertex_id)
      ret = Vertex.new(_vertex_id)
      addVertex(ret)
    else
      ret = getVertex(_vertex_id)
    end

    return ret

  end

  def getVertex(_vertex_id)
    ret = self.vertices.select { |vertex| vertex.id == _vertex_id }
    if not ret.nil?
      ret = ret[0]
    end
    return ret
  end

  def existsVertexId(_vertex_id)
    ret = (not self.getVertex(_vertex_id).nil?)
    return ret
  end

  def existsVertex(_vertex)
    ret = self.existsVertexId(_vertex.id)
    return ret
  end

  def addVertex(_vertex)
    if not existsVertex(_vertex)
      self.vertices << _vertex
    end
  end

  def addEdge(_edge)
    self.edges << _edge
  end

  def getEdgeByVertexId(_v1, _v2)

    ret = self.edges.select { |edge| (edge.v1.id == _v1 and edge.v2.id ==_v2) or (edge.v1.id == _v2 and edge.v2.id ==_v1) }
    if ret.size == 1
      ret = ret[0]
    else
      ret = Edge.new(_v1, _v2, 0)
      self.edges << ret
    end
    return ret
  end

  def getEdge(_v1, _v2)
    ret = self.edges.select { |edge| (edge.v1 == _v1 and edge.v2 ==_v2) or (edge.v1 == _v2 and edge.v2 ==_v1) }
    if ret.size == 1
      ret = ret[0]
    else
      ret = Edge.new(_v1, _v2, 0)
      self.edges << ret
    end
    return ret
  end

end


def executeMCL(_file_name, _i, _out_file)

  cmd = " #{_file_name} -I #{_i} --abc -o #{_out_file}"
  if OS.linux? or OS.mac?
    if OS.linux?
      `./mcllinux #{cmd}`
    else
      `./mclmac #{cmd}`
    end

  else
    executeCommandLine("mcl "+ cmd)
  end


end

def extraClause(_inputs, _function)
  ret = false
  _inputs.each do |input|
    if not _function.inputs.include?(input)
      ret =true
      break
    end
  end
  return ret
end

def generateMCLFile(_function, _primal_graph=nil)
  ret = ""
  if _primal_graph.nil?()
    primal_graph = PrimalConstraintGraph.new()
  else
    primal_graph =_primal_graph
  end
  _function.clauses.values.each do |clause|

    if clause.inputs.size > 1 and not extraClause(clause.inputs, _function) and not _function.outputs.include?(clause.id)
      #print "#{clause.clause}\n"
      clause.inputs.permutation(2).to_a.each do |pair|
        v1=primal_graph.addVertexWithId(pair[0])
        v2=primal_graph.addVertexWithId(pair[1])
        edge = primal_graph.getEdge(v1, v2)
        if edge.weight == 0
          if ret != ""
            ret = ret + "\n"
          end
          ret = "#{ret}#{pair[0]}\t#{pair[1]}\t1"
        end
        edge.weight = edge.weight + 0.5
      end
    else
      if clause.inputs.size == 1 and not extraClause(clause.inputs, _function)
        v1 = primal_graph.addVertexWithId(clause.inputs[0])
        v2 = primal_graph.addVertexWithId(clause.inputs[0])

        edge = primal_graph.getEdge(v1, v2)
        if edge.weight == 0
          if ret != ""
            ret = ret + "\n"
          end
          ret = "#{ret}#{clause.inputs[0]}\t#{clause.inputs[0]}\t1"
        end
        edge.weight = edge.weight + 1
        #$stderr.print "error:#{clause.inputs}\t#{clause.clause}\n"
      end
    end
  end
  return ret

end

def getMCLClusters(_mcl_file)

  ret = Array.new()
  if File.exist?(_mcl_file)
    fs = File.open(_mcl_file)
    fs.readlines.each do |line|
      cluster = Array.new()
      line.split().each do |value|
        cluster << value.to_i
      end
      ret << cluster
    end
    fs.close()
  end

  return ret

end

def sortClusterVariables(_function, _primal_graph_edges, _cluster)

  ret = Array.new()
  # ROB 01/05/2016 Calc the weigh of each variable as the sum os adjacent vertex edges weight
  vertex_weight = Hash.new()
  _cluster.each do |vertex_id|
    vertex = _primal_graph_edges.getVertex(vertex_id)
    vertex_weight[vertex_id] = 0
    vertex.adjacent.each do |adjacent_vertex|
      if _cluster.include?(adjacent_vertex.id)
        vertex_weight[vertex_id] = vertex_weight[vertex_id] + _primal_graph_edges.getEdgeByVertexId(vertex_id, adjacent_vertex.id).weight
      end
    end
  end

  #Set the central vertex as the first vertex according the ssum of adjacent vertex edges weight
  sorted_vertex = vertex_weight.sort_by { |key, value| -value }
  central_vertex = sorted_vertex[0][0]

  #Sort the adjacent vertex to the central with the edge weight
  ret << central_vertex
  adjacent_central_vertex = Hash.new()
  _primal_graph_edges.getVertex(central_vertex).adjacent.each do |vertex|
    if _cluster.include?(vertex.id)
      adjacent_central_vertex[vertex.id] = _primal_graph_edges.getEdgeByVertexId(vertex.id, central_vertex).weight
    end
  end

  vertex_weight.delete(central_vertex)
  adjacent_central_vertex.sort_by { |key, value| -value }.each do |pair|
    ret << pair[0]
    vertex_weight.delete(pair[0])
  end

  extra_vertex = vertex_weight.sort_by { |key, value| -value }
  vertex_to_process = Array.new()
  extra_vertex.each do |pair|
    vertex_to_process << pair[0]
  end

  i = 0
  #The extra nod added vertex are sorted according the sum of their weight previous calculated, if two vertex have equal weight we sort according the sum of adjacent weights
  while vertex_to_process.size() > 0
    vertex_list = Hash.new()
    vertex_list[vertex_to_process[0]] = 0
    sel_value = extra_vertex.select { |value| value[0]==vertex_to_process[0] }[0][1]
    extra_vertex.select { |value| value[1] == sel_value }.to_a.each do |vertex|
      vertex_list[vertex[0]] = 0
    end
    vertex_list.keys.each do |vertex_id|
      vertex = _primal_graph_edges.getVertex(vertex_id)
      vertex.adjacent.each do |adjacent|
        vertex_list[vertex_id] = vertex_list[vertex_id] + _primal_graph_edges.getEdgeByVertexId(vertex_id, adjacent.id).weight
      end
      vertex_to_process.delete(vertex_id)
    end


    vertex_list.sort_by { |key, value| -value }.each do |vertex|
      ret << vertex[0]
    end

  end


  return ret

end

def getNarodystka(_function,_mcl_i=2.5)

  mcl_file = "#{File.dirname(__FILE__)}/mcl_in.txt"
  out_file = "#{File.dirname(__FILE__)}/mcl_out.txt"

  fd = File.open(mcl_file, "w")
  primal_graph = PrimalConstraintGraph.new()
  fd.write(generateMCLFile(_function, primal_graph))
  fd.close()


  executeMCL(mcl_file, _mcl_i, out_file)
  clusters = getMCLClusters(out_file)
  sorted_clusters = Array.new()
  clusters.each do |cluster|
    sorted_clusters << sortClusterVariables(_function, primal_graph, cluster)
  end
  projection = Hash.new()
  i = 0
  sorted_clusters.each do |cluster|
    projection[i] = 0
    cluster.each do |vertex_id|
      total_cluster = 0.0
      total_general = 0.0
      vertex = primal_graph.getVertex(vertex_id)
      vertex.adjacent.each do |adjacent|
        weight = primal_graph.getEdgeByVertexId(vertex_id, adjacent.id).weight
        total_general = total_general + weight
        if cluster.include?(adjacent.id)
          total_cluster = total_cluster + weight
        end
      end
      projection[i] = projection[i] + total_cluster / total_general
    end
    projection[i] = projection[i] / cluster.size()
    i = i + 1
  end

  ret = Array.new()
  projection.sort_by { |key, value| -value }.each do |pair|
    ret = ret.concat(sorted_clusters[pair[0]])
  end

  return ret

end
