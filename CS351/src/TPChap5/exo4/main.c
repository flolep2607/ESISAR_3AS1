#include <stdio.h>
#include <stdlib.h>
#include "listeTableau.h"

int elementLibre(liste l)
{
    for (int i = 0; i < TAILLEMAX; i++)
    {
        if (l[i].suivant == -1)
        {
            return i;
        }
    }
    return -1;
}

void creerListeVide(liste l)
{
    l[0].valeur = -1;
    l[0].suivant = 0;
    for (int i = 1; i < TAILLEMAX; i++)
    {
        l[i].suivant = -1;
    }
}
void insererElement(int x, liste l)
{
    int index_insertion=elementLibre(l);
    l[index_insertion].valeur=x;
    //let's go trouver l'element avant
    int index_before=0;
    int index=0;
    do
    {
        index = l[index].suivant;
        if(l[index].suivant==-1){
            index_before=index;
        }else if(l[index].valeur<=x && (l[index].suivant<1 || l[l[index].suivant].valeur>x)){
            index_before=index;
        }
    } while (l[index].suivant>0 && index_before==0);
    l[index_insertion].suivant=l[index_before].suivant;
    l[index_before].suivant=index_insertion;
}

void supprimerElement(int x, liste l)
{
    int index_before=0;
    int index=0;
    do
    {
        index = l[index].suivant;
        if(l[index].suivant>0 && l[l[index].suivant].valeur==x){
            index_before=index;
        }
    } while (l[index].suivant>0 && index_before==0);
    if(index_before==0) return;
    int index_to_remove=l[index_before].suivant;
    l[index_before].suivant=l[index_to_remove].suivant;
    l[index_to_remove].suivant=-1;
}
void compacterListe(liste l){
    int done=1;
    while(done!=0){
        done=0;
        for(int i=1;i+1<TAILLEMAX;i++){
            if(l[i].suivant==-1&&l[i+1].suivant!=-1){
                //x->l[i+1]->l[i]
                int x=0;
                while(l[x].suivant!=i+1) x++;
                l[x].suivant=i;
                l[i].valeur=l[i+1].valeur;
                l[i].suivant=l[i+1].suivant;
                l[i+1].suivant=-1;
                done++;
            }
        }
    }
}
void afficherListe(liste l)
{
    int index=0;
    do
    {
        index = l[index].suivant;
        printf("Indice: %d; Valeur: %d suivant:%d\n", index, l[index].valeur,l[index].suivant);
    } while (l[index].suivant!=0);
}
int main()
{
    element maListe[TAILLEMAX];

    creerListeVide(maListe);

    insererElement(4, maListe);
    insererElement(2, maListe);
    insererElement(6, maListe);
    insererElement(42, maListe);
    insererElement(6, maListe);
    supprimerElement(4,maListe);
    supprimerElement(4,maListe);
    compacterListe(maListe);
    afficherListe(maListe);

    return 0;
}
