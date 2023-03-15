#include <stdlib.h> 
#include <stdio.h> 

typedef struct Client { 
	int numero; 
	int prixAppel; 
	int nbAppel; 
	struct Client * gauche;
	struct Client * droite;
 
} client; 

// Nombre total de lignes dans le fichier
#ifndef NBLOGLINE
#define NBLOGLINE    1000000
#endif
// Nombre de clients
#ifndef NBCLIENT
#define NBCLIENT    20000
#endif


struct Client * creerClient(int numeroTel, int nbAppel,int cout)
{
}

struct Client * chercher(struct Client * abr,int numeroTel)
{
}

struct Client *inserer(struct Client ** abr, int numeroTel, int prixAppel)
{
}

struct Client *supprimerClient(struct Client ** abr, int numeroTel)
{
}


void parcourirInfixe(struct Client * abr)
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
    for(i=0;i<NBLOGLINE;i++)
    {

        // Génération d'un numéro de telephone portable
        numeroTel = 600000000+(rand() % NBCLIENT);

        // Donne un prix d'appel compris entre 0.01 et 4 euros
        prixAppel = (rand() % 400)+1;

        // Ajout de cette ligne de log dans la liste des clients
   	if (inserer(&liste ,numeroTel,prixAppel)==NULL) break; 

        // Affichage du pourcentage d'avancement
        if ((i % pas)==0)
        {
             printf("Done  = %d %%...\n",i/pas);
        }
    }

    printf("****** Facturation appels telephoniques ******\n");

    parcourirInfixe(liste);

    printf("****** Suppression de la facturation appels telephoniques ******\n");

    for (i=0;i<NBCLIENT;i++) {
	 client *tmp=NULL; 
	if ((tmp=supprimerClient(&liste,600000000+i)) != NULL) { free(tmp); }
    }
    printf("****** Fin Facturation appels telephoniques ******\n");    
}
 

