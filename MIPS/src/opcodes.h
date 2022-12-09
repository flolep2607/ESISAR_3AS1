#include "default.h"
typedef enum {
    I, //op6,rs5,rt5,i16                  => add
    J, //op6,addr26                       => j
    R, //special6,rs5,rt5,rd5,shamt5,op6  => addi
    R_reverse, 
    R_alternative,
    R_aled,
    I_no_first,
    R_inv_20,
    R_strange,
    I_oof
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
    {"ADDI",I,0b001000,0},
    {"ADD",R,0b100000,0},
    {"AND",R,0b100100,0},
    {"BEQ",I_oof,0b000100,0},
    {"BGTZ",I,0b000111,0},
    {"BLEZ",I,0b000110,0},
    {"BNE",I,0b000101,0},
    {"DIV",R_alternative,0b011010,0},
    {"J",J,0b000010,0},
    {"JAL",J,0b000011,0},
    {"JR",R_strange,0b001000,0},
    {"LUI",I_no_first,0b001111,0},
    {"LW",I,0b100011,0},
    {"MFHI",R_aled,0b010000,0},
    {"MFLO",R_aled,0b010010,0},
    {"MULT",R_alternative,0b011000,0},
    {"NOP",R_strange,0b000000,0},
    {"OR",R,0b100101,0},
    {"ROTR",R,0b000010,0},
    {"SLL",R_inv_20,0b000000,0},
    {"SLT",R,0b101010,0},
    {"SRL",R_inv_20,0b000010,0},
    {"SUB",R,0b100010,0},
    {"SW",I,0b101011,0},
    {"SYSCALL",J,0b001100,0},//à typer
    {"XOR",R,0b100110,0},
    {NULL}
};
#endif