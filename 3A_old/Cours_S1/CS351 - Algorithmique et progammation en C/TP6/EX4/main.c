#include <stdio.h>
#include "graphlib.h"

int main(){
	
	int Taille=500;
	printf("Test1:\n\tWindows  L:200 , H:100\n\tMosaique L:3 , H:2\n");
	gr_inits_w(Taille+100,Taille+100,"test");
	// cliquer();
	
	DessinerUnTriangleDeSierpinski(6,50,Taille+50,Taille);
	
	//clear_screen();
	cliquer();

	return 0;
}