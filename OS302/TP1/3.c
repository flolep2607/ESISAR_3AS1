#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void function_fils(int i)
{
    printf("pid:%d\nno",2*getpid());
    exit(0);
}
void function_pere()
{
    printf("je suis le pere\n");
    printf("pid pere: %d\n", getpid());
}

int main(void)
{
    for(int i=0;i<10;i++){
        if(fork()==0){
            function_fils(i);
        }
    }
    wait(NULL);
    printf("fin du pere\n");
    return 0;
}