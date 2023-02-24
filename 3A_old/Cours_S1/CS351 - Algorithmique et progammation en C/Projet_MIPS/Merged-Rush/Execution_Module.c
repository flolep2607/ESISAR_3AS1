#include "Memory_Module.h"
#include "Compile_Module.h"
#include "Execution_Module.h"

#define BIT5MASK 0x1F
#define BIT6MASK 0x3F
#define BIT16MASK 0xFFFF
#define BIT26MASK 0x3FFFFFF

#define IntergerOverflow 1
#define AddressError 2

/** This function verify if registre zero has been modified.
	Right now it doesn't do anything cause behavior isn't defined.
	Each time it's called it reset the registre to make sure it stays at zero.*/
void zero_integrity(){
	if(GPR[0])
		/* PANIC */
		{;}
	GPR[0] = 0;
}

/** This function do something on each SignalException.
	For now it just prints what kind of error it received. */
void SignalException(int code){
	switch(code){
		case IntergerOverflow:
			puts("Exception: IntergerOverflow");
			break;
		case AddressError:
			puts("Exception: AddressError");
			break;
		default:
			break;
	}
}

/** This function decode the hexadecimal code for an instruction and execute it.
	Args: inst -> The instruction to decode (a 32 bits integer)
*/
void execute_instruction(int inst){
	
	uint8_t SPECIAL, rs, rt, rd, sa;
	int16_t imm;/*Not clear if it should be signed or unsigned,
	for now it is signed because I want to ADDI negative numbers and that means
	it should be padded with prefix ones when transferring into a 32bits registre
	in order to retain signeness. */
	uint32_t target;
	
	long temp;
	
	/* Décomposition de l'opération en plusieurs morceaux */
	SPECIAL = (inst>>26)& BIT6MASK;
	rs = 	  (inst>>21)& BIT5MASK;
	rt = 	  (inst>>16)& BIT5MASK;
	rd = 	  (inst>>11)& BIT5MASK;
	sa = 	  (inst>>6) & BIT5MASK;
	//OP = 	  (inst)	& BIT6MASK;
	imm = 	  (inst)	& BIT16MASK;
	target =  (inst)	& BIT26MASK;
	
	/* Si SPECIAL = 0 ça veut dire que l'op code se trouve dans les 6 deniers bits
		On rajoute 0x80 à cette valeur de l'opcode pour pouvoir différentier 
		les opcodes similaires, mais qui seraient à des positions différentes .*/
	if (!SPECIAL) SPECIAL = (inst&BIT6MASK)+0x80;
	if (inst == HALT) SPECIAL = 0xFF;
	
	
	/* -- Main part -- */
	
/* switch the opcode and execute the corresponding function */
	switch(SPECIAL){
		
		/* Opcode defined in CPU_Struct.h */
		
		case ADD: printf("ADD");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			temp=GPR[rs]+GPR[rt];
			if ( ((temp>>30)&1) != ((temp>>31)&1) )
				SignalException(IntergerOverflow);
			else
				GPR[rd]=temp/*&0xFFFF*/;
			break;
			
		case ADDI: printf("ADDI");
		printf(" $%d, $%d, %d}\n",rt,rs,imm);
			temp=GPR[rs]+imm;
			if ( ((temp>>30)&1) != ((temp>>31)&1) )
				SignalException(IntergerOverflow);
			else
				GPR[rt]=temp;
			break;
			
		case AND: printf("AND");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			GPR[rd] = GPR[rs] & GPR[rt];
			break;
		
		case BEQ: printf("BEQ");
		printf(" $%d, $%d, %d}\n",rs,rt,imm);
			if (GPR[rs]==GPR[rt]) CPU.PC += ((int16_t)imm) *4;
			/* On multiplie par 4 au lieu de shift à gauche pour préserver le signe */
			break;
			
		case BGTZ: printf("BGTZ");
		printf(" $%d, %d}\n",rs,imm);
			//execute_instruction( read_word(CPU.PC) );
			if (GPR[rs]>0) CPU.PC += ((int16_t)imm)*4;
			//else CPU.PC +=4;
			break;
			
		case BLEZ: printf("BLEZ");
		printf(" $%d, %d}\n",rs,imm);
			if (GPR[rs]<=0) CPU.PC += ((int16_t)imm)*4;
			break;
			
		case BNE: printf("BNE");
		printf(" $%d, $%d, %d}\n",rs,rt,imm);
			if (GPR[rs]!=GPR[rt]) CPU.PC += ((int16_t)imm)*4;
			break;
			
		case DIV: printf("DIV");
		printf(" $%d, $%d}\n",rs,rt);
			if (GPR[rt]==0) /*dividing by zero should have unpredictable result*/
				/*unpredictable behavior*/; 	/* Je pense que ce if/else est injustifié */
			else { 	/* Néanmoins je suis obligé de l'implémenter, sinon le systeme stopera l'execution du programme et renverra une "Floating Point Exception" */
				CPU.LO = GPR[rs] / GPR[rt];
				CPU.HI = GPR[rs] % GPR[rt];
			}
			break;
			
		case JAL: printf("JAL");
		printf(" %d}\n",target);
			GPR[31]=CPU.PC+8;
			execute_instruction( read_word(CPU.PC) );
			CPU.PC = (target<<2) + (CPU.PC&0xF0000000);
			break;
		case J: printf("J");
		printf(" %d}\n",target);
			execute_instruction( read_word(CPU.PC) );
			CPU.PC = (target<<2) + (CPU.PC&0xF0000000);
			break;
			
		case JR: printf("JR");
		printf(" $%d}\n",rs);
			execute_instruction( read_word(CPU.PC) );
			CPU.PC = (GPR[rs]<<2) + (CPU.PC&0xF0000000);
			break;
			
		case LUI: printf("LUI");
		printf(" $%d, %d}\n",rt,imm);
			GPR[rt] = imm<<16;
			break;
		
		case LW: printf("LW");
		printf(" $%d, %d($%d)}\n",rt,imm,rs);
		/* rs is base, imm is offset */
			temp=GPR[rs]+imm;
			if ( temp%4 )
			SignalException(AddressError);
			else
				GPR[rt] = read_word(temp);
			break;
		
		case MFHI: printf("MFHI");
		printf(" $%d}\n",rd);
			GPR[rd] = CPU.HI;
			break;
			
		case MFLO: printf("MFLO");
		printf(" $%d}\n",rd);
			GPR[rd] = CPU.LO;
			break;
		
		case MULT: printf("MULT");
		printf(" $%d, $%d}\n",rs,rt);
			temp = GPR[rs] * GPR[rt] ;
			CPU.LO = temp&0x0000FFFF;
			CPU.HI = temp&0xFFFF0000;
			break;
			
		case OR: printf("OR");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			GPR[rd] = GPR[rs] | GPR[rt];
			break;
			
		case SLL: if(inst) printf("SLL $%d, $%d, $%d}\n",rd,rt,sa); else printf("NOP}");
			GPR[rd] = GPR[rt] << sa;
			break;
		
		case SLT: printf("SLT");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			GPR[rd] = (GPR[rs] < GPR[rt]);
			break;
			
		case SRL: 
			if (rs == 1){
				printf("ROTR $%d, $%d, %d}\n",rd,rt,sa);
				GPR[rd] = (GPR[rt]<<sa) | (GPR[rt]>>(32-sa));
			} else {
				printf("SRL $%d, $%d, %d}\n",rd,rt,sa);
				GPR[rd] = GPR[rt] >> sa;
			}
			break;
			
		case SUB: printf("SUB");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			temp=GPR[rs]-GPR[rt];
			if ( ((temp>>30)&1) != ((temp>>31)&1) )
				SignalException(IntergerOverflow);
			else
				GPR[rd]=temp/*&0xFFFF*/;
			break;
			
		case SW: printf("SW");
		printf(" $%d, %d($%d)}\n",rt,imm,rs);
			/* rs is base, imm is offset */
			temp=GPR[rs]+imm;
			if ( temp%4 )
				SignalException(AddressError);
			else
				write_word(temp, GPR[rt]);
			break;
		
		case XOR: printf("XOR");
		printf(" $%d, $%d, $%d}\n",rd,rs,rt);
			GPR[rd] = GPR[rs] ^ GPR[rt];
			break;
			
		/* Should never happen */
		case 0xFF: puts("Fin du programme}"); /* HALT */
			break;
		default:
			puts("non implémenté");
	}
	
}

/** La fonction principale */
void execute_program(){
	
	uint32_t inst;
	inst = read_word(CPU.PC);
	
	if (!INTERRACTIF) puts("*** Starting program execution ***\n");
	
	int i=0;
	/* Tant qu'on ne lit pas une instruction EXIT qui stoppe le programme
		On implémente aussi une hard limit sur le nombre d'instruction à exécuter */
	while( ((inst = read_word(CPU.PC)) != HALT) && i++<MAX_INSTRUCTIONS_EXECUTE){
		
		printf("PC:%X\n",CPU.PC);
		printf("Processing instruction:\n%08X {",inst);
		
		/* Le program Counter est incrémenté avant l'execution de l'instruction
		(nécessaire pour les branch et jump) */
		CPU.PC += 4;
		
		/* Execute l'instruction courante */
		execute_instruction(inst);
		
		/* Vérifie l'intégrité et reset le registre zero */
		zero_integrity();
		
		puts("");
		
		/* Si on est en mode pas à pas */
		if (PAS == 1) {
			char c; c=0;
			do{
				printf("*** [r]: display regitres; [m]: memory; [c]: continue\n");
				// scanf("%c\n",&c);
				c = getchar();
				if (c=='r')
					reg_state_print();
				else if (c=='m')
					mem_print_until_address(PROGRAMM_START);
				// else if (c=='t')
				//	print(text_segment);
				while (getchar() != '\n');
			}while(c != 'c');
			puts("");
		}
	
	}
	if (!INTERRACTIF) {
		/* Une fois l'execution terminé on affiche l'état final */
		puts("*** Final register states: ***");
		reg_state_print();
		puts("*** Final memory state: ***");
		mem_print_until_address(PROGRAMM_START);
	}
}

/** Fonction pour le mode interractif */
void interraction_profonde(){
	char inst[20];
	int hex;
	int index;
	char name[10]="";
	char arg1[10]="";
	char arg2[10]="";
	char arg3[10]="";
	puts("*** Mode Interractif ***\n");
	while(strcmp(inst,"EXIT")){
		
		/* Cette fonction executera les programme rentrés en mémoire depuis l'adresse courante du PC 
		jusqu'à ce qu'il atteigne une addresse non initialisée */
		execute_program();
		
		printf("Please type an instruction in asm:\n[EXIT] to quit; [reg] to printf registre states; [mem] to print memory state\n");
		fgets(inst, sizeof(inst), stdin);
		sed(inst, '\n','\0');
		if (!strcmp(inst,"reg"))
			reg_state_print();
		else if (!strcmp(inst,"mem"))
			mem_print_until_address(0x8000);
		else if (!strcmp(inst,"EXIT"))
			{;}
		/* Le plus gros du travail */
		else {
			/* Due à la manière dont j'ai codé la fonction qui traduit les instruction du fichier en hexa
				je ne peux pas le réutiliser ici, donc j'ai du un peu recopier
			Possible de mettre tout ça dans une fonction auxiliaire, mais pas le temps. */
			sed(inst, '_',' ');
			traitement_de_ligne(inst);
			*name='\0'; *arg1='\0'; *arg2='\0'; *arg3='\0';
			line_decomposer(inst, name, arg1, arg2, arg3);
			index = chercher_index(name);
			if (index != -1){
				hex = inst2hex(index, arg1, arg2, arg3);
				write_word(CPU.PC, hex);
			} else
				puts("Incompréhensible !\nplease type again\n");
		}
	}
}