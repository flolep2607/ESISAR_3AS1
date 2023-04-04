#include "default.h"
#include "registre.h"
#include "opcodes.h"

FILE *openfile(char *filename, const char *open_mode);
char *get_string_from_input();
char *get_line_from_file(FILE *fichier,bool* end);
char *trim(char *s);
uint32_t mask(uint8_t start, uint8_t end);
uint32_t part_set(uint32_t word,uint8_t start, uint8_t end);
uint32_t part_get(uint32_t word,uint8_t start, uint8_t end);
long fsize(FILE *file);
uint32_t get_cursor_position(register_pc* registre);
int8_t find_in_list(char string[],const instruction list_instruct[]);
char * trim_alloc(char * string);