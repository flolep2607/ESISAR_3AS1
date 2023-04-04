#include "MIPS.h"

// #define DEBUG_BITS
#define BIT5MASK 0b11111
#define BIT6MASK 0b11111
#define UNDEFINED 0

void printBitos(size_t const size, void const * const ptr){
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
	int cnt=1;
	int cnt2=0;
	printf(" ");
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
			if(cnt == 5 && cnt2 > 0){
				printf(" "); cnt2--; cnt = 0;
			}
			if (cnt == 6) {
				printf(" "); cnt2=4; cnt = 0;
			} cnt++;
        }
    }
    puts("");
	printf("%6s %5s %5s %5s %5s %6s\n","SPECIAL","rs","rt","rd","sa","OP");
}
void printBits(long unsigned int nb, size_t const size, void const * const ptr){
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            if((size*i+j)<nb)printf("%u", byte);
        }
    }
}

uint8_t str2reg(char* str){
	uint8_t regnum = 0;
	if (str[0] == '\0') ;
	else if (!strcmp(str,"$zero")) regnum = 0;
	else if (!strcmp(str,"$at")) regnum = 1;
	else if (!strcmp(str,"$v0")) regnum = 2;
	else if (!strcmp(str,"$v1")) regnum = 3;
	else if (!strcmp(str,"$a0")) regnum = 4;
	else if (!strcmp(str,"$a1")) regnum = 5;
	else if (!strcmp(str,"$a2")) regnum = 6;
	else if (!strcmp(str,"$a3")) regnum = 7;
	else if (!strcmp(str,"$t0")) regnum = 8;
	else if (!strcmp(str,"$t1")) regnum = 9;
	else if (!strcmp(str,"$t2")) regnum = 10;
	else if (!strcmp(str,"$t3")) regnum = 11;
	else if (!strcmp(str,"$t4")) regnum = 12;
	else if (!strcmp(str,"$t5")) regnum = 13;
	else if (!strcmp(str,"$t6")) regnum = 14;
	else if (!strcmp(str,"$t7")) regnum = 15;
	else if (!strcmp(str,"$s0")) regnum = 16;
	else if (!strcmp(str,"$s1")) regnum = 17;
	else if (!strcmp(str,"$s2")) regnum = 18;
	else if (!strcmp(str,"$s3")) regnum = 19;
	else if (!strcmp(str,"$s4")) regnum = 20;
	else if (!strcmp(str,"$s5")) regnum = 21;
	else if (!strcmp(str,"$s6")) regnum = 22;
	else if (!strcmp(str,"$s7")) regnum = 23;
	else if (!strcmp(str,"$t8")) regnum = 24;
	else if (!strcmp(str,"$t9")) regnum = 25;
	else if (!strcmp(str,"$k0")) regnum = 26;
	else if (!strcmp(str,"$k1")) regnum = 27;
	else if (!strcmp(str,"$gp")) regnum = 28;
	else if (!strcmp(str,"$sp")) regnum = 29;
	else if (!strcmp(str,"$fp")) regnum = 30;
	else if (!strcmp(str,"$ra")) regnum = 31;
	else if (!strcmp(str,"$0")) regnum = 0;
	else if (!strcmp(str,"$1")) regnum = 1;
	else if (!strcmp(str,"$2")) regnum = 2;
	else if (!strcmp(str,"$3")) regnum = 3;
	else if (!strcmp(str,"$4")) regnum = 4;
	else if (!strcmp(str,"$5")) regnum = 5;
	else if (!strcmp(str,"$6")) regnum = 6;
	else if (!strcmp(str,"$7")) regnum = 7;
	else if (!strcmp(str,"$8")) regnum = 8;
	else if (!strcmp(str,"$9")) regnum = 9;
	else if (!strcmp(str,"$10")) regnum = 10;
	else if (!strcmp(str,"$11")) regnum = 11;
	else if (!strcmp(str,"$12")) regnum = 12;
	else if (!strcmp(str,"$13")) regnum = 13;
	else if (!strcmp(str,"$14")) regnum = 14;
	else if (!strcmp(str,"$15")) regnum = 15;
	else if (!strcmp(str,"$16")) regnum = 16;
	else if (!strcmp(str,"$17")) regnum = 17;
	else if (!strcmp(str,"$18")) regnum = 18;
	else if (!strcmp(str,"$19")) regnum = 19;
	else if (!strcmp(str,"$20")) regnum = 20;
	else if (!strcmp(str,"$21")) regnum = 21;
	else if (!strcmp(str,"$22")) regnum = 22;
	else if (!strcmp(str,"$23")) regnum = 23;
	else if (!strcmp(str,"$24")) regnum = 24;
	else if (!strcmp(str,"$25")) regnum = 25;
	else if (!strcmp(str,"$26")) regnum = 26;
	else if (!strcmp(str,"$27")) regnum = 27;
	else if (!strcmp(str,"$28")) regnum = 28;
	else if (!strcmp(str,"$29")) regnum = 29;
	else if (!strcmp(str,"$30")) regnum = 30;
	else if (!strcmp(str,"$31")) regnum = 31;
	return regnum;
}

int inst2hex(char * inst){
	unsigned int hex=0;
	char name[10]="";
	char arg1[20]="";
	char arg2[20]="";
	char arg3[20]="";
	
	for(int i=0; (inst[i]!='\0'); i++) if(inst[i] == ',') inst[i] = ' ';
	
	sscanf(inst, "%s %s %s %s",name,arg1,arg2,arg3);
	//if(name[0] == '#') return(0);
	
	// printf("1:%s\n2:%s\n3:%s\n",arg1,arg2,arg3);
	
	uint8_t SPECIAL, rs, rt, rd, sa, OP;
	uint16_t imm;
	uint32_t target;
	/* Ordre
		SPECIAL : 6 bits
		rs      : 5 bits
		rt      : 5 bits
		rd      : 5 bits | ou imm 
		sa      : 5 bits | ou offset
		OP      : 6 bits | 16 bits
	*/
	SPECIAL = rs = rt = rd = sa = OP = 0;
	imm = 0;
	target = 0;
	
	char category = 0;
	_Bool nonsigne = 1;
	
	
	/* ADD rd,rs,rt */
	if(strcmp("ADD",name)==0){//OK
		category = 'R';
		OP = 0b100000;
	} else
	if(!strcmp("ADDI",name)){//OK
		SPECIAL = 0b001000;
		category = 'I';
		nonsigne=0;
	} else
	if(!strcmp("SUB",name)){
		category = 'R';
		OP = 0b100010;
	} else
	if(!strcmp("MULT",name)){
		category = 4;//pas vraiment, rd = sa = 0
		OP = 0b011000;
	} else
	if(!strcmp("DIV",name)){
		rs=str2reg(arg1);
		rt=str2reg(arg2);
		OP = 0b011010;
	} else
	
	if(!strcmp("AND",name)){
		category = 'R';
		OP = 0b100100;
	} else
	if(!strcmp("OR",name)){
		category = 'R';
		OP = 0b100101;
	} else
	if(!strcmp("XOR",name)){
		category = 'R';
		OP = 0b100110;
	} else
	
	if(!strcmp("ROTR",name)){
		OP = 0b000010;
		rs = 1;
		category = 'S';
	} else
	if(!strcmp("SLL",name)){
		// SPECIAL = 0b000000;
		category = 'S';
	} else
	if(!strcmp("SRL",name)){
		OP = 0b000010;
		category = 'S';
	} else
	
	if(!strcmp("SLT",name)){
		category = 'R';
		OP = 0b101010;
	} else
	
	if(!strcmp("LW",name)){
		SPECIAL = 0b100011;
		rt = str2reg(arg1);
		sscanf(arg2,"%hud(%hhud)",&imm,&rs);//triste :(
		sscanf(arg2,"%*d(%hhud)",&rs);
	} else
	if(!strcmp("SW",name)){
		SPECIAL = 0b101011;
		rt = str2reg(arg1);
		sscanf(arg2,"%hud(%hhud)",&imm,&rs);//triste :(
		sscanf(arg2,"%*d(%hhud)",&rs);
	} else
	if(!strcmp("LUI",name)){
		SPECIAL = 0b001111;
		rt = str2reg(arg1);
		sscanf(arg2,"%hud",&imm);
	} else
	if(!strcmp("MFHI",name)){
		category = 'R';//pas vraiment, rs = rt = sa = 0
		OP = 0b010000;
	} else
	if(!strcmp("MFLO",name)){
		category = 'R';//pas vraiment, rs = rt = sa = 0
		OP = 0b010010;
	} else
	
	if(!strcmp("BEQ",name)){
		SPECIAL = 0b000100;
		category = 4;
	} else
	if(!strcmp("BNE",name)){
		SPECIAL = 0b000101;
		category = 4;
	} else
	if(!strcmp("BGTZ",name)){
		SPECIAL = 0b000111;
		category = 5;
	} else
	if(!strcmp("BLEZ",name)){
		SPECIAL = 0b000110;
		category = 5;
	} else
	if(!strcmp("J",name)){
		SPECIAL = 0b000010;
		sscanf(arg1,"%ud",&target);
	} else
	if(!strcmp("JAL",name)){
		SPECIAL = 0b000011;
		sscanf(arg1,"%ud",&target);
	} else
	if(!strcmp("JR",name)){
		OP = 0b001000;
		category = 4; // special case, rt and offset = 0, same as rs = str2reg(arg1)
	} else
	
	if(!strcmp("NOP",name)){
		;//everything is already set to 0 by default
	}
	
	switch(category){
		case 'R': // INST rd,rs,rt
			rs = str2reg(arg2);
			rt = str2reg(arg3);
			rd = str2reg(arg1);
			break;
		case 'I': // INST rt,rs,imm
			rs = str2reg(arg2);
			rt = str2reg(arg1);
			if (nonsigne) sscanf(arg3,"%hud",&imm);
			else sscanf(arg3,"%hd",&imm);
			break;
		case 'J': // INST target
			break;
		case 4: // INST rs, rt, offset
			rs = str2reg(arg1);
			rt = str2reg(arg2);
			sscanf(arg3,"%hud",&imm);
			break;
		case 5: // INST rs, offset
			rs = str2reg(arg1);
			sscanf(arg2,"%hud",&imm);
			break;
		case 'S': // INST rd,rt,sa
			rt = str2reg(arg2);
			rd = str2reg(arg1);
			sscanf(arg3,"%hhud",&sa);
			break;
		case 'T': // INST rd,rt,rs
			rs = str2reg(arg3);
			rt = str2reg(arg2);
			rd = str2reg(arg1);
			break;
		case 0:
		default: 
			break;
	}
	
	
	target |= imm;
	
	/* assert size */
	SPECIAL &= 0b111111;
	rs &= 0b11111;
	rt &= 0b11111;
	rd &= 0b11111;
	sa &= 0b11111;
	OP &= 0b111111;
	target &=0x3FFFFFF;
	
	/* fill hex value */
	 				hex |= SPECIAL;
	hex <<= 5;		hex |= rs;
	hex <<= 5;		hex |= rt;
	hex <<= 5;		hex |= rd;
	hex <<= 5;		hex |= sa;
	hex <<= 6;		hex |= OP;
	//hex |= imm; /* Ne fait rien si imm n'est pas set*/
	hex |= target;
	
	#ifdef DEBUG_BITS
	// printBitos(sizeof(hex), &hex);
	printBits(6, sizeof(SPECIAL), &SPECIAL);
	printf(" ");
	printBits(5, sizeof(rs), &rs);
	printf(" ");
	printBits(5, sizeof(rt), &rt);
	if(imm){
		printf(" ");
		printBits(16, sizeof(imm), &imm);
	}else{
		printf(" ");
		printBits(5, sizeof(rd), &rd);
		printf(" ");
		printBits(5, sizeof(sa), &sa);
		printf(" ");
		printBits(5, sizeof(OP), &OP);
	}
	puts("");
	#endif
	
	return hex;
}