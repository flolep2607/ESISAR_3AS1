#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//TODO chercher  sur chamillo pile.c/pile.h
typedef struct
{
    char info;
    Pile *suiv;
} Pile;

Pile *sommet;
char p1;
char ch[20], c;
int i = 0, code = 0;
char tempo[2];

Pile *Init(Pile **sommet)
{

    sommet = NULL;

    return *sommet;
}

int char_to_int(char c)
{
    if (c == '0')
        return code == 0;
    else
    {
        code = c - 48;
        return code;
    }
}

char int_to_char(int int_to_ch)
{
    int_to_ch += 48;
    c = (char)int_to_ch;
    return c;
}

void empiler(char x, Pile **sommet)
{
    Pile *p;

    p = (Pile *)malloc(sizeof(Pile));
    p->info = x;
    p->suiv = *sommet;

    sommet = p;
}

int depiler(Pile **sommet)
{
    if (*sommet == NULL)
        printf("E R R E U R ! LA PILE EST VIDE");
    else
    {
        Pile *p = *sommet;
        p1 = p->info;

        sommet = p->suiv;

        free(p);
        printf("\nOPERATION SUCCESS\n");
        printf("VALEUR depilerILEE :%d\n", char_to_int(p1));
        return p1;
    }
}

void saisie(char t[1])
{
    char c;
    int j1 = 0;

    do
    {
        c = getch();
        if (((c >= '0') && (c <= '9')) || ((c == '*') || (c == '-') || (c == '+') || (c == '/')))
        {
            if ((c >= '0') && (c <= '9'))
            {
                j1++; // comptabilise les caracteres entre '0' et '9'
                if (j1 > 2)
                    printf("ACTION NON AUTORISEE\n");
                else
                {
                    t[i] = c;
                    printf("%c\n", t[i]);
                    i++;
                }
            }

            if ((c == '*') || (c == '-') || (c == '+') || (c == '/'))
            {
                j1 = 0;
                t[i] = c;
                printf("%c\n", t[i]);
                i++;
            }
        }
    } while (c != 13);
}

void VISU(Pile *sommet)
{
    if (sommet != NULL)
    {
        Pile *p = sommet;
        while (p)
        {
            printf("%c ->", p->info);
            p = p->suiv;
        }
    }
    else{
        printf("il faut rempiler avant");
    }
}

void Traitement(char t[1])
{
    int k, k1, code2 = 0, code1 = 0, resultat = 0;

    char c;
    for (k = 0; k < i; k++)
    {
        if ((t[k] >= '0') && (t[k] <= '9'))
            empiler(t[k], &sommet);

        if ((t[k] == '*') || (t[k] == '-') || (t[k] == '+') || (t[k] == '/'))
        {
            k1 = 1;
            while ((sommet != NULL) && (k1 >= 0)) 
            {
                depiler(&sommet);
                tempo[k1] = p1;
                k1--;
            }
            code1 = char_to_int(tempo[0]);
            code2 = char_to_int(tempo[1]);

            switch (t[k])
            {
            case '+':
                resultat = code1 + code2;
                printf("%d+%d=%d\n", code1, code2, resultat);
                break;
            case '-':
                resultat = code1 - code2;
                printf("%d-%d=%d\n", code1, code2, resultat);
                break;
            case '*':
                resultat = code1 * code2;
                printf("%d*%d=%d\n", code1, code2, resultat);
                break;
            case '/':
                resultat = code1 / code2;
                printf("%d/%d=%d   il s'agit d'une division enti?re\n", code1, code2, resultat);
                break;
            }

            empiler(int_to_char(resultat), &sommet);
        }
    }
}
void main()
{
    clrscr();
    saisie(ch);
    Init(&sommet);
    Traitement(ch);
    getch();
}