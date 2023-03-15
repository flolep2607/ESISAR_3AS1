#include <stdio.h>
#include <stdlib.h>

typedef struct Client {
    int numero;
    int prixAppel;
    int nbAppel;
    struct Client *suivant;
} client;

// Nombre total de lignes dans le fichier
#ifndef NBLOGLINE
#define NBLOGLINE 200000
#endif

// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT 20000
#endif

struct Client *createClient(int numero, int nbAppel, int prixAppel) {
     struct Client *client = malloc(sizeof(struct Client));
     client->numero = numero;
     client->nbAppel = nbAppel;
     client->prixAppel = prixAppel;
     client->suivant = NULL;
     return client;
}

struct Client* addLogLine(struct Client **liste, int numero, int prixAppel) {
     struct Client *client = *liste;
     struct Client *precedent = NULL;
     struct Client *newClient = NULL;
     while (client != NULL && client->numero <= numero) {
          precedent = client;
          client = client->suivant;
     }
     if (client != NULL && client->numero == numero) {
          client->nbAppel++;
          client->prixAppel += prixAppel;
          newClient = client;
     }else{
          newClient = createClient(numero, 1, prixAppel);
          if (precedent == NULL) {
               *liste = newClient;
          } else {
               precedent->suivant = newClient;
          }
     }
     return newClient;
}

void dumpListe(struct Client *liste) {
}

int main() {
    client *liste = NULL;

    int i;
    int numeroTel;
    int prixAppel;

    // Aide au calcul du pourcentage d'avancement
    int pas = NBLOGLINE / 100;

    printf("****** Facturation appels telephoniques ******\n");

    for (i = 0; i < NBLOGLINE; i++) {
        // Génération d'un numéro de telephone portable
        numeroTel = 600000000 + (rand() % NBCLIENT);

        // Donne un prix d'appel compris entre 0.01 et 4 euros
        prixAppel = (rand() % 400) + 1;

        // Ajout de cette ligne de log dans la liste des clients
        if (!addLogLine(&liste, numeroTel, prixAppel)) break;
        //
        // printf("numero=%d prix = %d\n",numeroTel,prixAppel);

        // Affichage du pourcentage d'avancement
        if ((i % pas) == 0) {
            printf("Done  = %d %%...\n", i / pas);
        }
    }

    dumpListe(liste);
    printf("======= Facturation appels telephoniques ======\n");

    return 0;
}
