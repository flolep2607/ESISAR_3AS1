#include <stdio.h>

int main() {

	char note;
	printf("Entrez la note:");
	scanf("%c",&note);

	switch(note){
	case 'A': printf("Très bien\n"); break;
	case 'B': printf("Bien\n"); break;
	case 'C': printf("Assez bien\n"); break;
	case 'D': printf("Passable\n"); break;
	case 'E': printf("Insuffisant\n");
	}
	return 0;

}

