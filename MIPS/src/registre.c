#include "registre.h"

// 0->31
// at  -> 1 => ne doit pas etre lu
// -> 26-27 => ne doit pas etre lu
// gp  ->28 => pas touche
// fp  ->30 => pas touche

//ZERO -> 0 => toujours 0

// t0-9->8-15+24-25=>temporaires
// s0-7 -> 16-23 => temporaires pour sous routine
// sp  ->29 => stack pointer
// ra  ->31 => return address

// HI LO ->32-33 => resultat pour divison mult
// pc    ->34
//! total registres 32+3 pas grave si y'en a d'inutiles
registre* create_registre(){
    registre* elem = calloc(1,sizeof(registre));
    return elem;
}
void index2name(short index,char name[3]){
    if(index<32){
        sprintf(name,"$%02d",index);
    }else if(index==32){
        sprintf(name,"HI");
    }else{
        sprintf(name,"LO");
    }
}
void printf_registre(registre* reg){
    char name[4]={0};
    for (size_t i = 0; i < 34; i++)
    {
        if((*reg)[i]==0){
            index2name(i,name);
            printf("%s: %d\n",name,(*reg)[i]);
        }
    }
}
int32_t get_registre(char* mnemo){
    return 0;
}
// int main(){
//     registre* reg=create_registre();
//     printf_registre(reg);
//     free(reg);
//     return 0;
// }