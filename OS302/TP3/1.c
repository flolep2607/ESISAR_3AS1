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
    int pipe(int pipefd[2]);
}