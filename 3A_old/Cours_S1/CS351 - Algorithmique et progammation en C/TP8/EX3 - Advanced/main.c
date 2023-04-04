#include <stdio.h>
#include "MatriceCreuse.h"


int main() {
	
	matrice L=NULL;
	creerMatriceVide(4, 4, &L);
	
	afficherMatrice(L);
	
	/* Insere la valeur x a la ligne n colone m de la matrice M */
	/* insererElement(x, n, m, M);                              */
	insererElement(12, 0, 2, L);
	insererElement(-4, 2, 1, L);
	insererElement(12, 1, 0, L);
	insererElement(5, 1, 1, L);
	insererElement(-15, 3, 3, L);
	printf("\n A: \n");
	afficherMatrice(L);

	matrice S=NULL;
	creerMatriceVide(2, 5, &S);
	insererElement(42, 0, 0, S);
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
	
	int mat[2][2] = {{1,2},{3,4}};
	matriceVersMatriceCreuse(2 ,2, mat ,&L);
	
	printf("\n C: \n");
	afficherMatrice(L);
	
	printf("\n C: \n");
	insererElement(0,1,1, L);
	afficherMatriceLazy(L);
	
	matriceCreuseVersMatrice(mat,L);
	printf("mat: \n");

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("% d",mat[i][j]);
		} printf("\n");
	}
	
	
	printf("Exit:%d\n", 0); /* ce programme affiche 0 */
	
	return 0;
}