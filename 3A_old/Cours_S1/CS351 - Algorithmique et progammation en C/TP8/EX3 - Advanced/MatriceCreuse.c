#include <stdio.h>
#include <assert.h>
#include "MatriceCreuse.h"

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

/* Create an empty matrix of size lignes*colones */
void creerMatriceVide(int nb_lignes, int nb_colones, matrice *M){ /* -----OK----- */
	(*M) = (matrice) malloc(sizeof(element));
	(*M)->valeur = 1;
	
	matrice tmp;
	matrice preced;
	/* To proced we keep track of the previous element then,
	   link it to the new one we just created, shift them, 
	   and start again until the last one.
	   Then we link it back to the base (ie. M).
	*/
	/* Creation des indexs colone */
	preced = (*M);
	for(int i=0; i<nb_colones; i++){
		tmp = (matrice) malloc(sizeof(element));
		tmp->suivant_vertical = tmp;
		tmp->valeur=0; /* The value 0 is used to recognize borders.                   */
					   /* This is ok because 0 should stay unused in matrix elements. */
		preced->suivant_horizontal = tmp;
		preced = tmp;
	} tmp->suivant_horizontal = *M;
	
	/* Creation des indexs ligne */
	preced = (*M);
	for(int i=0; i<nb_lignes; i++){
		tmp = (matrice) malloc(sizeof(element));
		tmp->suivant_horizontal = tmp;
		tmp->valeur = 0;
		preced->suivant_vertical = tmp;
		preced = tmp;
	} tmp->suivant_vertical = *M;
}

/* Does not work on anything wich is not an element of the matrix (eg. a column or line element)*/
/* Edit: new version will probably return -1 in that case */
/** int grabElementColumn(matrice M, matrice elem){ 
	matrice ptr1, ptr2;
	ptr1 = elem;
	while(ptr1->valeur != 0)
		ptr1=ptr1->suivant_vertical;
	ptr2 = M->suivant_horizontal;
	int i = 0;
	while(ptr1 != ptr2){
		ptr2=ptr2->suivant_horizontal;
		i++;
	}
	return i;
}**/
int grabElementColumn(matrice elem){ /* -----OK----- */
	matrice ptr,tmp;
	int i=0;
	ptr = elem;
	/* On décale un pointeur jusqu'a un bord de la matrice (la ligne des indexs colones) */
	while(ptr->valeur) ptr=ptr->suivant_vertical;
	/* On sauvegarde l'addresse de l'index colonne */
	tmp=ptr;
	/* On deplace le pointeur jusqu'a la base de la matrice */
	while( !(ptr->valeur) ) ptr=ptr->suivant_horizontal;
	/* On compte combien de fois on doit se déplacer a droite pour retrouver l'adrresse sauvegardee */
	while(ptr != tmp){ i++; ptr=ptr->suivant_horizontal; }
	/* On retire 1 car les colones sont indexees a partir de zero */
	return(--i);
}
/**int grabElementLine(matrice M, matrice elem){ 
	matrice ptr1, ptr2;
	ptr1 = elem;
	while(ptr1->valeur != 0)
		ptr1=ptr1->suivant_horizontal;
	ptr2 = M->suivant_vertical;
	int i = 0;
	while(ptr1 != ptr2){
		ptr2=ptr2->suivant_vertical;
		i++;
	}
	return i;
}**/
int grabElementLine(matrice elem){ /* -----OK----- */
	matrice ptr,tmp;
	int i=0;
	ptr = elem;
	while(ptr->valeur) ptr=ptr->suivant_horizontal;
	tmp=ptr;
	while(! ptr->valeur) ptr=ptr->suivant_vertical;
	while(ptr != tmp){ i++; ptr=ptr->suivant_vertical; }
	return(--i);
}

/* Return the number of columns of matrix M */
int nbColumn(matrice M){ /* -----OK----- */
	int i = 0;
	matrice ptr = M->suivant_horizontal;
	while(ptr != M){
		ptr = ptr->suivant_horizontal;
		i++;
	}
	return i;
}
/* Return the number of lines of matrix M */
int nbLines(matrice M){ /* -----OK----- */
	int i = 0;
	matrice ptr = M->suivant_vertical;
	while(ptr != M){
		ptr = ptr->suivant_vertical;
		i++;
	}
	return i;
}

/** ------------------------------------------------------------------------------------------------ **/
/* Apply op to x and y */
/* ret x op y */
int operation(char op, int x, int y){ /* -----OK----- */
	int result;
	switch(op){
		case '+': result = x + y; break; /* add       */
		case '-': result = x - y; break; /* substract */
		case '*': result = x * y; break; /* multiply  */
		case '/': result = x / y; break; /* divide    */
		case 'r': result = y; break;     /* replace   */
	}
	return result;
}

/** LE MORE IMPORTANT **/
/* If A = M[ligne,colone] then */
/* M[ligne,colone] = A op x    */
/* Available operation are +, -, *, /, r */
/* 'r' stand for replace */
void operationElement(int x,char op, int ligne, int colone, matrice M){ /* -----OK----- */
	int C, L;
	C = nbColumn(M);
	L = nbLines(M);
	assert(colone < C && ligne < L);
	
	matrice ptr, ptelem, preced;

	/* On deplace un pointeur jusqu'a la ligne concerne */
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
		
	/* On cherche l'endroit ou inserer l'eleme*/
	ptelem = ptr->suivant_horizontal;
	preced = ptr;
	while(ptelem != ptr && colone > grabElementColumn(ptelem)){
		preced = ptelem;
		ptelem = ptelem->suivant_horizontal;
	}
	/* Si l'element existe deja */
	if(ptelem != ptr && grabElementColumn(ptelem) == colone)
		ptelem->valeur = operation(op, ptelem->valeur, x);
		
	/* Sinon on continue */
	else {
	/* On cree le nouvel element a inserer */
		matrice insert = (element* ) malloc(sizeof(element));
		/* On applique l'op pour y=0  */
		insert->valeur = operation(op, 0, x);
		
	/* On fait le link horizontal */
		preced->suivant_horizontal = insert;
		insert->suivant_horizontal = ptelem;	

	/* On refait la même chose pour le link vertical */
		ptr = M->suivant_horizontal;
		for(int i = 0; i<colone; i++)
			ptr = ptr->suivant_horizontal;
		ptelem = ptr->suivant_vertical;
		preced = ptr;
		while(ptelem != ptr && ligne > grabElementLine(ptelem)){
			preced = ptelem;
			ptelem = ptelem->suivant_vertical;
		}
	/* On fait le link vertical */
		preced->suivant_vertical = insert;
		insert->suivant_vertical = ptelem;
	}
	
}

/* Insert an the value x in matrix M at column `colone`, line `ligne` */
void insererElement(int x,int ligne, int colone, matrice M){ /* -----OK----- */
	if(x!=0) /* Si c'est un zero, on ne l'insere pas*/
	operationElement(x, 'r', ligne, colone, M);
	else 
	supprimerElement(ligne, colone, M);
}


/** ------------------------------------------------------------------------------------------------ **/

/* Expand the matrix M to the size colone*ligne if it is bigger */
void etendreMatrice(int ligne, int colone, matrice M){ /* -----OK----- */
	matrice ptr;
	ptr = M;
	int C, L;
	C = nbColumn(M);
	L = nbLines(M);
	
	if (colone > C){
		for(int i=0; i<colone; i++){
		/*Si le pointeur est le dernier element des indexs colones, on rajoute un nouveau */
			if(i>=C){
				matrice elem = (matrice) malloc(sizeof(element));
				elem->suivant_vertical = elem;
				elem->valeur = 0;
				ptr->suivant_horizontal = elem;
			}
			ptr=ptr->suivant_horizontal;
		}
		ptr->suivant_horizontal = M; 
		/* On oublie pas de reboucler a la base */
	}
	
	/* Pareil mais pour les lignes */
	ptr = M;
	if (ligne > L){
		for(int i=0; i<ligne; i++){
			if(i>=L){
			matrice elem = (matrice) malloc(sizeof(element));
			elem->suivant_horizontal = elem;
			elem->valeur = 0;
			ptr->suivant_vertical = elem;
			}
			ptr=ptr->suivant_vertical;
		}
		ptr->suivant_vertical = M;
	}
}

/* M1 = M1 + M2 */
/* This function will modify matrix M1 /!\ */
void operationMatriceElementAElement(char op, matrice M1, matrice M2){ /* -----OK----- */
	int L1, L2, C1, C2;
	L1 = nbLines(M1);
	L2 = nbLines(M2);
	C1 = nbColumn(M1);
	C2 = nbColumn(M2);
	etendreMatrice(max(L1,L2), max(C1,C2), M1);
	/* La double boucle sert a enumerer les elements non nuls       */
	/* On utilise ensuite la fonction operationElement pour sommer. */
	matrice ptr, ptelem;
	ptr = M2 ;
	for (int i = 0; i< L2; i++){
		ptr=ptr->suivant_vertical;
		ptelem=ptr->suivant_horizontal;
		while(ptelem != ptr){
			/* i correspond a la ligne */
			operationElement(ptelem->valeur, op, i, grabElementColumn(ptelem), M1);
			ptelem=ptelem->suivant_horizontal;
		}
	}
}

/* M1 = M1 + M2 */
/* This function will modify matrix M1 /!\ */
void sommeMatrice(matrice M1, matrice M2){ /* -----OK----- */
	operationMatriceElementAElement( '+', M1, M2);
}

/* M3 = M1 + M2 */
/* M3 should be an uninitialized pointer with element type*/
void sommeMatriceNonDestructive(matrice M1, matrice M2, matrice *M3){ /* -----OK----- */
	/*assert(*M3==NULL);*/
	creerMatriceVide( 1, 1, M3);
	/* On cree une matrice de taille 1,          */
	/* sommeMatrice() se chargera de l'agrandir. */
	sommeMatrice(*M3, M1);
	sommeMatrice(*M3, M2);
}


/** ------------------------------------------------------------------------------------------------ **/


/* M1 = M1 - M2 */
/* This function will modify matrix M1 /!\ */
void soustractionMatrice(matrice M1, matrice M2){ /* -----OK----- */
	operationMatriceElementAElement( '-', M1, M2);
}
/* M1 = M1 .* M2 (notation matlab pour multiplication element a element) */
/* This function will modify matrix M1 /!\ */
void multiplicationMatriceElementAElement(matrice M1, matrice M2){ /* -----OK----- */
	operationMatriceElementAElement( '*', M1, M2);
}




/* Return the value of the element of matrix M at line `ligne` and column `colone`*/
/* ret M[ligne,colone] */
int grabElement(int ligne, int colone, matrice M){ /* -----OK----- */
	int C, L;
	C = nbColumn(M);
	L = nbLines(M);
	assert(colone < C && ligne < L);
	
	matrice ptr, ptelem;
	int result;
	result = 0;
	
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
	
	ptelem = ptr->suivant_horizontal;
	
	while(ptelem != ptr && colone > grabElementColumn(ptelem))
		ptelem = ptelem->suivant_horizontal;
	
	if(ptelem != ptr && grabElementColumn(ptelem) == colone)
		result = ptelem->valeur;
	
	return result;
}

/* Fait le produit vectoriel entre deux vecteurs (ligne et colone) d'une matrice */
int produitVecteurs(matrice LigneM1, matrice ColoneM2){ /* -----OK----- */
	matrice ptrL1, ptrC2;
	ptrL1=LigneM1->suivant_horizontal;
	ptrC2=ColoneM2->suivant_vertical;
	int res = 0;
	int n,k;
	n=k=-1;
	while(ptrL1!=LigneM1 && ptrC2!=ColoneM2){
	/*  On recalcule les indexs des elements seulement s'ils ont change */
		if(n==-1) n = grabElementColumn(ptrL1);
		if(k==-1) k = grabElementLine(ptrC2);
		
	/*  Si les indexs correspondes (le resultat sera non nul) */
		if(n==k){
			res += ptrL1->valeur * ptrC2->valeur;
			ptrL1=ptrL1->suivant_horizontal;
			ptrC2=ptrC2->suivant_vertical;
			n=k=-1;
	/*  Sinon on avance celui avec le plus petit index */
		}else if(n > k){
			ptrC2=ptrC2->suivant_vertical;
			k=-1;
		}else{
			ptrL1=ptrL1->suivant_horizontal;
			n=-1;
		}

	}
	return res;
}

/* M3 = M1 x M2 */
/* M3 should be an unitialized pointer of matrice type */
void produitMatrice(matrice M1, matrice M2, matrice* M3){ /* -----OK----- */
	int nb_colones, nb_lignes;
	nb_colones = nbColumn(M1);
	nb_lignes = nbLines(M2);
	
	assert(nb_colones == nb_lignes);
	
	nb_colones = nbColumn(M2);
	nb_lignes = nbLines(M1);
	creerMatriceVide(nb_lignes, nb_colones, M3);
	
	matrice ptr1, ptr2;
	ptr2 = M2;
	
	/* For each column vector in M2 */
	for(int i=0; i<nb_colones; i++){
		ptr1 = M1;
		ptr2 = ptr2->suivant_horizontal;
		
		/* For each line vector in M1 */
		for(int j=0; j<nb_lignes; j++){
			ptr1 = ptr1->suivant_vertical;
		/* On insere a l'index [j,i] le resultat du produit vectoriel 
		   de la colone ptr2 et de la ligne ptr1 */
			insererElement(produitVecteurs(ptr1, ptr2), j, i, (*M3));
		}
	}
}


void matriceVersMatriceCreuse(int longueur, int largeur,int m[longueur][largeur], matrice *M){ /* -----OK----- */
	creerMatriceVide(longueur, largeur, M);
	for(int i=0; i<longueur; i++){
		for(int j=0; j<largeur; j++){
			insererElement(m[i][j],i,j,*M);
		}
	}
}

void matriceCreuseVersMatrice(int m[], matrice M){ /* -----OK----- */
	int largeur, longueur;
	largeur = nbColumn(M);
	longueur = nbLines(M);
	for(int i=0; i<longueur; i++){
		for(int j=0; j<largeur; j++){
			// printf("->%d\n",*(m+i*largeur+j));
			*(m+i*largeur+j) = grabElement(i,j,M);
			// printf("->%d\n",*(m+i*largeur+j));
		}
	}	
}



/** ------------------------------------------------------------------------------------------------ **/

/* Supprime un element de M */
void supprimerElement(int ligne, int colone, matrice M){ /* -----OK----- */
	int C, L;
	C = nbColumn(M);
	L = nbLines(M);
	assert(colone < C && ligne < L);
	
	matrice ptr, ptelem, preced;
	
	/* On deplace un pointeur jusqu'a la ligne concerne */
	ptr = M->suivant_vertical;
	for(int i=0; i<ligne; i++)
		ptr = ptr->suivant_vertical;
		
	/* On cherche l'element */
	ptelem = ptr->suivant_horizontal;
	preced = ptr;
	while(ptelem != ptr && colone != grabElementColumn(ptelem)){
		preced = ptelem;
		ptelem = ptelem->suivant_horizontal;
	}
	
	/* Si il existe */
	if(ptelem != ptr && grabElementColumn(ptelem) == colone){
		
		/* Nouveau link horizontal */
		preced->suivant_horizontal = ptelem->suivant_horizontal;
		
		/* On deplace un pointeur pour le link vertical */
		ptr = M->suivant_horizontal;
		for(int i = 0; i<colone; i++)
			ptr = ptr->suivant_horizontal;
		ptelem = ptr->suivant_vertical;
		preced = ptr;
		while(ptelem != ptr && ligne > grabElementLine(ptelem)){
			preced = ptelem;
			ptelem = ptelem->suivant_vertical;
		}
		/* On fait le link vertical */
		preced->suivant_vertical = ptelem->suivant_vertical;
		
		
		free(ptelem);
	}/* Sinon on fait rien */
}

/* Free every single memory space allocated for the matrix M */
void supprimerMatrice(matrice M){ /* -----OK----- */
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


/** ------------------------------------------------------------------------------------------------ **/

/* Print a matrix to stdout*/
void afficherMatrice(matrice M){ /* -----OK----- */
	matrice ptr = M->suivant_vertical;
	matrice ptelem;
	int C = nbColumn(M);
	while(ptr != M){
		ptelem=ptr->suivant_horizontal;
		
		int j = 0;
		while(ptelem != ptr){
			if (grabElementColumn(ptelem) == j){
				printf("%2d ",ptelem->valeur);
				ptelem=ptelem->suivant_horizontal;
			} else printf("00 ");
			j++;
		}
		
		while(j++ < C )
			printf("00 ");
		
		printf("\n");
		ptr=ptr->suivant_vertical;

	}
}


/* More readable but way less efficient */
void afficherMatriceLazy(matrice M){ /* -----OK----- */
	int C = nbColumn(M);
	int L = nbLines(M);
	
	for(int i=0; i<L; i++){
		for(int j=0; j<C; j++){
			printf("%2d ", grabElement(i, j, M));
		}
		printf("\n");
	}
}


