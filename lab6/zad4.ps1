
get-service spooler
stop-service spooler
get-service spooler

Get-ChildItem C:\Windows\System32\spool\PRINTERS -Include *.* -File -Recurse | foreach { $_.Delete()}

start-service spooler
get-service spooler