#include "module.h"
int main(int argc, char * argv[])
{
    int T[10] = {0};
    int nb = lireDonnes(argv[1], T);
    trieABulles(T, nb);
    afficherTableau(T, nb);
    enregistrerdonnees(argv[2],T,nb);
}