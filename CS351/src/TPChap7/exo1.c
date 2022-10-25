#include <stddef.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int *p1;
    int *p2;
    p1 = &a;
    p2 = &c;
    *p1 = *p2;
    (*p2)++;
    p1 = p2;
    p2 = &b;
    *p2 = *p1 - 2 * *p2;
    (*p2)--;
    *p1 = *p2 - c;
    a = (2 + *p2) * *p1;
    p2 = &c;
    *p2 = *p1 / *p2;
    *p1 = a + b;
    a += *p1;
    b = *p1 + *p2;
    *p1 = 2 * a;
    a = *p2;
    *p2 = *p1 - *p2;
    *p1 = 1 - c;
    *p2 += *p1 + a;
    p2 = p1 = &a;
    p2++;
    p1 += 2;
    c = p2 == &c;
    p1 = NULL;
}
