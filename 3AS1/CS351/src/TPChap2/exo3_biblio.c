#include <stdio.h>

int quotient(int a, int b){
    int q = 0;
    if(b <= 0){
        return 0;
    }
    while(a > 0){
        a -= b;
        if(a >= 0){q++;}
    }
    return q;
}

int reste(int a, int b){
    int rst = 0;
    if(b == 0){
        return 0;
    }
    while(a > 0){
        a -= b;
        if(a >= 0){rst=a;}
    }
    return rst;
}

int valabs(int a){
    return a >= 0?a:-a;
}

int pgcd(int a,int b)
{
    int tmp;
    while(b>0){
        tmp=b;
        b=a%b;
        a=tmp;
        #ifdef MISEAUPOINT
        printf("valeur courante de b = %d",b);
        #endif
    }
    return a;
}

int ppcm(int a, int b){
    return valabs(a * b)/pgcd(a, b);
}

int puissanceMB(int x, int n){
    int y=1,z=x;
    while(n > 0){
        if(n%2 == 0){
            n /= 2;
        } else{
            n /= 2;
            y *= z;
        }
        if(n == 0){
            return y;
        }
        z *= z;
    }
    return y;
}

/*(i) N ← n, Y ← 1, Z ← x
(ii) N ← N / 2. Si N était pair avant division, aller à l'étape 5
(iii) Y ← Z * Y
(iv) Si N = 0, fin de l'algorithme avec réponse Y
(v) Z ← Z * Z, aller à l'étape 2.*/

int sommeDesImpairs(int d,int f){
    int result=0;
    for(;d<=f;d+=2){
        result+=d;
    }
    return result;
}

int estUneDecompositionDe(int d,int f){
    int n = ((f-d)/2)+1;
    return sommeDesImpairs(d, f) == n*n*n?n:-1;
}

int testBibliotheque(){
    printf("%d\n", quotient(8,4));
    printf("%d\n", quotient(9,2));
    printf("%d\n", quotient(2,0));
    printf("%d\n", reste(8,4));
    printf("%d\n", reste(9,2));
    printf("%d\n", ppcm(2,0));
    printf("%d\n", puissanceMB(5,2));
    printf("%d\n", puissanceMB(5,3));
    printf("%d\n", sommeDesImpairs(7,11));
    printf("%d\n", estUneDecompositionDe(7,11));
    printf("%d\n", estUneDecompositionDe(7,13));
    return 0;
}

int main()
{
    int a,b;
    printf("a b:");
    scanf("%d %d", &a, &b);
    //printf("%d\n", sommeDesImpairs(a,b));
    printf("%d\n", estUneDecompositionDe(a,b));
    //printf("%d\n", quotient(a,b));
    //printf("%d\n", reste(a,b));
    //printf("%d\n", ppcm(a,b));
    //printf("%d\n", puissanceMB(a,b));
    return 0;
}