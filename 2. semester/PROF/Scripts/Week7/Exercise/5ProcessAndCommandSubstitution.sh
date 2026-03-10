#!/bin/bash

res=$(find /c/Users/Asger -maxdepth 1 -type f -printf "%s %P\n" | sort -k1 -n -r | head -n 5)
echo "$res"