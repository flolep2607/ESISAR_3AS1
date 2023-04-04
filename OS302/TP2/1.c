#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void action(int signum) {}

int main()
{
    signal(SIGUSR1, action);
    pid_t ret = fork();
    if (ret == 0)
    { // Le fils va s'occuper d'afficher les nombres pairs
        for (int i = 2; i < 101; i+=2)
        {
            printf("%d\n", i);
            kill(getppid(), SIGUSR1);
            pause();
        }
    }
    else
    { // Le père va s'occuper quant à lui d'afficher les nombres impairs
        for (int j = 1; j < 101; j+=2)
        {
            printf("%d\n", j);
            kill(ret, SIGUSR1);
            pause();
        }
    }
}
