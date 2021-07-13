$start = Get-Date 
$początek = $start.Millisecond + $start.Second *1000

"Czas startu: {0} ms"-f $początek 

$a = ping "wp.pl" 
$a = $a | Select-String "time="
$a = $a -replace "Reply from 212.77.98.9: bytes=32 ",""
$a = $a -replace "TTL=56",""
$a

$stop = Get-Date 
$koniec = $stop.Millisecond + $stop.Second *1000
"Czas końca: {0} ms" -f $koniec

$czas = $koniec - $początek

"Czas działania programu: {0} {1} ms" -f $czas, $start> proba.txt



