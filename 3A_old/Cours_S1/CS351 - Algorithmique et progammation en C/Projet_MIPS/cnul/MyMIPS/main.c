#include "MIPS.h"


int main(int argc, char *argv[]) {
	
	FILE * fic;
	FILE * fout;
	char line[TAILLE_LIGNE_MAX];
	char op[10];
	char fichier_entree[40];
	char fichier_sortie[40];
	unsigned int hex;
	
	sprintf(fichier_entree,"tests/%s",argv[1]);
	sprintf(fichier_sortie,"hexified/%s",argv[1]);
	/* Ouverture du fichier */
	fic = fopen(fichier_entree, "r");
	fout = fopen(fichier_sortie, "w");
	if(fic == NULL || fout == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}
	
	char c;
	while(!feof(fic)) {
		// fscanf(fic, "[^\n]", line);
		
		/* scan full line */
		fgets(line, sizeof(line), fic);
		
		*op='\0';
		sscanf(line,"%s ",op);
		
		/* do the stuff */
		printf("Analyzing: %s", line) ;
		hex = inst2hex(line);
		if( ( !hex && !strcmp(op,"NOP") ) || hex){
			printf("=> \033[0;32m%08X\033[0m\n\n", hex) ;
			fprintf(fout,"%08X\n",hex);
		} else printf("\033[0;31mBAD LINE\033[0m - OP:%s\n\n",op);
		
		
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