$action = New-ScheduledTaskAction -execute "pwsh.exe" -Argument "E:\semestr4\systemy_operacyjne\lab6\harmo.ps1"
$trigger = New-ScheduledTaskTrigger -Once -at "22:32" -RepetitionInterval (New-TimeSpan -Minutes 10)
$settings = New-ScheduledTaskSettingsSet
$inputo = New-ScheduledTask -Action $action  -Trigger $trigger -Settings $settings

Register-ScheduledTask -TaskName "Proba" MojeZadanie -InputObject $inputo
