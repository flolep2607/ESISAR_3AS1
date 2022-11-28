#include "default.h"
#include "memory.h"
#include "opcodes.h"
#include "process.h"
#include "registre.h"
#include "translate.h"
#include "utils.h"
//#ifdef TEST
// http://mipsconverter.com/instruction.html
char* translate_test_list[][2]={
    {"ADD $7, $5, $2","00a23820"},
    {"ADD $2,$3,$4","00641020"},
    {"ADDI $2, $3, 200","206200c8"},
    {"ADD $7,$5, $2","00a23820"},
    {"ADD             $2,$3,$4","00641020"},
    {"ADDI $2, $3,200 ","206200c8"},
    {"P $2, $3,200 ","206200c8"},
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
            printf("resultat recu:%08x\nresult atendu:%08x\n",tmp_resultat,good_resultat);
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
//#endif