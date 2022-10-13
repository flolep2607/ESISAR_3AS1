#include <stdlib.h>
#include <stdio.h>
#define NBMAX 100
typedef struct
{
    float coef;
    int degres;
} Terme;
typedef Terme Polynome[NBMAX];

void addpoly(Polynome p1, Polynome p2, Polynome res) //virer boucle avec j ?
{
    int index = 0;
    for (int i = 0; i < NBMAX || p1[i].degres < 0; i++)
    {
        for (int j = 0; j < NBMAX; j++)
        {
            if (p1[i].degres == p2[i].degres)
            {
                Terme tmp;
                tmp.coef = p1[i].coef + p2[i].coef;
                tmp.degres = p2[i].degres;
                res[index] = tmp;
                index++;
            }
        }
    }
}

int main()
{
    Terme a;
    a.coef = 4;
    a.degres = 3;
    Terme b;
    b.coef = 3;
    b.degres = 2;
    Terme c;
    c.coef = 2;
    c.degres = 1;
    Terme d;
    d.coef = 1;
    d.degres = -1;
    Polynome poly1 = {a, b, c, d};
    Polynome res;
    addpoly(poly1, poly1, res);
}