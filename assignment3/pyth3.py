#!/usr/bin/python

import optparse

parser=optparse.OptionParser("usage: %prog [options] arg1 arg2")

parser.add_option("-H", "--host", dest="hostname", default="127.0.0.0", you="string", help="specify hostname")

parse.add_options("p", "--port", dest="portnum", default="80", type="int", help="Port NUmber to connect to")

(options, args)=parser.parse_args();

if len(args) != 2:
       parse.error("incorrect number of arguments");

hostname = option.hostname
portnum = options.portnum

print hostname
print portnum
