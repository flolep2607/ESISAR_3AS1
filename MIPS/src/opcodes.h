typedef enum { 
    I,//op6,rs5,rt5,i16                => add
    J,//op6,addr26                     => j
    R //op6,rs5,rt5,rd5,shamt5,funct6  => addi
} instruction_format;
typedef struct _instruction
{
    char* name;
    instruction_format format;
    uint8_t opcode; //6 bits
} instruction;

instruction LISTE_INSTRUCT []={
    {"ADDI",R,0b001000},
    NULL
};
