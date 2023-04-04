#ifndef Library
	#include "Library.h"
#endif
#include "CPU_Struct.h"


typedef struct mem_bloc {
	unsigned int base;
	uint8_t bloc[16];
	struct mem_bloc * next;
} mem_bloc;

mem_bloc *Memory;

/**
\brief Cette fonction permet :
D'initialiser la variable Memory (=NULL)
*/
void mem_init();

/**
\brief Cette fonction permet de rechercher une adresse
\param base du bloc à rechercher
\return pointeur vers l'objet trouvé ou NULL sinon.
*/
mem_bloc *rechercher_bloc(unsigned int bloc_base);

/** 
\brief Cette fonction permet de créer un bloc en vérifiant qu'aucun bloc n'a la même base
\param address de base du bloc
\return pointeur vers le bloc
*/
mem_bloc *find_bloc_ptr(unsigned int bloc_base);

void write_byte(unsigned int address, uint8_t byte);

void write_word(unsigned int address, uint32_t word);

void mem_print();

void free_bloc(mem_bloc* bloc_ptr);

void mem_free(mem_bloc* ptr);

uint8_t read_byte(unsigned int address);

uint8_t read_word(unsigned int address);