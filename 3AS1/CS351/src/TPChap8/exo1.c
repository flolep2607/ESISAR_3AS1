#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    struct elem* next;
} element;

void insertelement(int value,element* list)
{
    element* currentAdd = list;
    element* newElem=malloc(sizeof(element)/sizeof(int));
    newElem->val = value;
    while (currentAdd->next != NULL && (currentAdd->next)->val < value)
    {
        currentAdd= currentAdd->next;
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
    element* elem = list;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        printf("%d ",elem->val);
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

element* create_liste(){
    element* elem = malloc(sizeof(element)/sizeof(char));
    elem->next = NULL;
    elem->val = 0;
    return elem;
}

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