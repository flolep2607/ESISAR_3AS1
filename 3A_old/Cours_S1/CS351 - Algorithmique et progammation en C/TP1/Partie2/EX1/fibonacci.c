#include <stdio.h>

int Fibonacci ( int n ) {

    int un=1;

    if (n==0) un=0;
    else if (n>1) {
        int ra=0;
        int tmp;
        for(int i=2;i<=n;i++) {
            tmp = ra + un ;
            ra = un ;
            un = tmp ;
        }
    }
    return un ;

}

int main() {
    
    int rang;
	printf("Entrez le rang:");
	scanf("%d",&rang);

    printf ("U%d: %d\n",rang,Fibonacci(rang)); // Il vaut mieux tester avec 0, 1 et 5

    return (0);
}