#include <stdio.h>

/*
   Nous testerons les années 1996, 2001, 1900 et 1600.
   Elles correspondent au 4 cas de figures possibles.
*/

int main() {
    
    int annee;
	printf("Entrez l'annee:");
	scanf("%d",&annee);

    int bissextile = 0;
    
    if (annee % 100 == 0) {
        if (annee % 400 == 0)
            bissextile = 1;
    } else if (annee % 4 == 0) {
            bissextile = 1;
    }

    if (bissextile) printf("L'annee %d est bissextile.\n",annee);
    else printf("L'annee %d n'est pas bissextile.\n",annee);

    return 0;

}