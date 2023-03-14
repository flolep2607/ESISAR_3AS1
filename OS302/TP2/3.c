#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

void lesig(int signum) {}

int main()
{
    pid_t fils1 = fork();
    
}