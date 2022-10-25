#include "listechainee.h"

void insertator(element* liste){
    insertelement(12,0,1,liste);
    insertelement(-15,3,3,liste);
    insertelement(11,2,0,liste);
    insertelement(5,1,1,liste);
    insertelement(-4,1,2,liste);
}
element* somme_matrice(element* mat1,element* mat2){
    int max_x=mat1->x;
    int max_y=mat1->y;
    if(max_y!=mat2->y || max_x!=mat2->x){
        printf("Les matrices sont pas de meme tailles\n");
        exit(-1);
    }
    element* mat_somme=create_liste(max_x,max_y);
    int value=0;
    element* elem = mat1;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        value=find_x_y(elem->x,elem->y,mat2)+elem->val;
        insertelement(value,elem->x,elem->y,mat_somme);
    }
    return mat_somme;
}

int main(){
    element* liste1=create_liste(4,4);
    insertator(liste1);
    element* mat_sommed=somme_matrice(liste1,liste1);
    affList(mat_sommed);
    freeAll(liste1);
    freeAll(mat_sommed);
    return 0;
}