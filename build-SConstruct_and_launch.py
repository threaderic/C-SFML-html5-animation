#!/usr/bin/python
'''
create the SConstruct from all name of the folders in ./ to be build with scons
first hand made line of Sconstruct which build good :
SConscript('ch02-02-event-demo/src/SConscript', variant_dir='build-scons/ch02-02-event-demo', duplicate=0)
'''

import os
import subprocess

lines_of_text=[]

lists=os.listdir(".")

for filename in lists: # loop through all the files and folders
    if os.path.isdir(os.path.join(os.path.abspath("."), filename)): # check whether the current object is a folder or not
        lines_of_text.append(filename)
        
print(lines_of_text)

ItemsToRemove=["shared-deps","_Template","build-scons",".git",".idea",".idea","_builds","build","cmake-build-release","cmake-build-debug"]

for x in ItemsToRemove :
    if x in lines_of_text: lines_of_text.remove(x)

print("\n\n\n")

counter=0

for val in lines_of_text:
    lines_of_text[counter]= "SConscript('" + lines_of_text[counter] + "/SConscript', variant_dir='build-scons/" + lines_of_text[counter] + "', duplicate=0)" + "\n"
    counter+=1
    
print(lines_of_text)
lines_of_text.sort()

#copy all lines in SConstruct file / if not exists create it
fh = open("SConstruct","w") 
fh.writelines(lines_of_text) 
fh.close() 

#launch scons
#p = subprocess.Popen('scons', shell=True)
#sts = os.waitpid(p.pid, 0)
