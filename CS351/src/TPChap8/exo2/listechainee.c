#include "listechainee.h"
void insertelement(int value,int x, int y,element* list)
{
    element* currentAdd = list;
    element* newElem=malloc(sizeof(element)/sizeof(int));
    newElem->val = value;
    newElem->x = x;
    newElem->y = y;
    while (currentAdd->next != NULL && (currentAdd->next)->val < value)
    {
        currentAdd=currentAdd->next;
    }
    newElem->next=currentAdd->next;
    currentAdd->next = newElem;
    
}
void delelement(int position,element* list)
{
    int index = 0;
    element *prevadd = list;
    element *nextID=prevadd->next;
    while (nextID->next != NULL && index < position)
    {
        index++;
        prevadd = nextID;
        nextID = nextID->next;
    }

    if(index == position)
    {
        prevadd->next = nextID->next;
        free(nextID);
    }

}
void affList(element* list)
{
    int max_x=list->x;
    int max_y=list->y;
    for(int y=0;y<max_y;y++){
        for(int x=0;x<max_x;x++){
            printf("%4d",find_x_y(x,y,list));
        }
        printf("\n");
    }
    printf("\n");
}

void freeAll(element* list)
{
    element* nextElem = list;
    element* current = list;
    while (current!= NULL)
    {
        nextElem = current->next;
        free(current);
        current = nextElem;
    }
}
element * find_next_x(int x,int y,element* list){
    element* elem_found;
    element* elem = list;
    int max_x=list->x;
    int dist=max_x+1;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        if(elem->y==y && (elem->x-x)%(max_x+1)<dist){
            elem_found=elem;
            dist=(elem_found->x-x)%(max_x+1);
        }
    }
    return elem_found;
}
element * find_next_y(int x,int y,element* list){
    element* elem_found;
    element* elem = list;
    int max_y=list->y;
    int dist=max_y+1;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        if(elem->x==x && (elem->x-x)%(max_y+1)<dist){
            elem_found=elem;
            dist=(elem_found->x-x)%(max_y+1);
        }
    }
    return elem_found;
}
int find_x_y(int x,int y,element* list){
    element* current = list;
    while (current!= NULL){
        if(current->x == x && current->y == y){
            return current->val;
        }
        current = current->next;
    }
    return 0;
}
element* create_liste(int max_x,int max_y){
    element* elem = malloc(sizeof(element)/sizeof(int));
    elem->next = NULL;
    elem->val = 0;
    elem->x=max_x;
    elem->y=max_y;
    return elem;
}
