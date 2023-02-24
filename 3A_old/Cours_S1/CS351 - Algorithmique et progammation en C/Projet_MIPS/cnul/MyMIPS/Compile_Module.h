

struct ligne_tableau {
	char[6] OP_NAME;
	uint8_t Code;
	char Category;
	char flags; //flags
	// bit 123 => arg 123
	// bit 5 =>    Set => SPECIAL
	//		   not Set => OP
	// bit 8 => ROTR special bit
};

struct ligne_tableau Tableau[25]={
    { "ADD",0b100000, 'R',0b00111},
    { "ADDI",0b001000, 'I',0b10111},
    { "AND",0b100100, 'R',0b00111},
    { "BEQ",0b000100, 4,0b10111},
    { "BGTZ",0b000111, 5,0b10011},
    { "BLEZ",0b000110, 5,0b10011},
    { "BNE",0b000101, 4,0b10111},
    { "DIV",0b000101, 4,0b00011},
    { "J",0b000010, 'J',0b10001},
    { "JAL",0b000011, 'J',0b10001},
    { "JR",0b001000, 4,0b10001},
    { "LUI",0b001111, 'Z',0b10011},
    { "LW",0b100011, 'Y',0b10111},
    { "MFHI",0b010000, 'R',0b00001},
    { "MFLO",0b010010, 'R',0b00001},
    { "MULT",0b011000, 4,0b00011},
    { "NOP",0b00000, 0,0b00000},
    { "OR",0b100101, 'R',0b00111},
    { "ROTR",0b000010, 'S',0b10000111},
    { "SLL",0b000000, 'S',0b00111},
    { "SLT",0b101010, 'R',0b00111},
    { "SRL",0b000010, 'S',0b00111},
    { "SUB",0b100010, 'R',0b00111},
    { "SW",0b100011, 'Y',0b00111},
    { "XOR",0b100110, 'R',0b00111}
};


if (!( Tableau[i].flags & 0b001)) arg1[0] = '\0';
if (!( Tableau[i].flags & 0b010)) arg2[0] = '\0';
if (!( Tableau[i].flags & 0b100)) arg3[0] = '\0';