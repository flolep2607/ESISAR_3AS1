/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include "store.h"
#include <stdio.h>


int main()
{
    //
    printf("****** Gestionnaire de magasin ******\n");
    init();
	// insertItem(10001, "Sucre", 1.20);
	// insertItem(10002, "Farine", 0.80);
	// suppressItem(10002);
	// insertItem(10002, "Farine", 0.80);
	// insertItem(10005, "Farine", 0.81);
	// insertItem(10009, "Farine", 1.00);
	// insertItem(10003, "Confiture Fraise", 2.50);
	// insertItem(10004, "Sel", 0.50);
	insertItem(0, "Sucre", 1.20);
	insertItem(1009, "Farine", 0.80);
	suppressItem(0);
    //
    printf("=======Gestionnaire de magasin ======\n");
	dumpItems();

    //
    printf("======Reconstruction de la table=====\n");
    rebuildTable();
    dumpItems();
	
	//
    printf("====== Recherche d'items ============\n");
	Result * res = findItem("Farine");
	while (res) { printf("Index res=%d prix %.2f\t\t%s\n",res->item->code,res->item->price,res->item->name); res=res->next; }
	
    return 0;
}
