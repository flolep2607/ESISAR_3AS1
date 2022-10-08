#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

size_t mystrlen(const char *s);
char *mystrcpy(char *dest, const char *src);
void affichageenhexa(char *string);
void affichageenint(char *string);
char * mettreenmajuscule(char *string);
char * mettreenminuscule(char *string);
char * transformerminmaj(char *string);
char * retournermot(char *string);
int recherchercaractereg(char *string,char caract);
int recherchercaractered(char *string,char caract);
int estpalindrome(char *string,int f,int d);
int comparerchaine(char *string1,char *string2);
int valeurdecimale(char *string);
void intverschaine(int value,char *string);
