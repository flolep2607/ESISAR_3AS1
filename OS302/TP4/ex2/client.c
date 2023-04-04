#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "vars.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("1 arg\n");
        exit(EXIT_FAILURE);
    }
    struct message_struct msg;
    strcpy(msg.mtext, argv[1]);
    msg.mtype = 1;
    int msg_id;
    int msg_retour_id;
    key_t cle;
    key_t cle_retour;
    if ((cle = ftok(FILE1, 0)) == -1 || (cle_retour = ftok(FILE2, 0)) == -1) { 
        perror("[CLIENT] ERROR ftok");
        exit(EXIT_FAILURE);
    }

    if ((msg_id = msgget(cle, 0)) == -1 || (msg_retour_id = msgget(cle_retour, 0)) == -1) { 
        perror("[CLIENT] ERROR msgget retour");
        exit(EXIT_FAILURE);
    }
    msg.pid = getpid();

    /* Envoi du message */

    if (msgsnd(msg_id, &msg, MSG_SIZE, 0) == -1) {  
        perror("[CLIENT] ERROR msgsnd");
        exit(EXIT_FAILURE);
    }
    if (!strcmp(argv[1], "@")) { 
        printf("[CLIENT] close server\n");
        return EXIT_SUCCESS;
    }

    printf("[CLIENT] wait answer\n");

    if (msgrcv(msg_retour_id, &msg, MSG_SIZE, getpid(), 0) == -1) {  
        perror("[CLIENT] ERROR msgrcv retour");
        exit(EXIT_FAILURE);
    }
    printf("[CLIENT] %s\n", msg.mtext);

    return EXIT_SUCCESS;
}
