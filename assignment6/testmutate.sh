#!/bin/sh 
cat /proc/self/maps | ./sfrobu | wc -l
