#include <stdio.h>
#include "Polynomes.h"

void addPolynomes(Polynome p1, Polynome p2, Polynome res){
	
	int i1=0;
	int i2=0;
	int i3=0;
	while( !(p1[i1].degre < 0 && p2[i2].degre < 0) ){
		if (p1[i1].degre > p2[i2].degre){
			res[i3].degre = p1[i1].degre;
			res[i3].coeff = p1[i1].coeff;
			i1++;
		} else if (p1[i1].degre < p2[i2].degre){
			res[i3].degre = p2[i2].degre;
			res[i3].coeff = p2[i2].coeff;
			i2++;
		} else {
			res[i3].degre = p1[i1].degre;
			res[i3].coeff = p1[i1].coeff + p2[i2].coeff;
			i1++; i2++;
		}
		i3++;
	}
	
	res[i3].degre = -1;
	
}

void printPolynome(Polynome p){
	int i=0;
	while(p[i].degre > 1){
		printf("%.2f*x^%d + ",p[i].coeff, p[i].degre);
		i++;
	}
	// On sépare les deux cas suivants par rapport à l'affichage
	if (p[i].degre==1) printf("%.2f*x + ",p[i++].coeff);
	if (p[i].degre==0) printf("%.2f...",p[i].coeff);
	if (i > 0) printf("\b\b\b   \n");
	//On test si i>0 car on ne veut pas effacer les charactères
	//précédents si jamais la fonction à été appelé avec un
	//polynome nul (ie p[0].degre < 0) 
}

