#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int fd[2];
    pipe(fd);
    pid_t fils;
    if ((fils=fork()) == 0)
    {
        write(fd[1], "Je  suis  le  premier  fils", 27);
        return 0;
    }
    if ((fils=fork()) == 0)
    {
        write(fd[1], "Je  suis  le  second fils", 25);
        return 0;
    }
    waitpid(fils, NULL, 0);
    char buffer[500];
    read(fd[0], buffer, 500);
    buffer[500]='\0';
    printf("%s\n", buffer);
    close(fd[0]);
    return 0;
}