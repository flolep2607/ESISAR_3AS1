#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

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
            int compteur = 0;
            if(S == 0)
            {
                while (1)
                {
                    alarm(1);
                    if (signal(SIGALRM, second))
                    {
                        printf("%d secondes\n", compteur);
                        compteur++;
                        if (compteur == 60)
                        {
                            kill(getppid(), SIGALRM);
                            compteur = 0;
                        }
                        pause();
                    }
                }
            }
            else
            {   
                while (1)
                {
                    if (signal(SIGALRM, second))
                    {
                        printf("%d minutes\n", compteur);
                        compteur++;
                        if (compteur == 60)
                        {
                            kill(getppid(), SIGALRM);
                            compteur = 0;
                        }
                        pause();
                    }
                }
            }
        }
        else
        {
            int compteur2 = 0;
            while (1)
                {
                    if (signal(SIGALRM, second))
                    {
                        printf("%d heures\n", compteur2);
                        compteur2++;
                        if (compteur2 == 24)
                        {
                            compteur2 = 0;
                        }
                        pause();
                    }
                }
        }
    }
    else
    {
        wait(NULL);
        printf("P\n");
    }
}
