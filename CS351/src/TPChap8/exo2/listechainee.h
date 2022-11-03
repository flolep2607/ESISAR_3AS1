#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int val;
    int x;
    int y;
    struct elem* next;
} element;

void insertelement(int value,int x, int y,element* list);
void delelement(int position,element* list);
void affList(element* list);

void freeAll(element* list);
element * find_next_x(int x,int y,element* list);
element * find_next_y(int x,int y,element* list);
int find_x_y(int x,int y,element* list);

element* create_liste(int max_x,int max_y);
