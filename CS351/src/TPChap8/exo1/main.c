#include "listechainee.h"
int main(){
    element* liste=create_liste();
    for(int i = 10 ; i>0 ; i--)
    {
        insertelement(i,liste);
        affList(liste);
    }
    for(int i = 0 ; i< 5 ; i++)
    {
        delelement(i,liste);
        affList(liste);
    }

    freeAll(liste);
    return 0;
}