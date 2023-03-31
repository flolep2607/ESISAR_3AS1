/******************************************************************************
 * Implementation du module gestion de stock d'un magasin
 * avec une table de hachage
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*----------------------------------------------------------------------------
 * Variable globale contenant le tableau
 *----------------------------------------------------------------------------*/
Item hash_table[TABLE_SIZE];

/*----------------------------------------------------------------------------
 * Cette fonction initialise le tableau hash_table
 * en positionnant tous les elements à NULL_ITEM
 *----------------------------------------------------------------------------*/
void init()
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i].status = NULL_ITEM;
        hash_table[i].price = 0.00f;
        hash_table[i].code = 0;
    }
}

/*----------------------------------------------------------------------------
 * Cette fonction calcule la valeur de hachage pour le produit itemCode
 *----------------------------------------------------------------------------*/
uint32_t hashkey(uint32_t itemCode, uint32_t nbTry)
{
    return (((itemCode % TABLE_SIZE) + nbTry * (1 + itemCode % (TABLE_SIZE - 1))) % TABLE_SIZE);
}

/*----------------------------------------------------------------------------
 * Cette fonction insère le produit indiqué dans la table de hachage.
 * Si le produit est inséré avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit existe déjà dans la table, alors la fonction retourne INSERT_ALREADY_EXIST (-1),
 * et la table de hachage n'est pas modifiée
 * Si la table est pleine, alors la fonction retourne TABLE_FULL (-2).
 *----------------------------------------------------------------------------*/

// typedef struct structItem
// {
// 	uint8_t status;
// 	uint32_t code;
// 	char name[ITEM_NAME_SIZE];
// 	float price;
// 	uint8_t dirty;
// } Item;

int insertItem(uint32_t itemCode, char *itemName, float itemPrice)
{
    //taille du tableau : TABLE_SIZE
    int empty_place = -1;
    int index;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = hashkey(itemCode, i);
        if (hash_table[index].status == NULL_ITEM)
        {
            if (empty_place != -1)
            {
                hash_table[empty_place].code = itemCode;
                strcpy(hash_table[empty_place].name, itemName);
                hash_table[empty_place].price = itemPrice;
                hash_table[empty_place].status = USED_ITEM;
                return SUCCESS;
            }
            else
            {
                hash_table[index].code = itemCode;
                strcpy(hash_table[index].name, itemName);
                hash_table[index].price = itemPrice;
                hash_table[index].status = USED_ITEM;
                return SUCCESS;
            }
        }
        else if (hash_table[index].status == USED_ITEM && hash_table[index].code == itemCode)
        {
            return INSERT_ALREADY_EXIST;
        }
        else if (hash_table[index].status == DELETED_ITEM && empty_place == -1)
        {
            empty_place = index;
        }
    }
    return TABLE_FULL;
}

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprimé avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(unsigned int itemCode)
{
    int index;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = hashkey(itemCode, i);
        if (hash_table[index].status == USED_ITEM && hash_table[index].code == itemCode)
        {
            hash_table[index].status = DELETED_ITEM;
            hash_table[index].code = 0;
            strcpy(hash_table[index].name, "");
            hash_table[index].price = 0.00;
            return SUCCESS;
        }
    }
    return DELETE_NO_ROW;
}

/*----------------------------------------------------------------------------
 * Pour chaque produit, cette fonction affiche sur une ligne
 * le code du produit
 * son libellé
 * son prix
 * son index dans la table de hashage
 * sa valeur de hash
 *----------------------------------------------------------------------------*/
void dumpItems()
{
    printf("Code\t Libellé\t Prix\t Index\t\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i].status == USED_ITEM)
        {
            printf("%d\t %s\t %f\t %d\t\n", hash_table[i].code, hash_table[i].name, hash_table[i].price, i);
        }
    }
}

/*----------------------------------------------------------------------------
 * Cette fonction trouve le produit dont le code est itemCode.
 * Cette fonction retourne NULL si le produit n'existe pas.
 * Cette fonction retourne un pointeur vers le produit si le produit existe.
 *----------------------------------------------------------------------------*/
Item *getItem(unsigned int itemCode)
{
    int index;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = hashkey(itemCode, i);
        if (hash_table[index].status == USED_ITEM && hash_table[index].code == itemCode)
        {
            printf("Found it at index %d\n", index);
            return &hash_table[index];
        }
    }
    return NULL;
}

/*----------------------------------------------------------------------------
 *  fonction de mise à jour d'un produit :
 * Si le produit est mis à jour avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne UPDATE_NO_ROW (-5)
 *----------------------------------------------------------------------------*/
int updateItem(unsigned int itemCode, char *itemName, float itemPrice)
{
    int index;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        index = hashkey(itemCode, i);
        if (hash_table[index].status == USED_ITEM && hash_table[index].code == itemCode)
        {
            strcpy(hash_table[index].name, itemName);
            hash_table[index].price = itemPrice;
            return SUCCESS;
        }
    }
    return UPDATE_NO_ROW;
}

/*----------------------------------------------------------------------------
 * la fonction de réorganisation in situ:
 *----------------------------------------------------------------------------*/
void rebuildTable()
{//TODO: faire fonctionner ça tout court lol
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i].dirty = 1;
    }
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i].status == DELETED_ITEM)
        {
            hash_table[i].status = NULL_ITEM;
        }
        else if (hash_table[i].status == USED_ITEM)
        {
            uint32_t codeTMP = hash_table[i].code;
            char nameTMP[ITEM_NAME_SIZE];
            strcpy(nameTMP, hash_table[i].name);
            float priceTMP = hash_table[i].price;
            suppressItem(hash_table[i].code);
            insertItem(codeTMP, nameTMP, priceTMP);
        }
        hash_table->dirty = 0;
    }
}