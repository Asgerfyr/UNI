#!/bin/bash


COLLECTED_CODE_PATH="/c/Users/Asger/Uni/Github/UNI/2. semester/PROF/Scripts/Week7/Exercise/Collected_Code"
IFS=":" #the seperation char for when the array is expanded to a stirng
DIR_COLLECTED="${$IFS}Collected_Code${$IFS}" # a long string with IFS seperating the directories


# if we have the collect folder store all the existing directories in the array, otherwise we create the folder
if [ -d "$COLLECTED_CODE_PATH" ]; then
    DIR_COLLECTED+=$(find "$COLLECTED_CODE_PATH" -type d -printf "%f$IFS")
else 
    mkdir '/c/Users/Asger/Uni/Github/UNI/2. semester/PROF/Scripts/Week7/Exercise/' Collected_Code
fi

find . -prune -o -type f \( -name "*.cpp" -o -name "*.h" \) | while read file; do
    dir=$(dirname "$file")
    # check if we already have the directory in the array of collected directories,
    if [[ "$DIR_COLLECTED" == *"$IFS$dir$IFS"* ]]; then
        continue # if we already have the directory, we skip it
    fi
    DIR_COLLECTED+="$dir$IFS" # add the directory to the array of collected directories
    cp -r "$dir" "$COLLECTED_CODE_PATH" 2>/dev/null || true # copy the directory to the collected code path, and hide any permission messages
done

