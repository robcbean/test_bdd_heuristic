def executeCommandLine(_cmd)
  cmd = "c:\\cygwin64\\bin\\bash.exe --login -c \"#{_cmd}\""
  `#{cmd}`
end