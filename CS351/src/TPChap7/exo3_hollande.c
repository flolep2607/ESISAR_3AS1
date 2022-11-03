#include <stdio.h>
#include <stdlib.h>
// Enum couleur {bleu, blanc, rouge}
// Lexique : b, w, r : entier ; T : tab[1..n] de couleur
// Début
// 	b ← 1; w ← 1 ; r ← n
// 	tant que w ≤ r faire
// 		si T[w] = blanc alors w ← w+1
// 		sinon si T[w] = bleu alors
// 			{échanger T[b] et T[w] ;
// 			b ← b+1 ; w ← w+1 }
// 		sinon // T[w] = rouge
// 			{échanger T[w] avec T[r] ;
// 			r ← r-1}
// 	fintantque ;
// Fin

void tri(int *tab, int size)
{
    printf("size:%d\n", size);
    int b = 0, w = 0, r = size - 1;
    int tmp;
    while (w <= r)
    {
        if (*(tab + w) >= 3 && *(tab + w) <= 6)
        {
            w++;
        }
        else if (*(tab + w) < 3)
        {
            tmp = *(tab + b);
            *(tab + b) = *(tab + w);
            *(tab + w) = tmp;
            b++;
            w++;
        }
        else
        {
            tmp = *(tab + r);
            *(tab + r) = *(tab + w);
            *(tab + w) = tmp;
            r--;
        }
    }
}

int main()
{
    int tab[] = {5, 8, 1, 4, 3, 9, 2, 7, 3, 8, 1, 4, 5, 3, 8};
    int size = sizeof(tab) / sizeof(*tab);
    tri(tab, size);
    for (int i = 0; i < size; i++)
    {
        printf("%4d", tab[i]);
    }
    printf("\n");
}
