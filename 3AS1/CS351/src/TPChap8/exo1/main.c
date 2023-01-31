#include "listechainee.h"
int main(){
    element* liste=create_liste();
    /*for(int i = 10 ; i>0 ; i--)
    {
        insertelement(i,liste);
        affList(liste);
    }
    for(int i = 0 ; i< 5 ; i++)
    {
        delelement(i,liste);
        affList(liste);
    }*/
    for(int i = 10 ; i>0 ; i--)
    {
        insertelement(i,liste);
        affList(liste);
    }
    delelement(0, liste);
    affList(liste);
    delelement(4, liste);
    affList(liste);
    delelement(7, liste);
    affList(liste);
    insertelement(0, liste);
    affList(liste);
    insertelement(8, liste);
    affList(liste);

    freeAll(liste);
    return 0;
}