//64050543 ปริยากร ประมูลศิลป์
//n is 20! = 2432902008176640000
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
int main(void) {
    pid_t pid = fork();
    if (pid==0)
    {
        printf("child created\n");
        while (1)
        {
            sleep(1);
            printf("this line should not be shown\n"); 
        }
        exit(0);
    }else
    {
        sleep(4);
        kill(pid,9);
    }  
return 0;
} 
