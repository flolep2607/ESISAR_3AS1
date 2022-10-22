#include <stdio.h>
#include "dessin.h"
#include "graphlib/graphlib.h"

int main()
{
    int taille, largeur, hauteur;
    printf("taille largeur hauteur:");
    scanf("%d %d %d",&taille, &largeur, &hauteur);
    gr_inits_w(500,500,"MOSAIQUE");
    set_black();
    dessineMosaiqueAvecSouris(taille,largeur,hauteur);
    cliquer();
    return 0;
}