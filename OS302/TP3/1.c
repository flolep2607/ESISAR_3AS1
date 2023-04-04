#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <assert.h>

int main (int argc, char *argv[]) {
	
	pid_t pid;
	int fd[2];	
	pipe(fd);
	
	assert(argc==3);
	if ((pid=fork())>0) { // pere
		waitpid(pid,NULL,0);
		
		close(fd[1]);
		dup2 (fd[0], STDIN_FILENO);
		system(argv[2]);
        close(fd[0]);
	}
	else if (pid == 0)// fils 
	{
		close(fd[0]);
		dup2 (fd[1], STDOUT_FILENO);
		system(argv[1]);
        close(fd[1]);
	}
	else {
		perror("Creation de processus");
		exit(2);
	}


	exit(0);
}
