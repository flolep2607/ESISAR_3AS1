#include "Compile_Module.h"
#include "Memory_Module.h"
#include "Execution_Module.h"

#define MAX_PATH_LEN 256

/* Pre Processing: Travail non réalisé.
//What would be in a pre processor module:
//Can be ignored for now as we supposed a few things:
//	-input file does not contains labels nor variables.
//	-input file content is syntaxicaly correct and valid.

pre_process(fichier_entree,fichier_sortie){
	
	FILE * fic;
	FILE * fout;
	
	// Ouverture du fichier
	fic = fopen(fichier_entree, "r");
	if(fic == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}
	fout = fopen(fichier_sortie, "w");
	
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
		
	printf("\t\t\t***** MIPS Emulator *****\nCS351 - Jean Rougé, Gauthier Patard\n\n");
	
	
	INTERRACTIF = 0;
	PAS = 0;
	
	switch(argc){
		case 1:
			//mode interractif
			INTERRACTIF=1;
			break;
	/*	Do nothing so commented out
		case 2: // nomfichier
			// mode normal
			char fichier_entree[MAX_PATH_LEN];
		char fichier_sortie[MAX_PATH_LEN];
		char fichier_reg[MAX_PATH_LEN];
			break;
	*/
		case 3: // nomfichier -pas
			// mode pas à pas
			if (!strcmp("-pas",argv[1]) || !strcmp("-pas",argv[2]))
				PAS=1;
			break;
	/*	Do nothing so commented out
		case 4: // nomfichier sortie_hex sortie_state
			// mode normal
			break;
	*/
		default:
			break;
		
	}
	
	
	/* Travail de preprocessing optionel
	
	strcpy(fichier_sortie, "temp.txt");
	
	pre_process(fichier_entree,fichier_sortie);
	
	strcpy(fichier_entree, "temp.txt");
	
	*/
	
	
	mem_init();
	reg_init();
	
	if (!INTERRACTIF){
		char nom_fichier[MAX_PATH_LEN-40];
		strcpy( nom_fichier, argv[1]);
		char fichier_entree[MAX_PATH_LEN];
		char fichier_sortie[MAX_PATH_LEN];
		char fichier_reg[MAX_PATH_LEN];
		
		sprintf(fichier_entree,"testfiles/%s",nom_fichier);
		if(argc<4){
		sed(nom_fichier,'.','\0');//coupe l'extension du nom de fichier
		
		/* Pas d'indication sur la localisation des fichiers en sorties
		donc ont les laisse à la racine (le dossier d'où on aura appelé la fonction)*/
		sprintf(fichier_sortie,"%s.hex",nom_fichier);
		sprintf(fichier_reg,"%s.state",nom_fichier);
		} else {
			strcpy( fichier_sortie, argv[2]);			
			strcpy( fichier_reg, argv[3]);
		}
		
		printf("Assembling file: %s\n",fichier_entree);
		printf("Output will be written in %s\n\n",fichier_sortie);
		
		printf("*** Starting program compilation ***\n\n");
		compile_segment(fichier_entree,fichier_sortie);
		
		printf("\n*** Text segment loaded - Ready to execute ***\n");
		print_program_mem();
		printf("\n\n");
		
		execute_program();
		
		reg_state_out(fichier_reg);
		
		}
	
	else interraction_profonde();
	
	
	
	printf("\nExit: 0\n");
	return 0;
}


