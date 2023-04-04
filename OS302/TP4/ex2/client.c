#include <assert.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define KEY_FILE "/tmp/key_"
// #define KEY_FILE "/home/flo/ESISAR_3AS1/OS302/TP4/ex2/cle1"
#define MSG_SIZE sizeof(msg_contenu)
#define MAX_MSG_SIZE 100

typedef struct msg_contenu {
    char msg[MAX_MSG_SIZE];
    pid_t pid;
} msg_contenu;

typedef struct msg_struct {
    long type;
    msg_contenu data;
} msg_struct;

int msg_send_id, msg_recv_id;

int main(int argc, char const *argv[]) {
    struct msg_struct message;
    int pid = getpid();
    if (argc < 2) {
        printf("Usage: string %s\n", argv[0]);
        return EXIT_FAILURE;
    }
    key_t send_key = ftok(KEY_FILE, 1);
    key_t recv_key = ftok(KEY_FILE, 0);
    if (send_key == -1 || recv_key == -1)
        perror("ftok");
    msg_recv_id = msgget(recv_key, 0);
    msg_send_id = msgget(send_key, 0);
    if (msg_send_id == -1 || msg_recv_id == -1)
        perror("msgget");

    message.type = 1;
    message.data.pid = pid;
    strcpy(message.data.msg, argv[1]);
    printf("msg_send_id : %d|%d\n", msg_send_id, msg_recv_id);
    if (msgsnd(msg_send_id, &message, MSG_SIZE, 0) == -1) {
        perror("msgsnd");
    } else {
        printf("Message client envoyé : %s\n", message.data.msg);
    }
    if (msgrcv(msg_recv_id, &message, MSG_SIZE, (long)pid, 0) == -1) {
        perror("msgrcv");
    }
    printf("Message client reçu : %s\n", message.data.msg);
}