
#include <stdlib.h>

typedef struct element element ;
struct element {
	int valeur ; /* valeur de l’élément */
	element* suivant ; /* adresse du successeur */
};
typedef element* liste ;


void creerListeVide(liste *l);
void insererElement(int x, liste *l);
void supprimerElement(int i, liste *l);
void supprimerListe(liste *l);
void afficherListe(liste *l);
