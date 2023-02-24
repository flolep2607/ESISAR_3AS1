#include <stdio.h>
#include "listePointeur.h"

void creerListeVide(liste* l){
	(*l) = NULL;
}

void afficherListe(liste* l){
	if ((*l) != NULL){
		printf("[%d],",(*l)->valeur);
		afficherListe(&(*l)->suivant);
	} else
		printf("\b \n");
}


void insererElement(int x, liste* l){
	if((*l)==NULL){
		printf("Liste vide\n");
		(*l) = (element*) malloc(sizeof(element)) ;
		(*l)->suivant=NULL;
		(*l)->valeur=x;
	} 
	else {		
		if ((*l)->valeur > x){
			element *e = (element* ) malloc(sizeof(element)) ;
			e->valeur = (*l)->valeur;
			(*l)->valeur = x;
			e->suivant = (*l)->suivant;
			(*l)->suivant = e;
		} 
		else if ((*l)->suivant == NULL) {
			element *e = (element* ) malloc(sizeof(element)) ;
			e->valeur = x;
			e->suivant = NULL;
			(*l)->suivant = e;
		}
		else insererElement( x, &(*l)->suivant);
	}
}

/* Supprime le i-eme element de la liste (sachant que le premier indice est 1) */
void supprimerElement(int i, liste *l){
	if(i > 2)
		/*if ((*l)->suivant != NULL)*/ supprimerElement(i-1, &(*l)->suivant);
		// else printf("liste trop courte\n");
	else if (i==2){
		if ( (*l)->suivant == NULL)
			printf("liste trop courte\n");
		else{
			liste tmp = (*l)->suivant->suivant;
			free ((*l)->suivant);
			(*l)->suivant = tmp;
		}
	}else{
		liste tmp = (*l);
		(*l)=(*l)->suivant;
		free(tmp);
	}
}

void supprimerListe(liste *l){
	liste tmp;
	while((*l)!=NULL){
		tmp = (*l);
		(*l)=(*l)->suivant;
		free(tmp);
	}
}

/*void insererElement(int x, liste l){	
	if(l==NULL){
		l = (element* ) malloc(sizeof(element)) ;
		l.suivant=NULL;
		l.valeur=x;
		return;
	}
	element* preced;
	while(x>l.valeur && l.suivant!=NULL){
		preced=l;
		l=l.suivant;
	}
		
	if(x==l.valeur) return; // Si on veut gérer les doublons
	
	element *e = (element* ) malloc(sizeof(element)) ;
	e->valeur = x;
	
	if(x>l.valeur){
		l.suivant = e;
	}else{
		e.suivant = l;
		preced.suivant = e;
	}
}*/


