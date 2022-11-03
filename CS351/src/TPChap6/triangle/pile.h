#include <stdlib.h>
#define TAILLE 100

typedef struct {
  int pile[TAILLE]; /* tableau contenant la pile */
  int pp;           /* pointeur de pile */
} sPileInt;
typedef sPileInt* pileInt;


pileInt creerPile();
int estPileVide(pileInt);
void empiler(pileInt, int);
int depiler(pileInt);
