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
    _registre registre;
} register_pc;
#endif
register_pc* create_register();
void printf_registre(register_pc *);
void write_registre(register_pc *regist,FILE* file);
int32_t get_register(register_pc *, uint8_t);
void set_register(register_pc *, uint8_t ,int32_t);
void set_pc(register_pc *, uint32_t );
int16_t get_pc(register_pc *);
void increase_pc(register_pc *regist, uint32_t value);