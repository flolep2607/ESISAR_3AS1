#define PROGRAMM_START 0x8000
#define STACK_BASE 0xFFFF


struct CPU_Model {
	unsigned int PC ; /* Program Counter */
	int SP ; /* Stack Pointer */
	int SB ; /* Stack Base */
	int SR ; /* Status Flags */
	int HI ;
	int LO ;
};

/* Structure globale permettant d'accéder au divers registres internes au CPU */
/* L'utilisation d'une structure n'est pas justifiée */
struct CPU_Model CPU;

/* Tableau des regitsres (adressable globalement) */
uint32_t GPR[32];

int INTERRACTIF;
int PAS;

// HALT should now be reffered as EXIT.
#define HALT 0xffffffff

/* Ces defines prennent en compte le bit7 à un si l'opcode est
	situé dans les 6derniers bits de l'instruction */
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

/* NOP et ROTR sont commenté car ils possèdent le même opcode que SLL et SRL respectivement
	De ce fait nous n'avons pas besoin de les définirs */
