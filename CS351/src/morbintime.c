#include <stdlib.h>
#include <stdio.h>

int calculator3000(int TABLEAU[][2], int taille, int value, int poids, int poids_max){ // poids = poids courant, poids_max = poids limite demandé
    int value_max = value;
    int value_tmp = 0;
    for (int i = 0; i < taille; i++)
    {
        if (poids + TABLEAU[i][0] > poids_max)
        {
            continue;
        }
        value_tmp = calculator3000(TABLEAU, taille, value + TABLEAU[i][1], poids + TABLEAU[i][0], poids_max);
        if (value_tmp > value_max)
        {
            value_max = value_tmp;
        }
    }
    return value_max;
}

#define POIDS_MAX 10

int main(){
    int TABLEAU[][2] = {{1, 2}, {2, 3}}; //{poids,valeur}
    printf("%d\n",calculator3000(TABLEAU,sizeof(TABLEAU)/sizeof(int **),0,0,POIDS_MAX));
}