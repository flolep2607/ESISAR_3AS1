#include "Memory_Module.h"


int main(){//int argc, char *argv[]) {
	mem_init();
	
	write_word(4,0xFFEEDDCC);
	write_word(16*4,0xDEADBEEF);
	
	write_word(5000,0xDEADBEEF);
	mem_print();
	printf(" @0: %08X\n",read_word(0));
	free_bloc(rechercher_bloc(0));
	mem_print();
	write_word(0,1);
	puts("(0,0)");
	
	free_bloc(rechercher_bloc(64));
	mem_print();
	puts("test word");
	write_word(0x801C,0xDEADBEEF);
	printf(" @801C: %08X\n",read_word(0x801C));
	puts("done");
	mem_print();
	printf("penis\n\n");
	
	mem_free(Memory);
	return 0;
}