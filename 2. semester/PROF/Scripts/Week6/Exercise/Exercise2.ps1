param(
    [string]$path = ".\"
)


$files = Get-ChildItem -Recurse -Path $path 
| where-Object { -not $_.PSContainer} 


[int]$count = 0

ForEach($file in $files){
    if($file.name -like "*.png"){
        $count++
    }
}

$count
