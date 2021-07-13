$n = Get-Process -name "Notepad"
$n
$a = $n.Id
$not = Get-CimInstance -ClassName win32_process -Filter "processId = $a "
$not
$not.ParentProcessId
$parent= Get-Process -id $not.ParentProcessId
Stop-Process -Name $parent.Name
