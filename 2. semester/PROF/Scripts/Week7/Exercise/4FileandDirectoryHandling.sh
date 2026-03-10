#!/bin/bash

data=$(date "+%Y-%m-%d")

mkdir -p "backup_$data"

mv *.txt "backup_$data"