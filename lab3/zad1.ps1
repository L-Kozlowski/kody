notepad
Get-Process

Get-Process -Name notepad
$id = Read-Host("Podaj PID processu który ma zostać zatrzymany")
Write-Host("Proces zostanie zatrzymany")
Get-Process -id $id
Stop-Process -id $id

