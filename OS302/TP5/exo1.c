/*********************************************************************
 * OS302 - shm - Exercice 1                                          *
 * Utilisation des segments de memoire partagee                      *
 *********************************************************************/
#include "segment_memoire.h"

int main() {  
  int shmid ;
  char *nom = (char *) malloc(100*sizeof(char)) ;
  nom = "exo1.c" ;
  shmid = cree_segment(100,nom,1) ;
  afficher_info_segment(shmid) ;
  detruire_segment(shmid) ;
  return 0 ;
}
