#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void function_fils(int i)
{
    printf("je suis le fils\n");
    printf("pid fils: %d\n", getpid());
    sleep(i*2);
    printf("fin du fils %d\n",i);
    exit(0);
}
void function_pere()
{
    printf("je suis le pere\n");
    printf("pid pere: %d\n", getpid());
}

int main(void)
{
    function_pere();
    pid_t fils1=fork();
    if (fils1 == 0)
    {
        function_fils(2);
    }
    else
    {
        if(fork() == 0){
            function_fils(1);
        }
    }
    waitpid(fils1, NULL, 0);
    printf("fin du pere\n");
    return 0;
}