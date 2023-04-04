#include <stdio.h>
#include <stdlib.h>
#include "MIPS.h"


int main(int argc, char *argv[]) {
	
	FILE * fic;
	FILE * fout;
	char line[60];
	char fichier_entree[40];
	char fichier_sortie[40];
	unsigned int hex;
	
	sprintf(fichier_entree,"tests/%s",argv[1]);
	sprintf(fichier_sortie,"hexified/%s",argv[1]);
	/* Ouverture du fichier */
	fic = fopen(fichier_entree, "r");
	fout = fopen(fichier_sortie, "w");
	if(fic == NULL || fout == NULL) {
		perror("Probleme ouverture fichier monFichier.txt");
		exit(1);
	}
	char c;
	while(!feof(fic)) {
		// fscanf(fic, "%s\n", line);
		
		/* getting rid of empty lines */
		c = getc(fic);
		while( c =='\n' || c == ' ' || c == 0x0D) c = getc(fic);
		ungetc(c,fic) ;
		
		/* Remove commented lines */
		line[0] = '#';
		while(line[0] == '#')
			/* scan full line */
			fgets(line, sizeof(line), fic);
		
		
		/* do the stuff */
		printf("Analyzing: %s", line) ;
		hex = inst2hex(line);
		printf("=> %08X\n\n", hex) ;
		fprintf(fout,"%08X\n",hex);
		
		
		/* remove duplicate bug (if file end with \n)*/
		c = getc(fic);
		while( c =='\n') c = getc(fic);
		ungetc(c,fic) ;
	}
	
	/* Fermeture du fichier */
	fclose(fic);
	fclose(fout);
	
	
	printf("Exit:%d\n", 0); /* ce programme affiche 0 */
	
	return 0;
}