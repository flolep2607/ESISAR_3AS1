#include <stdio.h>

int factorielle ( int n ) {

    int fac=1;

    for (int i=2; i<=n; i++)
        fac*=i;


    return fac;
}

int factorielleBis ( int m ) {

    int n=1;
    int fac=1;

    while (fac < m){
        fac*=++n;
    }

    return n;
}

/* J'ai testé la fonction factorielle avec quelques valeurs
   dont je connaissait le résultat. De même pour factorielleBis
*/

int main() {
    
    int nombre;
	printf("Entrez un nombre:");
	scanf("%d",&nombre);

    printf ("%d! = %d\n\n",nombre, factorielle(nombre) );

	printf("Entrez un nombre:");
	scanf("%d",&nombre);

    printf ("%d < %d!\n",nombre, factorielleBis(nombre) );

    return (0);
}