param(
    [string]$path
)
#printing out all files over 10MB in this directory and its subdirectorys, not recursively


#getting all files from the subdirectory
(Get-ChildItem -Path $path | 
Where-Object { $_.PSIsContainer } | 
ForEach-Object { Get-ChildItem $_.FullName | 
Where-Object { -not $_.PSIsContainer -and $_.length -gt 10MB} }) + 

#getting all files in this directory
(Get-ChildItem -Path $path | 
Where-Object { -not $_.PSIsContainer -and $_.length -gt 10MB}) | 
Sort-Object -Property Length -Descending

#there is probably filter and depth on find Get-ChildItem, but this taught me a lot about piping