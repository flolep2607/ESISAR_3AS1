#include "execution.h"
uint8_t registers[50] = {0};
// registre_set((int)addresse,int32_t value)
int addOverflow(int *result, int a, int b) {
  if (a > INT32_MAX - b)
    return -1;
  else {
    *result = a + b;
    return 0;
  }
}
void I_type_inst(uint32_t instr, register_pc *registers,memory* ram, bool *executed) {
  if (!(*executed)) {
    uint32_t opcode = part_get(instr, 26, 31);
    uint32_t rs = part_get(instr, 21, 25);
    uint32_t rt = part_get(instr, 16, 20);
    uint32_t immediate = part_get(instr, 0, 15);
    int32_t SignExtImm;
    // convert a u16bits to a signed 32bits
    if (immediate >> 15) {
      SignExtImm = immediate | 0xFFFF0000;
    } else {
      SignExtImm = immediate;
    }
    switch (opcode) {
    case 0x04: // BEQ
      if (register_get(registers, rs) == register_get(registers, rt)) {
        pc_increase(registers, SignExtImm*4);
        registers->delayslot=true;
      }
      *executed = true;
      return;
    case 0x05: // BNE
      if (register_get(registers, rs) != register_get(registers, rt)) {
        pc_increase(registers, SignExtImm*4);
        registers->delayslot=true;
        //*4 car c'est la taille dans le registre d'une instruction
        //et que dans les tests c'est indiqué que c'est le nb d'instruction a sauter
        //alors que dans la doc c'est le decalage de d'octets
      }
      *executed = true;
      return;
    case 0x06: // BLEZ
      if (register_get(registers, rs) <= 0) {
        pc_increase(registers, SignExtImm*4);
        registers->delayslot=true;
      }
      *executed = true;
      return;
    case 0x07: // BGTZ
      if (register_get(registers, rs) > 0) {
        pc_increase(registers, SignExtImm*4);
        registers->delayslot=true;
      }
      *executed = true;
      return;
    case 0x08: // ADDI
      // Perform the addition and store the result in the rt register
      registre_set(registers, rt, register_get(registers, rs) + SignExtImm);
      *executed = true;
      break;
    case 0x09: // ADDIU
      // Perform the addition and store the result in the rt register
      registre_set(registers, rt, register_get(registers, rs) + immediate);
      *executed = true;
      break;
    case 0x0F: // LUI
      // Shift the immediate value left by 16 bits and store the result in the rt register
      registre_set(registers, rt, immediate << 16);
      *executed = true;
      break;
    case 0x23: // LW
      //TODO registre_set(registers, rt,);
      registre_set(registers, rt,memory_get(ram,immediate+(int32_t)register_get(registers, rs)));
      *executed = true;
      break;
    case 0x2B: // SW
      //TODO registre_set(registers, rt,);
      memory_set(ram,immediate+(int32_t)register_get(registers, rs),register_get(registers, rt));
      *executed = true;
      break;
    case 0x29:
      // TODO
      //  Handle SH instruction
      //  Store the least significant half-word of the value in the rt register at the specified address in memory
      //     memory[registers[rs] + immediate] = register_get(registers,rt) & 0xFFFF;
      *executed = true;
      break;
    case 0x26:
      // Handle XORI instruction
      // Perform the bitwise XOR and store the result in the rt register
      registre_set(registers, rt, register_get(registers, rs) ^ immediate);
      *executed = true;
      break;
    }
  }
}
void J_type_inst(uint32_t instr, register_pc *registers, bool *executed) {
  if (!(*executed)) {
    uint32_t opcode = part_get(instr, 26, 31);
    uint32_t address = part_get(instr, 0, 25);
    //TODO !!
    // printf("opcode:%08x|%08x|%08x\n",opcode,address,pc_get(registers)+4);
    switch (opcode) {
    case 0x2:// J
      pc_set(registers, address*4 - 4);
      *executed = true;
      break;
    case 0x3:// JAL
      registre_set(registers, 31, pc_get(registers) + 8);
      pc_set(registers, address*4-4);
      *executed = true;
      break;
    }
  }
}
void R_type_inst(uint32_t instr, register_pc *registers, bool *executed) {
  uint32_t opcode = part_get(instr, 26, 31);
  if (!(*executed) && opcode == 0) {
    uint32_t funct_field = part_get(instr, 0, 5);
    uint32_t shamt_field = part_get(instr, 6, 10);
    uint32_t rd = part_get(instr, 11, 15);
    uint32_t rt = part_get(instr, 16, 20);
    uint32_t rs = part_get(instr, 21, 26);
    // printf("func:%x\n",funct_field);
    switch (funct_field) {
      case 0x0C://SYSCALL
      registers->error=true;
      *executed = true;
      break;
    case 0x08:// JR
      pc_set(registers, register_get(registers, rs) - 4);
      *executed = true;
      break;
    case 0x2A:
      // Handle SLT instruction
      if (register_get(registers, rs) < register_get(registers, rt)) {
        registre_set(registers, rd, 1);
      } else {
        registre_set(registers, rd, 0);
      }
      *executed = true;
      break;
    case 0x10:
      // Handle MFHI instruction
      registre_set(registers, rd, registers->HI);
      *executed = true;
      break;
    case 0x12:
      // Handle MFLO instruction
      registre_set(registers, rd, registers->LO);
      *executed = true;
      break;
    case 0x26:
      // Handle XOR instruction
      // Extract the register numbers
      // Perform the bitwise XOR and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) ^ register_get(registers, rt));
      *executed = true;
      break;
    case 0x20:// ADD
      // Perform the addition and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) + register_get(registers, rt));
      *executed = true;
      break;
    case 0x21:
      // Handle ADDU instruction
      // Extract the register numbers
      // Perform the addition and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) + register_get(registers, rt));
      *executed = true;
      break;
    case 0x24:// AND
      registre_set(registers, rd, register_get(registers, rs) & register_get(registers, rt));
      *executed = true;
      break;
    case 0x1A:// DIV
      // Divide the values in the rs and rt registers and store the result in the LO and HI registers
      registers->LO = register_get(registers, rs) / register_get(registers, rt);
      registers->HI = register_get(registers, rs) % register_get(registers, rt);
      *executed = true;
      break;
    case 0x18:// MULT
      // Multiply the values in the rs and rt registers and store the result in the LO and HI registers
      registers->LO = (int32_t)((int64_t)register_get(registers, rs) * (int64_t)register_get(registers, rt)) & 0xFFFFFFFF;
      registers->HI = (int32_t)(((int64_t)register_get(registers, rs) * (int64_t)register_get(registers, rt)) >> 32) & 0xFFFFFFFF;
      *executed = true;
      break;
    case 0x25:// OR
      // Perform the bitwise OR and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) | register_get(registers, rt));
      *executed = true;
      break;
    case 0x00:
      // Handle SLL instruction
      // Extract the register numbers and shift amount
      // Shift the value in the rt register left by the specified amount and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rt) << shamt_field);
      *executed = true;
      break;

    case 0x02:
      // Handle SRL instruction
      // Extract the register numbers and shift amount
      // Shift the value in the rt register right by the specified amount and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rt) >> shamt_field);
      *executed = true;
      break;
    case 0x22:
      // Handle SUB instruction
      // Extract the register numbers
      // Perform the subtraction and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) - register_get(registers, rt));
      *executed = true;
      break;
    case 0x23:
      // TODO error LOL
      //  Handle SUBU instruction
      //  Extract the register numbers
      //  Perform the subtraction and store the result in the rd register
      registre_set(registers, rd, register_get(registers, rs) - register_get(registers, rt));
      *executed = true;
      break;
    }
  }
}

void execute_instruction(uint32_t instruction, register_pc *registers,memory* ram) {
  bool executed = false;
  // printf("%d\n",instruction);
  J_type_inst(instruction, registers, &executed);
  R_type_inst(instruction, registers, &executed);
  I_type_inst(instruction, registers,ram, &executed);
  if (!executed) {
    printf("%x command not found\n", instruction);
    exit(8);
  }
}