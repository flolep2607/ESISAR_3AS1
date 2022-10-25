#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#define isnum(X)  (X>='0' && X<='9')

int calcul(int y,int x,int calc){
    switch (calc)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '/':
            return x/y;
        case '*':
        case 'x':
            return x*y;
        default:
            break;
    }
    return 0;
}
int main()
{
    pileInt numbers = creerPile();
    char string[]="4 2 + 5 * 6 7 - /";
    int num=0;
    for(int i=0;string[i]!=0;i++){
        if(string[i]==' '){continue;}
        if(isnum(string[i])){
            empiler(numbers,string[i]-'0');
            num++;
        }else{
            int x =depiler(numbers);
            int y = depiler(numbers);
            int result=calcul(x,y,string[i]);
            printf("%d %c %d=%d\n",y,string[i],x,result);
            empiler(numbers,result);
        }
    }
    printf("ress:%d\n",depiler(numbers));
    /*while(!estPileVide(maPile)){
        printf("%c",depiler(maPile));
    }*/
    printf("\n");
    return 0;
}
//? 4 2 + 5 x 6 7 - /.