#include <stdlib.h>
#include <stdio.h>
#define NBMAX 100
typedef struct
{
    float coef;
    int degres;
} Terme;
typedef Terme Polynome[NBMAX];
void addpoly(Polynome p1,Polynome p2,Polynome res){
    int index=0;
    for(int i=0;i<NBMAX && p1[i].degres>0;i++){
        for(int j=0;j<NBMAX && p2[j].degres>0;j++){
            if(p1[i].degres == p2[j].degres){
                Terme * tmp = (Terme*) malloc(sizeof(Terme));
                tmp->coef=p1[i].coef+p2[j].coef;
                tmp->degres=p2[j].degres;
                res[index]=*tmp;
                index++;
            }
        }
    }
    Terme * tmp = (Terme*) malloc(sizeof(Terme));
    tmp->degres=-1;
    res[index]=*tmp;
}

int main()
{
    Terme a = {4,3};
    Terme b = {3,2};
    Terme c;
    c.coef = 2;
    c.degres = 1;
    Terme d;
    d.coef = 1;
    d.degres = -1;
    Polynome poly1 = {{4,3}, {3,2}, {1,1}, {1,-1}};
    Polynome res;
    addpoly(poly1, poly1, res);
    for(int i=0;i<NBMAX && res[i].degres>0;i++){
        printf("+(%fx^%d)",res[i].coef,res[i].degres);
    }
    printf("\n");
}