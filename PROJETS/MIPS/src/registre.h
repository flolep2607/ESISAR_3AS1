#include "default.h"
/**
 * @struct memory
 * @brief 
 */
#ifndef REGISTER_STRUCT
#define REGISTER_STRUCT
typedef int32_t _registre[31]; 

typedef struct _register_pc
{
    // registre register;
    uint32_t pc;
    int32_t HI;
    int32_t LO;
    bool delayslot;
    bool error;
    _registre registre;
} register_pc;
#endif
register_pc* register_create();
void registre_show(register_pc *);
void registre_write(register_pc *regist,FILE* file);
int32_t register_get(register_pc *, uint8_t);
void registre_set(register_pc *, uint8_t ,int32_t);
void pc_set(register_pc *, uint32_t );
int16_t pc_get(register_pc *);
void pc_increase(register_pc *regist, uint32_t value);