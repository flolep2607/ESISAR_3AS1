#include <ctype.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#include "vars.h"

int msg_id;
int msg_retour_id;

void signal_catcher(int signal) {
    msgctl(msg_id, IPC_RMID, NULL);
    msgctl(msg_retour_id, IPC_RMID, NULL);
}
void to_uppercase(char* string)
{
    const char OFFSET = 'a' - 'A';
    while (*string)
    {
        *string = toupper(*string);
        string++;
    }
}


int main() {
    struct message_struct msg;
    key_t cle_entree;
    key_t cle_retour;
    for (int i_sig = 0; i_sig < NSIG; i_sig++) {
        signal(i_sig, signal_catcher);
    }
    if ((cle_entree = ftok(FILE1, 0)) == -1 || (cle_retour = ftok(FILE2, 0)) == -1) {
        perror("[SERVER] ERROR ftok");
        exit(EXIT_FAILURE);
    }

    if ((msg_id = msgget(cle_entree, IPC_CREAT | IPC_EXCL | 0666)) == -1 || (msg_retour_id = msgget(cle_retour, IPC_CREAT | IPC_EXCL | 0666)) == -1) {
        perror("[SERVER] ERROR msgget");
        exit(EXIT_FAILURE);
    }

    while (1) {
        /* Reception de la demande du client */

        if (msgrcv(msg_id, &msg, MSG_SIZE, 1, 0) == -1) {
            msgctl(msg_id, IPC_RMID, NULL);
            msgctl(msg_retour_id, IPC_RMID, NULL);
            perror("[SERVER] ERROR msgrcv");
            exit(EXIT_FAILURE);
        }
        if (!strcmp(msg.mtext, "@")) {
            printf("[SERVER] closing\n");
            /*suppression des deux files de messages*/
            msgctl(msg_id, IPC_RMID, NULL);
            msgctl(msg_retour_id, IPC_RMID, NULL);

            return EXIT_SUCCESS;
        }
        printf("[SERVER] PID serveur: %d\n", getpid());
        printf("[SERVER] PID client: %d\n", msg.pid);

        msg.mtype = msg.pid;
        msg.pid = getpid();

        to_uppercase(msg.mtext); 
        printf("[SERVER] result: %s\n", msg.mtext);

        if (msgsnd(msg_retour_id, &msg, MSG_SIZE, 0) == -1) {
            perror("[SERVER] ERROR msgsnd");
            exit(EXIT_FAILURE);
        }
        printf("[SERVER] Sent\n");
    }

    return EXIT_SUCCESS;
}
