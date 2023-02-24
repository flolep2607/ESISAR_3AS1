#include <stdio.h>
#include <stdlib.h>
#include "Polynomes.h"


int main(){
	
	Polynome p1, p2, p3;

	p1[0].coeff=6; p1[0].degre=3;
	p1[1].coeff=20; p1[1].degre=1;
	p1[2].coeff=1; p1[2].degre=-1;
	
	p2[0].coeff=1; p2[0].degre=85;
	p2[1].coeff=1; p2[1].degre=-1;


	addPolynomes(p1, p2, p3);
	printPolynome(p3);
	
	return 0;
}