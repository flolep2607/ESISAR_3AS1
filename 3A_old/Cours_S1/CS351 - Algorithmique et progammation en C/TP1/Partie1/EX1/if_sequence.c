#include <stdio.h>

int main() {

	char note;
	printf("Entrez la note:");
	scanf("%c",&note);

	if (note == 'A'){
		printf("Très bien\n");
	}
	if (note == 'B'){
		printf("Bien\n");
	}
	if (note == 'C'){
		printf("Assez bien\n");
	}
	if (note == 'D'){
		printf("Passable\n");
	}
	if (note == 'E'){
		printf("Insuffisant\n");
	}
	return 0;

}

