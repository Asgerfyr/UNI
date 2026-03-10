#!/bin/bash

#get all files in user/Asger and print it out in "size path" 
#| sort the output numerically and reverse acording to 1st parameter in "size path"
#| get the top 5 and print it out 
res=$(find /c/Users/Asger -maxdepth 1 -type f -printf "%s %P\n" | sort -k1 -n -r | head -n 5)
echo "$res"