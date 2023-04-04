#include "Memory_Module.h"
#include "Compile_Module.h"
#include "Execution_Module.h"

#define BIT5MASK 0x1F
#define BIT6MASK 0x3F
#define BIT16MASK 0xFFFF
#define BIT26MASK 0x3FFFFFF

int Exception_Flag;

int isHALT(uint32_t instruction){
	return (instruction == HALT);
}


void execute_instruction(int inst){
	
	uint8_t SPECIAL, rs, rt, rd, sa;
	int16_t imm;
	uint32_t target;
	
	long temp;
	
	SPECIAL = (inst>>26)& BIT6MASK;
	rs = 	  (inst>>21)& BIT5MASK;
	rt = 	  (inst>>16)& BIT5MASK;
	rd = 	  (inst>>11)& BIT5MASK;
	sa = 	  (inst>>6) & BIT5MASK;
	//OP = 	  (inst)	& BIT6MASK;
	imm = 	  (inst)	& BIT16MASK;
	target =  (inst)	& BIT26MASK;
	
	if (!SPECIAL) SPECIAL = (inst&BIT6MASK)+0x80;
	
	/* -- Main part -- */
	
	switch(SPECIAL){
		/* Opcode defined in CPU_Struct.h */
		case ADD: puts("ADD");
			temp=GPR[rs]+GPR[rt];
			if (temp>>31) /*( ((temp>>30)&1) != ((temp>>31)&1) )*/
			/* SignalException(IntergerOverflow) */
				{puts("IntergerOverflow");}
			else
				GPR[rd]=temp/*&0xFFFF*/;
			break;
			
		case ADDI: puts("ADDI");
			temp=GPR[rs]+imm;
			if ( ((temp>>30)&1) != ((temp>>31)&1) )
			/* SignalException(IntergerOverflow) */
				{puts("IntergerOverflow");}
			else
				GPR[rt]=temp;
			break;
			
		case AND: puts("AND");
			GPR[rd] = GPR[rs] & GPR[rt];
			break;
		
		case BEQ: puts("BEQ");
			printf("imm: %d\n",imm);
			if (GPR[rs]==GPR[rt]) CPU.PC += imm*4;
			/* On multiplie par 4 au lieu de shift à gauche pour préserver le signe */
			break;
			
		case BGTZ: puts("BGTZ");
			//execute_instruction( read_word(CPU.PC) );
			if (GPR[rs]>0) CPU.PC += imm*4;
			//else CPU.PC +=4;
			break;
			
		case BLEZ: puts("BLEZ");
			if (GPR[rs]<=0) CPU.PC += imm*4;
			break;
			
		case BNE: puts("BNE");
			if (GPR[rs]!=GPR[rt]) CPU.PC += imm*4;
			break;
			
		case DIV: puts("DIV");
			/*if (GPR[rt]!=0)*/ /*dividing by zero should have unpredictable result*/
			CPU.LO = GPR[rs] / GPR[rt];
			CPU.HI = GPR[rs] % GPR[rt];
			break;
			
		case JAL: puts("JAL");
			GPR[31]=CPU.PC+8;
			//implicit_fallthrough
			__attribute__ ((fallthrough));
		case J: puts("J");
			execute_instruction( read_word(CPU.PC) );
			CPU.PC = target<<2 CPU.PC&0xF0000000;
			break;
			
		case JR: puts("JR");
			execute_instruction( read_word(CPU.PC) );
			CPU.PC = GPR[rs]<<2 CPU.PC&0xF0000000;
			break;
			
		case LUI: puts("LUI");
			GPR[rt] = imm<<16;
			break;
		
		case LW: puts("LW");
		/* rs is base, imm is offset */
			temp=GPR[rs]+imm;
			if ( temp%4 )
			/* SignalException(AddressError) */
				{puts("AddressError");}
			else
				GPR[rt] = read_word(temp);
			break;
		
		case MFHI: puts("MFHI");
			GPR[rd] = CPU.HI;
			break;
			
		case MFLO: puts("MFLO");
			GPR[rd] = CPU.LO;
			break;
		
		case MULT: puts("MULT");
			temp = GPR[rs] * GPR[rt] ;
			CPU.LO = temp&0x0000FFFF;
			CPU.HI = temp&0xFFFF0000;
			break;
			
		case OR: puts("OR");
			GPR[rd] = GPR[rs] | GPR[rt];
			break;
			
		case SLL: puts("SLL");
			GPR[rd] = GPR[rt] << sa;
			break;
		
		case SLT: puts("SLT");
			GPR[rd] = (GPR[rs] < GPR[rt]);
			break;
			
		case SRL: 
			if (rs == 1){
				puts("ROTR");
				GPR[rd] = (GPR[rt]<<sa) | (GPR[rt]>>(32-sa));
			} else {
				puts("SRL");
				GPR[rd] = GPR[rt] >> sa;
			}
			break;
			
		case SUB: puts("SUB");
			temp=GPR[rs]-GPR[rt];
			if ( ((temp>>30)&1) == ((temp>>31)&1) )
			/* SignalException(IntergerOverflow) */
				{puts("IntergerOverflow");}
			else
				GPR[rd]=temp/*&0xFFFF*/;
			break;
			
		case SW: puts("SW");
			/* rs is base, imm is offset */
			temp=GPR[rs]+imm;
			if ( temp%4 )
			/* SignalException(AddressError) */
				{printf("addr: %ld\t->\t",temp);
				puts("AddressError");}
			else
				write_word(temp, GPR[rt]);
			break;
		
		case XOR: puts("XOR");
			GPR[rd] = GPR[rs] ^ GPR[rt];
			break;
		
		default:
			puts("non implémenté");
	}
	
}

void execute_program(){
	
	uint32_t inst;
	inst = read_word(CPU.PC);
	
	
	
	int i=0;
	while( !isHALT(inst) && i++<40){
		
		printf("PC:%X\n",CPU.PC);
		inst = read_word(CPU.PC);
		
		CPU.PC += 4;
		
		printf("instruction: %08X\n",inst);
		
		execute_instruction(inst);
		
		puts("");
	
	}
	reg_state_print();
	mem_print();//_until_address(0x8000);
	
}