#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int num;
    int den;
} Fraction;
int pgcd(int a, int b)
{
    int c;
    while (a != 0)
    {
        c = a;
        a = b % a;
        b = c;
    }
    return b>0?b:-b;
}
// tu met un truc divisé par zero je te renvoie de la merde cheeeeeeeeeeeeeeh
void addfraction(Fraction a, Fraction b)
{
    Fraction c;
    c.num = a.num * b.den + b.num * a.den;
    c.den = a.den * b.den;
    int common = pgcd(c.num, c.den);
    c.num/=common;c.den/=common;
    printf("%d/%d\n", c.num, c.den);
}
void subfraction(Fraction a, Fraction b)
{
    b.num=-b.num;
    addfraction(a,b);
}
void mulfraction(Fraction a, Fraction b)
{
    Fraction c={a.num*b.num,a.den*b.den};
    int common = pgcd(c.num, c.den);
    c.num/=common;c.den/=common;
    printf("%d/%d\n", c.num, c.den);
}
void divfraction(Fraction a, Fraction b)
{
    int c=b.den;
    b.den=b.num;b.num=c;
    mulfraction(a,b);
}

int main()
{
    Fraction a, b;
    char op;
    printf("entrer 2 fractions:");
    scanf("%d/%d %c %d/%d",&a.num,&a.den,&op,&b.num,&b.den);
    switch (op)
    {
    case '+':
        addfraction(a,b);
        break;
    case '-':
        subfraction(a,b);
        break;
    case '*':
        mulfraction(a,b);
        break;
    case '/':
        divfraction(a,b);
        break;
    default:
    printf("boouh il sait pas ecrire\n");
        break;
    }
}