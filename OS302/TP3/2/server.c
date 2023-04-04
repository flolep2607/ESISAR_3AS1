#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 10
void on_sigint(int sig) {
    // On SIGINT we delete the fifo file
    int ret = unlink("/tmp/fifo");
    // and we exit the program
    exit(ret);
}
int main(int argc, char *argv[]) {
    signal(SIGINT, on_sigint);
    mkfifo("/tmp/fifo", 0666);
    char buf[MAX];
    int fd = open("/tmp/fifo", O_RDONLY);
    while (1) {
        int n = read(fd, buf, MAX);
        if (n > 0) {
            printf("%s\n", buf);
        }
    }
    close(fd);
}