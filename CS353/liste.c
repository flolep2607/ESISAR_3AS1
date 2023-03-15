#include <stdlib.h> 
#include <stdio.h> 

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

struct Client *createClient(int numero, int nbAppel, int prixAppel) 
{
	
}

int addLogLine(struct Client **liste, int numero, int prixAppel) 
{

	
}

void dumpListe(struct Client *liste) 
{
}	


int main() 
{
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
   	if (!addLogLine(&list ,numeroTel,prixAppel)) break; 
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

   return 0;
}


 

