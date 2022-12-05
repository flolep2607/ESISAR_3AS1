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
    {"ADDI",I,0b001000,NULL},
    {"ADD",R,0b100000,0},
    {"AND",R,0b100100,0},
    {"BEQ",I,0b000100,NULL},
    {"BGTZ",I,0b000111,NULL},
    {"BLEZ",I,0b000110,NULL},
    {"BNE",I,0b000101,NULL},
    {"DIV",R,0b011010,0},
    {"J",J,0b000010,NULL},
    {"JAL",J,0b000011,NULL},
    {"JR",R,0b001000,0},
    {"LUI",I,0b001111,NULL},
    {"LW",I,0b100011,NULL},
    {"MFHI",R,0b010000,0},
    {"MFLO",R,0b010010,0},
    {"MULT",R,0b001111,0},//à typer
    {"NOP",R,0b000000,0},
    {"OR",R,0b100101,0},
    {"ROTR",R,0b000010,0},
    {"SLL",R,0b000000,0},
    {"SLT",R,0b101010,0},
    {"SRL",R,0b000010,0},
    {"SUB",R,0b100010,0},
    {"SW",I,0b101011,NULL},
    {"SYSCALL",J,0b001100,0},
    {"XOR",R,0b100110,0},
    NULL
};
#endif