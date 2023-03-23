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
#define NBLOGLINE 1000000
#endif
// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT 20000
#endif

struct Client *creerClient(int numeroTel, int nbAppel, int cout) {
    client *nouveau = (client *)malloc(sizeof(client));
    nouveau->numero = numeroTel;
    nouveau->nbAppel = nbAppel;
    nouveau->prixAppel = cout;
    nouveau->gauche = NULL;
    nouveau->droite = NULL;
    return nouveau;
}

struct Client *createSampleTree() {
    client *abr = creerClient(10, 1, 10);
    inserer(&abr, 5, 5);
    return abr;
}
struct Client *chercher(struct Client *abr, int numeroTel) {
    if (abr == NULL) return NULL;
    if (abr->numero == numeroTel) return abr;
    if (abr->numero > numeroTel) return chercher(abr->gauche, numeroTel);
    return chercher(abr->droite, numeroTel);
}

struct Client *inserer(struct Client **abr, int numeroTel, int prixAppel) {
    if (*abr == NULL) {
        *abr = creerClient(numeroTel, 1, prixAppel);
        return *abr;
    }
    if ((*abr)->numero == numeroTel) {
        (*abr)->nbAppel++;
        (*abr)->prixAppel += prixAppel;
        return *abr;
    }
    if ((*abr)->numero > numeroTel) return inserer(&((*abr)->gauche), numeroTel, prixAppel);
    return inserer(&((*abr)->droite), numeroTel, prixAppel);
}

struct Client *supprimerClient(struct Client **abr, int numeroTel) {
    if (*abr == NULL) return NULL;
    if ((*abr)->numero == numeroTel) {
        client *tmp = *abr;
        if ((*abr)->gauche == NULL) {
            *abr = (*abr)->droite;
        } else {
            client *tmp2 = *abr;
            *abr = (*abr)->gauche;
            inserer(abr, tmp2->droite->numero, tmp2->droite->prixAppel);
        }
        return tmp;
    }
    if ((*abr)->numero > numeroTel) return supprimerClient(&((*abr)->gauche), numeroTel);
    return supprimerClient(&((*abr)->droite), numeroTel);
}

void parcourirInfixe(struct Client *abr) {
    if (abr == NULL) return;
    parcourirInfixe(abr->gauche);
    parcourirInfixe(abr->droite);
}

int main() {
    client *liste = NULL;

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
