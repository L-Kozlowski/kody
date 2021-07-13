
#pobranie informacji
$Adapters = Get-NetAdapter

$Tab1 = @()

foreach($Adapter in $Adapters) {
    $AdapterStats = Get-NetAdapterStatistics
    $Temp = "" | Select-Object Interface, AdresMAC, Wyslane, Pobrane
    $Temp.Interface = $Adapter.InterfaceDescription
    $Temp.AdresMAC = $Adapter.MacAddress
    $Temp.Wyslane = $AdapterStats.SentBytes
    $Temp.Pobrane = $AdapterStats.ReceivedBytes
    $Tab1 += $Temp
    }

Write-Output $Tab1 | Format-Table

#pobranie informacji
$TCP = Get-NetTCPConnection | Where-Object {$_.State -eq "Established" } | 
Sort-Object { $_.RemoteAddress} -Unique

$TCP | Select-Object `
@{n="Cel";e={$_.RemoteAddress}},
@{n="Port";e={$_.RemotePort}} |
Format-Table

