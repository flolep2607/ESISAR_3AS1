#include <stdlib.h>
#include <stdio.h>

/*int **creationMatrice(int ligne, int colonne){
    int matrice[ligne][colonne];
    return 0;
}*/

int afficherMatrice(int ligne, int colonne, int matrice[ligne][colonne]){
    for(int i = 0; i < ligne; i++){
        for(int j = 0; j < colonne; j++){
            printf("%d   ", matrice[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int additionnerMatrices(int ligne, int colonne, int mat1[ligne][colonne], int mat2[ligne][colonne]){
    int matResultat[ligne][colonne];
    for(int i = 0; i < ligne; i++){
        for(int j = 0; j < colonne; j++){
            matResultat[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    afficherMatrice(ligne, colonne, matResultat);
    return 0;
}

int transposee(int ligne, int colonne, int matrice[ligne][colonne]){
    int matTransposee[colonne][ligne];
    for(int i = 0; i < ligne; i++){
        for(int j = 0; j < colonne; j++){
            matTransposee[j][i] = matrice[i][j];
        }
    }
    afficherMatrice(colonne, ligne, matTransposee);
    return 0;
}

/*int produitMatriciel(){

}*/

int main(){
    int matrice[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int matrice2[3][4] = {{-1,-2,-3,-4},{-5,-6,-7,-8},{-9,-10,-11,-12}};
    int column = sizeof(matrice[0])/sizeof(matrice[0][0]);
    int row = sizeof(matrice)/sizeof(matrice[0]);
    afficherMatrice(row, column, matrice);
    additionnerMatrices(row, column, matrice, matrice2);
    transposee(row, column, matrice);
}