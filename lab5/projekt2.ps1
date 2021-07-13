$parametr = $ARGS[0]
if(Test-Path baza_danych.json)
{
    $sciezka = Get-Content -path baza_danych.json  |ConvertFrom-Json
    $sciezka = $sciezka.POMOCNICZE_PARAMETRY.SCIEZKA
    if($parametr -eq $sciezka )
    {
        $plik = 1
    }else
    {
        $plik = 0
    }
}else
{
    $plik = 0
}

#------------------------------------------------------------------ BAZY DANYCH

if(($plik)){
$a = Get-Content -path baza_danych.json |ConvertFrom-Json
$h = $a.BAZA_DANYCH.hash
$path = $a.BAZA_DANYCH.path
$dane =  Get-ChildItem -path $parametr -Recurse -Force -File 

#-------------------------------------------------------------------- DATY

$date = Get-Content baza_danych.json  |ConvertFrom-Json
$date = $date.POMOCNICZE_PARAMETRY.DATA
$date_stala = Get-Date -Date "piątek, 9 kwietnia 2021 19:20:00"
$date_new = Get-Date 
$suma = @{
DATA = $date_new
SCIEZKA = $parametr
}
#$suma 

#-------------------------------------------------------------------- NOWE PLIKI PO DACIE



$job = Start-Job -ScriptBlock{

@( for($i = 0; $i -lt $args[0].Count;$i++)
{
    if($args[0].LastWriteTime[$i] -gt $args[1])
    {
    $dane = $args[0]
    $ss =$dane[$i] |Get-FileHash
        @{
            Hash =$ss.hash
            Path =$ss.path
        }
    }
})| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
} -ArgumentList $dane,$date

<#
$nh = for($i = 0; $i -lt $dane.Count;$i++)
{
    if($dane.LastWriteTime[$i] -gt $date)
    {
    $dane[$i]
    }
}
#$nh | Get-FileHash

$job = Start-Job -ScriptBlock{
 $args[0] |Get-FileHash

} -ArgumentList $nh
#>
$job.State

$wait = Wait-Job $job
$job.State
$nh  = Receive-Job $job 
#$cokolwiek
$aa
"STARA BAZA " 
$a.BAZA_HASH
" DO ZAKTUALIZOWANIA  "
$nh
" ZAKTUALIZOWANA BAZA  "
#-------------------------------------------------------------------- ZAKTUALIZOWANA BAZA DANYCH
if($nh.count -eq 1)
{
    $wyklucz = 1
}else
{
    $wyklucz = 1..$nh.count
}
$zaaktualizowana_baza=@( 
for($i = 0; $i -lt $a.BAZA_HASH.Count;$i++)
{
        for($j = 0; $j -lt $nh.Count;$j++)
        {
            if($a.BAZA_HASH.path[$i] -eq $nh.path[$j] -or $a.BAZA_HASH.path[$i] -eq $nh.path )
            {
                $a.BAZA_HASH[$i] =$nh[$j]

                if($nh.count -eq 1)
                {
                    $wyklucz = 0
                }else
                {
                    $wyklucz[$j] = 0
                }
            }
        }
    @{
        Hash =$a.BAZA_HASH.hash[$i]
        Path =$a.BAZA_HASH.path[$i]
    }
}
for($i = 0; $i -lt $nh.Count;$i++)
{
    if($wyklucz[$i])
    {
        if($nh.count -eq 1)
        {
            @{
                Hash =$nh.hash
                Path =$nh.path
                
            }              
        }else
        {
            @{
                Hash =$nh.hash[$i]
                Path =$nh.path[$i]
                }
        }
    }
}) | % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
$zaaktualizowana_baza
$h = $zaaktualizowana_baza.hash
$path = $zaaktualizowana_baza.path

$dla_powtorek = $zaaktualizowana_baza

   $mega = @{
    POMOCNICZE_PARAMETRY = $suma 
    BAZA_HASH = $zaaktualizowana_baza 

}
$mega | ConvertTo-JSON > baza_danych.json


}else
{
$job = Start-Job -ScriptBlock{Get-ChildItem -path $args[0] -Recurse -Force -File | Get-FileHash} -ArgumentList $parametr
$job.State

$wait = Wait-Job $job
$job.State
$z  = Receive-Job $job 

"======================="
#$z
    
    $h = $z.hash
    $path = $z.path

    $result =  @(for($i = 0; $i -lt $z.count; $i++)
            {

            @{
            Hash =$h[$i]
            Path = $path[$i]}
            })| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
                
   $dla_powtorek = $result
   $result

   $date = Get-Date 
   $suma = @{
   DATA = $date
   SCIEZKA = $parametr
   }

   $mega = @{
    POMOCNICZE_PARAMETRY = $suma 
    BAZA_HASH = $result 

}
$mega | ConvertTo-JSON > baza_danych.json
}

#-------------------------------------------------------------------- POWTÓRKI
$zmienna = $dla_powtorek.hash | Sort-Object 
$zmienna = $zmienna | Get-Unique


$index = 1;
"Powtorki">powtorzone.txt
for($i = 0; $i -lt $zmienna.Count;$i++){
    $finalowe_powtorki = for($j = 0 ; $j -lt $h.Count;$j++)
    {
        if($zmienna[$i] -eq $h[$j]) 
        {
           $path[$j]
        }

    }
    if($finalowe_powtorki.count -gt 1)
    {
        "NR:{0} HASH: {1}" -f $index,$zmienna[$i] >> powtorzone.txt
         for($j = 0 ; $j -lt $finalowe_powtorki.Count;$j++)
         {
            "`t{0}" -f $finalowe_powtorki[$j] >>powtorzone.txt
         }
        $index++
    }
}



