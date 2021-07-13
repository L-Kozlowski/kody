
#------------------------------------------------------------------------------------POBIERANIE BAZY I PRZYGOTOWANIE ZMIENNYCH
$request = Invoke-WebRequest 'https://api.covid19api.com/summary' | ConvertFrom-Json
$data = $request.Countries
$country = $data.Country
$total_confirmed= $data.TotalConfirmed
$total_recovered= $data.TotalRecovered
$total_deaths= $data.TotalDeaths
$date= $data.Date

#------------------------------------------------------------------------------------KONWERSJA DATY
$StartDate= (Get-date)
$final_date = for($i = 0; $i -lt $country.count; $i++)
    {
        $EndDate=[datetime]$date[$i]

        $new_date = NEW-TIMESPAN –Start $StartDate –End $EndDate

        if($new_date.Days -eq 0 -and $new_date.Hours -ne 0)
        {
        "{0}h {1}m" -f $new_date.Hours, $new_date.Minutes 
        }
        elseif($new_date.Days -eq 0 -and $new_date.Hours -eq 0)
        {
         "{0}m" -f $new_date.Minutes
        }
        else
        {
        "{0} dni {1}h {2}m" -f $new_date.Days, $new_date.Hours, $new_date.Minutes 
        }

    }
#------------------------------------------------------------------------------------OSTATECZNA TABELA I PRZESŁANIE JEJ DO PLIKU
$result =  @(for($i = 0; $i -lt $country.count; $i++)
     {
    @{
     Kraj = $country[$i]
     Zakażeni =$total_confirmed[$i]
     Ozdrowieńcy = $total_recovered[$i]
     Zgony = $total_deaths[$i]
     Czas =  $final_date[$i]}
    })| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
$result |Format-Table  > covid.txt
$result | Format-Table