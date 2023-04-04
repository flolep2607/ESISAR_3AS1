#include <stdio.h>
#include <stdlib.h>

/* Lis des nombres entiers dans un fichier, séparé par `\n`.
   Renvoie le nombre d'entiers lu. */
int lireDonnees(char nomFichier[], int T[]);

/* Affiche sur une même ligne les élément d'un tableau d'entiers 
   de nb éléments séparé par ` `. */
void afficherTableau(int T[], int nb);

/* Trie un tableau d'entiers de nb éléments par ordre croissant. */
void triABulles(int T[], int nb);

/* écris dans le fichier nomFichier tous les éléments du tableau T de taille nb
   séparé par des `\n`*/
void enregistrerDonnees(char nomFichier[], int T[], int nb);