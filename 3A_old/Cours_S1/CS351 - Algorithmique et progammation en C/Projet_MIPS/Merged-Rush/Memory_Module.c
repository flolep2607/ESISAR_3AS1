#include "Memory_Module.h"
#include "Compile_Module.h"

void mem_init(){
	free(Memory);
	Memory = NULL;
}

void reg_init(){
	CPU.PC = PROGRAMM_START;
	CPU.SP = STACK_BASE;
	CPU.SB = STACK_BASE;
	CPU.SR = 0;
	CPU.HI = 0;
	CPU.LO = 0;
	
	for (int i=0; i<32; i++) GPR[i]=0;
}

mem_bloc *rechercher_bloc(unsigned int bloc_base){
	mem_bloc *ptr;//on crée un pointeur
	ptr = Memory;//        qui pointe vers le premier objet
	while ( ptr != NULL) {//                     on cycle à travers tous les objets
		if (ptr->base == bloc_base) return ptr ;//et si les noms sont identiques, on retourne le pointeur
		ptr = ptr->next;
	}return NULL;// sinon on rertourne NULL
}

mem_bloc *find_bloc_ptr(unsigned int bloc_base){
	
	mem_bloc *ptr;//on crée un pointeur
	ptr = rechercher_bloc(bloc_base);
	/* Si il existe deja un bloc, on retourne son adresse */
	if( ptr != NULL ) return ptr;
		
	/* Sinon on crée un nouveau */
	ptr = Memory;
	
	mem_bloc *preced;
	preced = ptr;
	
	if(ptr==NULL || ptr->base > bloc_base) {
		mem_bloc *nouveau = (mem_bloc*) malloc(sizeof(mem_bloc));
		nouveau->base = bloc_base;
		for(int i=0;i<16;i++) nouveau->bloc[i]=0; //Initialisation du bloc (non nécessaire ??)
		
		if (INTERRACTIF) if (nouveau->base>=PROGRAMM_START) for(int i=0;i<16;i++) nouveau->bloc[i]=HALT; //pourrissement volontaire de la mémoire
		
		nouveau->next = ptr;// Null ou suivant
		Memory = nouveau;
		ptr = nouveau;
	}else { 
		ptr = ptr->next;
		while(ptr != NULL && ptr->base < bloc_base) {//cherche l'objet en queue de liste
			preced = ptr;
			ptr = ptr->next;
		}
		if(ptr != NULL && ptr->base == bloc_base)
			; /* Le bloc existe deja et ptr le pointe */
		else {
			mem_bloc *nouveau = (mem_bloc*) malloc(sizeof(mem_bloc));
			/* Ajoute le nouveau bloc */
			preced->next = nouveau;
			nouveau->base = bloc_base;
			for(int i=0;i<16;i++) nouveau->bloc[i]=0; //Initialisation du bloc (non nécessaire ??)
			
			if (INTERRACTIF) if (nouveau->base>=PROGRAMM_START) for(int i=0;i<16;i++) nouveau->bloc[i]=HALT; //pourrissement volontaire de la mémoire 
			/* (on pourrait enlever le if (interractif) car tous les modes en bénéfiscierait */
			
			nouveau->next = ptr; 
			ptr = nouveau; //pour le retourner
		}
	}
	return ptr;//retourne un pointeur vers le bloc
}

void write_word(unsigned int address, uint32_t word){
	mem_bloc* ptr;
	unsigned int offset = address % (16*4);
	unsigned int base = address - offset;
	ptr = find_bloc_ptr(base);
	
	if (offset%4) puts("erreur adresse pas modulo 4");
	offset/=4;
	
	if(word)
			ptr->bloc[offset] = word;
	else{ /* Si on a voulu écrire un zéro, on vérifie si le bloc est vide,
			si c'est le cas, on le supprime */
		int a=1;
		for (int i=0; i<16; i++) if (ptr->bloc[i]) a=0;
		if (a) free_bloc(ptr);//remove_bloc(ptr);
	}
}

uint32_t read_word(unsigned int address){
	mem_bloc* ptr;
	unsigned int offset = address % (16*4);
	unsigned int base = address - offset;
	ptr = rechercher_bloc(base);
	
	if (offset%4) puts("erreur adresse pas modulo 4");
	offset/=4;
	
	/* Si l'adresse est dans la zone réservée au programme on renvoit EXIT
	pour que le programme ne s'exécute pas dans une zone non initialisée */
	int a= (base>=PROGRAMM_START) ? HALT : 0; 
	if (ptr!=NULL)
			a = ptr->bloc[offset];
	return a;
}

void mem_print_until_address(unsigned int address){
	mem_bloc *ptr;
	ptr = Memory;
	while (ptr != NULL && ptr->base < address){
		for (int i=0; i<16;  ){
			for (int j=0; j<4; j++){
				printf("@%04d: %08X    ",(ptr->base+i*4),ptr->bloc[i]);
				i++;
			}
			puts("");
		}
		ptr = ptr->next;
	}
	if (ptr == Memory) printf("[[Memory Empty]]\n");
	
}

void print_program_mem(){
	mem_bloc *ptr;
	ptr = Memory;
	while (ptr != NULL && ptr->base < PROGRAMM_START) ptr = ptr->next;
	while (ptr != NULL){
		for (int i=0; i<16;  ){
			for (int j=0; j<4; j++){
				printf("@%08X: %08x\n",(ptr->base+i*4),ptr->bloc[i]);
				i++;
			}
		}
		ptr = ptr->next;
	}
	
}

void mem_print(){
	mem_bloc *ptr;
	ptr = Memory;
	while (ptr != NULL){
		for (int i=0; i<16;  ){
			for (int j=0; j<4; j++){
				printf("@%04X: %08X    ",(ptr->base+i*4),ptr->bloc[i]);
				i++;
			}
			puts("");
		}
		ptr = ptr->next;
	}
	
	if (ptr == Memory) printf("[[Memory Empty]]\n");
	
}

void reg_state_print(){
	for(int j=0; j<32; j+=4){
		for(int i=0; i<4;i++){
			printf("$%02d: %d\t\t",j+i,GPR[j+i]);
		}
		puts("");
	}
	printf("HI: %d\t\tLO: %d\n",CPU.HI,CPU.LO);
	
}

void reg_state_out(char* nomfichier){
	FILE * fic = fopen(nomfichier, "w");
	if(fic == NULL) {
		perror("Probleme ouverture fichier sortie registre");
		exit(1);
	}
	for(int i = 0; i<32; i++) fprintf(fic,"$%02d:%d\n",i,GPR[i]);
	fprintf(fic,"HI:%d\n",CPU.HI);
	fprintf(fic,"LO:%d\n",CPU.LO);
}

void free_bloc(mem_bloc* bloc_ptr){
	mem_bloc* ptr;
	mem_bloc* preced;
	ptr = Memory;
	if (bloc_ptr == Memory) {
		Memory = bloc_ptr->next;
		free(bloc_ptr);
	}
	else {
		while (ptr != bloc_ptr && ptr  != NULL) {
			preced = ptr;
			ptr = ptr->next;
		}
		if (ptr==bloc_ptr) {
			preced->next = ptr->next;
			free(ptr);
		}
	}
}

void mem_free(mem_bloc* ptr){
	if (ptr!=NULL) {
		free(ptr->next);
		free(ptr);
	}
}
