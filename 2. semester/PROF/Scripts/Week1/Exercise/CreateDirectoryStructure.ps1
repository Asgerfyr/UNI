param(
    [int]$WeekNo,
    [int]$N,
    [string]$Ext

)
#this script needs to be started from this directory
cd ../..
New-Item "Week$WeekNo" -ItemType Directory | Out-Null #make the week folder
cd "Week$WeekNo"
New-Item "Notes.txt" | Out-Null #make the note.txt file
New-Item "Exercise" -ItemType Directory | Out-Null #make the Exercise folder
cd "Exercise"
for($i = 0; $i -lt $N; $i++){
    New-Item "Exercise$($i+1).$Ext" | Out-Null #make all the Exercise.[extention] file
}
cd "../../Week1/Exercise"
"all the files for week $WeekNo have been created" #print to user