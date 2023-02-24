#include <stdio.h>

int main() {
    
    int n;
	printf("Entrez un nombre:");
	scanf("%d",&n);
    
    int somme=0;
    int indice=0;
    
    do {
        somme += indice;
    } while( ++indice <= n );

    printf("Somme des %d premiers entiers: %d\n",n,somme);

    return 0;

}