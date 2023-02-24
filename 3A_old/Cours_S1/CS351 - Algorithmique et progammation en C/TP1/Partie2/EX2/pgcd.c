#include <stdio.h>

#define min(X, Y) (((X) < (Y)) ? (X) : (Y))
#define max(X, Y) (((X) >= (Y)) ? (X) : (Y))

int pgcd ( int a, int b ) {

	int tmp = max(a,b); //permet de trier
	b = min(a,b);//       de sorte à ce que
	a = tmp;//            a >= b
    
	int pgcd=a;
	
    while(b!=0){
		tmp = a % b;
		a=b;
		b=tmp;
		pgcd=a;
    }

    return pgcd;
}

int main() {
    
    int nombre1;
	printf("Entrez le 1er nombre:");
	scanf("%d",&nombre1);
    int nombre2;
	printf("Entrez le 2nd nombre:");
	scanf("%d",&nombre2);

    printf ("Pgcd(%d, %d) = %d\n",nombre1,nombre2, pgcd(nombre1,nombre2) ); // On peut tester avec (a=6, b=4, p=2)

    return (0);
}