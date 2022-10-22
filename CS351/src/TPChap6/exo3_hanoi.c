#include <stdlib.h>
#include <stdio.h>

void hanoi(int nb_disques, char from, char to, char cache)
{
    if (nb_disques == 1)
    {
        printf("%c->%c\n", from, to);
        return;
    }
    hanoi(nb_disques-1, from, cache, to);
    printf("%c->%c\n", from, to);
    hanoi(nb_disques-1, cache, to, from);
}

int main()
{
    int n = 1;
    hanoi(n, 'A','B','C');
}