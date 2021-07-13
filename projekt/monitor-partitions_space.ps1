
"Zapis ostrzeżeń o przepełnionych partycjach`n**************************************************************`n" > record_memory.txt

while(1)
{
    cls
    #-------------------------------------------------------------------- POBRANIE I WYPISANIE DANYCH O PARTYCJACH
    $memory = Get-CimInstance win32_logicaldisk

    $memory_free = @(for($i = 0; $i -lt $memory.Count;$i ++)
    {
      $memory.freespace[$i]/1000000000
    })


    $memory_size = @(for($i = 0; $i -lt $memory.Count;$i++)
    {
       $memory.size[$i]/1000000000
    })

    $memory_percent = @(for($i = 0; $i -lt $memory.Count;$i++)
    {
       $memory_free[$i]/$memory_size[$i] *100
    })

    "`n------------WOLNA PAMIEĆ----------------"
    for($i = 0; $i -lt $memory.Count;$i ++)
    {
       "Na partycji {0} pozostało {1}GB" -f $memory.name[$i],[math]::round($memory_free[$i],3)
    }


 
    "`n----------CAŁKOWITA PAMIEĆ--------------"
        for($i = 0; $i -lt $memory.Count;$i ++)
    {
        "Partycja {0} posiada {1}GB" -f $memory.name[$i],[math]::round($memory_size[$i],3)
    }
    "-----------------------------------------`n"


    #-------------------------------------------------------------------- SPRAWDZENIE CZY NA PARTYCJI JEST WYSTARCZAJĄCO DUŻO WOLNEGO MIEJSCA
    @(for($i = 0; $i -lt $memory.Count;$i ++)
    {
        if($memory_percent[$i] -lt 15)
        {
           $round_percent = [math]::round($memory_percent[$i],2)
           $memory_name = $memory[$i].Name
           Write-warning "$round_percent% zbyt mało wolnego miescja na partycji $memory_name"
           $date = Get-Date
           Write-warning "$date`t$round_percent% zbyt mało wolnego miescja na partycji $memory_name" 3>&1 >> record_memory.txt
        }
    })

    Start-sleep 5
}