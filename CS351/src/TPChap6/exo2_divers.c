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

/*char palindrome(char mot[], int taille){

}*/

int main(){
    //printf("%d\n", fibonacci(3));
    printf("%d\n", pgcd_rec(16,4));
    //palindrome("kayak", 5);
}