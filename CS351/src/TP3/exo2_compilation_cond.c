#include <stdio.h>

int pgcd(int a,int b)
{
    int tmp;
    while(b>0){
        #ifdef MISEAUPOINT
        printf("valeur courante de b = %d\n", b);
        #endif
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

/*int pgcd(int a, int b){
    int r;
    if(b == 0){
        r = a;
    }
    else if(a == 0){
        r = b;
    }
    else if(b > a){
        pgcd(b,a);
    }
    else{
        while(b > 0){
            #ifdef MISEAUPOINT
            printf("valeur courante de b = %d", b)
            #endif
            r = a%b;
            a = b;
            b = r;
        }
    }
    return r;
}*/

int main()
{
    int a,b;
    printf("a b:");
    scanf("%d %d", &a, &b);
    printf("%d\n", pgcd(a,b));
    return 0;
}