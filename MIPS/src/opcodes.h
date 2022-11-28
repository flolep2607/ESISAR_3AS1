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
    uint8_t special;
} instruction;
#ifndef LISTE_INSTRUCT_H
#define LISTE_INSTRUCT_H
static const instruction LISTE_INSTRUCT []={
    {"ADDI",R,0b001000,NULL},
    {"ADD",I,0,0b100000},
    {"AND",R,0b000000,NULL},
    {"BEQ",R,0b000100,NULL},
    NULL
};
#endif