#include <stdio.h>
#include <stdlib.h>

#define MEMOPT 1

typedef struct {
	int cle;
	int nb_succ;
	int* succ_list;
} Noeud;

typedef struct {
	int len;
	Noeud* sommets;
} Graphe;

void append(Noeud* elem, int succ){
	elem->succ_list[elem->nb_succ] = succ;
	elem->nb_succ++;
}

Graphe graphe_oriente(int len, int rnd)
{
	int i,j;
	Noeud* G=malloc(len*sizeof(Noeud));
	
	/* Init */
	for(i=0; i<len; i++){
		G[i].cle=i;
		G[i].nb_succ=0;
		G[i].succ_list=malloc(len * sizeof(int));
	}
	
	/* Build */
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			if ( (i != j) && ((i + j)^2) % (i % rnd + rnd) == 0 ){
				append(&G[i], j);
			}
		}
	}
	
	#if MEMOPT == 1
	/* Clean */
	for(i=0; i<len; i++){
		G[i].succ_list=realloc(G[i].succ_list, G[i].nb_succ * sizeof(int));
	}
	#endif
	
	return (Graphe) {len,G};
}

Graphe graphe_non_oriente(int len, int rnd)
{
	int i,j;
	Noeud* G=malloc(len*sizeof(Noeud));
	
	/* Init */
	for(i=0; i<len; i++){
		G[i].cle=i;
		G[i].nb_succ=0;
		G[i].succ_list=malloc(len * sizeof(int));
	}
	
	/* Build */
	for(i=0; i<len; i++){
		for(j=0; j<i; j++){
			if ( (i != j) && ((i + j)^2) % (i % rnd + rnd) == 0 ){
				append(&G[i], j);
				append(&G[j], i);
			}
		}
	}
	
	#if MEMOPT == 1
	/* Clean */
	for(i=0; i<len; i++){
		G[i].succ_list=realloc(G[i].succ_list, G[i].nb_succ * sizeof(int));
	}
	#endif
	return (Graphe) {len,G};
}

void print_graph(Graphe G){
	/* Display */
	for(int i=0; i<G.len; i++){
	    printf("%d:[",G.sommets[i].cle);/* équivalent à i */
		for(int a=0; a<G.sommets[i].nb_succ; a++)
		    printf("%d,",G.sommets[i].succ_list[a]);
		if (G.sommets[i].nb_succ) printf("\b");
		printf("]\n");
    }
}

void free_graph(Graphe G){
    free(G.sommets);
}

int main()
{
    int len=5;
	Graphe graphe = graphe_oriente(len, 2);
	print_graph(graphe);
	free_graph(graphe);
	
	graphe = graphe_non_oriente(len, 2);
	print_graph(graphe);
	free_graph(graphe);

    return 0;
}
