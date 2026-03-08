Write-Host "Enter your age:`n"

[int]$age = $null

try {
    $age = (Read-Host)
}catch {
    Write-Host "please enter a number"
    exit 1
}


[string]$response = $null

switch ($age){

    {$_ -lt 13}{
        $response = "Child"
        break
    }

    {$_ -lt 19}{
        $response = "Teenager"
        break
    }

    {$_ -ge 20}{
        $response = "Adult"
        break
    }
}

Write-Host "you are a $response"


