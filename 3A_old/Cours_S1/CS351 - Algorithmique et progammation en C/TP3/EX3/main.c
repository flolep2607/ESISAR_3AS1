#include <stdio.h>

int main(int argc, char * argv[]) {
	
	int i;
	printf("Nombre d'arguments : %d\n", argc);
	
	for(i = argc-1 ; i > 0 ; i--) {
		printf("%s\n", argv[i]);
	}
	
	return 0;
}
/*

Le résultat obtenu sans argument est:
	Nombre d'arguments : 1

Le résultat obtenu avec la commande "./monProgramme 12 toto 20.5" est:
	Nombre d'arguments : 4
	20.5
	toto
	12

*/