#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

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
        system(argv[2]);
    }
    else
    {
        dup2(pipefd[0], STDIN_FILENO);
        system(argv[1]);
    }
    /*char buffer[500];
    read(fd[0], buffer, 500);*/
}