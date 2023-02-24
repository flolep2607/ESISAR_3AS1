/*********************************************************************/
/* Realisation d'une liste chainee dans un tableau                   */
/* ioannis.parissis@grenoble-inp.fr                                  */
/* Sep 2012                                                          */
/*********************************************************************/
#include "listeTableau.h"


int elementLibre(liste l){
	int i=1;
	while(l[i].suivant!=-1)
		i++;
	return i;
}

void creerListeVide(liste l){
	l[0].suivant=0;
	for(int i=1; i<TAILLEMAX; i++)
		l[i].suivant=-1;
}
/* void insererElement(int x, liste l){
	int i=l[0].suivant;
	if(i==0){
		l[0].suivant=1;
		l[1].suivant=0;
		l[1].valeur=x;
		return;
	}
	
	while(x>l[i].valeur && l[i].suivant!=0)
		i=l[i].suivant;
		
	if(x==l[i].valeur) return; // Si on veut gérer les doublons
	int insert = elementLibre(l);
	printf("insert %d at %d\n",x,insert);
	if(x>l[i].valeur){
		l[insert].valeur = x;
		l[insert].suivant = 0;
		l[i].suivant = insert;
	}else{
		l[insert].valeur = l[i].valeur;
		l[insert].suivant = l[i].suivant;
		l[i].valeur = x;
		l[i].suivant = insert;
	}
} */
void insererElement(int x, liste l){
	int i=l[0].suivant;
	int preced=0;
	if(i==0){
		l[0].suivant=1;
		l[1].suivant=0;
		l[1].valeur=x;
		return;
	}
	
	while(x>l[i].valeur && l[i].suivant!=0){
		preced=i;
		i=l[i].suivant;
	}
		
	if(x==l[i].valeur) return; // Si on veut gérer les doublons
	int insert = elementLibre(l);
	if(x>l[i].valeur){
		l[insert].valeur = x;
		l[insert].suivant = 0;
		l[i].suivant = insert;
	}else{
		l[insert].valeur = x;
		l[insert].suivant = i;
		l[preced].suivant = insert;
	}
}

void supprimerElement(int x, liste l){
	int i=l[0].suivant;
	int precedent=0;
	while(l[i].valeur!=x && l[i].suivant!=0){
		precedent = i;
		i=l[i].suivant;
	}
	if(l[i].valeur == x){
		l[precedent].suivant = l[i].suivant;
		l[i].suivant = -1;
	}
}

void supprimerElement_i(int i, liste l){
	int cnt=0;
	int index=0;
	int precedent=0;
	while(cnt<i && l[index].suivant !=0) {
		cnt++;
		precedent=index;
		index=l[index].suivant;
	}
	if (cnt==i) {
		l[precedent].suivant = l[index].suivant;
		l[index].suivant = -1;
	}
}

void afficherListe(liste l){
	int i=l[0].suivant;
	int cnt = 1;
	while(i!=0){
		printf("Liste[%d]: %d, %d\n",cnt++,l[i].suivant,l[i].valeur);
		i=l[i].suivant;
	}
	printf("\n");
	
}

/* void compacterListe(liste l){
	int index_f = 0;//forward
	int index_b = TAILLEMAX-1;//backward
	while(index_f<index_b){
		printf("index_f:%d index_b:%d\n",index_f,index_b);
		if(l[index_f].suivant==-1){
//      Si l'index forward trouve un "trou"
			while(l[index_b].suivant==-1)
				index_b--;
//			On déplace l'index backward jusqu'à la dernière valeur indexée
			l[index_f].suivant = l[index_b].suivant;
			l[index_f].valeur = l[index_b].valeur;
//			On échange cette valeur avec le "trou"
			l[index_b].suivant = -1;
//			Puis on la déclare comme libre
		}
		index_f++;
	}
} */

void compacterListe(liste l){
	int i=l[0].suivant;
	int x;
	while(l[i].suivant!=0){
			// printf("l[%d]: v%d, s%d -> [%d]\n",i,l[i].valeur,l[i].suivant,l[l[i].suivant].valeur);
		x=l[l[i].suivant].valeur;
		supprimerElement(x, l);
		insererElement(x, l);
// Supprimer et insérer les élément premet de les replacer à l'index le plus petit
		i=l[i].suivant;
	}
}
