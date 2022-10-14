for file in $(find . -type f -name "*.c")
do    
    prog_name=`echo $file | cut -d'/' -f2 | cut -d'.' -f1`
    prog=$(echo $file | cut -d'/' -f2)
    gcc $prog -o $prog_name 2> /dev/null
    if [ -f $prog_name ]
    then
        ans=$(./$prog_name)
        if [ "$ans" = 20 ] 
        then
        score=10
        elif [ "$ans" != 20 ] 
        then
        score=7
        fi
    else 
        score=5
    fi
    printf "%s.c %s\n" $prog_name $score
done
