#include <stdio.h>

void swap(int *T,int a, int b){
	int tmp = *(T+a);
	*(T+a)=*(T+b);
	*(T+b)=tmp;
}


void drapeau(int *T, int n) {
	int b=0; int w=0; int r=n-1;
	while (w <= r) {
		if (T[w] >6){ // bleu == superieur a 6
			swap( T, w, r);
			r-=1;
		} else if (T[w] <3) { // rouge == inferieur a 3
			swap( T, b, w);
			b+=1;
			w+=1;
		} else 
			w += 1;// blanc == entre 3 et 6
	}
	
}


int main() {
	
	int x[] = {5,1,6,4,8,7,2,6,1,4,6,5,3,9,0};
	
	drapeau(x, 15);
	
	printf("[");
	for (int i=0; i<15; i++) printf("%d, ", x[i]); /* ce programme affiche 6 */
	printf("\b\b]\n");
	
	return 0;
}