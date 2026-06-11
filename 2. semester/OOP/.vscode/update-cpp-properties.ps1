param([string]$ProjectDir)

# Extract exam year and task name from path
$pathParts = $ProjectDir -split '\\'
$taskName = $pathParts[-1]  # e.g., "Opgave_3"
$examYear = $pathParts[-2]  # e.g., "sommer-2025"

# Find all Opgave folders in the same exam directory
$examDir = Split-Path $ProjectDir
$opgaveFolders = Get-ChildItem -Path $examDir -Directory -Filter "Opgave_*" | Sort-Object Name

# Build include paths: current task first, then others
$includePaths = [System.Collections.Generic.List[string]]::new()

# Add current task's includes first (both include/ and src/)
$currentTask = $opgaveFolders | Where-Object { $_.Name -eq $taskName }
if ($currentTask) {
    $includePaths.Add("$($currentTask.FullName)\include")
    $includePaths.Add("$($currentTask.FullName)\src")
}

# Add other tasks' includes (both include/ and src/)
$opgaveFolders | Where-Object { $_.Name -ne $taskName } | ForEach-Object {
    $includePaths.Add("$($_.FullName)\include")
    $includePaths.Add("$($_.FullName)\src")
}

# Find .vscode directory
$vscodeDir = Split-Path $ProjectDir -Parent
while ($vscodeDir -and !(Test-Path "$vscodeDir\.vscode")) {
    $vscodeDir = Split-Path $vscodeDir -Parent
}

if (Test-Path "$vscodeDir\.vscode\c_cpp_properties.json") {
    # Escape backslashes for JSON
    $escapedPaths = $includePaths | ForEach-Object { $_.Replace('\', '\\') }
    $cppPropsJson = @"
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                $(($escapedPaths | ForEach-Object { "`"$_`"" }) -join ",`n                ")
            ],
            "defines": [],
            "compilerPath": "C:/Windows/c/bin/c++.exe",
            "cStandard": "c23",
            "cppStandard": "c++20",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}
"@
    $cppPropsJson | Set-Content -Path "$vscodeDir\.vscode\c_cpp_properties.json"
    Write-Output "Updated c_cpp_properties.json for $taskName in $examYear"
    Write-Output "Include paths:"
    $includePaths | ForEach-Object { Write-Output "  - $_" }
}
