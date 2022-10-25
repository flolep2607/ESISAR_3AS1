#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "pile.h"
#define iscalc(X)  (X=='+' || X=='-' || X=='*' || X=='/')
void init(pileInt maPile){
    char string[]="1 1+";
    int n=0;
    int size = strlen(string);
    for(int i=size;i>=0;i--){
        if(string[i]!=' '){
            empiler(maPile,string[i]);
        }
    }
}
int calcul(int x,int y,int calc){
    switch (calc)
    {
        case '+':
            return x+y;
        case '-':
            return x-y;
        case '/':
            return x*y;
        case '*':
            return x/y;
        default:
            break;
    }
    return 0;
}
int calculer(pileInt maPile){
   
    return 0;
}
int main()
{
    pileInt maPile = creerPile();
    init(maPile);
    int res=calculer(maPile);
    printf("ress:%d\n",res);
    /*while(!estPileVide(maPile)){
        printf("%c",depiler(maPile));
    }*/
    printf("\n");
    return 0;
}
//? 4 2 + 5 x 6 7 - /.