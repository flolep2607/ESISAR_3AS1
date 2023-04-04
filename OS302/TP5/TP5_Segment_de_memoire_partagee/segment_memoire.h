/*********************************************************************
 * OS302 - shm - Exercice 1                                          *
 * Utilisation des segments de memoire partagee                      *
 *********************************************************************/
#ifndef SEGMENT_MEM_H
#define SEGMENT_MEM_H

#include <sys/types.h>

/* Cree un segment de memoire
 * nom      : le nom du fichier associe
 * taille   : la taille du segment memoire a creer
 * id       : associe au nom pour la construction d'une cle identifiant
 *            le segment memoire (on utilisant la fonction ftok)
 * retourne : l'identificateur du segment, ou -1 en cas d'erreur */
int cree_segment(char* nom, size_t taille, int id);

/* Affiche toutes les informations concernant un segment de memoire
 * shmid : l'identificateur du segment
 * retourn -1 en cas d'erreur */
int afficher_info_segment(int shmid);


/* Detruie un segment de mémoire
 * shmid : l'identificateur du segment
 * retourn -1 en cas d'erreur */
int detruire_segment(int shmid);

#endif /* SEGMENT_MEM_H */
