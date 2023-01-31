#include "default.h"
#include <time.h>
#ifndef MEMORY
#define MEMORY
typedef struct _memory
{
    uint32_t data; /* contient les donnnés */
    unsigned long int address;/* addresse sur 32bits long int => minimum 32 bits = 0xFFFFFFFF */
    struct _memory* next;
} memory;
#endif
uint32_t memory_get(memory* mem,unsigned long int address);
void memory_set(memory* mem,unsigned long int address,int32_t data);
void memory_delete(memory* mem,unsigned long int address);
void memory_show(memory* mem);
void memory_free(memory* mem);
memory* memory_create();
