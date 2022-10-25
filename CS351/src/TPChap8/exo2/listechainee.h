#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    int x;
    int y;
    struct elem* next;
} element;

void insertelement(int value,element* list);
void delelement(int position,element* list);
void affList(element* list);

void freeAll(element* list);
element * find_next_x(int x,int y,element* list);
element * find_next_y(int x,int y,element* list);
element * find_x_y(int x,int y,element* list);

element* create_liste();
