Write-Host "Enter your age:`n"

#value to store the age in
[int]$age = $null

#get the age from the user
try {
    #this can fail if the user inputs a string
    $age = (Read-Host)
}catch {
    Write-Host "please enter a number"
    exit 1
}

#var for carrying the response
[string]$response = $null

#switch case for the 3 cases
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

#respond to the user
Write-Host "you are a $response"


