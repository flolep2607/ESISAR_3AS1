#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
void o(){}
int main(int argc, char *argv[])
{
    if (argc != 3) {
		printf("Utilisation : %s executable !\n", argv[0]);
		return EXIT_FAILURE;
	}
    int pipefd[2];
    pipe(pipefd);
    pid_t ret = fork();
    if (ret == 0)
    {
        close(pipefd[0]);
        dup2(pipefd[1],STDOUT_FILENO);
        system(argv[1]);
        close(pipefd[1]);
    }
    else
    {   
        waitpid(ret, NULL, 0);
        close(pipefd[1]);
        dup2(pipefd[0],STDIN_FILENO);
        printf("%s\n", argv[2]);
        system(argv[2]);
        //TODO: faire marcher cette merde
    }
}