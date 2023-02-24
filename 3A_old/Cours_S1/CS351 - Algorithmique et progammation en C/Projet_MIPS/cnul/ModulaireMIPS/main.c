#include "Compile_Module.h"
#include "Library.h"
#include "CPU_Struct.h"


int main(int argc, char *argv[]) {
	
	char fichier_entree[40];
	char fichier_sortie[40];
	
	sprintf(fichier_entree,"tests/%s",argv[1]);
	sprintf(fichier_sortie,"hexified/%s",argv[1]);
	
	compile_segment(argv[1]);
	
	return 0;
}