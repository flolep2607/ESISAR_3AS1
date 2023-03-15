#include <stdio.h>
#include <stdlib.h>

typedef struct Client {
    unsigned numero;
    unsigned prixAppel;
    unsigned nbAppel;
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

struct Client *createClient(unsigned numero, unsigned nbAppel, unsigned prixAppel) {
     struct Client *client = malloc(sizeof(struct Client));
     client->numero = numero;
     client->nbAppel = nbAppel;
     client->prixAppel = prixAppel;
     client->suivant = NULL;
     return client;
}

struct Client* addLogLine(struct Client **liste, unsigned numero, unsigned prixAppel) {
     struct Client *client = *liste;
     struct Client *precedent = NULL;
     while (client != NULL && numero > client->numero) {
          precedent = client;
          client = client->suivant;
     }
     if (client != NULL && client->numero == numero) {
          client->nbAppel++;
          client->prixAppel += prixAppel;
     }else{
          struct Client *newClient = createClient(numero, 1, prixAppel);
          if (precedent == NULL) {
               newClient->suivant = *liste;
               *liste = newClient;
          } else {
               precedent->suivant = newClient;
          }
     }
     return *liste;
}

void dumpListe(struct Client *liste) {
     struct Client *client = liste;
     while (client != NULL)
     {
          printf("Numéro : %d, Prix de l'Appel : %d, Nombre d'appels : %d\n", client->numero, client->prixAppel, client->nbAppel);
          struct Client * tmp = client;
          client = tmp->suivant;
          // free(tmp);
     }
}

int main() {
    client *liste = NULL;

    int i;
    unsigned numeroTel;
    unsigned prixAppel;

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
