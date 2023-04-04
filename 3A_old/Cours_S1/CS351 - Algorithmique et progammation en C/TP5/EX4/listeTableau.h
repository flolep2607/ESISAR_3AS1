/*********************************************************************/
/* Realisation d'une liste chainee dans un tableau                   */
/* ioannis.parissis@grenoble-inp.fr                                  */
/* Sep 2012                                                          */
/*********************************************************************/

#ifndef __LISTETABLEAU_H__
#define __LISTETABLEAU_H__

#include <stdio.h>

#define TAILLEMAX 100

typedef struct {
	int valeur ;
	int suivant ;
} element ;

/* le type liste permet de ne pas utiliser de pointeurs */
typedef element* liste;




/* Retourne un element libre du tableau
   (suivant = -1). On suppose qu'il y en a toujours un */
int elementLibre(liste l);

/* Initialise le tableau de sorte que tous les éléments soient libres (suivant = -1)
   sauf celui d'indice 0 où suivant == 0*/
void creerListeVide(liste l);

/* Affiche les elements de la liste dans l'ordre */
void afficherListe(liste l);

/* Ajoute x dans la liste triee l */
void insererElement(int x, liste l);

/* Supprime le i-ème élément de l, i = 1,2... */
void supprimerElement(int i, liste l);

void compacterListe(liste l);


#endif
