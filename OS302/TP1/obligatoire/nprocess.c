#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void fils(int i){
	printf("Je suis le fils %d et mon pere est %d\n",getpid(),getppid());
	sleep(2*i);
	exit(i);
}
void pere(){
	int etat;
	pid_t ret_fils;
	while ((ret_fils=wait(&etat))!=-1)
	{
		printf("Le fils %d est mort avec l'etat %d\n",ret_fils,WEXITSTATUS(etat));
	}
}
/*
 * Dans main, on indique comment  utiliser les parametres passes sur la
 * ligne de commande
 */
int main(int argc, char *argv[])
{
	int nb_proc;
	int i_fils;
	pid_t pid_fils;

	if (argc != 2) {
		printf("Utilisation : %s nbre-de-processus !\n", argv[0]);
		return EXIT_FAILURE;
	}

	nb_proc = atoi(argv[1]); /* Retourne 0 si argv[1] n'est pas un nombre */

	/* Creation des processus fils */
	for (i_fils = 1 ; i_fils <= nb_proc ; i_fils++) {
		pid_fils = fork();
		switch (pid_fils) {
		case 0:
			fils(i_fils);       /* il faut ecrire la fonction fils ... */
			break;
		case -1 :
			perror("Le fork n'a pas reussi");
			return EXIT_FAILURE;
		}
	}

	/*
	*  Dans la fonction pere, on utilisera le fait que wait renvoie la valeur
	*  -1 quand il n'y a plus de processus fils a attendre.
	*/
	pere();

	return EXIT_SUCCESS;
}
