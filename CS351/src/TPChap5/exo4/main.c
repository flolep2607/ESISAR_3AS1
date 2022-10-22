#include <stdio.h>
#include <stdlib.h>
#include "listeTableau.h"

int main()
{
    element maListe[TAILLEMAX];

    creerListeVide(maListe);

    insererElement(4, maListe);
    insererElement(2, maListe);
    insererElement(6, maListe);
    insererElement(42, maListe);
    insererElement(6, maListe);
    supprimerElement(4,maListe);
    supprimerElement(4,maListe);

    afficherListe(maListe);

    return 0;
}
