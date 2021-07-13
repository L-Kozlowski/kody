$i = "Ola"
$j = "Łukasz"

" {0} uczy {1}, {1} nie jest przekonana do tego co mówi {0}" -f $j,$i > przykład.txt


<#param #definicja bloku parametrow
(
$foo
)

Write-Output "argumenty:"

for($i = 0; $i -lt $ARGS.Count; $i++)
{
Write-Host "$i = $($ARGS[$i])" > sprawdz.txt
}

#C:\Users\48692\Desktop\SEMESTR_4\"SYSTEMY OPERACYJNE"\parametry.ps1 a b c

Write-Output "parametry nazwane:"
Write-host "foo = $foo"
Write-Host "bar = $bar"
#>



#$z

<#
#for($i = 0; $i -lt $h.Count;$i++){
$z >> baza_danych.json
#}
#>
#Algorithm  = $algorithm[$i]


#$algorithm = $z.algorithm

#Write-Host "$h[0]"
#$h[0]



#TO była próba w for
#$k
#$ii = -1


            <#for($l =0; $l -lt $z.Count;$l++){
                if($k[$l] -eq $h[$i] -and $ii -ne $i )
                {
                break;
                }
            }
            $z[$index] = $h[$i]
            $ii =$i#>
         
            #"{0} {1} identyczny dla {2}" -f $h[$i],$path[$i],$path[$j]  >>powtorzone2.txt
            #$w >> sprawdz.txt
            #$j
            #$w = $z[$j]
            #$w >> sprawdz.txt
              #$w = $z[$i]







  #$j
            #$w = $z |Where-Object hash -Match $h[$j]
            #$w #>> sprawdz.txt


function funkcja{
param
(
$zmienna,
$data
#$liczba,
#$nh 
)
$pliki = Get-ChildItem -path  "$zmienna"| Where-Object -Property Mode -ne -Value "d----"
$foldery = Get-ChildItem -path  "$zmienna" | Where-Object -Property Mode -eq -Value "d----"


"`n pliki z folderu {0}`n" -f $zmienna
for($i = 0; $i -lt $pliki.Count;$i++)
{
if($pliki.LastWriteTime[$i] -gt $data)
{
$nh = $pliki[$i] |Get-FileHash
#$nh[$liczba] = $nh3
$nh
$liczba = $liczba +1
#"{0} {1} " -f $pliki.LastWriteTime[$i],$pliki.name[$i]
}
}

#"`n foldery: {0}`n" -f $zmienna
#for($i = 0; $i -lt $foldery.Count;$i++)
#{
#"{0} {1} " -f $foldery.LastWriteTime[$i],$foldery.name[$i]
#}
#$parametr = $ARGS[0].ToString()
#$parametr


for($i = 0; $i -lt $foldery.Count;$i++)
{
$scierzka = $foldery[$i].PSPath
$scierzka = $scierzka.replace("Microsoft.PowerShell.Core\FileSystem::","")
funkcja -zmienna $scierzka -data $data # -liczba $liczba -nh $nh
}
}
$liczba = 1
#$nh[100]

funkcja -zmienna $ARGS[0] -data $date_stala #-liczba $liczba -nh $nh


    <#
}else
{
    $z = Get-ChildItem -path $parametr -Recurse -Force -File | Get-FileHash
    $h = $z.hash
    #$h
    $path = $z.path

    $result =  @(for($i = 0; $i -lt $z.count; $i++)
    {
        @{
        Hash =$h[$i]
        Path = $path[$i]}
    })| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
    $result | ConvertTo-JSON > baza_danych.json

    Get-Date > pomocnicze_parametry.txt
    $parametr  >> pomocnicze_parametry.txt
}#>
<#
$brak_pliku = 0
if($scierzka -eq $null)
{
    $brak_pliku = 1
}else
{
    $sciezka[3]
    $sciezka = $sciezka[3]
    $sciezka
    $parametr
}
if($parametr -eq $scierzka -or $brak_pliku)
{#>