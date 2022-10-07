#include <stdio.h>

int main(int argc, char * argv[]) {
    int i;
    printf("Nombre d'arguments : %d\n", argc);
    for(i = argc-1 ; i > 0 ; i--) {
        printf("%s\n", argv[i]);
    }
    return 0;
}

//Le programme retourne le nombre d'arguments donnés, avec au moins un étant argv[0].
// Il retourne ensuite tous les arguments, dans l'ordre décroissant.