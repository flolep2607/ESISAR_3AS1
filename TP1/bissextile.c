#include <stdio.h>
#include <stdlib.h>

int bissextile(){
    int annee;
    printf("Merci de rentrer une année.\n");
    scanf("%d", &annee);
    if (annee%4 == 0){
        if (annee%100 == 0){
            if (annee%400 == 0){
                printf("L'année %d est bissextile\n", annee);
            }
            else {
                printf("L'année %d n'est pas bissextile\n", annee);
            }
        }
        else {
                printf("L'année %d est bissextile\n", annee);
            }
    }
    else {
                printf("L'année %d n'est pas bissextile\n", annee);
            }
    return 0;
}

int main(){
    bissextile();
}