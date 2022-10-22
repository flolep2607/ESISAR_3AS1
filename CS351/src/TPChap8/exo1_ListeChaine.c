// #include <stdlib.h>
// #include <stdio.h>
// #include <assert.h>
// typedef struct element
// {
// 	int valeur;		  /* valeur de l’élément */
// 	element *suivant; /* adresse du successeur */
// } element;

// typedef element *liste;
// typedef struct node
// {
// 	char data;
// 	struct node *link;
// } Lnode;

// void insererElement(int x, liste *l){
// 	element* newOne = (element *)malloc(sizeof(element));
// 	newOne->valeur = x;
// 	newOne->suivant = NULL;
// 	element* ptr;
// 	ptr = *l;
// 	while(ptr->suivant != NULL){
// 		if(ptr->suivant->valeur < newOne->valeur){
// 			newOne->suivant = ptr;
// 		}
// 		else{
// 			ptr = ptr->suivant;
// 		}
// 	}
// }

// void supprimerElement(int i, liste *l){

// }

// /* Ici, on est oblig� d'utiliser la notation struct xxx,
// car la structure s'auto-r�f�rence!*/


// /* Proc�dure d'affichage de la liste. Ne doit pas �tre modifi�e!!! */
// void listeAffiche(Lnode * ptr){
// 	if ( NULL == ptr )
// 		printf("Liste vide!") ;
// 	else 
// 		printf("Contenu de la liste : ") ;
// 	while ( NULL != ptr ) 	{
// 		printf("%c ",ptr->data);
// 		ptr = ptr->link ;
// 		}
// 	printf("\n") ;
// }

// /* Insertion en "t�te de liste" */
// void insertionTete(Lnode **ph,char item){
// 	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
// 	node->data = item;
// 	node->link = *ph;
// 	*ph = node;
// }

// /* Insertion en "queue de liste" */
// void insertionQueue(Lnode **ph,char item)	{
// 	Lnode* node = (Lnode*) malloc(sizeof(Lnode));
// 	node->data = item;
// 	node->link = NULL;
// 	Lnode* ptr;
// 	ptr = *ph;
// 	while (ptr->link != NULL)
// 	{
// 		ptr = ptr->link;		
// 	}
// 	ptr->link = node;
// }

// /* Suppression en "t�te de liste" */
// void suppressionTete(Lnode **ph){
// 	if (*ph != NULL)
// 	{
// 		*ph = (*ph)->link;
// 	}
// }

// /* Suppression en "Queue" de liste" */
// void suppressionQueue(Lnode **ph){
// 	Lnode* ptr;
// 	ptr = *ph;
// 	while (ptr != NULL)
// 	{
// 		ptr = ptr->link;		
// 	}
// 	ptr->link = NULL;
// }


// /* Programme principal. Ne doit pas �tre modifi�!!! */
// int main(void)
// {
// 	liste l = NULL;
// 	insertionTete
// }