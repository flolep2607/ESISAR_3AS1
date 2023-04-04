/*******************************************************************************
 * OS302 - shm - Exercice 1                                                    *
 * Utilisation des segments de memoire partagee                                *
 ******************************************************************************/
#include "segment_memoire.h"

#define NOM "exo1.c"
#define TAILLE 100
#define ID 1

int main(void)
{  
	int shmid = cree_segment(NOM, TAILLE, ID);
	afficher_info_segment(shmid);
	detruire_segment(shmid);
	return 0;
}
