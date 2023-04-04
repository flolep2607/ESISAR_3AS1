#include <stdio.h>
#include <stdlib.h>
#include "listeTableau.h"

// #define TAILLEMAX 1000

int main()
{
    /* déclaration du tableau contenant la liste */
    element maListe[TAILLEMAX];

    creerListeVide(maListe);

    /* ... */
	for(int i=1; i<15; i++) insererElement(i, maListe);
	
	
	afficherListe(maListe);

	
	printf("Premier element libre: %d\n",elementLibre(maListe));

	for(int i=1; i<6; i++) supprimerElement(2*i, maListe);
	
	afficherListe(maListe);
	printf("Premier element libre: %d\n",elementLibre(maListe));
	printf("insert 20\n");
	insererElement(20, maListe);
	printf("Premier element libre: %d\n",elementLibre(maListe));
	
	compacterListe(maListe);

    afficherListe(maListe);
	printf("Premier element libre: %d\n",elementLibre(maListe));
    return 0;
}
