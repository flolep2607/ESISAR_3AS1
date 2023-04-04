#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void second(int signum) {
    
}

int main() // On a 3 fils, un pour les heures, un pour les minutes et un pour les secondes
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
            { // On est dans le fils des secondes, on va donc incrémenter le compteur toutes les secondes et envoyer un signal au fils des minutes lorsque le compteur atteint 60
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
            {   // Ici on est dans le fils des minutes, on fait de même que dans le fils des secondes mais on envoie un signal au fils des heures cette fois-ci
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
                { // Ici on est dans le fils des heures, on fait de même que dans les deux autres fils mais on envoie un signal au père lorsque le compteur atteint 24
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
