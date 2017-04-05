#!/bin/sh

./script.sh | grep -v ".*--" | sed "/not a dynamic executable/d" | sed "s/=>.*//g" | sed "s/(0x00007.*//g" | sed "s/\t//g" |  sort -u 
