#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    mkfifo("/tmp/fifo", 0666);
    int fd=open("/tmp/fifo", O_WRONLY);
    for(int i=1; i<argc; i++){
        write(fd, argv[i], strlen(argv[i])+1);
    }
}