#include "Library.h"
#include "Memory_Module.h"

#define L *liste

void write_byte(unsigned int base, unsigned int offset, uint8_t byte){
	struct mem_bloc *ptr = Memoire;
	while(ptr->suivant != NULL && ptr->suivant->base <= base)
		ptr = ptr->suivant;
	if (ptr->base = base){
		// offset = offset % 16;
		ptr->bloc[offset] = byte;
	}else{
		struct mem_bloc* e = (mem_bloc*) malloc(sizeof(mem_bloc));
		e->suivant = ptr->suivant;
		ptr->suivant = e;
		e->base = base;
		e->bloc[offset] = byte;
		ptr = e;
	}
	return e;
} 

uint8_t read_byte(unsigned int base, unsigned int offset){
	mem_bloc *ptr = Memoire;
	while(ptr->suivant != NULL && ptr->suivant->base <= base)
		ptr = ptr->suivant;
	if (ptr->base = base){
		// offset = offset % 16;
		return ptr->bloc[offset];
	}else{
		return 0;
	}
} 
