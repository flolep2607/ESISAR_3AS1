#include <stdlib.h>
#ifndef __CALCUL_H__
#define __CALCUL_H__

struct msg_struct
{
    long type;
    /* A COMPLETER */
    pid_t pid;
    int operande1;
    int operande2;
    char operateur; // + - * /
    int resultat;
};

#endif /* __CALCUL_H__ */
