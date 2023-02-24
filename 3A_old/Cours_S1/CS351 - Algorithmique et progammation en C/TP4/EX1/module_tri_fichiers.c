#include "module_tri_fichiers.h"

int lireDonnees(char nomFichier[], int T[]){
	
	FILE *fichier;
	fichier = fopen(nomFichier, "r");
	if(fichier == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}
	
	int nombre;
	int i=0;
	while(!feof(fichier)) {
		fscanf(fichier, "%d", &nombre);
		printf("Valeur lue = %d\n", nombre) ;
		T[i++]=nombre;
	}
	
	
	fclose(fichier);
	
	return i;
}

void afficherTableau(int T[], int nb){
	
	for(int i=0; i<nb; i++)
		printf("%d ",T[i]);
	printf("\n");
	
}

void triABulles(int T[], int nb){
	
	_Bool Trie;//crée un booléen qui passera à 1 quand le tableau sera trié
	
	for(int i=nb; i>=1; i--){//l'index i remonte le tableau en partant du bas
		Trie=1;
		for(int j=0; j<i-1; j++){//l'index j descent le tableau de 0 à i
			if( T[j+1] < T[j] ){
				int tmp = T[j+1];
				T[j+1] = T[j];
				T[j] = tmp;
				Trie=0;//si un échange à lieu le booléen passe à 0 car le tableau n'est peut-être pas trié
			}
			nb++;
		}
		if(Trie==1){
			return;//si il n'y a eu aucun changement, la liste est trié, donc on arrête
		}
	}
	
}

void enregistrerDonnees(char nomFichier[], int T[], int nb){
	
	FILE *fichier;
	fichier = fopen(nomFichier, "w");
	if(fichier == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}
	
	for(int i = 0 ; i < nb ; i++)
		fprintf(fichier, "%d\n", T[i]);
	
	fclose(fichier);
	
}
