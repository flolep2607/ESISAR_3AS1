#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int recu=0;
void sigint_handler(int sig)
{
    recu++;
    printf("signal:%d\n",sig);
    if(recu>=5){
        exit(0);
    }
}
int main(void)
{
    signal(SIGINT, sigint_handler);
    while (1);
    
    printf("fin du pere\n");
    return 0;
}