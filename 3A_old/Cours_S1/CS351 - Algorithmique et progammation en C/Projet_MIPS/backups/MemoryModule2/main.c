#include "Memory_Module.h"


int main(){//int argc, char *argv[]) {
	mem_init();
	
	write_word(0,0xFFEEDDCC);
	write_word(16*4,0xDEADBEEF);
	mem_print();
	printf(" @0: %08X\n",read_word(0));
	free_bloc(rechercher_bloc(0));
	mem_print();
	write_word(0,0);
	puts("(0,0)");
	mem_print();
	
	
	printf("penis");
	
	mem_free(Memory);
	return 0;
}