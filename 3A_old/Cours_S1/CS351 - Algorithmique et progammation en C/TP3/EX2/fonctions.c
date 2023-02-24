#include <stdio.h>
#include "fonctions.h"


float  valeurPolynome(float *A, int N, float x0){
	
	float ret=A[N-1];//on crée une variable de retour contenant le dernier élément du tableau
	//                   (la parenthèse la plus imbriqué)
	for(int i=N-2; i>=0; i--){
		ret*=x0;//on multiplie par x
		ret+=A[i];//on ajoute l'élément précédent pour correspondre à la parenthèse de profondeur N-1
	}
	
	return(ret);
}

float  valeurPolynomeRecursif(float *A, int N, float x0){

	#ifdef DEBUG

	if ( N <= 1){
		printf("N=%d	ret %.2f \n",N,*A);
		return A[0];
	}
	else {
		float tmp=valeurPolynome(A+1,N-1,x0);//A+1 = &A[1]
		printf("N=%d	ret %.2f + ( %.2f * %.2f)\n",N, A[0], x0, tmp);
		return (A[0] + (x0 * tmp )) ;
	}
	#else 

	if ( N <= 1)
		return A[0];
	else 
		return (A[0] + (x0 * valeurPolynome(A+1,N-1,x0) )) ;// A+1 = &A[1]
	
	#endif

}