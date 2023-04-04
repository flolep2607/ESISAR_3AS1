/*******************************************************************************
 * OS302 - shm - Exercice 2                                                    *
 * Utilisation des segments de memoire partagee                                *
 ******************************************************************************/

#include "segment_memoire.h"

#include <stdio.h>
#include <unistd.h>

#define NOM "exo2.c"
#define SLEEP_TIME 2

int main(void)
{
	pid_t pid;
	char *mem;
	int shmid;

	/* a completer : creation du segment de memoire partagee */
	/* ... */

	switch(pid = fork()) {
	case -1:
		perror("fork");
		return -1;
	case 0:
		sleep(SLEEP_TIME);
		/* a completer : s'attacher au segment et affichage de son contenu */
		/* ... */
		break;
	default:
		/* a completer : attachement et ecriture sur le segment de memoire
		 *				 partagee
		 */
		/* ... */
		/* a completer : attendre la fin du fils + detacher le segment et le
		 *				 detruire
		 */
		/* ... */
	}

	return 0;
}
