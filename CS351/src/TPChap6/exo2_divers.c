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

/*int pgcd(int a, int b){

}

char palindrome(char mot[], int taille){

}*/

int main(){
    printf("%d\n", fibonacci(3));
    //pgcd(95,42);
    //palindrome("kayak", 5);
}