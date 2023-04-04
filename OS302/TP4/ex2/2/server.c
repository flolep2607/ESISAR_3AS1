#include "calcul.h"

#define NOM_FICHIER "/tmp/key_"
#define FLAG IPC_CREAT | IPC_EXCL
#define MSG_FLAG 0

int msg_id, msg_id2;

void raz_msg(int signal) {
    printf("\nSuppression de la file de message!\n");
    msgctl(msg_id, IPC_RMID, NULL);
    msgctl(msg_id2, IPC_RMID, NULL);
    exit(0);
}

int main(int argc, char const *argv[]) {
    struct msg_struct msg;
    int i_sig;
    int result;
    key_t cle;
    msg_struct message;
    // Creation du fichier

    /* liberer la zone de messages sur reception de n'importe quel signal */
    for (i_sig = 0; i_sig < NSIG; i_sig++) {
        signal(i_sig, raz_msg);
    }

    // création de la première file de message
    if ((cle = ftok(NOM_FICHIER, 10)) == -1) {
        printf("erreur ftok\n");
        return EXIT_FAILURE;
    }
    msg_id = msgget(cle, IPC_CREAT | 0666);
    msg_id2 = msgget(cle, IPC_CREAT | 0666);

    if (msg_id == -1 || msg_id2 == -1) {
        printf("erreur msg_id\n");
        return EXIT_FAILURE;
    }
    printf("SERVEUR: pret!\n");

    while (1) {
        // message = malloc(sizeof(msg_struct));

        if (msgrcv(msg_id, &message, sizeof(msg_data), (long)1, 0) == -1) {
            printf("erreur msgrcv\n");
            return EXIT_FAILURE;
        }

        printf("SERVEUR: reception d'une requete de la part de: %d\n", message.data.pid);
        if (((message.data).message)[0] == '@') {
            printf("Extinction du serveur\n");
            raz_msg(SIGINT);
            return EXIT_SUCCESS;
        }
        for (size_t i = 0; message.data.message[i]!=0; i++) {
			message.data.message[i]=toupper((message.data.message)[i]);
        }
        printf("Envoi du message suivant : %s\n", message.data.message);
        message.type = message.data.pid;
        msgsnd(msg_id2, &message, sizeof(msg_data), MSG_FLAG);
    }
    return EXIT_SUCCESS;
}
