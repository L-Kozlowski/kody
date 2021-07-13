$ostatni = Get-Process 
for($i = 0; $i -lt  ($ostatni.count);$i++)
{

$p = Get-Process | Sort id |Select-Object -Skip $i  | Select-Object -First 1
$id = $p.Id
$not = Get-CimInstance -ClassName win32_process -Filter "processId = $id "
"ID: {0} Nazwa: {1} " -f $p.Id, $p.Name
$liczba = 1
while($not.ParentProcessId -ne 0 )
{
if($not -eq $null)
{break}
for($z = 0; $z -lt  $liczba;$z++)
{Write-Host("`t")-NoNewline}
Write-Host("Parent nr:",($liczba),": ",$not.Name)



$not2 =$not.ParentProcessId
$not = Get-CimInstance -ClassName win32_process -Filter "processId = $not2 "
$liczba = $liczba +1


}
#$not.Name

}