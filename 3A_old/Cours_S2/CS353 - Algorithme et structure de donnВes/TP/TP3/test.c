/******************************************************************************
 * Programme de test du gestionnaire de magasin                               *                                                               *
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <time.h>


/*----------------------------------------------------------------------------
 * Cette fonction Compte le nombre d'essai avant d'arriver sur l'item. 
 *----------------------------------------------------------------------------*/

int testInsert() 
{
	int r,ind=0; 
	int tab[TABLE_SIZE]; 
        Result *res;
 
	r=0;
	ind=0; 
	//if ( insertItem(300,"ToFind",r*1.0) == SUCCESS ) { tab[r]=ind; r++; }
	//if ( insertItem(400,"ToFind",r*1.0) == SUCCESS ) { tab[r]=ind; r++; }

        while (r<TABLE_SIZE) {
	    ind=rand()%50000; 
            if ( insertItem(ind,"NONAME",r*1.0) == SUCCESS ) { tab[r]=ind; r++; }
    	}

	printf("Insert OK\n"); 
	for(r=0;r<TABLE_SIZE/100;r++) {
		if ( updateItem(tab[r],"ToFind",r*1.0) != SUCCESS ) return 0; 
	}
	// dumpItems();

	printf("Update OK\n"); 
	res=findItem("ToFind"); 
	while (res) { printf("res=%d prix %.2f\n",res->item->code,res->item->price); res=res->next; }	
	res=NULL; 

	res=findItemWithIndex("ToFind"); 
	while (res) { printf("Index res=%d prix %.2f\t\t%s\n",res->item->code,res->item->price,res->item->name); res=res->next; }	
	
}

int main()
{

    int nb=0,r;
    //
    printf("****** Gestionnaire de magasin ******\n");
    // 
    init();
    //
    testInsert();   
    printf("=======Gestionnaire de magasin ======\n");

    return 0;
}

