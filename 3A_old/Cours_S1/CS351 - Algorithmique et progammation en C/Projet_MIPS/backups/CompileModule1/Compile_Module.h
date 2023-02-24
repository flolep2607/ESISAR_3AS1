#ifndef Library
	#include "Library.h"
#endif

struct ligne_tableau {
	char OP_NAME[6];
	uint8_t Code;
	char Category;
	char flags; //flags
	// bit 123 => arg 123
	// bit 5 =>    Set => SPECIAL
	//		   not Set => OP
	// bit 8 => ROTR special bit
};

struct ligne_tableau Tableau[25];

void compile_segment(char *nomfichier);