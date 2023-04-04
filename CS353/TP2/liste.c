#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Client {
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
#define NBCLIENT 2000000
#endif

client *creerClient(int numeroTel, int nbAppel, int cout) {
    client *nouveau = (client *)malloc(sizeof(client));
    nouveau->numero = numeroTel;
    nouveau->nbAppel = nbAppel;
    nouveau->prixAppel = cout;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

client *inserer(client **abr, int numeroTel, int prixAppel) {
    client *start = *abr;
    bool end = false;
    while (start != NULL && !end) {
        if (start->numero == numeroTel) {
            start->nbAppel++;
            start->prixAppel += prixAppel;
            return *abr;
        }
        if (start->numero > numeroTel) {
            if (start->gauche == NULL) {
                start->gauche = creerClient(numeroTel, 1, prixAppel);
                return *abr;
            }
            start = start->gauche;
        } else {
            if (start->droite == NULL) {
                start->droite = creerClient(numeroTel, 1, prixAppel);
                return *abr;
            }
            start = start->droite;
        }
    }
    *abr = creerClient(numeroTel, 1, prixAppel);
    return *abr;
}
client *createSampleTree() {
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
client *chercher(client *abr, int numeroTel) {
    if (abr == NULL) return NULL;
    if (abr->numero == numeroTel) return abr;
    if (abr->numero > numeroTel) return chercher(abr->gauche, numeroTel);
    return chercher(abr->droite, numeroTel);
}

client *supprimerClient(client **abr, int numeroTel) {
    client *start = *abr;
    bool end = false;
    while (start != NULL && !end) {
        if (start->numero == numeroTel) {
            if (start->gauche == NULL) start = start->droite;
            else if (start->droite == NULL) start = start->gauche;
            else {
                client *tmp = start;
                start = start->droite;
                while (start->gauche != NULL) {
                    start = start->gauche;
                }
                tmp=start;
                start=start->droite;
            }
            return *abr;
        } else if (start->numero > numeroTel) {
            start = start->gauche;
        } else {
            start = start->droite;
        }
    }
    return *abr;
}

void parcourirInfixe(client *abr) {
    if (abr == NULL) return;
    parcourirInfixe(abr->gauche);
    // printf("Numero : %d, nbAppel : %d, prixAppel : %d\n", abr->numero, abr->nbAppel, abr->prixAppel);
    parcourirInfixe(abr->droite);
}

int main() {
    client *liste = NULL;
    // liste=createSampleTree();
    // parcourirInfixe(liste);
    // return 0;
    int i;
    int numeroTel;
    int prixAppel;

    // Aide au calcul du pourcentage d'avancement
    int pas = NBLOGLINE / 100;
    for (i = 0; i < NBLOGLINE; i++) {
        // Génération d'un numéro de telephone portable
        numeroTel = 600000000 + (rand() % NBCLIENT);

        // Donne un prix d'appel compris entre 0.01 et 4 euros
        prixAppel = (rand() % 400) + 1;

        // Ajout de cette ligne de log dans la liste des clients
        if (inserer(&liste, numeroTel, prixAppel) == NULL) break;

        // Affichage du pourcentage d'avancement
        if ((i % pas) == 0) {
            printf("Done  = %d %%...\n", i / pas);
        }
    }

    printf("****** Facturation appels telephoniques ******\n");

    parcourirInfixe(liste);

    printf("****** Suppression de la facturation appels telephoniques ******\n");

    for (i = 0; i < NBCLIENT; i++) {
        client *tmp = NULL;
        if ((tmp = supprimerClient(&liste, 600000000 + i)) != NULL) {
            free(tmp);
        }
    }
    printf("****** Fin Facturation appels telephoniques ******\n");
}
