[System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")

[System.Windows.forms.messagebox]::show(
    "Testuje",
    "Eloo",

    [System.Windows.forms.MessageBoxButtons]::OK,
    [System.Windows.forms.MessageBoxIcon]::information
)