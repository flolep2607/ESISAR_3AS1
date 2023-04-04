#include "calcul.h"

// #include <stdlib.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int msg_id;
    struct msg_struct *msg = malloc(sizeof(struct msg_struct));

    if (argc != 4) {
        printf("Usage: %s operande1 {+|-|*|/} operande2\n", argv[0]);
        return EXIT_FAILURE;
    }

	/* il faut eviter la division par zero */
	if (argv[2][0] == '/' && atoi(argv[3]) == 0) {
		printf("Erreur: Division par zero\n");
		return EXIT_FAILURE;
	}
	/* ATTENTION : la file de messages doit avoir ete creee par le serveur. Il
	 * faudrait tester la valeur de retour (msg_id) pour verifier que cette
	 * creation a bien eu lieu. */
	key_t ma_cle = ftok("key", 0);
	msg_id = msgget(ma_cle, 0);
	if (msg_id == -1)
	{
		perror("msg_id error");
		exit(1);
	}

    printf(
        "CLIENT %d: preparation du message contenant l'operation suivante:\
		   	%d %c %d\n",
        getpid(), atoi(argv[1]), argv[2][0], atoi(argv[3]));

	/* On prepare un message de type 1 à envoyer au serveur avec les
	 * informations necessaires */
	/* A COMPLETER */
	/* envoi du message */
	msg->type = 1;
	msg->operande1 = atoi(argv[1]);
	msg->operande2 = atoi(argv[3]);
	msg->operateur = argv[2][0];
	msg->pid = getpid();
	// printf("YOLO %d\n", msg->pid);
	int snd = msgsnd(msg_id, msg, sizeof(struct msg_struct) - sizeof(long), 0);
	if (snd == -1)
	{
		printf("Erreur d'envoi\n");
		return EXIT_FAILURE;
	}

	/* reception de la reponse */
	// int rcv = msgrcv(msg_id, msg, sizeof(struct msg_struct) - sizeof(long), getpid(), 0);
	if (msgrcv(msg_id, msg, sizeof(struct msg_struct) - sizeof(long), 1, 0) == -1)
		{
			printf("Erreur de reception\n");
			return EXIT_FAILURE;
		}
	printf("CLIENT: resultat recu depuis le serveur %d : %d\n",

		   msg->pid, msg->resultat);
	free(msg);
	return EXIT_SUCCESS;
}
