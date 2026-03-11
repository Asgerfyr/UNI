#get a random number
[int]$randNum = Get-Random -Minimum 0 -Maximum 100

#store the users guess
[int]$guess = $null

#print out the the user what there task is
Write-Host "Guess a number between 0 and 100"
#a var to store the message printed to the user in the input field
#this allows for changing the printed text
$guess_str = "Enter your guess"
#store the number of tries
[int]$tries = 0

while ($true){
    $tries++ # increment tries

    #user guess
    try {
        $guess = (Read-Host $guess_str)
    }catch{
        $guess_str = "please enter a number, your mistake costs 1 guess, try again"
        continue
    }

    #is it the right guess
    if ($guess -eq $randNum){
        break
    }

    #change the text in the input to match if the number was higher or lower
    $guess_str = ("Wrong, your guess it too " + (($guess -gt $randNum)? "high" : "low") + ", try again")

}

#print end result to the user
Write-Host "`n`n`n`nCongratulations, you guessed the number $randNum"
Write-host ("It took you $tries guesse" + (($tries -ge 2)?"s":""))





