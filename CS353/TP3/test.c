/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "store.h"

/*----------------------------------------------------------------------------
 * Cette fonction Compte le nombre d'essai avant d'arriver sur l'item.
 *----------------------------------------------------------------------------*/

// Liste chaînée faite pour le type Result (il s'agit d'une liste chaînée d'Items)

typedef struct structResult
{
    Item *item;
    struct structResult *next;
} Result;

// int testInsert()
// {
//     int r, ind = 0;
//     int tab[TABLE_SIZE];
//     Result *res;

//     r = 0;
//     ind = 0;
//     // if ( insertItem(300,"ToFind",r*1.0) == SUCCESS ) { tab[r]=ind; r++; }
//     // if ( insertItem(400,"ToFind",r*1.0) == SUCCESS ) { tab[r]=ind; r++; }

//     while (r < TABLE_SIZE)
//     {
//         ind = rand() % 50000;
//         if (insertItem(ind, "NONAME", r * 1.0) == SUCCESS)
//         {
//             tab[r] = ind;
//             r++;
//         }
//     }

//     printf("Insert OK\n");
//     // dumpItems();
//     for (r = 0; r < TABLE_SIZE / 100; r++)
//     {
//         if (updateItem(tab[r], "ToFind", r * 1.0) != SUCCESS)
//             return 0;
//     }

//     printf("Update OK\n");
//     dumpItems();
//     // res = *getItem("ToFind");
//     // while (res)
//     // {
//     //     printf("res=%d prix %.2f\n", res->item->code, res->item->price);
//     //     res = res->next;
//     // }
//     // res = NULL;

//     // res = *getItemWithIndex("ToFind");
//     // while (res)
//     // {
//     //     printf("Index res=%d prix %.2f\n", res->item->code, res->item->price);
//     //     res = res->next;
//     // }
//     return 1;
// }

int testInsertButActuallyGood()
{
    insertItem(1000, "Sucre", 20.50);
    insertItem(60, "Sel", 695.23);
    insertItem(16, "Poudre bleue", 999.99);
    // dumpItems();
    suppressItem(1000);
    insertItem(666, "Fromage", 59.23);
    // dumpItems();
    updateItem(60, "Sel de Guérin", 69.52);
    // dumpItems();
    insertItem(1234, "Apple", 1.99);
    insertItem(5678, "Banana", 0.99);
    insertItem(32, "Orange", 2.49);
    // dumpItems();
    suppressItem(5678);
    suppressItem(16);
    insertItem(2468, "Grapes", 3.99);
    // dumpItems();
    updateItem(1234, "Red Apple", 2.49);
    dumpItems();
    return 0;
}

// int testInsertButAnotherOne()
// {
//     insertItem(1234, "Apple", 1.99);
//     insertItem(5678, "Banana", 0.99);
//     insertItem(32, "Orange", 2.49);
//     //dumpItems();
//     suppressItem(5678);
//     suppressItem(32);
//     insertItem(2468, "Grapes", 3.99);
//     //dumpItems();
//     updateItem(1234, "Red Apple", 2.49);
//     dumpItems();
//     return 0;
// }

int main()
{
    // int nb = 0, r;
    //
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
