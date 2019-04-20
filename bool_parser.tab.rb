#
# DO NOT MODIFY!!!!
# This file is automatically generated by Racc 1.4.8
# from Racc grammer file "".
#

###### racc/parser.rb begin
unless $".index 'racc/parser.rb'
  $".push 'racc/parser.rb'
  self.class.module_eval(<<'...end racc/parser.rb/module_eval...', 'racc/parser.rb', 1)
  #
# $Id: 3c2cf4b8b66a54ac219c7a6020e94b8668ec7e25 $
#
# Copyright (c) 1999-2006 Minero Aoki
#
# This program is free software.
# You can distribute/modify this program under the same terms of ruby.
#
# As a special exception, when this code is copied by Racc
# into a Racc output file, you may use that output file
# without restriction.
#

unless defined?(NotImplementedError)
  NotImplementedError = NotImplementError
end

module Racc
  class ParseError < StandardError; end
end
unless defined?(::ParseError)
  ParseError = Racc::ParseError
end

module Racc

  unless defined?(Racc_No_Extentions)
    Racc_No_Extentions = false
  end

  class Parser

    Racc_Runtime_Version = '1.4.6'
    Racc_Runtime_Revision = '$Id: 3c2cf4b8b66a54ac219c7a6020e94b8668ec7e25 $'

    Racc_Runtime_Core_Version_R = '1.4.6'
    Racc_Runtime_Core_Revision_R = '$Id: 3c2cf4b8b66a54ac219c7a6020e94b8668ec7e25 $'.split[1]
    begin
      require 'racc/cparse'
    # Racc_Runtime_Core_Version_C  = (defined in extention)
      Racc_Runtime_Core_Revision_C = Racc_Runtime_Core_Id_C.split[2]
      unless new.respond_to?(:_racc_do_parse_c, true)
        raise LoadError, 'old cparse.so'
      end
      if Racc_No_Extentions
        raise LoadError, 'selecting ruby version of racc runtime core'
      end

      Racc_Main_Parsing_Routine    = :_racc_do_parse_c
      Racc_YY_Parse_Method         = :_racc_yyparse_c
      Racc_Runtime_Core_Version    = Racc_Runtime_Core_Version_C
      Racc_Runtime_Core_Revision   = Racc_Runtime_Core_Revision_C
      Racc_Runtime_Type            = 'c'
    rescue LoadError
      Racc_Main_Parsing_Routine    = :_racc_do_parse_rb
      Racc_YY_Parse_Method         = :_racc_yyparse_rb
      Racc_Runtime_Core_Version    = Racc_Runtime_Core_Version_R
      Racc_Runtime_Core_Revision   = Racc_Runtime_Core_Revision_R
      Racc_Runtime_Type            = 'ruby'
    end

    def Parser.racc_runtime_type
      Racc_Runtime_Type
    end

    private

    def _racc_setup
      @yydebug = false unless self.class::Racc_debug_parser
      @yydebug = false unless defined?(@yydebug)
      if @yydebug
        @racc_debug_out = $stderr unless defined?(@racc_debug_out)
        @racc_debug_out ||= $stderr
      end
      arg = self.class::Racc_arg
      arg[13] = true if arg.size < 14
      arg
    end

    def _racc_init_sysvars
      @racc_state  = [0]
      @racc_tstack = []
      @racc_vstack = []

      @racc_t = nil
      @racc_val = nil

      @racc_read_next = true

      @racc_user_yyerror = false
      @racc_error_status = 0
    end

    ###
    ### do_parse
    ###

    def do_parse
      __send__(Racc_Main_Parsing_Routine, _racc_setup(), false)
    end

    def next_token
      raise NotImplementedError, "#{self.class}\#next_token is not defined"
    end

    def _racc_do_parse_rb(arg, in_debug)
      action_table, action_check, action_default, action_pointer,
      goto_table,   goto_check,   goto_default,   goto_pointer,
      nt_base,      reduce_table, token_table,    shift_n,
      reduce_n,     use_result,   * = arg

      _racc_init_sysvars
      tok = act = i = nil
      nerr = 0

      catch(:racc_end_parse) {
        while true
          if i = action_pointer[@racc_state[-1]]
            if @racc_read_next
              if @racc_t != 0   # not EOF
                tok, @racc_val = next_token()
                unless tok      # EOF
                  @racc_t = 0
                else
                  @racc_t = (token_table[tok] or 1)   # error token
                end
                racc_read_token(@racc_t, tok, @racc_val) if @yydebug
                @racc_read_next = false
              end
            end
            i += @racc_t
            unless i >= 0 and
                   act = action_table[i] and
                   action_check[i] == @racc_state[-1]
              act = action_default[@racc_state[-1]]
            end
          else
            act = action_default[@racc_state[-1]]
          end
          while act = _racc_evalact(act, arg)
            ;
          end
        end
      }
    end

    ###
    ### yyparse
    ###

    def yyparse(recv, mid)
      __send__(Racc_YY_Parse_Method, recv, mid, _racc_setup(), true)
    end

    def _racc_yyparse_rb(recv, mid, arg, c_debug)
      action_table, action_check, action_default, action_pointer,
      goto_table,   goto_check,   goto_default,   goto_pointer,
      nt_base,      reduce_table, token_table,    shift_n,
      reduce_n,     use_result,   * = arg

      _racc_init_sysvars
      nerr = 0

      catch(:racc_end_parse) {
        until i = action_pointer[@racc_state[-1]]
          while act = _racc_evalact(action_default[@racc_state[-1]], arg)
            ;
          end
        end
        recv.__send__(mid) do |tok, val|
          unless tok
            @racc_t = 0
          else
            @racc_t = (token_table[tok] or 1)   # error token
          end
          @racc_val = val
          @racc_read_next = false

          i += @racc_t
          unless i >= 0 and
                 act = action_table[i] and
                 action_check[i] == @racc_state[-1]
            act = action_default[@racc_state[-1]]
          end
          while act = _racc_evalact(act, arg)
            ;
          end

          while !(i = action_pointer[@racc_state[-1]]) ||
                ! @racc_read_next ||
                @racc_t == 0  # $
            unless i and i += @racc_t and
                   i >= 0 and
                   act = action_table[i] and
                   action_check[i] == @racc_state[-1]
              act = action_default[@racc_state[-1]]
            end
            while act = _racc_evalact(act, arg)
              ;
            end
          end
        end
      }
    end

    ###
    ### common
    ###

    def _racc_evalact(act, arg)
      action_table, action_check, action_default, action_pointer,
      goto_table,   goto_check,   goto_default,   goto_pointer,
      nt_base,      reduce_table, token_table,    shift_n,
      reduce_n,     use_result,   * = arg
      nerr = 0   # tmp

      if act > 0 and act < shift_n
        #
        # shift
        #
        if @racc_error_status > 0
          @racc_error_status -= 1 unless @racc_t == 1   # error token
        end
        @racc_vstack.push @racc_val
        @racc_state.push act
        @racc_read_next = true
        if @yydebug
          @racc_tstack.push @racc_t
          racc_shift @racc_t, @racc_tstack, @racc_vstack
        end

      elsif act < 0 and act > -reduce_n
        #
        # reduce
        #
        code = catch(:racc_jump) {
          @racc_state.push _racc_do_reduce(arg, act)
          false
        }
        if code
          case code
          when 1 # yyerror
            @racc_user_yyerror = true   # user_yyerror
            return -reduce_n
          when 2 # yyaccept
            return shift_n
          else
            raise '[Racc Bug] unknown jump code'
          end
        end

      elsif act == shift_n
        #
        # accept
        #
        racc_accept if @yydebug
        throw :racc_end_parse, @racc_vstack[0]

      elsif act == -reduce_n
        #
        # error
        #
        case @racc_error_status
        when 0
          unless arg[21]    # user_yyerror
            nerr += 1
            on_error @racc_t, @racc_val, @racc_vstack
          end
        when 3
          if @racc_t == 0   # is $
            throw :racc_end_parse, nil
          end
          @racc_read_next = true
        end
        @racc_user_yyerror = false
        @racc_error_status = 3
        while true
          if i = action_pointer[@racc_state[-1]]
            i += 1   # error token
            if  i >= 0 and
                (act = action_table[i]) and
                action_check[i] == @racc_state[-1]
              break
            end
          end
          throw :racc_end_parse, nil if @racc_state.size <= 1
          @racc_state.pop
          @racc_vstack.pop
          if @yydebug
            @racc_tstack.pop
            racc_e_pop @racc_state, @racc_tstack, @racc_vstack
          end
        end
        return act

      else
        raise "[Racc Bug] unknown action #{act.inspect}"
      end

      racc_next_state(@racc_state[-1], @racc_state) if @yydebug

      nil
    end

    def _racc_do_reduce(arg, act)
      action_table, action_check, action_default, action_pointer,
      goto_table,   goto_check,   goto_default,   goto_pointer,
      nt_base,      reduce_table, token_table,    shift_n,
      reduce_n,     use_result,   * = arg
      state = @racc_state
      vstack = @racc_vstack
      tstack = @racc_tstack

      i = act * -3
      len       = reduce_table[i]
      reduce_to = reduce_table[i+1]
      method_id = reduce_table[i+2]
      void_array = []

      tmp_t = tstack[-len, len] if @yydebug
      tmp_v = vstack[-len, len]
      tstack[-len, len] = void_array if @yydebug
      vstack[-len, len] = void_array
      state[-len, len]  = void_array

      # tstack must be updated AFTER method call
      if use_result
        vstack.push __send__(method_id, tmp_v, vstack, tmp_v[0])
      else
        vstack.push __send__(method_id, tmp_v, vstack)
      end
      tstack.push reduce_to

      racc_reduce(tmp_t, reduce_to, tstack, vstack) if @yydebug

      k1 = reduce_to - nt_base
      if i = goto_pointer[k1]
        i += state[-1]
        if i >= 0 and (curstate = goto_table[i]) and goto_check[i] == k1
          return curstate
        end
      end
      goto_default[k1]
    end

    def on_error(t, val, vstack)
      raise ParseError, sprintf("\nparse error on value %s (%s)",
                                val.inspect, token_to_str(t) || '?')
    end

    def yyerror
      throw :racc_jump, 1
    end

    def yyaccept
      throw :racc_jump, 2
    end

    def yyerrok
      @racc_error_status = 0
    end

    #
    # for debugging output
    #

    def racc_read_token(t, tok, val)
      @racc_debug_out.print 'read    '
      @racc_debug_out.print tok.inspect, '(', racc_token2str(t), ') '
      @racc_debug_out.puts val.inspect
      @racc_debug_out.puts
    end

    def racc_shift(tok, tstack, vstack)
      @racc_debug_out.puts "shift   #{racc_token2str tok}"
      racc_print_stacks tstack, vstack
      @racc_debug_out.puts
    end

    def racc_reduce(toks, sim, tstack, vstack)
      out = @racc_debug_out
      out.print 'reduce '
      if toks.empty?
        out.print ' <none>'
      else
        toks.each {|t| out.print ' ', racc_token2str(t) }
      end
      out.puts " --> #{racc_token2str(sim)}"
          
      racc_print_stacks tstack, vstack
      @racc_debug_out.puts
    end

    def racc_accept
      @racc_debug_out.puts 'accept'
      @racc_debug_out.puts
    end

    def racc_e_pop(state, tstack, vstack)
      @racc_debug_out.puts 'error recovering mode: pop token'
      racc_print_states state
      racc_print_stacks tstack, vstack
      @racc_debug_out.puts
    end

    def racc_next_state(curstate, state)
      @racc_debug_out.puts  "goto    #{curstate}"
      racc_print_states state
      @racc_debug_out.puts
    end

    def racc_print_stacks(t, v)
      out = @racc_debug_out
      out.print '        ['
      t.each_index do |i|
        out.print ' (', racc_token2str(t[i]), ' ', v[i].inspect, ')'
      end
      out.puts ' ]'
    end

    def racc_print_states(s)
      out = @racc_debug_out
      out.print '        ['
      s.each {|st| out.print ' ', st }
      out.puts ' ]'
    end

    def racc_token2str(tok)
      self.class::Racc_token_to_s_table[tok] or
          raise "[Racc Bug] can't convert token #{tok} to string"
    end

    def token_to_str(t)
      self.class::Racc_token_to_s_table[t]
    end

  end

end

...end racc/parser.rb/module_eval...
end
###### racc/parser.rb end
class BoolParser < Racc::Parser

  module_eval(<<'...end bool_parser.y/module_eval...', 'bool_parser.y', 53)

def initialize(lexerClass)
  @lexer_class = lexerClass
end

def parse(aString)
  @lexer = eval "#{@lexer_class}.new(aString)"
  do_parse
end

def next_token
  @lexer.next_token
end

TokenValueClass = Struct.new("TokenValueClass", :value, :tmp, :code)

class LexerError < Exception; end

class Lexer

  def initialize(aString)
    @str = aString
  end
  
  def next_token
    token = nil
    until token
      if @str =~ /^and\b/
        token = [$&, $&]
      elsif @str =~ /^or\b/
        token = [$&, $&]
      elsif @str =~ /^not\b/
        token = [$&, $&]
      elsif @str =~ /^=>/
        token = [$&, $&]
      elsif @str =~ /^<=>/
        token = [$&, $&]
      elsif @str =~ /^(\(|\))/
        token = [$&, $&]
      elsif @str =~ /^[a-zA-Z_]([a-zA-Z_0-9])*/
        token = [:LITERAL, $&]
      elsif @str =~ /^\s+/
        # do nothing      
      elsif @str.length > 0
        raise LexerError, "Invalid token at '#{@str[0, 10]}'"
      else
        token = [false, '$end']
      end # if      
      @str = $'
    end # until
    return token
  end
end #Lexer
...end bool_parser.y/module_eval...
##### State transition tables begin ###

  racc_action_table = [
      3, 10, 9, 7, 8, 5, 4, 18, 3, 13,
      3, 6, 3, 5, 4, 5, 4, 5, 4, 3,
      10, 3, nil, 3, 5, 4, 5, 4, 5, 4,
      10, 9, 7, 8, 10, 9, 7, 8, 10, 9,
      7, 8]

  racc_action_check = [
      0, 12, 12, 12, 12, 0, 0, 12, 10, 6,
      3, 1, 4, 10, 10, 3, 3, 4, 4, 9,
      16, 7, nil, 8, 9, 9, 7, 7, 8, 8,
      14, 14, 14, 14, 2, 2, 2, 2, 15, 15,
      15, 15]

  racc_action_pointer = [
      -2, 11, 31, 8, 10, nil, 9, 19, 21, 17,
      6, nil, -2, nil, 27, 35, 17, nil, nil]

  racc_action_default = [
      -2, -10, -1, -10, -10, -9, -10, -10, -10, -10,
      -10, -7, -10, 19, -3, -4, -5, -6, -8]

  racc_goto_table = [
      2, 1, nil, 11, 12, nil, nil, 14, 15, 16,
      17]

  racc_goto_check = [
      2, 1, nil, 2, 2, nil, nil, 2, 2, 2,
      2]

  racc_goto_pointer = [
      nil, 1, 0]

  racc_goto_default = [
      nil, nil, nil]

  racc_reduce_table = [
      0, 0, :racc_error,
      1, 11, :_reduce_none,
      0, 11, :_reduce_2,
      3, 12, :_reduce_3,
      3, 12, :_reduce_4,
      3, 12, :_reduce_5,
      3, 12, :_reduce_6,
      2, 12, :_reduce_7,
      3, 12, :_reduce_8,
      1, 12, :_reduce_9]

  racc_reduce_n = 10

  racc_shift_n = 19

  racc_token_table = {
      false => 0,
      :error => 1,
      "not" => 2,
      "and" => 3,
      "or" => 4,
      "=>" => 5,
      "<=>" => 6,
      :LITERAL => 7,
      "(" => 8,
      ")" => 9}

  racc_nt_base = 10

  racc_use_result_var = true

  Racc_arg = [
      racc_action_table,
      racc_action_check,
      racc_action_default,
      racc_action_pointer,
      racc_goto_table,
      racc_goto_check,
      racc_goto_default,
      racc_goto_pointer,
      racc_nt_base,
      racc_reduce_table,
      racc_token_table,
      racc_shift_n,
      racc_reduce_n,
      racc_use_result_var]

  Racc_token_to_s_table = [
      "$end",
      "error",
      "\"not\"",
      "\"and\"",
      "\"or\"",
      "\"=>\"",
      "\"<=>\"",
      "LITERAL",
      "\"(\"",
      "\")\"",
      "$start",
      "target",
      "expr"]

  Racc_debug_parser = false

##### State transition tables end #####

# reduce 0 omitted

# reduce 1 omitted

  module_eval(<<'.,.,', 'bool_parser.y', 38)
  def _reduce_2(val, _values, result)
     result = nil 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 41)
  def _reduce_3(val, _values, result)
     result = Implication.new(val[0], val[2]) 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 42)
  def _reduce_4(val, _values, result)
     result = DoubleImplication.new(val[0], val[2]) 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 43)
  def _reduce_5(val, _values, result)
     result = Or.new(val[0], val[2]) 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 44)
  def _reduce_6(val, _values, result)
     result = And.new(val[0], val[2]) 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 45)
  def _reduce_7(val, _values, result)
     result = Not.new(val[1]) 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 46)
  def _reduce_8(val, _values, result)
     result = val[1] 
    result
  end
.,.,

  module_eval(<<'.,.,', 'bool_parser.y', 47)
  def _reduce_9(val, _values, result)
     result = Lit.new(val[0]) 
    result
  end
.,.,

  def _reduce_none(val, _values, result)
    val[0]
  end

end # class BoolParser
