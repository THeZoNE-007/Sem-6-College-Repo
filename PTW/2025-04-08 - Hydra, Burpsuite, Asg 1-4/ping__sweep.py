import sys
import subprocess as sp
result = sp.run(['nmap', '-sn', sys.argv[1]], stdout=sp.PIPE, stderr=sp.PIPE)
count=-1
for line in result.stdout.splitlines("\n"):
	cleanString = line.decode("utf-8").strip()
	print(cleanString)
	
