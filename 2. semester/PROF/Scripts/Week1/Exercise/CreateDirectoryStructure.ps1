param(
    [int]$WeekNo,
    [int]$N,
    [string]$Ext

)

cd ../..
New-Item "Week$WeekNo" -ItemType Directory | Out-Null
cd "Week$WeekNo"
New-Item "Notes.txt" | Out-Null
New-Item "Exercise" -ItemType Directory | Out-Null
cd "Exercise"
for($i = 0; $i -lt $N; $i++){
    New-Item "Exercise$($i+1).$Ext" | Out-Null
}
cd "../../Week1/Exercise"
"all the files for week $WeekNo have been created"