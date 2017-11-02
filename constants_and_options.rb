require 'os'


def getOptimization()
  if OS.mac?
    ret = ""
  else
    ret = "-O3"
  end
end

def getDebug()
  ret = ""
  #ret = " -g "
  return ret
end


def minisat_factor()
  ret = ""
  return ret
end


def srcPathCygWin()
  return "/cygdrive/c/Users/Roberto/Dropbox/Uned/Doctorado/bdd_heur_analysis/src"
end

def srcPathDOS()
  return "C:\\\\Users\\\\Roberto\\\\Dropbox\\\\Uned\\\\Doctorado\\\\bdd_heur_analysis\\\\src"
end

def srcPathDOSOnlyOne()
  return srcPathDOS.gsub("\\\\", "\\")
end

def calcComplexity?()
  ret = false
  return ret
end

def calcAllSpan?()
  ret = false
  return ret
end

def calcNewSpan?()
  ret = false
  return ret
end 


def calcPowerSpan?()
  ret = false
  return ret
end


def getCNFMINCEFile()
  ret = "cnfmince.dimacs"
  return ret
end

def getLeftOrderFile()
  ret = "left2right.ord"
  return ret
end

def grownFile()
  if OS.linux? or OS.mac?
    ret = "growth.txt"
  else
    ret = "#{srcPathDOS}\\\\growth.txt"
  end

  return ret
end

def printMinters()
  ret = true
  return ret
end


def preorderInSPLOT()
  ret = false
  return ret
end

def calcTotal()
  ret = "true"
  return ret
end



def malik_level()
  "malik_level"
end

def malik_fanin()
  "malik_fanin"
end

def fujita()
  "fujita"
end

def fujii()
  "fujii"
end

def FORCE()
  "FORCE"
end

def MINCE()
  "MINCE"
end

def mendonca()
  "mendonca"
end

def narodyska()
  "narodyska"
end

def preorderRandom()
  "preorder_random"
end


def useNokogiri?()
  ret = true
  if isUNED?
    ret = false
  end
  return ret
end

def isUNED?()
  ret = false
  name = `hostname`
  if name.strip == "ram.issi.uned.es"
    ret = true
  end

  return ret
end


def printSymmetric?()
  ret = false
  return ret
end

def showStatistics()
  ret = false
  return ret
end



def sendMail?

  if isUNED?
    ret = true
  else
    ret = false
  end

  ret = false
  return ret
end


def printOrder()
  ret = true
  return ret
end
