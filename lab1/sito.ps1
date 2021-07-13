Write-Host "wpisz liczbe"
$N = Read-Host
Write-Host "Wpisałeś liczbe"
$N
$arr = [int[]]::new($N)

$sq = [math]::Sqrt($N)

for($i = 0;$i -lt $arr.Length; $i++)
{
    $arr[$i] = 1
}

for($i = 2;$i -lt $sq;$i++)
{
    if($arr[$i] -eq 1)
    { 
       for($j = $i+$i; $j -lt $arr.Length; $j+=$i)
      {
        $arr[$j] = 0
      }
    }
}
#$arr
Write-Host "Liczby pierwsze to:"
for($i = 2;$i -lt $arr.Length;$i++)
{
    if($arr[$i] -eq 1)
    { 
    $i
    }

}