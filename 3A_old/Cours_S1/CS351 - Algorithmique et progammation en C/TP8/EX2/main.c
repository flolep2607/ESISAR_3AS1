#include <stdio.h>
#include "listePointeur.h"

void elem0(liste *l){
	(*l) = (liste) malloc(sizeof(element)) ;
	(*l)->valeur=0;
	(*l)->suivant=NULL;
}


int main() {
	
	liste L=NULL;
	creerListeVide(&L);
	// elem0(&L);
	
	// L = (liste) malloc(sizeof(element)) ;
	// L->valeur=1;
	// L->suivant=NULL;
	
	// liste e2 = (liste) malloc(sizeof(element)) ;
	// e2->valeur=2;
	// e2->suivant=NULL;
	// L->suivant=e2;
	
	afficherListe(&L);
	
	insererElement(1 , &L);
	afficherListe(&L);
	
	for (int i = 2; i<=10; i++) insererElement(i , &L);
	afficherListe(&L);
	
	supprimerElement(6 , &L);
	afficherListe(&L);
	
	supprimerElement(10 , &L);
	afficherListe(&L);
	
	insererElement(6 , &L);
	afficherListe(&L);
	
	printf("Exit:%d\n", 6); /* ce programme affiche 6 */
	
	supprimerListe(&L);
	
	return 0;
}