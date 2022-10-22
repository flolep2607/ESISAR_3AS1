#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float afficherNotes(int nbNotes, float tableauNotes[]){
    for(int i = 0; i < nbNotes; i++){
        printf("%f\n", tableauNotes[i]);
    }
    return 0;
}

float minimumNote(int nbNotes, float tableauNotes[]){
    float minTab = 20;
    for(int i = 0; i < nbNotes; i++){
        if(tableauNotes[i] < minTab){
            minTab = tableauNotes[i];
        }
    }
    return minTab;
}

float maximumNote(int nbNotes, float tableauNotes[]){
    float maxTab = 0;
    for(int i = 0; i < nbNotes; i++){
        if(tableauNotes[i] > maxTab){
            maxTab = tableauNotes[i];
        }
    }
    return maxTab;
}

float calculeMoyenne(int nbNotes, float tableauNotes[]){
    float moyenne = 0;
    for(int i = 0; i < nbNotes; i++){
        moyenne += tableauNotes[i];
    }
    moyenne /= nbNotes;
    return moyenne;
}

float calculeVariance(int nbNotes, float tableauNotes[]){
    float moyenne = calculeMoyenne(nbNotes, tableauNotes);
    float variance = 0;
    for(int i = 0; i < nbNotes; i++){
        variance += (tableauNotes[i] - moyenne)*(tableauNotes[i] - moyenne);
    }
    variance /= nbNotes;
    return variance;
}

float calculeEcartType(int nbNotes, float tableauNotes[]){
    float variance = calculeVariance(nbNotes, tableauNotes);
    float EcartType = sqrt(variance);
    return EcartType;
}

int rechercherValeur(int nbNotes, float tableauNotes[], float valeur){
    for(int i = 0; i < nbNotes; i++){
        if(tableauNotes[i] == valeur){
            return i+1;
        }
    }
    return -1;
}

void histogrammeHorizontal(int nbNotes, float tableauNotes[]){
    for(int i = 2; i <= 20; i+=2){
        if(i == 2){
            printf("[");
        }
        else{
            printf("]");
        }
        printf("%-2d; %-2d]  ", i-2, i);
        for(int j = 0; j < nbNotes; j++){
            if((tableauNotes[j] <= i) && (tableauNotes[j] > i-2)){
                printf("══════════════");
            }
            else if (i == 2 && tableauNotes[j] == 0)
            {
                printf("══════════════");
            } 
        }
        printf("\n");
    }
}

void histogrammeVertical(int nbNotes, float tableauNotes[]){
    int temparray[10]={0};
    for(int i = 1; i <= 10; i++){
        for(int j = 0; j < nbNotes; j++){
            if((tableauNotes[j] <= i*2) && (tableauNotes[j] > i*2-2)){
                temparray[i-1]++;
            }
            else if (i == 2 && tableauNotes[j] == 0)
            {
                temparray[i-1]++;
            } 
        }
    }
    int max=0;
    for (int i = 0; i < 10; i++){
        if (temparray[i] > max){
            max = temparray[i];
        }
    }    
    for(;max>0;max--){
        for(int i=0;i<10;i++){
            if(temparray[i]>=max){
                printf("    █    ");
            }else{
                printf("         ");
            }
        }
        printf("\n");
    }
    for(int i=2;i<=20;i+=2){
        if(i == 2){
            printf(" [");
        }else{
            printf(" ]");
        }
        printf("%-2d;%-2d] ", i-2, i);
    }
    printf("\n");
}

int main(){
    float tableauTest[] = {0 , 13.5 , 8.5 , 13.7 , 20 , 12 , 8.5 , 17 , 11 , 10 , 9.5 , 4 , 14 , 13.5 , 12 , 1 , 15 , 10.5 , 7.5 , 9.5};
    int sizeTest = sizeof(tableauTest)/sizeof(float);
    //afficherNotes(sizeTest, tableauTest);
    //printf("Note la plus basse : %f\n", minimumNote(sizeTest, tableauTest));
    //printf("Note la plus haute : %f\n", maximumNote(sizeTest, tableauTest));
    //printf("Moyenne de classe : %f\n", calculeMoyenne(sizeTest, tableauTest));
    //printf("Variance : %f\n", calculeVariance(sizeTest, tableauTest));
    //printf("Écart Type : %f\n", calculeEcartType(sizeTest, tableauTest));
    //printf("Position dans le tableau : %f\n", rechercherValeur(sizeTest, tableauTest, 12));
    //printf("Position dans le tableau : %f\n", rechercherValeur(sizeTest, tableauTest, 15));
    histogrammeVertical(sizeTest, tableauTest);
    histogrammeHorizontal(sizeTest, tableauTest);
}