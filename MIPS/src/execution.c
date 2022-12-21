#include "execution.h"
uint8_t registers[50] = {0};
// set_register((int)addresse,int32_t value)
void I_type_inst(uint32_t instr, register_pc *registers, bool *executed) {
  if (!(*executed)) {
    uint32_t opcode = get_part(instr, 26, 30);
    uint32_t rs = get_part(instr, 21, 25);
    uint32_t rt = get_part(instr, 16, 20);
    uint32_t immediate = get_part(instr, 0, 15);
    int32_t SignExtImm;

    if (immediate >> 15) {
      SignExtImm = immediate | 0xFFFF0000;
    } else {
      SignExtImm = immediate;
    }
    switch (opcode) {
    case 0x00000005:
      if (get_register(registers, rs) != get_register(registers, rt)) {
        increase_pc(registers, SignExtImm - 4);
      }
      *executed = true;
      return;
    case 0x07:
      // Handle BGTZ instruction
      if (get_register(registers, rs) > 0) {
        increase_pc(registers, SignExtImm - 4);
      }
      *executed = true;
      return;
    case 0x08:
      // Handle ADDI instruction
      // Perform the addition and store the result in the rt register
      set_register(registers, rt, get_register(registers, rs) + SignExtImm);
      *executed = true;
      break;
    case 0x0C:
      // Handle ANDI instruction
      // Perform the bitwise AND and store the result in the rt register
      set_register(registers, rt, get_register(registers, rs) & SignExtImm);
      *executed = true;
      break;
    case 0x09:
      // Handle ADDIU instruction
      // Perform the addition and store the result in the rt register
      set_register(registers, rt, get_register(registers, rs) + immediate);
      *executed = true;
      break;
    case 0x24:
    //TODO
      // Handle LBU instruction
      // Load a byte from memory and sign-extend it to a word, then store it in the rt register
      //    registers[rt] = (int32_t)(int8_t)memory[registers[rs] + immediate];
      *executed = true;
      break;
    case 0x25:
    //TODO
      // Handle LHU instruction
      // Load a half-word from memory and sign-extend it to a word, then store it in the rt register
      //    registers[rt] = (int32_t)(int16_t)memory[registers[rs] + immediate];
      *executed = true;
      break;
    case 0x30:
    //TODO
      // Handle LL instruction
      // Load a word from memory and store it in the rt register
      //    registers[rt] = memory[registers[rs] + immediate];
      *executed = true;
      break;
    case 0x0F:
      // Handle LUI instruction
      // Shift the immediate value left by 16 bits and store the result in the rt register
      set_register(registers, rt, immediate << 16);
      *executed = true;
      break;
    case 0x0D:
      // Handle ORI instruction
      // Perform the bitwise OR and store the result in the rt register
      set_register(registers, rt, get_register(registers, rs) | immediate);
      *executed = true;
      break;
    case 0x28:
    //TODO
      // Handle SB instruction
      // Store the least significant byte of the value in the rt register at the specified address in memory
      //    memory[registers[rs] + immediate] = get_register(registers,rt) & 0xFF;
      *executed = true;
      break;
    case 0x38:
    //TODO
      // Handle SC instruction
      // Store the value in the rt register at the specified address in memory
      //    memory[registers[rs] + immediate] = get_register(registers,rt);
      // Set the least significant bit of the rt register to 1 if the store was successful, or 0 if it was not
      //    registers[rt] = memory[registers[rs] + immediate] = = get_register(registers,rt) ? 1 : 0;
      *executed = true;
      break;
    case 0x29:
    //TODO
      // Handle SH instruction
      // Store the least significant half-word of the value in the rt register at the specified address in memory
      //    memory[registers[rs] + immediate] = get_register(registers,rt) & 0xFFFF;
      *executed = true;
      break;
    case 0x26:
      // Handle XORI instruction
      // Perform the bitwise XOR and store the result in the rt register
      set_register(registers, rt, get_register(registers, rs) ^ immediate);
      *executed = true;
      break;
    }
  }
}
void J_type_inst(uint32_t instr, register_pc *registers, bool *executed) {
  if (!(*executed)) {
    uint32_t opcode = get_part(instr, 25, 31);
    uint32_t address = get_part(instr, 0, 26);
    switch (opcode) {
    case 0x2:
      set_pc(registers, address - 4);
      *executed = true;
      break;
    case 0x3:
      set_register(registers, 31, get_pc(registers) + 4);
      set_pc(registers, address - 4);
      *executed = true;
      break;
    }
  }
}
void R_type_inst(uint32_t instr, register_pc *registers, bool *executed) {
  uint32_t opcode = get_part(instr, 26, 31);
  if (!(*executed) && opcode == 0) {
    uint32_t funct_field = get_part(instr, 0, 5);
    uint32_t shamt_field = get_part(instr, 6, 10);
    uint32_t rd = get_part(instr, 11, 15);
    uint32_t rt = get_part(instr, 16, 20);
    uint32_t rs = get_part(instr, 21, 26);
    // printf("func:%x\n",funct_field);
    switch (funct_field) {
    case 0x08:
      set_pc(registers, get_register(registers, rs) - 4);
      *executed = true;
      break;
    case 0x2A:
      // Handle SLT instruction
      if (get_register(registers, rs) < get_register(registers, rt)) {
        set_register(registers, rd, 1);
      } else {
        set_register(registers, rd, 0);
      }
      *executed = true;
      break;
    case 0x10:
      // Handle MFHI instruction
      set_register(registers, rd, registers->HI);
      *executed = true;
      break;
    case 0x12:
      // Handle MFLO instruction
      set_register(registers, rd, registers->LO);
      *executed = true;
      break;
    case 0x26:
      // Handle XOR instruction
      // Extract the register numbers
      // Perform the bitwise XOR and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) ^ get_register(registers, rt));
      *executed = true;
      break;
    case 0x20:
      // Handle ADD instruction
      // Extract the register numbers
      // Perform the addition and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) + get_register(registers, rt));
      *executed = true;
      break;
    case 0x21:
      // Handle ADDU instruction
      // Extract the register numbers
      // Perform the addition and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) + get_register(registers, rt));
      *executed = true;
      break;
    case 0x24:
      // Handle AND instruction
      // Extract the register numbers
      // Perform the bitwise AND and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) & get_register(registers, rt));
      *executed = true;
      break;
    case 0x1A:
      // Handle DIV instruction
      // Extract the register numbers
      // Divide the values in the rs and rt registers and store the result in the LO and HI registers
      registers->LO = get_register(registers, rs) / get_register(registers, rt);
      registers->HI = get_register(registers, rs) % get_register(registers, rt);
      *executed = true;
      break;
    case 0x1B:
      // Handle DIVU instruction
      // Extract the register numbers
      // Divide the values in the rs and rt registers and store the result in the LO and HI registers
      registers->LO = (uint32_t)get_register(registers, rs) / (uint32_t)get_register(registers, rt);
      registers->HI = (uint32_t)get_register(registers, rs) % (uint32_t)get_register(registers, rt);
      *executed = true;
      break;
    case 0x18:
      // Handle MULT instruction
      // Extract the register numbers
      // Multiply the values in the rs and rt registers and store the result in the LO and HI registers
      registers->LO = (int32_t)((int64_t)get_register(registers, rs) * (int64_t)get_register(registers, rt)) & 0xFFFFFFFF;
      registers->HI = (int32_t)(((int64_t)get_register(registers, rs) * (int64_t)get_register(registers, rt)) >> 32) & 0xFFFFFFFF;
      *executed = true;
      break;
    case 0x25:
      // Handle OR instruction
      // Extract the register numbers
      // Perform the bitwise OR and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) | get_register(registers, rt));
      *executed = true;
      break;
    case 0x00:
      // Handle SLL instruction
      // Extract the register numbers and shift amount
      // Shift the value in the rt register left by the specified amount and store the result in the rd register
      set_register(registers, rd, get_register(registers, rt) << shamt_field);
      *executed = true;
      break;

    case 0x02:
      // Handle SRL instruction
      // Extract the register numbers and shift amount
      // Shift the value in the rt register right by the specified amount and store the result in the rd register
      set_register(registers, rd, get_register(registers, rt) >> shamt_field);
      *executed = true;
      break;
    case 0x22:
      // Handle SUB instruction
      // Extract the register numbers
      // Perform the subtraction and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) - get_register(registers, rt));
      *executed = true;
      break;
    case 0x23:
      // TODO error LOL
      //  Handle SUBU instruction
      //  Extract the register numbers
      //  Perform the subtraction and store the result in the rd register
      set_register(registers, rd, get_register(registers, rs) - get_register(registers, rt));
      *executed = true;
      break;
    }
  }
}

void execute_instruction(uint32_t instruction, register_pc *registers) {
  bool executed = false;
  J_type_inst(instruction, registers, &executed);
  R_type_inst(instruction, registers, &executed);
  I_type_inst(instruction, registers, &executed);
  if (!executed) {
    printf("%x command not found\n", instruction);
    exit(-1);
  }
}