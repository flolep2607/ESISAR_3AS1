#include <stdio.h>

int main() {
    
    int i = 2, j = 3, k = 4;
    
    printf("%d, %d, %d\n", i & j, i | 1, k | j);
/*  Détail des opérations en binaire:
    i & j:   0010 <- 2   i | 1:   0010 <- 2   k | j:   0100 <-4
           & 0011 <- 3          | 0001 <- 1          | 0011 <-3 
             0010 <- 2            0011 <- 3            0111 <-7
*/    
    if ((i & k) || (i & j)) // i&k = 0
        printf("ok");
/* || représente un "ou" logique         
    ici ( 0 ou 2 ) => (Faux ou Vrai) => Vrai 
*/
    return (0);
}
