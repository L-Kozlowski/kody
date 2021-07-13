param(
    [string]$tytul,
    [string]$komunikat
)

Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System" -Name "legalnoticecaption" -Value $tytul
Set-ItemProperty -Path "HKLM:\SOFTWARE\Microsoft\Windows\CurrentVersion\Policies\System" -Name "legalnoticetext" -Value $komunikat

Write-Host "ustawiony tytul: $tytul"
Write-Host "ustawiony komunikat: $komunikat"