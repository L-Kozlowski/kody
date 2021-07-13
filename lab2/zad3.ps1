Write-Output "Czas co 5 sek">zad3.txt

while(1)
{
&{ 
Get-Date |Format-Table -Property Hour, minute, second
Get-Process | Sort-Object "CPU" -desc| Select-Object -First 1 |Format-Table -Property ProcessName,cpu,Id
 } >> zad3.txt
 $p = Get-Date |Format-Table -Property Hour, minute, second
$d=Get-Process | Sort-Object "CPU" -desc| Select-Object -First 1 |Format-Table -Property ProcessName,cpu,Id

#"{0:yyy-MM-dd}" -f 


Start-Sleep -s 5
}