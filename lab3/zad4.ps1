#Write-Output "Argumenty:"
#for($i = 0;$i -lt $args.Count; $i++){
#    Write-Host "$i :" $ARGS[$i]
#    }


    if(Test-Connection -BufferSize 24 -Count 1 -Quiet $args[0])
    {
    #"Adres {0} jest aktywny" -f $args[0]
    $args[0]
    }
    else
    {
    #"Adres {0} jest nieaktywny" -f $args[0]
    #"."
    }

    #192.168.0.192