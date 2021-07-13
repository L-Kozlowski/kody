Write-Output "Czas co 5 sek">zad2.txt

while(1)
{
 Get-Date |Select-Object Hour, minute, second >> zad2.txt


Start-Sleep -s 5
}