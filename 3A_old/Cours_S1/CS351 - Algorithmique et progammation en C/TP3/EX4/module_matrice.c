#include <stdio.h>

void afficherMatrice(int *Matrix,int hauteur,int longueur){
	
	for(int j=0; j<hauteur; j++){
		printf(" [  ");
		for(int i=0; i<longueur; i++)
			printf("%2d  ", *((Matrix+j*longueur)+i) );//Matrix[j][i]
		printf("]\n");
	}
}

void additionnerMatrice(int *Matrix1,int *Matrix2,int hauteur,int longueur){
	
	int matricetmp[hauteur][longueur];
	for(int j=0; j<hauteur; j++)
		for(int i=0; i<longueur; i++)
			matricetmp[j][i] = *((Matrix1+j*longueur)+i) + *((Matrix2+j*longueur)+i);
	afficherMatrice(&matricetmp[0][0],hauteur, longueur);
	
}/*
Pour réaliser une addition sur deux matrices, il faut qu'elles aient les mêmes dimensions.
La matrice résultat sera de même taille que les opérandes.
*/

void transposee(int *Matrix,int hauteur,int longueur) {
	int matricetmp[longueur][hauteur];
	for(int j=0; j<hauteur; j++)
		for(int i=0; i<longueur; i++)
			matricetmp[i][j] = *((Matrix+j*longueur)+i);
	afficherMatrice(&matricetmp[0][0],longueur, hauteur);
}

void produitMatriciel(int *Matrix1,int hauteur1,int longueur1,int *Matrix2,int hauteur2,int longueur2){
	
	if (longueur1 != hauteur2) return;
	
	int matricetmp[hauteur1][longueur2];
	
	for(int j=0; j<hauteur1; j++)
		for(int i=0; i<longueur2; i++){
			matricetmp[j][i] = 0;
			for(int k=0; k<longueur1; k++)
				matricetmp[j][i] += (*((Matrix1+j*longueur1)+k)) * (*((Matrix2+k*longueur2)+i)) ;
	
		}
	afficherMatrice(&matricetmp[0][0],hauteur1, longueur2);
	
}