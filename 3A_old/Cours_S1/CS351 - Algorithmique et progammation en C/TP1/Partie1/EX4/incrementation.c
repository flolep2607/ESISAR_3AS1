#include <stdio.h>

int main() {
    int i, j, k, l;
    i = j = k = l = 0;
    
    while(i < 9) {
        printf("i++ = %d, ++j = %d, k-- = %d, --l = %d\n", i++, ++j, k--, --l);
    }
    printf ("i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);
    return (0);
}

/* Ce programme permet de démontrer l'utilité de la post et pré incrémentation et décrémentation
   On peut voir que (--) et (++) renvoient une valeur avant ou après leur opération en fonction
   de leur positionnemment. */ 