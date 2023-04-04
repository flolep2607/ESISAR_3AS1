#include <stdio.h>
#include "module_matrice.h"

int main() {
	
	int matrice[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } } ;
	
	int matrice2[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } } ;
	
	printf("matrice 1:\n");
	afficherMatrice(&matrice[0][0], 3, 4);
//  |-> fonctione aussi avec "matrice" mais warning: "imcompatible pointer type"

	printf("matrice 2:\n");
	afficherMatrice(&matrice2[0][0], 3, 4);

	printf("--------------------------------\n");
	printf("matrice 1 + matrice 1:\n");
	additionnerMatrice(&matrice[0][0], &matrice[0][0], 3, 4);
	
	printf("--------------------------------\n");
	printf("transposee matrice 1:\n");
	transposee(&matrice[0][0], 3, 4);
	
	printf("--------------------------------\n");
	printf("matrice 1 * matrice 2:\n");
	produitMatriciel(&matrice[0][0], 3, 4, &matrice2[0][0], 4, 4);
	
	return 0;
}