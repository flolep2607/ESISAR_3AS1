#include "default.h"
/**
 * @struct memory
 * @brief 
 */
typedef struct _memory
{
    int32_t data; /* contient les donnnés */
    unsigned long int address;/* addresse sur 32bits long int => minimum 32 bits = 0xFFFFFFFF */
    struct _memory* next;
} memory;
