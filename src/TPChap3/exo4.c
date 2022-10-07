#include <stdlib.h>
#include <stdio.h>

int creationMatrice(int ligne, int colonne){
    int matrice[ligne][colonne];
    return matrice;
}

int afficherMatrice(int ligne, int colonne, int matrice[][]){
    for(int i = 0; i < ligne; i++){
        for(int j = 0; j < colonne; j++){
            printf("%d   ", matrice[i][j]);
        }
        printf("\n");
    }
}

int additionnerMatrices(){
    
}

int transposee(){

}

int produitMatriciel(){

}

int main(){
    int matrice[][] = creationMatrice(3, 4);
    afficherMatrice(3, 4, matrice);
}