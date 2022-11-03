#include <stdio.h>

int pgcd(int n1,int n2)
{
    int tmp;
    while(n2>0){
        tmp=n2;
        n2=n1%n2;
        n1=tmp;
    }
    return n1;
}

int main()
{
    int n1,n2;
    printf("n1 n2:");
    scanf("%d %d", &n1, &n2);
    printf("%d\n", pgcd(n1,n2));
    return 0;
}
