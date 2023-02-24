#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Client { 
	int numero; 
	int prixAppel; 
	int nbAppel; 
	struct Client * suivant; 
} client;

// Nombre total de lignes dans le fichier
#ifndef NBLOGLINE
#define NBLOGLINE    200000
#endif

// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT    20000
#endif

//Creation d'un nouveau client
client *createClient(int numero, int nbAppel, int prixAppel) {
	client *NewClient = malloc(sizeof(client));
	NewClient->numero = numero;
	NewClient->nbAppel = nbAppel;
	NewClient->prixAppel = prixAppel;
	return NewClient;
}

//Update les log
int addLogLine(struct Client **liste, int numero, int prixAppel) {
	client *ptr = *liste;
	client *ptr_prec = NULL;

	while(ptr != NULL && ptr->numero < numero){	//Tant qu'on est "avant" le numero recherche
		ptr_prec = ptr;
		ptr = ptr->suivant;	//passage a l'element suivant
	}

	if(ptr_prec == NULL){	//Insertion en tete
		client *NewClient = createClient(numero, 1, prixAppel);	//Creation d'un client qui a passe un appel
		*liste = NewClient;	//Tete[liste] = NewClient
		NewClient->suivant = ptr;
		return 1;
	}
	if (ptr == NULL || ptr->numero > numero){	//Insertion en milieu ou fin de liste
		client *NewClient = createClient(numero, 1, prixAppel);
		ptr_prec->suivant = NewClient;
		NewClient->suivant = ptr;
	}
	/*if (ptr->numero == numero)*/else{	//le numero existe dans la liste de logs: update du log
		ptr->nbAppel++;
		ptr->prixAppel += prixAppel;
	}
	return 1;
}

//Affich tous la liste de log. Pour chaque client, affiche son numero, le prix total de ses appels et son nombre d'appels
void dumpListe(struct Client *liste) {
	client *ptr = liste;
	while (ptr != NULL){
		printf("numero:%d prixAppel:%d nbAppel:%d\n", ptr->numero, ptr->prixAppel, ptr->nbAppel);
		ptr = ptr->suivant;
	}
}

//Free tous les clients créés
void freeEverything(struct Client *liste){
	if (liste==NULL){
		return;
	}
	freeEverything(liste->suivant);
	free(liste);
}

int main() {
    client *liste=NULL;

    int i;
    int numeroTel;
    int prixAppel;

    // Aide au calcul du pourcentage d'avancement
    int pas = NBLOGLINE/100;

    printf("****** Facturation appels telephoniques ******\n");


    for(i=0;i<NBLOGLINE;i++)
    {

        // Génération d'un numéro de telephone portable
        numeroTel = 600000000+(rand() % NBCLIENT);

        // Donne un prix d'appel compris entre 0.01 et 4 euros
        prixAppel = (rand() % 400)+1;

        // Ajout de cette ligne de log dans la liste des clients
   	if (!addLogLine(&liste,numeroTel,prixAppel)) break;
        //
        // printf("numero=%d prix = %d\n",numeroTel,prixAppel);


        // Affichage du pourcentage d'avancement
        if ((i % pas)==0)
        {
             printf("Done  = %d %%...\n",i/pas);
        }
	}

	dumpListe(liste);
	printf("======= Facturation appels telephoniques ======\n");
	freeEverything(liste);

	return 0;
}
