#include <stdio.h>
#include "MatriceCreuse.h"


int main() {
	
	matrice L=NULL;
	creerMatriceVide(4, 4, &L);
	
	afficherMatrice(L);
	
	/* Insere la valeur x a la ligne n colone m de la matrice M */
	/* insererElement(x, n, m, M);                              */
	insererElement(12, 0, 2, L);
	insererElement(12, 1, 0, L);
	insererElement(5, 1, 1, L);
	insererElement(-4, 2, 1, L);
	insererElement(-15, 3, 3, L);
	printf("\n A: \n");
	// etendreMatrice(6,5,L);
	afficherMatrice(L);

	matrice S=NULL;
	creerMatriceVide(2, 5, &S);
	insererElement(42, 0, 0, S);
	// insererElement(42, 0, 1, S);
	printf("\n B: \n");
	afficherMatrice(S);
	sommeMatrice(S, L);
	
	printf("\n A+B: \n");
	afficherMatrice(S);
	
	matrice P;
	produitMatrice(L, S, &P);
	
	printf("\n A * A+B: \n");
	afficherMatrice(P);
	
	
	supprimerMatrice(L);
	supprimerMatrice(S);
	supprimerMatrice(P);
	
	printf("Exit:%d\n", 0); /* ce programme affiche 0 */
	
	return 0;
}