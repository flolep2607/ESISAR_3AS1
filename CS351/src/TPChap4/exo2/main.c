#include "module.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char * argv[])
{
    char * string="jeSuisla";
    char string_copied[10];
    printf("len:%lu\n",mystrlen(string));
    mystrcpy(string_copied,string);
    printf("len copied:%lu\n",mystrlen(string_copied));
    affichageenhexa(string_copied);
    affichageenint(string_copied);
    printf("%s\n",string);
    char * SS =mettreenmajuscule(string);
    char * ss =mettreenminuscule(SS);
    char * Ss =transformerminmaj(string);
    char * se = retournermot(string);
    int position = recherchercaractereg(string,'s');
    printf("%s\n",SS);
    printf("%s\n",ss);
    printf("%s\n",Ss);
    printf("%s\n",se);
    printf("%d\n",position);
    printf("%d\n",valeurdecimale("49"));
    intverschaine(696,string_copied);
    printf("%s\n",string_copied);
}