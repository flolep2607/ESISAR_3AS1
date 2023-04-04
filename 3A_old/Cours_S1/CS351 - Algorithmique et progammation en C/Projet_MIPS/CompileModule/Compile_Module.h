#ifndef Library
	#include "Library.h"
#endif

#define TAILLE_TABLEAU 25

struct ligne_tableau {
	char OP_NAME[6];
	uint8_t Code;
	char Category;
	uint8_t flags; /*flags:
					bit 123 => arg 123
					bit 5 =>    Set => SPECIAL
							not Set => OP
	 				bit 8 => ROTR special bit
	*/
};

/** Déclare un tableau, contenant les détails de chaque opération,
	addressable globalement.
*/
struct ligne_tableau Tableau[25];

/**
Traduit un fichier en language assembleur MIPS (supposé sans erreur de syntaxe)
et crée un fichier contenant le language machine (une instruction en hexadecimal
par ligne.
Argument: fichier_entree, le fichier asm à traduire
		  fichier_sortie, le fichier traduit obtenu
*/
void compile_segment(char *fichier_entree, char *fichier_sortie);