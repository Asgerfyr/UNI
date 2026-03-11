#removes the next x amount of commands from the command list
function Remove-Commands{
    param(
        [int]$amount = 1,
        [array]$commandList
    )
    if($amount -eq $commandList.Length){
        return @()
    }
    return $commandList[$amount..($commandList.Length - 1)]
}

#prints out a help message
function Show-Help{
    write-host "
                -h                      : show help
                -add [item] [item]      : add item to todo
                -a [item] [item]        : add item to todo
                -remove [index] [index] : remove item from todo
                -r [index] [index]      : remove item from todo
                -view                   : view todo list
                -v                      : view todo list
                -exit                   : exit the program

                chain commands together like this:
                -add task1 task2 -view -remove 0 -view
                "
}

#finds all arguments until the next command
function Get-Args{
    param(
        $a
    )
    $stop = $false
    return @(
        $a | foreach-object {
            if($stop){return}
            if($_ -like "-*"){$stop = $true; return }
            $_
        }
    )
}

#only keeps the item in the todo list that are not in the list of indexes to remove
function Remove-Tasks{
    param(
        [array]$indexes,
        [array]$todoList
    )
    $indexes = $indexes | foreach-object {[int]$_}
    return @(
        for($i = 0; $i -lt $todoList.length; $i++) {
            if(($i+1) -notIn $indexes){$todoList[$i]}
        }
    )
}

#print out the todo list
function Show-Tasks{
    param(
        [array]$todoList
    )
    for($i = 0; $i -lt $todoList.Length; $i++){
        Write-Host "$($i+1)`: $($todoList[$i])"
    }
    return @($todoList)
}


$todoList = @()
Write-Host -NoNewline "             -h for help`n`n"
while($true){

    Write-Host -NoNewline "Todo> "
    [string]$commands = Read-Host #get alle commands and arg from user
    write-host ""

    [array]$commandList = $commands.Split(" ") #split commands and args into array

    while($commandList.Length -ne 0){
        switch($commandList[0]){ #read the first command

            {$_ -in "-h", "-help"} { #show help
                $commandList = Remove-Commands -commandList $commandList #remove the first command
                Show-Help #show help
                break
            }

            {$_ -in "-add", "-a"} { #add all the arg to the todo list
                $commandList = Remove-Commands -commandList $commandList; #remove the first command
                [array]$tasksToAdd = Get-Args -a $commandList #get all the arguments after the command
                if($tasksToAdd.length -gt 0){$todoList += $tasksToAdd} #if there are any tasks to add, add them
                write-host "added $($tasksToAdd.length) tasks`n`n" #print out the tasks added
                $commandList = Remove-Commands -amount $tasksToAdd.length -commandList $commandList #remove the arguments, so the next command is the first in the list
                break
            }

            {$_ -in "-remove", "-r"} { #remove all the arg index form the todo list
                $commandList = Remove-Commands -commandList $commandList #remove the first command
                [array]$tasksToRemove = Get-Args -a $commandList #get all the arguments after the command
                $todoList = Remove-Tasks -indexes $tasksToRemove -todoList $todoList #remove all the tasks mentioned by the arguments
                write-host "removed $($tasksToRemove.length) tasks`n`n" #print out the tasks removed
                $commandList = Remove-Commands -amount $tasksToRemove.length -commandList $commandList #remove the arguments, so the next command is the first in the list
                break
            }

            {$_ -in "-view", "-v"} { #show todo list
                $commandList = Remove-Commands -commandList $commandList #remove the first command
                Show-Tasks -todoList $todoList | Out-Null #show the todolist
                write-host "`n" #make new line
                break
            }

            "-exit" { #exit the program
                exit 0 #exit program
            }
            
            default { #unknown command
                write-host "unknown command: $($commandList[0])`n`n" #print out the unknown command
                $commandList = Remove-Commands -commandList $commandList #remove the first command
                break
            }
            
        }
    }

}