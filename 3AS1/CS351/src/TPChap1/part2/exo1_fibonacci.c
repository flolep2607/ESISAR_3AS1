#include <stdio.h>

int fibonnacci(int n)
{
    int t1 = 0, t2 = 1, tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        t1 = t2;
        t2 = tmp;
        tmp = t1 + t2;
    }
    return tmp;
}

int main()
{
    int index;
    printf("Merci de rentrer un index:");
    scanf("%d", &index);
    printf("%d\n", fibonnacci(index));
    return 0;
}
