#include <stdio.h>
#include "graphlib/graphlib.h"

void liner(int x, int y, int xx, int yy)
{
    //fill_triangle(x, y, x + xx, y + yy,x+5, y+5);
    line(x, y, x + xx, y + yy);
}
void dessineCarre(int x, int y, int taille)
{
    liner(x, y, -taille / 2, -taille / 2);         // \down
    liner(x, y - taille, taille / 2, taille / 2);  // \up
    liner(x, y, taille / 2, -taille / 2);          // /down
    liner(x, y - taille, -taille / 2, taille / 2); // /up
}
void dessineCarreDiagonale(int x, int y, int taille)
{
    dessineCarre(x, y, taille);
    liner(x - taille / 2, y - taille / 2, taille, 0); // _
    liner(x, y, 0, -taille);                          // |
}

void dessineMosaique(int taille, int x, int y, int largeur, int hauteur)
{
    for (int i = 0; i <= largeur; i++)
    {
        for (int j = 0; j <= hauteur; j++)
        {
            if ((j + i) % 2 == 0)
            {
                set_blue();
            }
            else
            {
                set_black();
            }
            dessineCarre(x + taille / 2 + i * taille, y - j * taille, taille);
        }
    }
}
void dessineMosaiqueAvecSouris(int taille, int largeur, int hauteur)
{
    int x, y;
    cliquer_xy(&x, &y);
    dessineMosaique(taille, x, y, largeur, hauteur);
}