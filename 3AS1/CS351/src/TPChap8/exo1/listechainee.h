#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    struct elem* next;
} element;

void insertelement(int value,element* list);
void delelement(int position,element* list);
void affList(element* list);

void freeAll(element* list);

element* create_liste();
