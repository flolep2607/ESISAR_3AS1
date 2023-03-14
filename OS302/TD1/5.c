#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int main(void)
{
    pid_t fils=fork();
    if(fils==0){
        printf("je suis le fils%d\n",getpid());
        while(1);
    }else{
        int result=kill(fils,SIGUSR1);
        sleep(1);
        printf("result:%d\n",result);
    }
    int status=0;
    waitpid(fils, &status, 0);    
    printf("fin du pere\n");
    printf("status:%d\n",status);
    return 0;
}