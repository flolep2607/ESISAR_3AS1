#include <stdlib.h>
#include <stdio.h>

typedef struct {
int valeur ;
int suivant ;
} element ;

typedef element* liste;

int elementLibre(liste l){
	
}

void creerListeVide(liste l){
	liste *L;
	element *premier;
	L[0] = premier;
}

void afficherListe(liste l){
	int size = sizeof(l)/sizeof(l[0]);
	printf("(");
	for (int i = 0; i < size; i++)
	{
		printf("%d; ", l[i].valeur);
	}
	printf(")\n");
}

void insererElement(int x, liste l){
	
}

void supprimerElement(int i, liste l){

}

int main(){
	element premier;
	premier.valeur = 6;
	element deuxieme;
	deuxieme.valeur = 7;
	premier.suivant = deuxieme.valeur;
	deuxieme.valeur = 0;
	liste *l_test;
	l_test[0]->valeur = premier.valeur;
	l_test[0]->suivant = premier.suivant;
	l_test[1]->valeur = deuxieme.valeur;
	l_test[1]->suivant = deuxieme.suivant;
	afficherListe(*l_test);
}