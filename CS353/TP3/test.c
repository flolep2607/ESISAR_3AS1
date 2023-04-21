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

void testInsertButActuallyGood()
{
    insertItem(1000, "Sucre", 20.50);
    insertItem(60, "Sel", 695.23);
    insertItem(666, "Fromage", 59.23);
    updateItem(60, "Sel de Guerande", 69.52);
    insertItem(1234, "Pomme", 1.99);
    insertItem(5678, "Banane", 0.99);
    insertItem(990, "Orange", 2.49);
    insertItem(1999, "Poudre bleue", 999.99);
    suppressItem(5678);
    suppressItem(32);
    insertItem(2468, "Raisin", 3.99);
    updateItem(1234, "Pomme Rouge", 2.49);
    insertItem(999, "Sucre", 20.50);
    Result* tmp=findItem("Sucre");
    printList(&tmp);
    dumpItems();
}

int main() {
    printf("****** Gestionnaire de magasin ******\n");
    //
    init();
    //
    testInsertButActuallyGood();
    // Result *res = findItem("Sucre");
    // printList(&res);
    printf("=======Gestionnaire de magasin ======\n");
    rebuildTable();
    dumpItems();
    return 0;
}