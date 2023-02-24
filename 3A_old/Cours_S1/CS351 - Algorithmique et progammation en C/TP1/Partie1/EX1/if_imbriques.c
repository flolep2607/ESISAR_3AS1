#include <stdio.h>

int main() {

	char note;
	printf("Entrez la note:");
	scanf("%c",&note);

	if (note == 'A'){
		printf("Très bien\n");
	}
	else if (note == 'B'){
		printf("Bien\n");
	}
	else if (note == 'C'){
		printf("Assez bien\n");
	}
	else if (note == 'D'){
		printf("Passable\n");
	}
	else if (note == 'E'){
		printf("Insuffisant\n");
	}
	return 0;

}

