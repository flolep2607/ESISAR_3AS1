#include <stdio.h>
#include <stdlib.h>
void triInsertion(int tab[],int size)
{
    printf("size:%d\n",size);
    int j, tmp;
    for (int i = 1; i <= size - 1; i++)
    {
        for (j = i;j > 0 && tab[j - 1] > tab[j];j--)
        {
            tmp = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = tmp;
        }
    }
}
int main()
{
    int tab[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int size = sizeof(tab) / sizeof(*tab);
    triInsertion(tab,size);
    for (int i = 0; i < size; i++){
        printf("%4d", tab[i]);
    }
    printf("\n");
}
