#include <stdio.h>
#include <stdlib.h>

void iterationV1(int n)
{
    int i = 0;
    int k = 0;
    while (i <= n)
    {
        k += i;
        i++;
    }
    printf("%d\n", k);
}

void iterationV2(int n)
{
    int i = 0;
    int k = 0;
    do
    {
        k += i;
        i++;
    } while (i <= n);
    printf("%d\n", k);
}

int main()
{
    int n;
    printf("Rentrez un entier n :");
    scanf("%d", &n);
    iterationV1(n);
    iterationV2(n);
}