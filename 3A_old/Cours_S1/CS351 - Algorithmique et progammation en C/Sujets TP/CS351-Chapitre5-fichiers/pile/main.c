#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

int main()
{
    int i;
    pileInt maPile = creerPile();
    i = 0;
    while (i<=25){
        empiler(maPile, i);
        i++;
    }

    while (!estPileVide(maPile)){
        printf("Je depile : %d\n", depiler(maPile));
    }

    return 0;
}
