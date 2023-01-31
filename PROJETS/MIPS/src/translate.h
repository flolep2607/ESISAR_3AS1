#include "default.h"
#include "opcodes.h"
#include "default.h"
#include "labels.h"

#ifndef MNEMO_LISTE
#define MNEMO_LISTE
//pour eviter d'avoir un type en plus et utiliser la fonction find in list
static const instruction NEMO[] ={
  {"zero",I,0,0},
  {"at",I,1,0},
  {"v0",I,2,0},
  {"v1",I,3,0},
  {"a0",I,4,0},
  {"a1",I,5,0},
  {"a2",I,6,0},
  {"a3",I,7,0},
  {"t0",I,8,0},
  {"t1",I,9,0},
  {"t2",I,10,0},
  {"t3",I,11,0},
  {"t4",I,12,0},
  {"t5",I,13,0},
  {"t6",I,14,0},
  {"t7",I,15,0},
  {"s0",I,16,0},
  {"s1",I,17,0},
  {"s2",I,18,0},
  {"s3",I,19,0},
  {"s4",I,20,0},
  {"s5",I,21,0},
  {"s6",I,22,0},
  {"s7",I,23,0},
  {"t8",I,24,0},
  {"t9",I,25,0},
  {"k0",I,26,0},
  {"k1",I,27,0},
  {"gp",I,28,0},
  {"sp",I,29,0},
  {"fp",I,30,0},
  {"ra",I,31,0},
  {NULL}
};
#endif
uint32_t format_strange(uint8_t opcode, uint32_t args[]);
uint32_t format_R_aled(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_no_args(uint8_t opcode);
uint32_t format_R_alternative(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_R_inversed(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_R_inv_20(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_R(uint8_t opcode, uint32_t args[], uint32_t special);
uint32_t format_I_no_first(uint8_t opcode, uint32_t args[]);
uint32_t format_I_order(uint8_t opcode, uint32_t args[]);
uint32_t format_I3(uint8_t opcode, uint32_t args[]);
uint32_t format_I2(uint8_t opcode,uint32_t special, uint32_t args[]);
uint32_t format_I(uint8_t opcode, uint32_t args[]);
uint32_t format_J(uint8_t opcode, uint32_t args[]);


uint32_t* parse_parameters(char *string, int index,int nb_args_max,labels* labels_list);
uint32_t translate_line(char string[], uint32_t i, labels *labels_list,int* is_instruction);
