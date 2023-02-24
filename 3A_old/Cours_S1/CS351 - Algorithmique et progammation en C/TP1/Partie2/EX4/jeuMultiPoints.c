#include <stdio.h>


int main() {
    
    int nombre=0;

    while (nombre<2 || nombre>9){
        printf("Valeur de n:");
        scanf("%d",&nombre);

        if (nombre<2 || nombre>9) 
            printf("Réessayez : la valeur doit être comprise entre 2 et 9");
    }

    int i=1;
    int erreur=0;
    int reponse;

    while( i<=10){
        
        printf ("%d * %d =", i, nombre);
        scanf("%d" ,&reponse);

        if (i*nombre != reponse) {
            printf("\x1b[31mErreur !\x1b[0m %d x %d = %d et non %d\n", i, nombre, i*nombre, reponse);
            erreur++;
        }
        i++;
    }

    if (erreur) printf("%d erreur%c\n", erreur, (erreur==1) ? ' ' : 's');
    else printf("\x1b[32mFélicitations\x1b[0m\n");


    return (0);
}