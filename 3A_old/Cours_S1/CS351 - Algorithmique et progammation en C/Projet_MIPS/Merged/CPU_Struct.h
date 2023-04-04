#define PROGRAMM_START 0x8000
#define STACK_BASE 0xFFFF


struct CPU_Model {
	int PC ; /* Program Counter */
	int SP ; /* Stack Pointer */
	int SB ; /* Stack Base */
	int SR ; /* Status Flags */
	int BR ; /* Je sais plus */
	int HI ;
	int LO ;
};

struct CPU_Model CPU;

uint32_t GPR[32];


// #define HALT 0x1000ffff //BEQ $0, $0, -1
#define HALT 0xffffffff

#define ADD  0b10100000
#define ADDI 0b001000 //oui
#define AND  0b10100100
#define BEQ  0b000100 //oui
#define BGTZ 0b000111 //oui
#define BLEZ 0b000110 //oui
#define BNE  0b000101 //oui
#define DIV  0b10011010
#define J    0b000010 //oui
#define JAL  0b000011 //oui
#define JR   0b10001000 
#define LUI  0b001111 //oui
#define LW   0b100011 //oui
#define MFHI 0b10010000
#define MFLO 0b10010010
#define MULT 0b10011000
//#define NOP  0b10000000 
#define OR   0b10100101 
//#define ROTR 0b10000010
#define SLL  0b10000000
#define SLT  0b10101010
#define SRL  0b10000010
#define SUB  0b10100010
#define SW   0b101011 //oui
#define XOR  0b10100110





/*struct CPU_Regs {
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r12;
	uint32_t r13;
	uint32_t r14;
	uint32_t r15;
	uint32_t r16;
	uint32_t r17;
	uint32_t r18;
	uint32_t r19;
	uint32_t r20;
	uint32_t r21;
	uint32_t r22;
	uint32_t r23;
	uint32_t r24;
	uint32_t r25;
	uint32_t r26;
	uint32_t r27;
	uint32_t r28;
	uint32_t r29;
	uint32_t r30;
	uint32_t r31;
};*/


/*
struct Registres {
	uint32_t zero;
	uint32_t at;
	uint32_t v0;
	uint32_t v1;
	uint32_t a0;
	uint32_t a1;
	uint32_t a2;
	uint32_t a3;
	uint32_t t0;
	uint32_t t1;
	uint32_t t2;
	uint32_t t3;
	uint32_t t4;
	uint32_t t5;
	uint32_t t6;
	uint32_t t7;
	uint32_t s0;
	uint32_t s1;
	uint32_t s2;
	uint32_t s3;
	uint32_t s4;
	uint32_t s5;
	uint32_t s6;
	uint32_t s7;
	uint32_t t8;
	uint32_t t9;
	uint32_t k0;
	uint32_t k1;
	uint32_t gp;
	uint32_t sp;
	uint32_t fp;
	uint32_t ra;
};
*/

/* #define ( X in range 0:100 ) \
	int varX;
#undef X

int var0;
int var1;
..........
int var100;
*/

