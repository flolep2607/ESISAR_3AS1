#include <stdio.h>
#include <assert.h>
#include "MatriceCreuse.h"

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

void creerMatriceVide(int nb_lignes, int nb_colones, matrice *M){
	(*M) = (matrice) malloc(sizeof(element));
	(*M)->index_colone = nb_colones;
	(*M)->index_ligne = nb_lignes;
	
	matrice tmp;
	matrice preced;
	/* Creation des indexs colone */
	preced = (*M);
	for(int i=0; i<nb_colones; i++){
		tmp = (matrice) malloc(sizeof(element));
		tmp->suivant_vertical = tmp;
		preced->suivant_horizontal = tmp;
		preced = tmp;
	} tmp->suivant_horizontal = *M;
	
	/* Creation des indexs ligne */
	preced = (*M);
	for(int i=0; i<nb_lignes; i++){
		tmp = (matrice) malloc(sizeof(element));
		tmp->suivant_horizontal = tmp;
		preced->suivant_vertical = tmp;
		preced = tmp;
	} tmp->suivant_vertical = *M;
}



int operation(char op, int x, int y){
	int result;
	switch(op){
		case '+': result = x + y; break; // add
		case '-': result = x - y; break; // substract
		case '*': result = x * y; break; // multiply
		case 'r': result = x; break;     // replace
	}
	return result;
}

void operationElement(int x,char op, int ligne, int colone, matrice M){
	assert(colone < M->index_colone && ligne < M->index_ligne);
	
	matrice ptr, ptelem, preced;

	/* On deplace un pointeur jusqu'a la ligne concerne */
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
		
	/* On cherche l'endroit ou inserer l'eleme*/
	ptelem = ptr->suivant_horizontal;
	preced = ptr;
	while(ptelem != ptr && colone > ptelem->index_colone){
		preced = ptelem;
		ptelem = ptelem->suivant_horizontal;
	}
	/* Si l'element existe deja */
	if(ptelem->index_colone == colone && ptelem->index_ligne == ligne && ptelem != ptr)
		ptelem->valeur = operation(op, x, ptelem->valeur);
		
	/* Sinon on continue */
	else {
	/* On cree le nouvel element a inserer */
		matrice insert = (element* ) malloc(sizeof(element));
		insert->index_colone = colone;
		insert->index_ligne = ligne;
		// On applique l'op pour y=0
		insert->valeur = operation(op, x, 0);
		
	/* On fait le link horizontal */
		preced->suivant_horizontal = insert;
		insert->suivant_horizontal = ptelem;	

	/* On refait la même chose pour le link vertical */
		ptr = M->suivant_horizontal;
		for(int i = 0; i<colone; i++)
			ptr = ptr->suivant_horizontal;
		ptelem = ptr->suivant_vertical;
		preced = ptr;
		while(ptelem != ptr && ligne > ptelem->index_ligne){
			preced = ptelem;
			ptelem = ptelem->suivant_vertical;
		}
	/* On fait le link vertical */
		preced->suivant_vertical = insert;
		insert->suivant_vertical = ptelem;
	}
	
}

void insererElement(int x,int ligne, int colone, matrice M){
	if(x!=0) /* Si c'est un zero, on ne l'insere pas*/
	operationElement(x, 'r', ligne, colone, M);
	else
	supprimerElement(ligne, colone, M);
}





void etendreMatrice(int ligne, int colone, matrice M){
	matrice ptr;
	ptr = M;
	
	if (colone > M->index_colone){
		for(int i=0; i<colone; i++){
			if(i>=M->index_colone){
			matrice elem = (matrice) malloc(sizeof(element));
			elem->suivant_vertical = elem;
			ptr->suivant_horizontal = elem;
			}
			ptr=ptr->suivant_horizontal;
		}
		ptr->suivant_horizontal = M;
		M->index_colone = colone;
	}
	ptr = M;
	if (ligne > M->index_ligne){
		for(int i=0; i<ligne; i++){
			if(i>=M->index_ligne){
			matrice elem = (matrice) malloc(sizeof(element));
			elem->suivant_horizontal = elem;
			ptr->suivant_vertical = elem;
			}
			ptr=ptr->suivant_vertical;
		}
		ptr->suivant_vertical = M;
		M->index_ligne = ligne;
	}
}

/* M1 = M1 + M2 */
void sommeMatrice(matrice M1, matrice M2){
	etendreMatrice(max(M1->index_ligne,M2->index_ligne), max(M1->index_colone,M2->index_colone), M1);
	matrice ptr, ptelem;
	ptr = M2 ;
	for (int i = 0; i< M2->index_ligne; i++){
		ptr=ptr->suivant_vertical;
		ptelem=ptr->suivant_horizontal;
		while(ptelem != ptr){
			operationElement(ptelem->valeur, '+', ptelem->index_ligne, ptelem->index_colone, M1);
			ptelem=ptelem->suivant_horizontal;
		}
	}
}

/* M3 = M1 + M2 */
/* M3 should be a pointer */
void sommeMatriceNonDestructive(matrice M1, matrice M2, matrice *M3){
	creerMatriceVide( max(M1->index_ligne,M2->index_ligne), max(M1->index_colone,M2->index_colone), M3);
	sommeMatrice(*M3, M1);
	sommeMatrice(*M3, M2);
}




void afficherMatrice(matrice M){
	matrice ptr = M;
	matrice ptelem;
	for (int i = 0; i< M->index_ligne; i++){
		ptr=ptr->suivant_vertical;
		ptelem=ptr->suivant_horizontal;
		
		int j = 0;
		while(ptelem != ptr){
			if (ptelem->index_colone == j){
				printf("%2d ",ptelem->valeur);
				ptelem=ptelem->suivant_horizontal;
			} else printf("00 ");
			j++;
		}
		
		while(j++ < M->index_colone)
			printf("00 ");
		
		printf("\n");
	}
}



int grabElement(int ligne, int colone, matrice M){
	assert(colone < M->index_colone && ligne < M->index_ligne);
	
	matrice ptr, ptelem;
	int result;
	result = 0;
	
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
	
	while(ptelem != ptr && colone > ptelem->index_colone)
		ptelem = ptelem->suivant_horizontal;
	
	/* Si l'element existe deja */
	if(ptelem != ptr && ptelem->index_colone == colone && ptelem->index_ligne == ligne)
		result = ptelem->valeur;
	
	return result;
}




int produitVecteurs(matrice LigneM1, matrice ColoneM2){
	matrice ptrL1, ptrC2;
	ptrL1=LigneM1->suivant_horizontal;
	ptrC2=ColoneM2->suivant_vertical;
	int res = 0;
	while(ptrL1!=LigneM1 && ptrC2!=ColoneM2){
		// printf("L1val:%d\tC2val:%d\n", ptrL1->valeur, ptrC2->valeur);
		// printf("L1_il:%d \tC2_ic:%d\n",ptrL1->index_colone, ptrC2->index_ligne);
		if(ptrL1->index_colone==ptrC2->index_ligne){
			// printf("res(%d) += elemL1(%d) * elemC2(%d)\n", res, ptrL1->valeur, ptrC2->valeur);
			res += ptrL1->valeur * ptrC2->valeur;
			ptrL1=ptrL1->suivant_horizontal;
			ptrC2=ptrC2->suivant_vertical;
		}else if(ptrL1->index_colone > ptrC2->index_ligne)
			ptrC2=ptrC2->suivant_vertical;
		else
			ptrL1=ptrL1->suivant_horizontal;

	}
	return res;
}

/* M3 = M1 * M2 */
/* M3 should be an unitialized pointer of matrice type */
void produitMatrice(matrice M1, matrice M2, matrice* M3){
	assert(M1->index_colone == M2->index_ligne);
	
	creerMatriceVide(M1->index_ligne, M2->index_colone, M3);
	
	matrice ptr1, ptr2;
	ptr2 = M2;
	
	for(int i=0; i<M2->index_colone; i++){
		ptr1 = M1;
		ptr2 = ptr2->suivant_horizontal;
		
		for(int j=0; j<M1->index_ligne; j++){
			ptr1 = ptr1->suivant_vertical;
		/* On insere a l'index [j,i] le resultat du produit vectoriel 
		   de la colone ptr2 et de la ligne ptr1 */
			insererElement(produitVecteurs(ptr1, ptr2), j, i, (*M3));
		}
	}
}




void supprimerElement(int ligne, int colone, matrice M){ /* -----OK----- */
	int C, L;
	C = M->index_colone;
	L = M->index_ligne;
	assert(colone < C && ligne < L);
	
	matrice ptr, ptelem, preced;
	
	/* On deplace un pointeur jusqu'a la ligne concerne */
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
		
	/* On cherche l'element */
	ptelem = ptr->suivant_horizontal;
	preced = ptr;
	while(ptelem != ptr && colone != ptelem->index_colone){
		preced = ptelem;
		ptelem = ptelem->suivant_horizontal;
	}
	
	/* Si il existe */
	if(ptelem != ptr && ptelem->index_colone == colone){
		
		/* Nouveau link horizontal */
		preced->suivant_horizontal = ptelem->suivant_horizontal;
		
		/* On deplace un pointeur pour le link vertical */
		ptr = M->suivant_horizontal;
		for(int i = 0; i<colone; i++)
			ptr = ptr->suivant_horizontal;
		ptelem = ptr->suivant_vertical;
		preced = ptr;
		while(ptelem != ptr && ligne > ptelem->index_ligne){
			preced = ptelem;
			ptelem = ptelem->suivant_vertical;
		}
		/* On fait le link vertical */
		preced->suivant_vertical = ptelem->suivant_vertical;
		
		
		free(ptelem);
	}/* Sinon on fait rien */
}

void supprimerMatrice(matrice M){
	if (M->suivant_horizontal != NULL) {
		matrice tmp,ptr;
		tmp = M->suivant_horizontal;
		M->suivant_horizontal=NULL;
		supprimerMatrice(tmp);
		ptr = M->suivant_vertical;
		while(ptr != M){
			tmp=ptr;
			ptr = ptr->suivant_vertical;
			free(tmp);
		}
		free(M);
	}
}



