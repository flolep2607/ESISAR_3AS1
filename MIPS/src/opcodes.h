#include "default.h"
typedef enum { 
    I,//op6,rs5,rt5,i16                => add
    J,//op6,addr26                     => j
    R //op6,rs5,rt5,rd5,shamt5,funct6  => addi
} instruction_format;
typedef struct
{
    char* name;
    instruction_format format;
    uint8_t opcode; //6 bits
    uint32_t special;
} instruction;
#ifndef LISTE_INSTRUCT_H
#define LISTE_INSTRUCT_H
//TODO invert R et I lol
static const instruction LISTE_INSTRUCT []={
    {"ADDI",R,0b001000,NULL},
    {"ADD",I,0,0b100000},
    {"AND",R,0,0b100100},
    {"BEQ",I,0b000100,NULL},
    {"BGTZ",I,0b000111,NULL},
    {"BLEZ",I,0b000110,NULL},
    {"BNE",I,0b000101,NULL},
    {"DIV",I,0,0b011010},
    {"J",J,0b000010,NULL},
    NULL
};
#endif