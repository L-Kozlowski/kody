#------------------------------------------------------------------ SPRAWDZANIE CZY ISTNIEJE BAZA I CZY PROGRAM WYWOAŁYWANY JEST DLA TEGO SAMEGO FOLDERU 
$parameter = $ARGS[0]
if(Test-Path database.json)
{
    $folder_path  = Get-Content -path database.json  |ConvertFrom-Json
    $folder_path = $folder_path.SAVED_PARAMETERS.FOLDER_PATH
    if($parameter -eq $folder_path)
    {
        $test = 1
    }else
    {
        $test = 0
    }
}else
{
    $test = 0
}
#------------------------------------------------------------------ BAZY DANYCH

if(($test)){
    $old_database = Get-Content -path database.json |ConvertFrom-Json
    $hash = $old_database.DATABASE_HASH.hash
    $path = $old_database.DATABASE_HASH.path
    $files =  Get-ChildItem -path $parameter -Recurse -Force -File 

    #-------------------------------------------------------------------- DATY

    $date = Get-Content database.json  |ConvertFrom-Json
    $date = $date.SAVED_PARAMETERS.DATE
    $date_new = Get-Date 
    $sum = @{
    DATE = $date_new
    FOLDER_PATH = $parameter
    } 

    #-------------------------------------------------------------------- NOWE PLIKI PO DACIE

    $job = Start-Job -ScriptBlock{

    @( for($i = 0; $i -lt $args[0].Count;$i++)
    {
        if($args[0].LastWriteTime[$i] -gt $args[1])
        {
        $files = $args[0]
        $new_object = $files[$i] |Get-FileHash
            @{
                Hash =$new_object.hash
                Path =$new_object.path
            }
        }
    })| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
    } -ArgumentList $files,$date

    $job.State
    $wait = Wait-Job $job
    $job.State
    $new_hash  = Receive-Job $job 
    "======================================================================================================================================"
    "`nOLD DATABASE`n" 
    $old_database.DATABASE_HASH
    "======================================================================================================================================"
    "`nNEW FILES`n"
    $new_hash 

    #-------------------------------------------------------------------- ZAKTUALIZOWANIE BAZY DANYCH O NOWE HASHE
    if($new_hash.count -eq 1)
    {
        $exclude = 1
    }else
    {
        $exclude = 1..$new_hash.count #tabela z samymi wartościami prawdy
    }
    $new_database=@( 
    for($i = 0; $i -lt $old_database.DATABASE_HASH.Count;$i++)
    {
            for($j = 0; $j -lt $new_hash.Count;$j++)
            {
                if($old_database.DATABASE_HASH.path[$i] -eq $new_hash.path[$j] -or $old_database.DATABASE_HASH.path[$i] -eq $new_hash.path )
                {
                    $old_database.DATABASE_HASH[$i] =$new_hash[$j]

                    if($new_hash.count -eq 1)
                    {
                        $exclude = 0
                    }else
                    {
                        $exclude[$j] = 0
                    }
                }
            }
        @{
            Hash =$old_database.DATABASE_HASH.hash[$i]
            Path =$old_database.DATABASE_HASH.path[$i]
        }
    }
    for($i = 0; $i -lt $new_hash.Count;$i++)
    {
        if($exclude[$i])
        {
            if($new_hash.count -eq 1)
            {
                @{
                    Hash =$new_hash.hash
                    Path =$new_hash.path
                }              
            }else
            {
                @{
                    Hash =$new_hash.hash[$i]
                    Path =$new_hash.path[$i]
                    }
            }
        }
    }) | % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }

    "======================================================================================================================================"
    "`nNEW DATABASE`n"
    $new_database

    $hash = $new_database.hash
    $path = $new_database.path

    $duplicates = $new_database

    $final_database = @{
        SAVED_PARAMETERS = $sum 
        DATABASE_HASH = $new_database 

    }
    $final_database | ConvertTo-JSON > database.json

}else
{
#-------------------------------------------------------------------- TWORZENIE NOWEJ BAZY DANYCH

    $job = Start-Job -ScriptBlock{Get-ChildItem -path $args[0] -Recurse -Force -File | Get-FileHash} -ArgumentList $parameter
    $job.State

    $wait = Wait-Job $job
    $job.State
    $database  = Receive-Job $job 
    
        $hash = $database.hash
        $path = $database.path

        $result =  @(for($i = 0; $i -lt $database.count; $i++)
                {

                @{
                Hash =$hash[$i]
                Path = $path[$i]}
                })| % { New-Object object | Add-Member -NotePropertyMembers $_ -PassThru }
                
       $duplicates = $result

       "======================================================================================================================================"
       "`nNEW DATABASE`n"
       $result

       $date = Get-Date 
       $sum = @{
       DATE = $date
       FOLDER_PATH = $parameter
       }

       $final_database = @{
        SAVED_PARAMETERS  = $sum 
        DATABASE_HASH = $result 

    }
    $final_database | ConvertTo-JSON > database.json
}

#-------------------------------------------------------------------- POWTÓRKI
$unique_hash = $duplicates.hash | Sort-Object 
$unique_hash = $unique_hash | Get-Unique

$index = 1;

"======================================================================================================================================"
"`nDUPLICATES:`n"
"DUPLICATES:`n">duplicates.txt

for($i = 0; $i -lt $unique_hash.Count;$i++){
    $final_duplicates = for($j = 0 ; $j -lt $hash.Count;$j++)
        {
            if($unique_hash[$i] -eq $hash[$j]) 
            {
               $path[$j]
            }
        }
    if($final_duplicates.count -gt 1)
    {
        "NR:{0} HASH: {1}" -f $index,$unique_hash[$i]
        "NR:{0} HASH: {1}" -f $index,$unique_hash[$i] >> duplicates.txt
         for($j = 0 ; $j -lt $final_duplicates.Count;$j++)
         {
            "`t{0}" -f $final_duplicates[$j]
            "`t{0}" -f $final_duplicates[$j] >>duplicates.txt
         }
        $index++
    }
}



