#include "Memory_Module.h"

void mem_init(){
	Memory = NULL;
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
		
	/* Oui */
	ptr = Memory;
	
	mem_bloc *preced;
	preced = ptr;
	
	if(ptr==NULL || ptr->base > bloc_base) {
		mem_bloc *nouveau = (mem_bloc*) malloc(sizeof(mem_bloc));
		nouveau->base = bloc_base;
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
			nouveau->next = ptr; 
			ptr = nouveau; //pour le retourner
		}
	}
	return ptr;//retourne un pointeur vers le bloc
}

void write_word(unsigned int address, uint32_t word){ //update with size_t ??
	mem_bloc* ptr;
	unsigned int offset = address % (16*4);
	unsigned int base = address - offset;
	ptr = find_bloc_ptr(base);
	// printf("address: %X\tbase: %X\toffset: %x\n",address,base,offset);
	
	if (offset%4) puts("erreur adresse pas modulo 4");
	offset/=4;
	
	if(word)
			ptr->bloc[offset] = word;
	else{
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
	// printf("address: %X\tbase: %X\toffset: %x\n",address,base,offset);
	
	if (offset%4) puts("erreur adresse pas modulo 4");
	offset/=4;
	
	int a=0;
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
	
}

void free_bloc(mem_bloc* bloc_ptr){
	mem_bloc* ptr;
	mem_bloc* preced;
	ptr = Memory;
	//preced = ptr;// c'est bizarre
	//preced++;//     sinon il veut
	//preced--;//     pas et il warn
	if (bloc_ptr == Memory) {
		Memory = bloc_ptr->next;
		free(bloc_ptr);
	}
	else {
		printf("help\n");
		while (ptr != bloc_ptr && ptr  != NULL) {
			//printf("preced:0x%X",preced);
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

