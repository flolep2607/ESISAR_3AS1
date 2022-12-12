#include "execution.h"
uint8_t registers[50] = {
    0};
// set_register((int)addresse,int32_t value)
void R_type_inst(uint8_t funct, uint32_t instruction, register_pc *registers)
{
  uint8_t rd = (instruction >> 11) & 0x1F;
  uint8_t sa = (instruction >> 6) & 0x1F;
  uint8_t rs = (instruction >> 21) & 0x1F;
  uint8_t rt = (instruction >> 16) & 0x1F;
  switch (funct)
  {
  case 0x26:
    // Handle XOR instruction
    // Extract the register numbers
    // Perform the bitwise XOR and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) ^ get_register(registers,rt));
    break;
  case 0x20:
    // Handle ADD instruction
    // Extract the register numbers
    // Perform the addition and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) + get_register(registers,rt));
    break;
  case 0x21:
    // Handle ADDU instruction
    // Extract the register numbers
    // Perform the addition and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) + get_register(registers,rt));
    break;
  case 0x24:
    // Handle AND instruction
    // Extract the register numbers
    // Perform the bitwise AND and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) & get_register(registers,rt));
    break;
  case 0x1A:
    // Handle DIV instruction
    // Extract the register numbers
    // Divide the values in the rs and rt registers and store the result in the LO and HI registers
    registers->LO = get_register(registers,rs) / get_register(registers,rt);
    registers->HI = get_register(registers,rs) % get_register(registers,rt);
    break;
  case 0x1B:
    // Handle DIVU instruction
    // Extract the register numbers
    // Divide the values in the rs and rt registers and store the result in the LO and HI registers
    registers->LO = get_register(registers,rs) / get_register(registers,rt);
    registers->HI = get_register(registers,rs) % get_register(registers,rt);
    break;
  case 0x18:
    // Handle MULT instruction
    // Extract the register numbers
    // Multiply the values in the rs and rt registers and store the result in the LO and HI registers
    registers->LO = (int32_t)((int64_t)get_register(registers,rs) * (int64_t)get_register(registers,rt)) & 0xFFFFFFFF;
    registers->HI = (int32_t)(((int64_t)get_register(registers,rs) * (int64_t)get_register(registers,rt)) >> 32) & 0xFFFFFFFF;
    break;
  case 0x25:
    // Handle OR instruction
    // Extract the register numbers
    // Perform the bitwise OR and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) | get_register(registers,rt));
    break;
  case 0x00:
    // Handle SLL instruction
    // Extract the register numbers and shift amount
    // Shift the value in the rt register left by the specified amount and store the result in the rd register
    set_register(registers,rd,get_register(registers,rt) << sa);
    break;
  case 0x02:
    // Handle SRL instruction
    // Extract the register numbers and shift amount
    // Shift the value in the rt register right by the specified amount and store the result in the rd register
    set_register(registers,rd,get_register(registers,rt) >> sa);
    break;
  case 0x22:
    // Handle SUB instruction
    // Extract the register numbers
    // Perform the subtraction and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) - get_register(registers,rt));
     break;
  case 0x23:
  //TODO error LOL
    // Handle SUBU instruction
    // Extract the register numbers
    // Perform the subtraction and store the result in the rd register
    set_register(registers,rd,get_register(registers,rs) - get_register(registers,rt));
     break;
  }
}
void J_type_inst(uint32_t instruction, register_pc *registers)
{
  uint32_t target = 0;
  switch (instruction & 0x3F)
  {
  case 0x00:
    // Handle J instruction
    // Extract the target address
    target = instruction & 0x3FFFFFF;
    // Jump to the target address
    set_pc(registers, target);
    break;
  case 0x02:
    // Handle JAL instruction
    // Extract the target address
    target = instruction & 0x3FFFFFF;
    // Save the return address in the ra register
    set_register(registers,31,get_pc(registers));
    // Jump to the target address
    set_pc(registers, target);
    break;
    // Add cases for other J-type instructions
    // ...
  }
}
void I_type_inst(uint32_t instruction, register_pc *registers)
{
  uint8_t rt = (instruction >> 16) & 0x1F;
  uint8_t rs = (instruction >> 21) & 0x1F;
  uint8_t imm = instruction & 0xFFFF;
  switch (instruction & 0x3F)
  {
  case 0x08:
    // Handle ADDI instruction
    // Perform the addition and store the result in the rt register
    set_register(registers,rt,get_register(registers,rs) + imm);
    break;
  case 0x0C:
    // Handle ANDI instruction
    // Perform the bitwise AND and store the result in the rt register
    set_register(registers,rt,get_register(registers,rs) & imm);
    break;
  case 0x09:
    // Handle ADDIU instruction
    // Perform the addition and store the result in the rt register
    set_register(registers,rt,get_register(registers,rs) + imm);
    break;
  case 0x24:
    // Handle LBU instruction
    // Load a byte from memory and sign-extend it to a word, then store it in the rt register
//    registers[rt] = (int32_t)(int8_t)memory[registers[rs] + imm];
    break;
  case 0x25:
    // Handle LHU instruction
    // Load a half-word from memory and sign-extend it to a word, then store it in the rt register
//    registers[rt] = (int32_t)(int16_t)memory[registers[rs] + imm];
    break;
  case 0x30:
    // Handle LL instruction
    // Load a word from memory and store it in the rt register
//    registers[rt] = memory[registers[rs] + imm];
    break;
  case 0x0F:
    // Handle LUI instruction
    // Shift the immediate value left by 16 bits and store the result in the rt register
    set_register(registers,rt, imm << 16);
    break;
  case 0x0D:
    // Handle ORI instruction
    // Perform the bitwise OR and store the result in the rt register
    set_register(registers,rt,get_register(registers,rs) | imm);
    break;
  case 0x28:
    // Handle SB instruction
    // Store the least significant byte of the value in the rt register at the specified address in memory
//    memory[registers[rs] + imm] = get_register(registers,rt) & 0xFF;
    break;
  case 0x38:
    // Handle SC instruction
    // Store the value in the rt register at the specified address in memory
//    memory[registers[rs] + imm] = get_register(registers,rt);
    // Set the least significant bit of the rt register to 1 if the store was successful, or 0 if it was not
//    registers[rt] = memory[registers[rs] + imm] = = get_register(registers,rt) ? 1 : 0;
    break;
  case 0x29:
    // Handle SH instruction
    // Store the least significant half-word of the value in the rt register at the specified address in memory
//    memory[registers[rs] + imm] = get_register(registers,rt) & 0xFFFF;
    break;
  case 0x26:
    // Handle XORI instruction
    // Perform the bitwise XOR and store the result in the rt register
    set_register(registers,rt,get_register(registers,rs) ^ imm);
    break;
  }
}
void execute_instruction(uint32_t instruction, register_pc *registers)
{
  //TODO increase_pc+4 pour chaque sinon boucle
  // Extract the opcode from the instruction
  uint8_t opcode = instruction >> 26;
  uint8_t funct = instruction & 0x3F;
  uint32_t target_address = 0;
  uint8_t rs = (instruction >> 21) & 0x1F;
  uint8_t rt = (instruction >> 16) & 0x1F;
  int16_t imm = instruction & 0xFFFF;
  // Handle the different types of instructions
  switch (opcode)
  {
  case 0:
    R_type_inst(funct, instruction, registers);
    break;
  case 2:
    J_type_inst(instruction, registers);
    break;
  case 3:
    // JAL
    //  Extract the target address
    target_address = instruction & 0x3FFFFFF;
    // Set the program counter to the target address and store the current PC+4 in the RA register
    set_register(registers,31,get_pc(registers) + 4);
    set_pc(registers, target_address);
    break;
  case 4:
    // BEQ
    //  Compare the values in the registers and branch if they are equal
    if (get_register(registers,rs) == get_register(registers,rt))
    {
      increase_pc(registers,imm);
    }
    break;
  case 5:
    // Compare the values in the registers and branch if they are not equal
    if (get_register(registers,rs) != get_register(registers,rt))
    {
      increase_pc(registers,imm);
    }
    break;
  case 35:
    // Load the value from memory at the specified address and store it in the rt register
//    registers[rt] = memory[registers[rs] + imm];
    break;
  case 43:
    // Store the value in the rt register at the specified address in memory
//    memory[registers[rs] + imm] = get_register(registers,rt);
    break;
  default:
    I_type_inst(instruction, registers);
    break;
  }
}