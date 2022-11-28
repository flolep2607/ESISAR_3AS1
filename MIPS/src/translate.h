#include "default.h"

uint32_t format_J(uint8_t opcode, uint32_t address);
uint32_t format_R(uint8_t opcode, uint8_t rt, uint8_t rs, uint16_t i);
uint32_t format_I(uint8_t opcode, uint8_t rd, uint8_t rs, uint8_t rt, uint16_t special);
uint32_t mask(uint8_t start, uint8_t end);
void translate(char *line);
