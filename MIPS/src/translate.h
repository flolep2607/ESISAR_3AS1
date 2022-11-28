#include "default.h"

uint32_t format_J(uint8_t opcode, uint32_t address);
uint32_t format_R(uint8_t opcode, uint32_t rt, uint32_t rs, uint32_t i);
uint32_t format_I(uint8_t opcode, uint32_t rd, uint32_t rs, uint32_t rt, uint16_t special);
uint32_t mask(uint8_t start, uint8_t end);
uint32_t parse_parameters(char *string, int index);
void translate(char *line);
