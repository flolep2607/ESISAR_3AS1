#include "default.h"
#include "memory.h"
#include "opcodes.h"
#include "process.h"
#include "registre.h"
#include "translate.h"
#include "utils.h"
#ifdef TEST
//TODO implement hex for immediate
// http://mipsconverter.com/instruction.html
char* translate_test_list[][2]={
    {"ADD $7, $5, $2","00a23820"},
    {"ADD $2,$3,$4","00641020"},
    {"ADDI $2, $3, 200","206200c8"},
    {"ADD $7,$5, $2","00a23820"},
    {"ADD   $2,$3,$4","00641020"},
    {"ADDI $2, $3,200 ","206200c8"},
    {"lui $4, 1234","3c010001"},
    {"jal 0","0c000000"},
    // {"syscall","0xxxxxxc"},
    {"ADDI $5, $0, 5", "20050005"},
    {"ADDI $2, $0, 11", "2002000b"},
    {"ADD $7, $5, $2", "00a23820"},
    {"ADDI $11, $10, 7", "214b0007"},
    {"SUB $8, $3, $2", "00624022"},
    {"DIV $5, $2", "00a2001a"},
    {"MFHI $9", "00004810"},
    {"MFLO $10", "00005012"},
    {"MULT $5, $2", "00a20018"},
    {"BEQ $0 $10 0x0","10100000"},
    {"xor $0,$0,$0","01084026"},
    NULL
};

int translate_test()
{
    int i=0;
    int is_valid=0;
    uint32_t good_resultat,tmp_resultat;
    while(translate_test_list[i]!=NULL && translate_test_list[i][0]!=NULL){
        printf("operande:%s\n",translate_test_list[i][0]);
        sscanf(translate_test_list[i][1],"%x",&good_resultat);
        tmp_resultat=translate_line(translate_test_list[i][0]);
        if(tmp_resultat!=good_resultat){
            printf("\033[1;31mresultat recu:%08x\nresult atendu:%08x \033[0m\n",tmp_resultat,good_resultat);
            is_valid=1;
        }
        i++;
    }
    return is_valid;
}

int main()
{
    int anyerror=0;
    int error_code = translate_test();
    anyerror+=error_code;
    if (error_code > 0)
    {
        printf("[ERROR] translate code:%d\n", error_code);
    }
    if(anyerror){
        printf("[ERROR] detected some errors:%d\n",anyerror);
    }else{
        printf("[GOOD] No error\n");
    }
}
#endif