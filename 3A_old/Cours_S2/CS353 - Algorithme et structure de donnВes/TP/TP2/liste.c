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
	client * nouveau = malloc( sizeof(client) );
	nouveau->numero=numeroTel;
	nouveau->nbAppel=nbAppel;
	nouveau->prixAppel=cout;
	nouveau->gauche=NULL;
	nouveau->droite=NULL;
	return nouveau;
}

struct Client * chercher(struct Client * abr,int numeroTel)
{
	while( !(abr==NULL || numeroTel==abr->numero) ){
		if( numeroTel > abr->numero)
			abr = abr->droite;
		else
			abr = abr->gauche;
	}
	//On dit que la fonction return NULL si le numero n'est pas trouvé
	return abr;
}

struct Client *inserer(struct Client ** abr, int numeroTel, int prixAppel)
{
	if (*abr==NULL){
		(*abr)=creerClient(numeroTel,1,prixAppel);
	} else {
		client *ptr = *abr;
		client *suiv = ptr;
		do {
			ptr = suiv;
			if( numeroTel > ptr->numero)
				suiv = ptr->droite;
			else
				suiv = ptr->gauche;
		}while( !(suiv==NULL || numeroTel==ptr->numero) );
		
		if(numeroTel==ptr->numero){
			ptr->nbAppel += 1;
			ptr->prixAppel += prixAppel;
		}else{
			suiv = creerClient(numeroTel,1,prixAppel);
			if( numeroTel > ptr->numero)
				ptr->droite = suiv;
			else
				ptr->gauche = suiv;
		}
	}
	return *abr ;
}

struct Client *supprimerClient(struct Client ** abr, int numeroTel)
{
	if(!abr) return *abr ;
	
	client *ptr = *abr;
	client *preced;
	
	while( !(ptr==NULL || numeroTel==ptr->numero) ){
		preced = ptr;
		if( numeroTel > ptr->numero)
			ptr = ptr->droite;
		else
			ptr = ptr->gauche;
	}
	
	// Cas element non trouvé
	if(ptr==NULL) return *abr; 
	
	if(numeroTel==ptr->numero) {
		//Cas 0 fils
		if( !(ptr->gauche || ptr->droite)){
			//Cas suppr racine
			if(ptr==preced){
				*abr = NULL;
			} else {
				if( numeroTel > preced->numero)
					preced->droite=NULL;
				else
					preced->gauche=NULL;
			}
			free(ptr);
		}
		//Cas 2 fils
		else if(ptr->gauche && ptr->droite){
			client *tmp= ptr->droite;
			while(tmp->gauche) tmp = tmp->gauche;
			int num       = tmp->numero;
			ptr->prixAppel= tmp->prixAppel;
			ptr->nbAppel  = tmp->nbAppel;
			supprimerClient(&(ptr),num);
			ptr->numero   = num;
		}
		//Cas 1 fils
		else {
			client* tmp;
			if(ptr->gauche)
				tmp = ptr->gauche;
			else 
				tmp = ptr->droite;
			ptr->numero   = tmp->numero;
			ptr->prixAppel= tmp->prixAppel;
			ptr->nbAppel  = tmp->nbAppel;
			ptr->gauche   = tmp->gauche;
			ptr->droite   = tmp->droite;
			free(tmp);
		}
	}
	return *abr ;
}

struct Client *CreateSampleTree(){
	client *racine = creerClient(15,0,0);
		racine->gauche = creerClient(12,0,0);
			racine->gauche->gauche = creerClient(8,0,0);
				racine->gauche->gauche->droite = creerClient(10,0,0);
			racine->gauche->droite = creerClient(14,0,0);
				racine->gauche->droite->gauche = creerClient(13,0,0);
		racine->droite = creerClient(20,0,0);
			racine->droite->gauche = creerClient(16,0,0);
				racine->droite->gauche->droite = creerClient(17,0,0);
			racine->droite->droite = creerClient(21,0,0);
	return racine;
}

void parcourirInfixe(struct Client * abr)
{
	if(abr){
		parcourirInfixe(abr->gauche);
		printf("%d: %d\n",abr->numero, abr->nbAppel);
		parcourirInfixe(abr->droite);
	}
}	

void purgeTree(struct Client * abr)
{
	if(abr){
		purgeTree(abr->gauche);
		purgeTree(abr->droite);
		free(abr);
	}
}


void test_Q3(){
	printf("-- Test parcours infixe --\n");
	client*root = CreateSampleTree();
	parcourirInfixe(root);
	purgeTree(root);
	printf("--------------------------\n");
}

void test_Q4(){
	printf("-- Test Chercher Noeud ---\n");
	client *noeud,*root = CreateSampleTree();
	if((noeud = chercher(root,13)))
		printf("Noeud [%d]: %d\n",noeud->numero,noeud->prixAppel);
	purgeTree(root);
	printf("--------------------------\n");
}

void test_Q5(){
	printf("-- Test Inserer Noeud ----\n");
	client *root = CreateSampleTree();
	printf("Tree Before insertions\n");
	parcourirInfixe(root);
	printf(" insertion: 22 (Cas feuille)\n");
	inserer(&root,22,0);
	printf(" insertion: 20 (Cas déjà existant)\n");
	inserer(&root,20,0);
	printf("Tree After insertions\n");
	parcourirInfixe(root);
	printf("--------------------------\n");
}

void test_Q6(){
	printf("-- Test Supprimer Noeud --\n");
	client *root = CreateSampleTree();
	printf("Tree Before suppressions\n");
	parcourirInfixe(root);
	printf(" suppression: 10 (Cas 0 fils)\n");
	supprimerClient(&root,10);
	printf(" suppression: 16 (Cas 1 fils)\n");
	supprimerClient(&root,16);
	printf(" suppression: 20 (Cas 2 fils)\n");
	supprimerClient(&root,20);
	printf(" suppression: 15 (Cas racine)\n");
	supprimerClient(&root,15);
	printf("Tree After suppressions\n");
	parcourirInfixe(root);
	printf("--------------------------\n");
}

int main_test(){
	test_Q3();
	test_Q4();
	test_Q5();
	test_Q6();
}

int main() {
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
             printf("Done  = %02d %%...\r",i/pas);
        }
    }
	printf("\n");

    printf("****** Facturation appels telephoniques ******\n");

    parcourirInfixe(liste);

    printf("****** Suppression de la facturation appels telephoniques ******\n");

	/** J'ai commenté car il y a marqué dans le sujet que supprmierClient
		renvoie un pointeur vers la racine de l'arbre et comme le code 
		ci-dessous free cette racine, ça crée des problèmes.
		*/
    /*for (i=0;i<NBCLIENT;i++) {
	 client *tmp=NULL; 
	if ((tmp=supprimerClient(&liste,600000000+i)) != NULL) { free(tmp); }
    }*/
	purgeTree(liste);
    printf("****** Fin Facturation appels telephoniques ******\n");    
}
 

