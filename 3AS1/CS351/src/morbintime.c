#include <stdlib.h>
#include <stdio.h>

int calculator2000(int TABLEAU[][2], int taille, int value, int poids, int poids_max)
{ // poids = poids courant, poids_max = poids limite demandé
    int value_max = value;
    int value_tmp = 0;
    for (int i = 0; i < taille; i++)
    {
        if (poids + TABLEAU[i][0] > poids_max)
        {
            continue;
        }
        value_tmp = calculator2000(TABLEAU, taille, value + TABLEAU[i][1], poids + TABLEAU[i][0], poids_max);
        if (value_tmp > value_max)
        {
            value_max = value_tmp;
        }
    }
    return value_max;
}
void trieABulles(int Tableau[][2], int nb)
{
    int tmp[2];
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = 0; j < nb - i - 1; j++)
        {
            if (Tableau[j][0] < Tableau[j + 1][0]) // < pour tri decroissant
            {
                tmp[0] = Tableau[j][0];
                tmp[1] = Tableau[j][1];
                Tableau[j][0] = Tableau[j + 1][0];
                Tableau[j][1] = Tableau[j + 1][1];
                Tableau[j + 1][0] = tmp[0];
                Tableau[j + 1][1] = tmp[1];
            }
        }
    }
}

int supracalculator(int TABLEAU[][2], int taille, int poids_max){
    trieABulles(TABLEAU, taille);
    int poids_tmp = 0;
    int valeur_tmp = 0;
    int valeurMax = 0;
    for (int i = 0; i < taille; i++)
    {
        while(poids_tmp <= poids_max){
            poids_tmp += TABLEAU[i][0];
            if(poids_tmp <= poids_max){
                valeur_tmp += TABLEAU[i][1];
            }
        }
        if (valeur_tmp > valeurMax)
        {
            valeurMax = valeur_tmp;
        }
        poids_tmp=0;
        valeur_tmp=0;
    }
    return valeurMax;
}

#define POIDS_MAX 10

int main()
{
    int TABLEAU[][2] = {{3, 3}, {7, 8}}; //{poids,valeur}
    //printf("%d\n", calculator2000(TABLEAU, sizeof(TABLEAU) / sizeof(int **), 0, 0, POIDS_MAX));
    printf("%d\n", supracalculator(TABLEAU, sizeof(TABLEAU) / sizeof(int **), POIDS_MAX));
}