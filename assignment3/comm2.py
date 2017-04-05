#!/usr/bin/python

import random, sys, locale
from optparse import OptionParser

parser = OptionParser("comm [OPTION]... FILE1 FILE2")


parser.add_option("-1", action="store_true", dest="o1", default=False,help="supress column 1 which are all lines unique to file1")


parser.add_option("-2", action="store_true", dest="o2", default=False,help="supress column 2 which are all lines unique to file2")

parser.add_option("-3", action="store_true", dest="o3", default=False,help="supress column 3 which are all lines in the intersection of file1 and file2")

parser.add_option("-u", action="store_true", dest="sorting",default=False,help="prints out the lines regardless of the files of being sorted")

(options, args) = parser.parse_args()
file1=[]
file2=[]


if len(args) != 2:
    parser.error("ERROR: NEED TWO ARGUMENTS")
else:
    if args[0] != "-" and args[1] != "-":
        with open(args[0],'r') as f:
            for line in f:
                line=line.strip('\n')
                file1.append(line)
        with open(args[1],'r') as f:
            for line in f:
                line=line.strip('\n')
                file2.append(line)    
    elif args[0] == "-":
        userinput=list(sys.stdin.readlines())
        for line in userinput:
            line=line.strip('\n')
            file1.append(line)
        with open(args[1],'r') as f:
            for line in f:
                line=line.strip('\n')
                file2.append(line)
    elif args[1] == "-":
        with open(args[0],'r') as f:
            for line in f:
                line=line.strip('\n')
                file1.append(line)
        userinput=list(sys.stdin.readlines())
        for line in userinput:
            line=line.strip('\n')
            file2.append(line)
    else:
        print "cannout have both arguments as standard inputs"
        
#print file1
#print file2

#need to read files into an array or something
#unique to file1 perserving order
set1 = set(file2)
temp = [ x for x in file1 if x not in set1]
first = list(temp)
#print "first: "
#print first
#unique to file2 perserving order
set2 = set(file1)
temp =[x for x in file2 if x not in set2]
second = list(temp)
#print "second: "
#print second
#intersection of file1 and file2 perserving order
set3 = set(file2)
temp = [x for x in file1 if x in set3]
intersection=list(temp)
#print "intersection: "
#print intersection 

display=[]


if (options.o1 and not options.o2 and not options.o3):
    for x in second:
        display.append('\t'+x)
    for x in intersection:
        display.append('\t' + '\t' + x)
elif (not options.o1 and options.o2 and not options.o3):
    for x in first:
        display.append(x)
    for x in intersection:
        display.append('\t' + '\t' + x)
elif (not options.o1 and not options.o2 and options.o3):
    for x in first:
        display.append(x)
    for x in second:
        display.append('\t' + x)
elif (options.o1 and options.o2 and not options.o3):
    for x in intersection:
        display.append(x)
elif (options.o1 and not options.o2 and options.o3):
    for x in second:
        display.append(x)
elif (not options.o1 and options.o2 and options.o3):
    for x in first:
        display.append(x)
elif (not options.o1 and not options.o2 and not options.o3):
    for x in first:
        display.append(x)
    for x in second:
        display.append('\t' + x)
    for x in intersection:
        display.append('\t' + '\t' + x)
elif (options.o1 and options.o2 and options.o3):
    sys.stdout.write("")



display.sort(key=lambda x: x.count(' '), reverse=True)



for f in display:
    print f
