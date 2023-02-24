#ifndef Library
	#include "Library.h"
#endif
#include "CPU_Struct.h"

/** Structure d'un bloc d'une liste chainée représentant la mémoire 
	Chaque bloc contient 16 emplacement de 4 octets chacun */
typedef struct mem_bloc {
	unsigned int base;
	uint32_t bloc[16];
	struct mem_bloc * next;
} mem_bloc;

/** Pointeur adressable globalement pointant vers la base de la liste chainée */
mem_bloc *Memory;

/**
\brief Cette fonction permet :
D'initialiser la variable Memory (=NULL)
*/
void mem_init();

/** 
\brief Cette fonction permet d'initialiser les registres du cpu.
*/
void reg_init();

/**
\brief Cette fonction permet de rechercher une adresse
\param base du bloc à rechercher
\return pointeur vers l'objet trouvé ou NULL sinon.
*/
mem_bloc *rechercher_bloc(unsigned int bloc_base);

/** 
\brief Cette fonction permet de \créer un bloc en vérifiant qu'aucun bloc n'a la même base
\param address de base du bloc
\return pointeur vers le bloc
*/
mem_bloc *find_bloc_ptr(unsigned int bloc_base);

/** 
\brief Cette fonction permet d'écrire un mot à une addresse
\param adresse de l'emplacement où écrire, valeur du mot à écrire
*/
void write_word(unsigned int address, uint32_t word);

/** Cette fonction affiche le contenu des blocs mémoire jusqu'à une certainne adresse */
void mem_print_until_address(unsigned int address);

/** Cette fonction affiche le contenu des blocs mémoire depuis l'adresse de départ du programme (PROGRAM_START) */
void print_program_mem();

/** Cette fonction affiche le contenu de toute la mémoire avec le même format que l'example 2019 */
void mem_print();

/** Cette fonction affiche l'état des registres avec le même format que l'example 2019 */
void reg_state_print();

/** Cette fonction écrit l'état de chacun des registre dans un fichier en respectant
la syntaxe décrite dans le nouveau sujet (j'espère)  */
void reg_state_out(char * nomfichier);

/** Permet de supprimer un bloc (pointé par bloc_ptr) de la liste chainée correspondant à la mémoire */
void free_bloc(mem_bloc* bloc_ptr);

/** Permet de libérer la mémoire à réservée à une liste chainée pointée par 'ptr' */
void mem_free(mem_bloc* ptr);

/** 
\brief Cette fonction permet de lire le contenu d'une addresse
\param adresse de l'emplacement à lire
\return valeur (sur 4octets) contenue à l'addresse passé en parametre
*/
uint32_t read_word(unsigned int address);