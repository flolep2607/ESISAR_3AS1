#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void second(int signum) {

}

int main()
{
    pid_t H = fork();
    if(H == 0)
    {
        pid_t M = fork();
        if(M == 0)
        {
            pid_t S = fork();
            if(S == 0)
            {
                printf("S\n");
                signal(SIGALRM, second);
            }
            else
            {
                wait(NULL);
                printf("M\n");
            }
        }
        else
        {
            wait(NULL);
            printf("H\n");
        }
    }
    else
    {
        wait(NULL);
        printf("P\n");
    }
}
