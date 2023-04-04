/*********************************************************************
 * OS302 - shm - Exercice 1                                          *
 * Utilisation des segments de memoire partagee                      *
 *********************************************************************/
#include "segment_memoire.h"

/* Cree un segment de memoire
 * taille : la taille du segment memoire a creer
 * nom    : le nom du fichier associe
 * cle    : associe au nom pour la construction d'une cle identifiant
 *          le segment memoire (on utilisant la fonction ftok)
 * retourne : l'identificateur du segment, ou -1 en cas d'erreur */
int cree_segment(int taille, char *nom, int cle)
{
  int get = shmget(ftok(nom, cle), taille, IPC_CREAT | 0660);
  if (get == -1)
  {
    return -1;
  }
  return get;
}

/* Afficher toutes les informations concernant un segment de memoire
 * shmid : l'identificateur du segment
 * retourn -1 en cas d'erreur */
int afficher_info_segment(int shmid)
{
}

/* Detruie un segment de m�moire
 * shmid : l'identificateur du segment
 * retourn -1 en cas d'erreur */
int detruire_segment(int shmid)
{
}

int main()
{
  int shmid;
  char *nom = (char *)malloc(100 * sizeof(char));
  nom = "exo1.c";
  shmid = cree_segment(100, nom, 1);
  afficher_info_segment(shmid);
  detruire_segment(shmid);
  return 0;
}
