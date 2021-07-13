

if(Test-Path "E:\semestr4\systemy_operacyjne\lab2")
{
&{
  Write-Warning "Folder istnieje Warning"
  Write-Debug "Folder istnieje Debug" -Debug
} 3>&1 5>&1 > zad1.txt
}
else
{
    New-Item -Path "E:\semestr4\systemy_operacyjne\lab2\zad1" -ItemType Directory
}