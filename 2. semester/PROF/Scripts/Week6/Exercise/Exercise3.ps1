



[int]$randNum = Get-Random -Minimum 0 -Maximum 100

[int]$guess = $null

Write-Host "Guess a number between 0 and 100"
$guess_str = "Enter your guess"
[int]$tries = 0

while ($true){
    $tries++
    try {
        $guess = (Read-Host $guess_str)
    }catch{
        $guess_str = "please enter a number, your mistake costs 1 guess, try again"
        continue
    }

    if ($guess -eq $randNum){
        break
    }

    $guess_str = ("Wrong, your guess it too " + (($guess -gt $randNum)? "high" : "low") + ", try again")

}

Write-Host "`n`n`n`nCongratulations, you guessed the number $randNum"
Write-host ("It took you $tries guesse" + (($tries -ge 2)?"s":""))





