#include <stdio.h>
#include <stdlib.h>
#include "Fraction.h"


int main(){
	
	Fraction fa, fb;
	printf("Entrer deux fractions :");
	scanf("%d/%d %d/%d", &fa.num, &fa.den, &fb.num, &fb.den);
	char op='+';
	printf("Entrer une opération (+,-,/,*):");
	scanf(" %c",&op);
	switch(op){
		case '+':
			addFraction(fa, fb);
			break;
		case '-':
			subFraction(fa, fb);
			break;
		case '/':
			divFraction(fa, fb);
			break;
		case '*':
			mulFraction(fa, fb);
			break;
		default:
			printf("Mauvaise opération\n");
			exit(1);
	}
	printf("\n");
	
	return 0;
}