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

while($true){

    Write-Host -NoNewline "Todo> "
    [string]$commands = Read-Host 
    write-host ""

    [array]$commandList = $commands.Split(" ")

    while($commandList.Length -ne 0){
        switch($commandList[0]){

            {$_ -in "-h", "-help"} {
                $commandList = Remove-Commands -commandList $commandList
                Show-Help
                break
            }

            {$_ -in "-add", "-a"} {
                $commandList = Remove-Commands -commandList $commandList;
                [array]$tasksToAdd = Get-Args -a $commandList
                if($tasksToAdd.length -gt 0){$todoList += $tasksToAdd}
                write-host "added $($tasksToAdd.length) tasks`n`n"
                $commandList = Remove-Commands -amount $tasksToAdd.length -commandList $commandList
                break
            }

            {$_ -in "-remove", "-r"} {
                $commandList = Remove-Commands -commandList $commandList
                [array]$tasksToRemove = Get-Args -a $commandList
                $todoList = Remove-Tasks -indexes $tasksToRemove -todoList $todoList
                write-host "removed $($tasksToRemove.length) tasks`n`n"
                $commandList = Remove-Commands -amount $tasksToRemove.length -commandList $commandList
                break
            }

            {$_ -in "-view", "-v"} {
                $commandList = Remove-Commands -commandList $commandList
                Show-Tasks -todoList $todoList | Out-Null
                write-host "`n"
                break
            }

            "-exit" {
                exit 0
            }
            
            default {
                write-host "unknown command: $($commandList[0])`n`n"
                $commandList = Remove-Commands -commandList $commandList
                break
            }
            
        }
    }

}