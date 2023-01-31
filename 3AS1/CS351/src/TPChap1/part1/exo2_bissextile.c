#include <stdio.h>
#include <stdlib.h>

void bissextile(int annee)
{
    if (annee % 4 == 0)
    {
        if (annee % 100 == 0 && annee % 400 == 0)
        {

            printf("L'année %d est bissextile\n", annee);
        }
        else
        {
            printf("L'année %d est bissextile\n", annee);
        }
    }
    else
    {
        printf("L'année %d n'est pas bissextile\n", annee);
    }
}

int main()
{
    int annee;
    printf("Merci de rentrer une année:");
    scanf("%d", &annee);
    bissextile(annee);
    return 0;
}