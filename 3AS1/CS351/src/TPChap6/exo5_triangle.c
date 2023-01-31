#include <stdlib.h>
#include <stdio.h>
#define SIZE 10
char TABLE[SIZE][SIZE];
int poww(int base, int exp)
{
    if (exp < 0) return -1;
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}
int size_finder(){
    for(int i=1;i<20;i++){
        if(poww(2,i)>SIZE){
            return i-1;
        }
    }
    return 1;
}
void draw(int n, int x, int y)
{
    if (n == 1)
    {
        TABLE[x][y] = '#';
        TABLE[x][y + 1] = '#';
        TABLE[x + 1][y] = '#';
    }
    else if (n > 0)
    {
        draw(n - 1, x, y);
        draw(n - 1, x + poww(2,n-1), y);
        draw(n - 1, x, y + poww(2,n-1));
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            TABLE[i][j] = ' ';
        }
    }
    int n = size_finder();
    draw(n, 0, 0);
    for (int j = SIZE - 1; j >= 0; j--)
    {
        for (int i = 0; i < SIZE; i++)
        {
            printf("%c", TABLE[i][j]);
        }
        printf("\n");
    }
}