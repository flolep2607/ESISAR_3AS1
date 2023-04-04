#include <stdlib.h>
#include "libmath.h"

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) >= (Y)) ? (X) : (Y))

int quotient(int a, int b){
	
	if(b==0)return-1;
	
	int i;
	i=0;
	while (a>=b){
		a-=b;
		i++;
	}
	
	return (i);
}

int reste( int a, int b){
	
	return (a>=b ? a : b) - ( quotient(a,b) * (a<b ? a : b));
}

int valeurAbsolue(int a){
	return abs(a);
}

int pgcd ( int a, int b ) {

	int tmp = max(a,b);
	b = min(a,b);
	a = tmp;
    
	int pgcd=a;
	
    while(b!=0){
		tmp = a % b;
		a=b;
		b=tmp;
		pgcd=a;
    }

    return pgcd;
}

int ppcm(int a, int b){
	return quotient( valeurAbsolue(a*b), pgcd(a,b));
}


int puissanceMB (int x, int n){
	
	int N,Y,Z;
	#ifdef COMPTER
		int i=0;
	#endif
	N=n; Y=1; Z=x;
	
	while (N){
	#ifdef COMPTER
		i++;
	#endif
	n=N;
	N/=2;
	
	if (n%2 != 0)
		Y *= Z;
	
	Z*=Z;	
	}
	
	#ifdef COMPTER
		printf("nombre d'opérations: %d\n",i);
	#endif
	
	return Y;
}

int sommeDesImpairs(int d, int f)
{
	int sum=d;	
	int i = (f-d)/2;// (f-d)/2 = nombre d'impairs
					// entre d et f+2   
	for(;i>0;i--)   // on additionne donc tous ces impairs
		sum+= d + i*2;// dans l'ordre décroissant
	
	return sum;
}

int estUneDecompositionDe(int d, int f){

	int cible=sommeDesImpairs(d, f);
	int i=1;
	while( puissanceMB(i,3) < cible ) i++;

	if ( puissanceMB(i,3) != cible ) i=-1;

	return i;
}

void testBibliotheque(){
	printf("8/2 = %d\n-1/2 = %d\n1/0 = %d\n",quotient(8,2),quotient(-1,2),quotient(1,0));
	printf("-------\n");
	printf("8%%2 = %d\n1%%2 = %d\n4%%3 = %d\n",reste(8,2),reste(1,2),reste(4,3));
	printf("-------\n");
	printf("|-8| = %d\n|0| = %d\n|1| = %d\n",valeurAbsolue(-8),valeurAbsolue(0),valeurAbsolue(1));
	printf("-------\n");
	printf("ppcm(15,10) = %d\nppcm(4,5) = %d\n",ppcm(15,10),ppcm(4,5));
	printf("-------\n");
	printf("2^4 = %d\n0^6 = %d\n4^-2 = %d\n",puissanceMB(2,4),puissanceMB(0,6),puissanceMB(4,8));
	printf("-------\n");
	printf("3->5 = %d\n7->11 = %d\n",sommeDesImpairs(3,5),sommeDesImpairs(7,11));
	printf("-------\n");
	printf("3->5 = %d^3\n7->11 = %d^3\n",estUneDecompositionDe(3,5),estUneDecompositionDe(7,11));
	printf("7->13 = %d\n", estUneDecompositionDe(7, 13));
	printf("-------\n");
}

