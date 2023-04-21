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
#define NBLOGLINE 2000000
#endif

// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT 20000
#endif

// Toutes ces fonctions sont des fonctions classiques de gestion d'une liste chainée

// Fonction qui permet de créer une nouvelle structure Client
struct Client *createClient(unsigned numero, unsigned nbAppel, unsigned prixAppel) {
     struct Client *client = malloc(sizeof(struct Client));
     client->numero = numero;
     client->nbAppel = nbAppel;
     client->prixAppel = prixAppel;
     client->suivant = NULL;
     return client;
}

// Fonction qui permet d'ajouter une ligne de log dans la liste des clients et de créer le client s'il n'est pas déjà enregistré
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
               if(client != NULL){
                    newClient->suivant = client;
               }
               precedent->suivant = newClient;
          }
     }
     return *liste;
}

// Fonction qui permet d'afficher la liste des clients
void dumpListe(struct Client *liste) {
     struct Client *client = liste;
     struct Client * tmp=NULL;
     while (client != NULL)
     {
          printf("Numéro : %d, Prix de l'Appel : %d, Nombre d'appels : %d\n", client->numero, client->prixAppel, client->nbAppel);
          tmp = client;
          client = tmp->suivant;
          free(tmp);
     }
}

// Fonction principale qui permet de tester les fonctions
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
