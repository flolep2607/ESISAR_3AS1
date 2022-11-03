#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int fibonacci(int n)
{
    int somme;
    if (n == 0)
    {
        somme = 0;
    }
    else if (n == 1)
    {
        somme = 1;
    }
    else
    {
        somme = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return somme;
}

int pgcd_rec(int a, int b)
{
    int r = a % b;
    if (r == 0)
    {
        r = b;
        return r;
    }
    else
    {
        return pgcd_rec(b, r);
    }
}

bool palindrome(char *mot, int taille)
{
    if (taille <= 2)
    {
        printf("C'est un palindrome.\n");
        return true;
    }
    else
    {
        if (mot[0] != mot[taille - 2])
        {
            printf("Ce n'est pas un palindrome.\n");
            return false;
        }
        else
        {
            char *p = (char *)(mot + 1);
            return palindrome(p, taille - 2);
        }
    }
}

int main()
{
    // printf("%d\n", fibonacci(3));
    // printf("%d\n", pgcd_rec(16,4));
    char word[] = "kayak";
    int size = sizeof(word) / sizeof(char);
    palindrome(word, size);
}