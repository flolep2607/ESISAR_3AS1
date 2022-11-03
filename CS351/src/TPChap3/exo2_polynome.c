#include <stdlib.h>
#include <stdio.h>

float valeurPolynome(float A[], int N, float x0){
    int compteur = 0;
    int resultat = 0;
    while (compteur < N)
    {
        resultat = resultat * x0 + A[N-1-compteur];
        compteur ++;
    }
    return resultat;
}

int main(){
    float test[] = {1, 3, 5, 6}; 
    int degre = sizeof(test)/sizeof(float);
    printf("%f\n", valeurPolynome(test, degre, 2)); //valeur : 15 pour x0 = 1; 75 pour x0 = 2; 217 pour x0 = 3
}