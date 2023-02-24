#include "Compile_Module.h"
#include "Memory_Module.h"
#include "Execution_Module.h"


/* Pre Processing: Travail non réalisé.
//What would be in a pre processor module:
//Can be ignored for now as we supposed a few things:
//	-input file does not contains labels nor variables.
//	-input file content is syntaxicaly correct and valid.

pre_process(fichier_entree){
	
	FILE * fic;
	FILE * fout;
	
	// Ouverture du fichier
	fic = fopen(fichier_entree, "r");
	if(fic == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}
	fout = fopen("temp.txt", "w");
	
	//Keep track of:
	int file_line = 1;
	int prog_addr = PROGRAMM_START ; //#define PROGRAMM_START 0x8000
	
	struct label Label_Table[MAX_LABELS];
	//	struct label {
	//		char label[15];
	//		int address;
	//	}
	
	while(read lines){
		
		Check_if_label(); //Remove any label and add it to the Label_Table
							Replace any known label with value
		
		check_syntaxe();  //looking for ,error
		
		check_validity();   //check if: op is recognized
							//			number of args match
							//			args are valid (ex: reg number above 31)
		if(all_valid){
			copy_instruction();
	//	Will copy the current instruction to "fout" with the standard syntaxe
	//	INST ARG1,ARG2,ARG3  (or ,ARG2(ARG3) in some specific cases)
			prog_addr++;
		}
		else{
			report_error(error_type,file_line);
			exit(1);
		}
		
		if (end_of_line) file_line++;
	}
	

}

*/


int main(int argc, char *argv[]) {
		
	char fichier_entree[40];
	char fichier_sortie[40];
	sprintf(fichier_entree,"tests/%s",argv[1]);
	
	/* Travail de preprocessing optionel
	
	pre_process(fichier_entree,fichier_sortie);
	
	strcpy(fichier_entree, "temp.txt");
	
	*/
	
	sprintf(fichier_sortie,"hexified/%s",argv[1]);
	
	compile_segment(fichier_entree,fichier_sortie);
	
	mem_init();
	reg_init();
		
	segment2memory(fichier_sortie);
	
	mem_print();
	
	// execute_program();
	
	return 0;
}


