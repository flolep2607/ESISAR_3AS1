#include "Memory_Module.h"


int main(){//int argc, char *argv[]) {
	
	mem_init();
	write_word(0,0xFFEEDDCC);
	write_byte(5,0xDE);
	write_byte(6,0xAD);
	write_byte(7,0xBE);
	write_byte(8,0xEF);
	mem_print();
	printf("bit @7-8: %02X%02X\n",read_byte(7),read_byte(8));
	write_byte(25,0xFF);
	free_bloc(rechercher_bloc(0));
	mem_print();
	
	
	printf("penis");
	
	return 0;
}