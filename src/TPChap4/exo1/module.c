#include <stdio.h>
#include <stdlib.h>

int lireDonnes(char nomfichier[], int T[])
{
    FILE *file_pointer;
    int tmp_value = 0;
    int tmp_scan = 0;
    int i = 0;
    file_pointer = fopen(nomfichier, "r");
    do
    {
        tmp_scan = fscanf(file_pointer, "%d", &tmp_value);
        if (tmp_scan == 1)
        {
            T[i] = tmp_value;
            i++;
        }
    } while (tmp_scan != EOF);
    fclose(file_pointer);
    return i;
}

void afficherTableau(int T[], int nb)
{
    for (int i = 0; i < nb; i++)
    {
        printf("index: %d => value: %d\n", i, T[i]);
    }
}

void trieABulles(int T[], int nb)
{
    int tmp;
    for (int i = 0; i < nb - 1; i++)
    {
        for (int j = 0; j < nb - i - 1; j++)
        {
            if (T[j] > T[j + 1]) // < pour tri decroissant
            {
                tmp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = tmp;
            }
        }
    }
}
void enregistrerdonnees(char nomfichier[], int T[], int nb)
{
    FILE *file_pointer;
    file_pointer = fopen(nomfichier,"w");
    for (int i = 0; i < nb; i++)
    {
        fprintf(file_pointer,"%d\n", T[i]);
    }
    fclose(file_pointer);
}
