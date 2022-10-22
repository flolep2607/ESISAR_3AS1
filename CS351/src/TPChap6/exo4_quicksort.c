#include <stdio.h>
#include <stdlib.h>


void affiche(int* tab, int taille){ 
	for (int i = 0 ; i < taille ; i++){
		printf("%d ", tab[i]);
	}
	printf("\n");
}


void swap(int* a, int* b) 
{
	int temp;
	temp = *a; 
	*a = *b;
	*b = temp;
}
int partition(int tab[], int low, int high)
{
    int pivot = tab[high]; 
    int i = (low- 1); 
    for (int j = low; j <= high - 1; j++) {
        if (tab[j] < pivot) {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i + 1], &tab[high]);
    return (i + 1);
}

void quicksort (int tab[], int start, int end){
    if (start<end) {
        int pivot = partition(tab, start, end);
        quicksort(tab, start, pivot-1);
        quicksort(tab, pivot+1, end);
    }
}

int main(){

    int tab1[8] = {8,7,2,1,3,4,6,5};

    printf("Tableau:\n");
    affiche(tab1, 8);

    quicksort(tab1, 0, 7);
    printf("Tableau trie :\n");
    affiche(tab1, 8);

}