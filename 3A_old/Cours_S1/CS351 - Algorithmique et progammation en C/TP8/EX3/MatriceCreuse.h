#include <stdlib.h>

typedef struct element element ;
struct element {
	int valeur ; /* valeur de l’élément */
	int index_ligne;
	int index_colone;
	element* suivant_vertical;
	element* suivant_horizontal ; /* adresse du successeur */
};
typedef element* matrice ;


void creerMatriceVide(int nb_lignes, int nb_colones, matrice *M);
void insererElement(int x,int ligne, int colone, matrice M);
void afficherMatrice(matrice M);

void sommeMatrice(matrice M1, matrice M2);
void sommeMatriceNonDestructive(matrice M1, matrice M2, matrice *M3);
void etendreMatrice(int ligne, int colone, matrice M);

void produitMatrice(matrice M1, matrice M2, matrice *M3);
int produitVecteurs(matrice LigneM1, matrice ColoneM2);

void supprimerElement(int ligne, int colone, matrice M);
void supprimerMatrice(matrice M);
