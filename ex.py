import os
from pylab import *

filenames=os.listdir(os.getcwd())
for name in filenames:
     filenames[filenames.index(name)]=name[:-6]

plot(filenames,name)

out=open('names.txt','w')
for name in filenames:
     out.write(name+'\n')

out.close()
