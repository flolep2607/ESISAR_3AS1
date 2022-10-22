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
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; 
    int i = (low- 1); 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort (int tab[], int start, int end){  
    // int pivot, right, left; 
    if (start<end) {
        // pivot = start;
        // left = start;
        // right = end;
        int pivot = partition(arr, low, high);
        // while (left<right){
        //     while (tab[left]<=tab[pivot] && left<end){
        //         left++;
        //     }
        //     while (tab[right]>tab[pivot]){
        //         right--;
        //     }
        //     if (left<right){
        //         swap(&tab[left], &tab[right]);
        //         left++;
        //         right--;
        //     }
        // }
        // swap(&tab[pivot], &tab[right]);
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