#include "calcul.h"

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msg_id;

void raz_msg(int signal)
{
	printf("Suppression de la file de message!\n");
	msgctl(msg_id, IPC_RMID, NULL);
	exit(1);
}

int main(int argc, char const *argv[])
{
	struct msg_struct *msg = malloc(sizeof(struct msg_struct));
	int i_sig;
	int result;

	/* liberer la zone de messages sur reception de n'importe quel signal */

	for (i_sig = 0; i_sig < NSIG; i_sig++)
	{
		signal(i_sig, raz_msg);
	}

	key_t ma_cle = ftok("key", 0);
	msg_id = msgget(ma_cle, IPC_CREAT | 0660);
	if (msg_id == -1)
	{
		perror("msg_id error");
		exit(1);
	}
	else
	{
		printf("SERVEUR: pret!\n");
	}

	while (1 == 1)
	{
		/* reception */
		// int rcv = msgrcv(msg_id, &msg, sizeof(struct msg_struct) - sizeof(long), 1, 0);
		// printf("%d\n", rcv);
		if (msgrcv(msg_id, msg, sizeof(struct msg_struct) - sizeof(long), 1, 0) == -1)
		{
			printf("Erreur de reception\n");
			return EXIT_FAILURE;
		}
		printf("SERVEUR: reception d'une requete de la part de: %d\n",msg->pid);
		/* preparation de la reponse */
		/* A COMPLETER */
		/* envoi de la reponse */
		switch (msg->operateur)
		{
		case '+':
			result = msg->operande1 + msg->operande2;
			break;
		case '-':
			result = msg->operande1 - msg->operande2;
			break;
		case '*':
			result = msg->operande1 * msg->operande2;
			break;
		case '/':
			result = msg->operande1 / msg->operande2;
			break;
		default:
			break;
		}
		msg->resultat = result;
		// printf("%d\n", msg->resultat);
		// printf("%d\n", msg->operande1);
		// printf("%d\n", msg->operande2);
		// printf("%d\n", msg->operateur);
		printf("SERVEUR: envoi de la réponse: %d\n", msg->resultat);
		msgsnd(msg_id, msg, sizeof(struct msg_struct) - sizeof(long), 0);
	}
	free(msg);
	return EXIT_SUCCESS;
}
