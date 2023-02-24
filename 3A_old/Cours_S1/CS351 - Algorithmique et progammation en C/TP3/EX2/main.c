#include <stdio.h>
#include "fonctions.h"

#define Taille 5

int main() {
	
	float polynome[Taille];
	polynome[0]=1;
	polynome[1]=2;
	polynome[2]=3;
	polynome[3]=4;
	polynome[4]=5;
	
	printf("1 + 2*10 + 3*100 + 4*1000 + 5*10000 = %.2f\n",valeurPolynome(polynome, Taille, 10));
	printf("1 + 2*10 + 3*100 + 4*1000 + 5*10000 = %.2f\n",valeurPolynomeRecursif(polynome, Taille, 10));
	
	return 0;
}