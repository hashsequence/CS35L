#!/bin/sh 
cat /proc/self/maps | ./sfrob | wc -l
