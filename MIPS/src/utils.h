#include "default.h"
#include "registre.h"

FILE *openfile(char *filename, const char *open_mode);
char *get_string_from_input();
char *get_string_from_file(FILE *fichier,bool* end);
char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);
uint32_t mask(uint8_t start, uint8_t end);
uint32_t set_part(uint32_t word,uint8_t start, uint8_t end);
uint32_t get_part(uint32_t word,uint8_t start, uint8_t end);
long fsize(FILE *file);
uint32_t get_cursor_position(register_pc* registre);