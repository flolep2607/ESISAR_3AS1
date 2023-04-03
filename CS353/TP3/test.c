/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include <stdlib.h>

/*----------------------------------------------------------------------------
 * Cette fonction Compte le nombre d'essai avant d'arriver sur l'item.
 *----------------------------------------------------------------------------*/

void testInsert() {
    insertItem(1, "item1", 1.0f);
    insertItem(6, "item6", 6.0f);
    insertItem(2, "item2", 2.0f);
    insertItem(11, "item11", 11.0f);
    insertItem(3, "item3", 3.0f);
    insertItem(60007, "item60007", 11.0f);
    insertItem(4, "item4", 4.0f);
    insertItem(5, "item5", 5.0f);
    insertItem(6, "item6", 6.0f);
    insertItem(7, "item7", 7.0f);
    insertItem(8, "item8", 8.0f);
    insertItem(9, "item9", 9.0f);
    insertItem(10, "item10", 10.0f);
    insertItem(11, "item11", 11.0f);
    insertItem(11, "item11", 11.0f);
    insertItem(11, "item11", 11.0f);
    for(int i=10;i>0;i--){
        int r=rand();
        insertItem(r, "item", (float)(r%10));
    }
    dumpItems();
    for(int i=0;i<5;i--){
        suppressItem(i);
    }
    dumpItems();
    rebuildTable();
    dumpItems();
}

int main() {
    printf("****** Gestionnaire de magasin ******\n");
    //
    init();
    //
    testInsertButActuallyGood();
    // testInsertButAnotherOne();
    printf("=======Gestionnaire de magasin ======\n");
    rebuildTable();
    dumpItems();
    return 0;
}
