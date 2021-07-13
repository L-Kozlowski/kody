
function CreateShortCut{
    param (
        [string]$path,
        [string]$target
    )

$WscriptShell = New-Object -ComObject WScript.Shell
$shortcut = $WscriptShell.CreateShortCut($path)
$shortcut.TargetPath = $target
$shortcut.Save()

}
CreateShortCut -path "Photoshop.lnk" -target "C:/Windows/System32/mspaint.exe"

# symbolicLink
New-Item -ItemType SymbolicLink -path "Photoshop CS-2" -target "C:/Windows/System32/mspaint.exe"
# HardLink
New-Item -ItemType HardLink -Path "tekst" -target "E:\semestr4\systemy_operacyjne\lab5\d1\a.txt"
# Junction
New-Item -ItemType Junction -Path "systemek" -Target "C:/Windows/System32/"

