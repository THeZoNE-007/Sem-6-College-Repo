import sys
import operator as op
filename=sys.argv[1];
print("Sl Age")
with open(filename,'r') as file:
	for line in file.readlines():
	    splitted_line=line.split(" ");
	    print(splitted_line[0]," ",splitted_line[2].replace("\n",""))
print("Students having age > 18:")	    
with open(filename,'r') as file:
	for line in file.readlines():
	    splitted_line=line.split(" ");
	    age=int(splitted_line[2].replace("\n",""))
	    if age>18:
	       print(splitted_line[1])
print("Students having ram in their name: ")
count=0;	
ageSum=0;       
with open(filename,'r') as file:
	for line in file.readlines():
	    count+=1;
	    splitted_lines=line.split(" ");
	    ageSum+=int(splitted_lines[2])
	    if op.contains(splitted_lines[1].replace("\n","").lower(),"ram"):
	        print(line)
print("Lines present in file: ",count)
print("Average Age: ",ageSum/count)


