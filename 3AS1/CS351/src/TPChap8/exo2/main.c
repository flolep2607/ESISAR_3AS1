#include "listechainee.h"

void insertator(element* liste){
    insertelement(12,0,1,liste);
    insertelement(-15,3,3,liste);
    insertelement(11,2,0,liste);
    insertelement(5,1,1,liste);
    insertelement(-4,1,2,liste);
}
void insertator2(element* liste){
    for(int x=0;x<liste->x;x++){
        insertelement(1,x,x,liste);
    }
    insertelement(1,0,2,liste);
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
element* prod_matrice(element* mat1,element* mat2){
    if(mat1->y!=mat2->x){
        printf("Les matrices sont pas multipliables\n");
        exit(-1);
    }
    element* prod_somme=create_liste(mat1->x,mat2->y);
    for(int y=0;y<mat1->y;y++){
        for(int x=0;x<mat2->x;x++){
            int value=0;
            element* elem = mat1;
            while(elem->next !=NULL)
            {
                elem = elem->next;
                if(elem->y==y){
                    value+=find_x_y(x,elem->x,mat2)*elem->val;
                }
            }
            insertelement(value,x,y,prod_somme);
        }
    }
    return prod_somme;
}

int main(){
    element* liste1=create_liste(4,4);
    element* liste2=create_liste(4,4);
    insertator(liste1);
    insertator2(liste2);
    affList(liste2);
    element* mat_sommed=prod_matrice(liste1,liste2);
    affList(mat_sommed);
    freeAll(liste1);
    freeAll(liste2);
    freeAll(mat_sommed);
    return 0;
}
/*
? avant: h^2*m^2
? apres: (0.1*h)^2*(0.1*m)^2
*/