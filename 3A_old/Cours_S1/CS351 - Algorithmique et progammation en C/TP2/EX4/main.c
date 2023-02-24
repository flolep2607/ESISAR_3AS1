#include <stdio.h>
#include "graphlib/graphlib.h"
#include "fonctions.h"


int main(){
	
	printf("Test1:\n\tWindows  L:200 , H:100\n\tMosaique L:3 , H:2\n");
	gr_inits_w(200,100,"test");
	dessineMosaique(50,0,100,3,2);
	cliquer();
	/* La fonction cliquer permet de garder la fenêtre ouverte
	et de la fermer quand on veut avec un clic. */
	printf("Test2:\n\tWindows  L:500 , H:500\n\tMosaiqueAvecSouris L:4 , H:5\n");
	gr_inits_w(500,500,"mosique");
	dessineMosaiqueAvecSouris(50,4,5);
	cliquer();

	return 0;
}
