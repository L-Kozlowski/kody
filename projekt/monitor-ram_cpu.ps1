   
   # WAŻNE PROGRAM JEST USATWIONY NA INFORMOWANIE O WYSOKIM ZUŻYCIU DOIERO PRZY 90%, BY PRZETESTOWAĆ DZIAŁANIE PROGRAMU MOŻNA W IFACH ZMNIEJSZYĆ TEN PARAMETR
   
   "Zapis zużycia ramu oraz cpu procesora podczas działania sktyptu`n**************************************************************`n" > record_ram_cpu.txt
    while(1)
    {
        cls
        #------------------------------------------------------------------------------------ POBRANIE I WYPISANIE DANYCH O ZUŻYCIU RAMU I CPU
        $ram = Get-CimInstance -Class win32_operatingsystem -ErrorAction Stop
        $cpu = (Get-CimInstance -Class win32_processor -ErrorAction Stop | Measure-Object -Property LoadPercentage -Average | Select-Object Average).Average
        $ram_totalsize = $ram.TotalVisibleMemorySize/ 1000000
        $ram_free = $ram.FreePhysicalMemory/ 1000000
        $ram_usage = $ram_totalsize - $ram_free 
        $ram_usage_percent = (($ram_usage*100)/ $ram_totalsize) 

        "========================================="
        "`nCałkowita dostępna pamięć RAM `t{0}GB" -f         [math]::round($ram_totalsize,2)
        "Wolna pamieć RAM `t`t`t`t{0}GB" -f [math]::round($ram_free,2) 
        "Używana pamieć RAM `t`t`t`t{0}GB" -f [math]::round($ram_usage,2) 
        "Procentowe zużycie pamieć RAM `t{0}%" -f [math]::round($ram_usage_percent,2)
        "Procesor CPU:`t`t`t`t`t{0}% `n" -f $cpu
        
        #---------------------------------------------------------------------------------- ZAPISYWANIE PRZEBIEGU ZUŻYCIA RAMU I CPU DO PLIKU
        $date = Get-Date
        "{0} Zużycie ramu: {1}%`n`t`t    Zużycie CPU:  {2}%  " -f $date,[math]::round($ram_usage_percent,2),$cpu >> record_ram_cpu.txt


        #---------------------------------------------------------------------------------- SPRAWDZANIE CZY NIE ZU ZAPISYWANIE PRZEBIEGU ZUŻYCIA RAMU I CPU DO PLIKU
        if($ram_usage_percent -gt 90)
        {
            $round = [math]::round($ram_usage_percent,2)
            Write-Warning "Wysokie zużycie ramu aż $round%`n "
            #"***********Uwaga wysokie zużycie ramu: {0}%`t {1}************************ " -f [math]::round($ram_usage_percent,2),$date >> record.txt
            Write-Warning "`nWysokie zużycie ramu aż $round%`t $date`n " 3>&1 >> record_ram_cpu.txt
        }
        if($cpu -gt 90)
        {
            $round = [math]::round($cpu,2)
            Write-Warning "Wysokie zużycie CPU aż $round%`n "
            #"###########Uwaga wysokie zużycie CPU: {0}%`t {1}######################### " -f [math]::round($cpu,2),$date >> record.txt
            Write-Warning "`nWysokie zużycie CPU aż $round%`t $date`n " 3>&1 >> record_ram_cpu.txt
        }

        Start-Sleep 5

    }
