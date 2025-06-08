import subprocess as sp
import sys
# accessing the ip subnet address from the cmd
ip=sys.argv[1]

def pingSweep(ip):
       res=sp.run(['nmap','-sn',f'{ip}'],stdout=sp.PIPE,stderr=sp.PIPE)
       return res
       
res=pingSweep(ip)
count=-1
with open("findings.txt",'w+') as file:
    for line in res.stdout.splitlines("\n"):
         clean_string = line.decode('utf-8').strip()
         if count==-1:
              count=count+1
         else:
              file.write(clean_string + "\n")
              file.write("--------------------------------------------------------------------" + "\n")
file.close()
