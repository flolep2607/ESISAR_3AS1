#include <stdio.h>
#include <stdlib.h>

int iterationV1(){
    int i = 0;
    int k;
    int n;
    printf("Rentrez un entier n : \n");
    scanf("%d", &n);
    while(i <= n){
        k += i;
        i++;
    }
    printf("%d\n", k);
    return 0;
}

int iterationV2(){
    int i = 0;
    int k;
    int n;
    printf("Rentrez un entier n : \n");
    scanf("%d", &n);
    do{
        k += i;
        i++;
    }while(i <= n);
    printf("%d\n", k);
    return 0;
}

int main(){
    iterationV1();
    iterationV2();
}