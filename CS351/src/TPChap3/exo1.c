#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int afficherNotes(int nbNotes, int tableauNotes[]){
    for(int i = 0; i < nbNotes; i++){
        printf("%d\n", tableauNotes[i]);
    }
    return 0;
}

int minimumNote(int nbNotes, int tableauNotes[]){
    int minTab = 20;
    for(int i = 0; i < nbNotes; i++){
        if(tableauNotes[i] < minTab){
            minTab = tableauNotes[i];
        }
    }
    return minTab;
}

int maximumNote(int nbNotes, int tableauNotes[]){
    int maxTab = 0;
    for(int i = 0; i < nbNotes; i++){
        if(tableauNotes[i] > maxTab){
            maxTab = tableauNotes[i];
        }
    }
    return maxTab;
}

int calculeMoyenne(int nbNotes, int tableauNotes[]){
    int moyenne = 0;
    for(int i = 0; i < nbNotes; i++){
        moyenne += tableauNotes[i];
    }
    moyenne /= nbNotes;
    return moyenne;
}

int calculeVariance(int nbNotes, int tableauNotes[]){
    int moyenne = calculeMoyenne(nbNotes, tableauNotes);
    int variance = 0;
    for(int i = 0; i < nbNotes; i++){
        variance += (tableauNotes[i] - moyenne)*(tableauNotes[i] - moyenne);
    }
    variance /= nbNotes;
    return variance;
}

int calculeEcartType(int nbNotes, int tableauNotes[]){
    int variance = calculeVariance(nbNotes, tableauNotes);
    int EcartType = sqrt(variance);
    return EcartType;
}

int rechercherValeur(int nbNotes, int tableauNotes[], int valeur){
    int i;
    for(i = 0; i < nbNotes; i++){
        if(tableauNotes[i] == valeur){
            return i+1;
        }
    }
    return -1;
}

int main(){
    int tableauTest[] = {5, 12, 24, 48, 2, 0, 8};
    int sizeTest = sizeof(tableauTest)/sizeof(int);
    afficherNotes(sizeTest, tableauTest);
    printf("Note la plus basse : %d\n", minimumNote(sizeTest, tableauTest));
    printf("Note la plus haute : %d\n", maximumNote(sizeTest, tableauTest));
    printf("Moyenne de classe : %d\n", calculeMoyenne(sizeTest, tableauTest));
    printf("Variance : %d\n", calculeVariance(sizeTest, tableauTest));
    printf("Écart Type : %d\n", calculeEcartType(sizeTest, tableauTest));
    printf("Position dans le tableau : %d\n", rechercherValeur(sizeTest, tableauTest, 12));
    printf("Position dans le tableau : %d\n", rechercherValeur(sizeTest, tableauTest, 15));
}