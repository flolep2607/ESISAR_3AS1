#include "calcul.h"

// #include <stdlib.h>
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
}



int main(int argc, char const *argv[])
{
	struct msg_struct msg;
	int i_sig;
	int result;

	/* liberer la zone de messages sur reception de n'importe quel signal */

	for (i_sig = 0; i_sig < NSIG; i_sig++)
	{
		raz_msg(i_sig);
	}

	key_t ma_cle = ftok("/media/lysio4/0FEA11880FEA1188/Cours \3A/TPs/OS302/TP4/calcul.h", 0);
	msg_id = msgget(ma_cle, IPC_CREAT | 0x660);
	printf("SERVEUR: pret!\n");
	while (1)
	{
		/* reception */
		msgrcv(msg_id, &msg, sizeof(struct msg_struct) - sizeof(long), 1, 0);
		printf("SERVEUR: reception d'une requete de la part de: %d\n",
			   msg.pid);
		/* preparation de la reponse */
		/* A COMPLETER */
		/* envoi de la reponse */
		switch (msg.operateur)
		{
		case '+':
			result = msg.operande1 + msg.operande2;
			break;
		case '-':
			result = msg.operande1 - msg.operande2;
			break;
		case '*':
			result = msg.operande1 * msg.operande2;
			break;
		case '/':
			result = msg.operande1 / msg.operande2;
			break;
		default:
			break;
		}
		msg.resultat = result;
		printf("%d", msg.resultat);
		msgsnd(msg_id, &msg, sizeof(struct msg_struct) - sizeof(long), 0);
	}
	return EXIT_SUCCESS;
}
