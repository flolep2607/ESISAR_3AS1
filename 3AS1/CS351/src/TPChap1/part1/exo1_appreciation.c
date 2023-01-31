#include <stdio.h>

void note1(char note)
{
    if (note == 'A')
    {
        printf("Très bien\n");
    }
    else
    {
        if (note == 'B')
        {
            printf("Bien\n");
        }
        else
        {
            if (note == 'C')
            {
                printf("Assez Bien\n");
            }
            else
            {
                if (note == 'D')
                {
                    printf("Passable\n");
                }
                else
                {
                    if (note == 'E')
                    {
                        printf("Insuffisant\n");
                    }
                }
            }
        }
    }
}
void note2(char note)
{
    if (note == 'A')
    {
        printf("Très bien\n");
    }
    if (note == 'B')
    {
        printf("Bien\n");
    }
    if (note == 'C')
    {
        printf("Assez Bien\n");
    }
    if (note == 'D')
    {
        printf("Passable\n");
    }
    if (note == 'E')
    {
        printf("Insuffisant\n");
    }
}
void note3(char note)
{
    switch (note)
    {
    case 'A':
        printf("Très bien\n");
        break;
    case 'B':
        printf("Bien\n");
        break;
    case 'C':
        printf("Assez Bien\n");
        break;
    case 'D':
        printf("Passable\n");
        break;
    case 'E':
        printf("Insuffisant\n");
        break;
    default:
        break;
    }
}
int main()
{
    char note='\0';
    printf("Merci de rentrer une note:");
    scanf("%c", &note);
    note1(note);
    note2(note);
    note3(note);
    return 0;
}
