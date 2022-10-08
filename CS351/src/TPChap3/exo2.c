#include <stdlib.h>
#include <stdio.h>

float valeurPolynome(float A[], int N, float x0){
    int compteur = 1;
    int resultat = A[0];
    //int tmp;
    while (compteur < N)
    {
        /*tmp = A[compteur];
        for (int i = 0; i < compteur; i++)
        {
            tmp *= x0;
        }
        resultat += tmp;*/
        for(int i = 0; i < x0; i++){
            resultat += A[compteur];
        }
        x0 *= x0; 
    }
    return resultat;
}

int main(){
    float test[] = {1, 3, 5, 6};
    int degre = sizeof(test)/sizeof(float);
    printf("%f\n", valeurPolynome(test, degre, 1));
}

//gcc -o prog exo2.c -Wall