#include <stdio.h>

int main() {
    
    int n;
	printf("Entrez un nombre:");
	scanf("%d",&n);
    
    int somme=0;
    int indice=0;
    
    while( ++indice <= n ){
        somme += indice;
    }

    printf("Somme des %d premiers entiers: %d\n",n,somme);

    return 0;

}