#include <stdlib.h>
#include <stdio.h>

int fibonacci(int n){
    int somme;
    if (n == 0)
    {
        somme = 0;
    }
    else if (n == 1)
    {
        somme = 1;
    }
    else{
        somme = fibonacci(n-1) + fibonacci(n-2);
    }
    return somme;
}

int pgcd_rec(int a, int b){
    int r = a%b;
    if(r == 0){
        r = b;
        return r;
    }
    else{
        pgcd_rec(b, r);
    }
}

char palindrome(char mot[], int taille, int compteur){ // compteur = 0
    int myBool = 1;
    if(mot[compteur] != mot[taille - 2 - compteur]){
        myBool = -1;
        printf("%s n'est pas un palindrome\n", mot);
        return myBool;
    }
    else if(compteur == (taille-2)/2){
        myBool = -1;
        printf("%s n'est pas un palindrome\n", mot);
        return myBool;
    }
    else{
        palindrome(mot, taille, compteur+1);
        //printf("%s est un palindrome\n", mot);
    }
    /*if (myBool == 1)
    {
        printf("%s est un palindrome\n", mot);
    }
    else{
        printf("%s n'est pas un palindrome\n", mot);
    }*/
    return myBool;
}

int main(){
    //printf("%d\n", fibonacci(3));
    //printf("%d\n", pgcd_rec(16,4));
    int size = sizeof("kayak")/sizeof(char);
    palindrome("kayak", size, 0);
}