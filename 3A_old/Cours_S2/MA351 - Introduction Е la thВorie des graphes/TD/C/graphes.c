#include <stdio.h>
#include <stdlib.h>

#define MEMOPT 1

typedef struct {
	int num;
	int nb_succ;
	int* succ_list;
} Noeud;

void append(Noeud* elem, int succ){
	elem->succ_list[elem->nb_succ] = succ;
	elem->nb_succ++;
}

Noeud* graphe_oriente(int len, int rnd)
{
	int i,j;
	Noeud* G=malloc(len*sizeof(Noeud));
	
	/* Init */
	for(i=0; i<len; i++){
		G[i].num=i;
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
	return G;
}

Noeud* graphe_non_oriente(int len, int rnd)
{
	int i,j;
	Noeud* G=malloc(len*sizeof(Noeud));
	
	/* Init */
	for(i=0; i<len; i++){
		G[i].num=i;
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
	return G;
}

void print_graph(Noeud* G,int len){
	/* Display */
	for(int i=0; i<len; i++){
	    printf("%d:[",i);
		for(int a=0; a<G[i].nb_succ; a++) printf("%d,",G[i].succ_list[a]);
		if (G[i].nb_succ) printf("\b");
		printf("]\n");
    }
}

int main()
{
    int len=5;
	Noeud* graphe = graphe_oriente(len, 2);
	
	print_graph(graphe,len);

    return 0;
}