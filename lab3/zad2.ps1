notepad
Start-Sleep -s 5

Write-Host("Proces zostanie zatrzymany")
Get-Process -name notepad
Stop-Process -name notepad