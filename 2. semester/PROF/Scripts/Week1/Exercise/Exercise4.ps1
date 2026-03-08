param(
    [string]$path
)


(Get-ChildItem -Path $path | 
Where-Object { $_.PSIsContainer } | 
ForEach-Object { Get-ChildItem $_.FullName | 
Where-Object { -not $_.PSIsContainer -and $_.length -gt 10MB} }) + 

(Get-ChildItem -Path $path | 
Where-Object { -not $_.PSIsContainer -and $_.length -gt 10MB}) | 
Sort-Object -Property Length -Descending