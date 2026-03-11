param(
    [string]$path = ".\"
)

#get all items that are not a container, for the path provided by the user 
$files = Get-ChildItem -Recurse -Path $path 
| where-Object { -not $_.PSContainer} 

#counter var
[int]$count = 0

#counts up all the files that end with .png
ForEach($file in $files){
    if($file.name -like "*.png"){
        $count++
    }
}
#prints out the count
$count