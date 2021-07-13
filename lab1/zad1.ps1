param(
    [string]$inputPath1,
    [string]$inputPath2,
    [Parameter(Mandatory=$false)]
        [Switch]$size,
    [Parameter(Mandatory=$false)]
        [Switch]$moddate
)

function CompareFilesByProperty {
    param (
        [string]$path1,
        [string]$path2,
        [string]$property
    )
    # ścieżki do katalogów
    # $path1 = 'C:\path1'
    # $path2 = 'C:\path2'
    # zawartość katalogów
    $files1 = Get-ChildItem -Path $path1 -Recurse -File
    $files2 = Get-ChildItem -Path $path2 -Recurse -File

    # porównanie jednego z drugim i odwrotnie aby uzyskać obydwie ścieżki do plików
    $res1 = Compare-Object -ReferenceObject $files1 -DifferenceObject $files2 -Property $property -IncludeEqual -PassThru
    $res2 = Compare-Object -ReferenceObject $files2 -DifferenceObject $files1  -Property $property -IncludeEqual -PassThru
    # wybranie tylko tych plików których nazwa jest taka sama i zapisanie ich w jednej zmiennej
    # rzutowanie do obiektu poniższej klasy jest konieczne abu uniknąc niespodzieanych błędów
    $equal = $res1 | Where-Object {$_.SideIndicator -eq '=='}
    [System.IO.FileSystemInfo[]]$equal += $res2 | Where-Object {$_.SideIndicator -eq '=='}
    
    # wydzielenie samych ścieżek do plików - w rezultacie powstają dwie tablice, każda odpowadająca jednemu folderowi 
    $equal1 = $equal | Where-Object {$_.Directory.FullName -like "$($path1)*"} | Select-Object -Property FullName
    $equal2 = $equal | Where-Object {$_.Directory.FullName -like "$($path2)*"} | Select-Object -Property FullName

    # zapisanie wyników z dwóch tablic ze śceżkami do plików jako jedna tabelka
    $res = 0..($equal1.Length-1) | Select-Object @{n='Path1'; e={$equal1[$_].FullName}}, @{n='Path2'; e={$equal2[$_].FullName}}
    return $res
}

# zachowanie standardowe - jako argumenty $path1 oraz $path2
if ($moddate -eq $false -AND $size -eq $false) {
    Write-Host "Porównywanie plików w katalogach na podstawie nazwy: "
    CompareFilesByProperty -path1 $inputPath1 -path2 $inputPath2 -property "Name"
}

# zachowanie w przypadku porównywania rozmiaru -size
if ($size -eq $true -AND $moddate -eq $false) {
    Write-Host "Porównywanie plików w katalogach na podstawie rozmiaru: "
    CompareFilesByProperty -path1 $inputPath1 -path2 $inputPath2 -property "Length"
}

# zachowanie w przypadku porównywania po rozmiarach i dacie modyfikacji -size -moddate
if ($moddate -eq $true -AND $size -eq $true) {
    Write-Host "Porównywanie plików w katalogach na podstawie rozmiaru i daty modyfikacji: "
    $res1 = CompareFilesByProperty -path1 $inputPath1 -path2 $inputPath2 -property "Length"
    $res2 = CompareFilesByProperty -path1 $inputPath1 -path2 $inputPath2 -property "LastWriteTime"

 
    CompareFilesByProperty -path1 $inputPath1 -path2 $inputPath2 -property "Length, LastWriteTime"


}



