for file in $(find . -type f -name "*.c")
do    
    prog_name=`echo $file | cut -d'/' -f2 | cut -d'.' -f1`
    gcc -o $prog_name $file 2> /dev/null
    if [ -f $prog_name ]
    then
        ans=$(./$prog_name)
        if [ "$ans" = 20 ]
        then
        score=10
        elif [ "$ans" = 30 ]
        then
        score=7
        else
        score=5
        fi
    fi
    printf "%s.c    %s\n" $prog_name $score
done
