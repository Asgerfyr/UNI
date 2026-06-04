param([string]$StartDir)

# Find CMakeLists.txt by going up the directory tree
$dir = $StartDir
while ($dir -and !(Test-Path "$dir\CMakeLists.txt")) {
    $parent = Split-Path $dir
    if ($parent -eq $dir) { break }
    $dir = $parent
}

if (!(Test-Path "$dir\CMakeLists.txt")) {
    Write-Error "CMakeLists.txt not found"
    exit 1
}

Write-Output "Found CMakeLists.txt in: $dir"
Set-Location $dir

# Build
cmake -B build -S .
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

cmake --build build
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# Find and run executable
$exe = Get-ChildItem -Path "$dir\build" -Filter *.exe -Recurse -Exclude a.exe | Select-Object -First 1
if ($exe) {
    Write-Output "Running: $($exe.FullName)"
    Clear-Host
    & $exe.FullName
} else {
    Write-Error "No executable found"
    exit 1
}
