#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Client
{
    int numero;
    int prixAppel;
    int nbAppel;
    struct Client *gauche;
    struct Client *droite;

} client;

// Nombre total de lignes dans le fichier
#ifndef NBLOGLINE
#define NBLOGLINE 2000000
#endif
// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT 200000
#endif

// À une différence dans la structure près, toutes ces fonctions sont similaires aux fonctions du TDM1

// Fonction de création d'un client qui cette fois a 2 fils, car il s'agit d'un arbre binaire de recherche
client *creerClient(int numeroTel, int nbAppel, int cout)
{
    client *nouveau = (client *)malloc(sizeof(client));
    nouveau->numero = numeroTel;
    nouveau->nbAppel = nbAppel;
    nouveau->prixAppel = cout;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

// Fonction d'insertion d'un client dans l'arbre binaire de recherche
client *inserer(client **abr, int numeroTel, int prixAppel)
{
    client *start = *abr;
    bool end = false;
    while (start != NULL && !end)
    {
        if (start->numero == numeroTel)
        {
            start->nbAppel++;
            start->prixAppel += prixAppel;
            return *abr;
        }
        if (start->numero > numeroTel)
        {
            if (start->gauche == NULL)
            {
                start->gauche = creerClient(numeroTel, 1, prixAppel);
                return *abr;
            }
            start = start->gauche;
        }
        else
        {
            if (start->droite == NULL)
            {
                start->droite = creerClient(numeroTel, 1, prixAppel);
                return *abr;
            }
            start = start->droite;
        }
    }
    *abr = creerClient(numeroTel, 1, prixAppel);
    return *abr;
}
client *createSampleTree()
{
    client *abr = NULL;
    inserer(&abr, 15, 1);
    inserer(&abr, 12, 1);
    inserer(&abr, 8, 1);
    inserer(&abr, 10, 1);
    inserer(&abr, 14, 1);
    inserer(&abr, 13, 1);
    inserer(&abr, 20, 1);
    inserer(&abr, 16, 1);
    inserer(&abr, 17, 1);
    inserer(&abr, 21, 1);
    return abr;
}
client *chercher(client *abr, int numeroTel)
{
    if (abr == NULL)
        return NULL;
    if (abr->numero == numeroTel)
        return abr;
    if (abr->numero > numeroTel)
        return chercher(abr->gauche, numeroTel);
    return chercher(abr->droite, numeroTel);
}

// Fonction de suppression d'un client selon si il a 0, 1 ou 2 fils
client *supprimerClient(client **abr, int numeroTel)
{
    client *start = *abr;
    bool end = false;
    while (start != NULL && !end)
    {
        if (start->numero == numeroTel)
        {
            if (start->gauche == NULL)
                start = start->droite;
            else if (start->droite == NULL)
                start = start->gauche;
            else
            {
                start = start->droite;
                while (start->gauche != NULL)
                {
                    start = start->gauche;
                }
                start = start->droite;
            }
            return *abr;
        }
        else if (start->numero > numeroTel)
        {
            start = start->gauche;
        }
        else
        {
            start = start->droite;
        }
    }
    return *abr;
}

// Fonction qui permet de free l'allocation mémoire de l'arbre binaire de recherche
void purgeTree(struct Client * abr)
{
	if(abr){
		purgeTree(abr->gauche);
		purgeTree(abr->droite);
		free(abr);
	}
}

// Fonction de parcours infixe de l'arbre binaire de recherche
void parcourirInfixe(client *abr)
{
    if (abr == NULL)
    {
        return;
    }
    parcourirInfixe(abr->gauche);
    printf("Numéro : %d, Prix de l'Appel : %d, Nombre d'appels : %d\n", abr->numero, abr->nbAppel, abr->prixAppel);
    parcourirInfixe(abr->droite);
}

// Fonction principale de test
int main()
{
    client *liste = NULL;
    int i;
    int numeroTel;
    int prixAppel;

    // Aide au calcul du pourcentage d'avancement
    int pas = NBLOGLINE / 100;
    for (i = 0; i < NBLOGLINE; i++)
    {
        // Génération d'un numéro de telephone portable
        numeroTel = 600000000 + (rand() % NBCLIENT);

        // Donne un prix d'appel compris entre 0.01 et 4 euros
        prixAppel = (rand() % 400) + 1;

        // Ajout de cette ligne de log dans la liste des clients
        if (inserer(&liste, numeroTel, prixAppel) == NULL)
            break;

        // Affichage du pourcentage d'avancement
        if ((i % pas) == 0)
        {
            printf("Done  = %d %%...\n", i / pas);
        }
    }

    printf("****** Facturation appels telephoniques ******\n");

    parcourirInfixe(liste);

    printf("****** Suppression de la facturation appels telephoniques ******\n");

    // Puisque nous utilisons une fonction qui permet de free l'arbre, nous n'avons pas besoin de supprimer les clients un par un

    // for (i = 0; i < NBCLIENT; i++)
    // {
    //     client *tmp = NULL;
    //     printf("Suppression du pingas %d\n", i);
    //     if ((tmp = supprimerClient(&liste, 600000000 + i)) != NULL)
    //     {   
    //         free(tmp);
    //     }
    // }

    purgeTree(liste);
    
    printf("****** Fin Facturation appels telephoniques ******\n");
}
