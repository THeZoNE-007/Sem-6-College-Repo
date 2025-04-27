import sys
import subprocess as sp

file = sys.argv[1]
result = sp.run(["sudo","awk","\'{print $1 $3}\'","{file}"], stdout=sp.PIPE, stderr=sp.PIPE)

print(result)
