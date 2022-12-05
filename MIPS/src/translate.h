#include "default.h"

uint32_t format_J(uint8_t opcode, uint32_t args[]);
uint32_t format_I(uint8_t opcode, uint32_t args[]);
uint32_t format_R_alternative(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_R_inversed(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_R(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t mask(uint8_t start, uint8_t end);
uint32_t* parse_parameters(char *string, int index,int nb_args_max);
uint32_t translate_line(char string[]);
int find_instruction(char string[]);
