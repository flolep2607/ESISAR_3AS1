#include "default.h"
#include "memory.h"
#include "opcodes.h"
#include "process.h"
#include "registre.h"
#include "translate.h"
#include "utils.h"
//#ifdef TEST
char* translate_test_list[][2]={
    {"ADD $7, $5, $2","00a23820"},
    {"ADD $2,$3,$4","00641020"},
    {"ADDI $2, $3, 200","206200c8"},
    NULL
};

int translate_test()
{
    // ADD $7, $5, $2
    // 00a23820
    // ADD $2,$3,$4
    // 00641020
    // printf("%08x\n", format_I(0b100000, 2, 3, 4, 0));
    // ADDI $2, $3, 200
    // 206200c8
    int i=0;
    bool is_valid=true;
    uint32_t good_resultat,tmp_resultat;
    while(translate_test_list[i]!=NULL){
        printf("operande:%s\n",translate_test_list[i][0]);
        sscanf(translate_test_list[i][0],"%x",&good_resultat);
        tmp_resultat=translate_line(translate_test_list[i][0]);
        if(tmp_resultat!=good_resultat){
            printf("resultat recu:%08x\nresult atendu:%08x\n",tmp_resultat,good_resultat);
            is_valid=false;
        }
        i++;
    }
    return is_valid;
}

int main()
{
    int error_code = translate_test();
    if (error_code > 0)
    {
        printf("[ERROR] translate code:%d\n", error_code);
    }
}
//#endif