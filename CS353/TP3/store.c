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
Item index_table[INDEX_SIZE];

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
    int empty_place = -1; // Utilisé pour stocker l'index de la première case vide
    int index;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        unsigned int index_hash = hashIndex(itemName, strlen(itemName));
        index = hashkey(index_hash, 0) % INDEX_SIZE;
        // index = hashkey(itemCode, i);
        if (hash_table[index].status == NULL_ITEM)
        {
            if (empty_place != -1) // Si on a trouvé une case vide avant, alors on va stocker le produit dans cette case
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
            empty_place = index; // On stocke l'index de la première case vide
        }
    }
    return TABLE_FULL;
}

// int insertItem(uint32_t itemCode, char *itemName, float itemPrice)
// {
//     // Ancien code d'insertion dans la table de hachage principale
//     /* ... (code existant) ... */

//     // Mettre à jour l'index (ajouté)
//     unsigned int index_hash = hashIndex(itemName, strlen(itemName));
//     int index = hashkey(index_hash, 0) % INDEX_SIZE;
//     for (int i = 0; i < INDEX_SIZE; i++)
//     {
//         if (index_table[index].status == NULL_ITEM || index_table[index].status == DELETED_ITEM)
//         {
//             index_table[index].code = itemCode;
//             strcpy(index_table[index].name, itemName);
//             index_table[index].price = itemPrice;
//             index_table[index].status = USED_ITEM;
//             break;
//         }
//         index = (index++) % INDEX_SIZE;
//     }

//     return SUCCESS;
// }


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
        // index = hashkey(itemCode, i);
        unsigned int index_hash = hashIndex(hash_table[index].name, strlen(hash_table[index].name));
        index = hashkey(index_hash, 0) % INDEX_SIZE;
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

// int suppressItem(unsigned int itemCode)
// {
//     // Ancien code de suppression de la table de hachage principale
//     /* ... (code existant) ... */

//     // Mettre à jour l'index (ajouté)
//     unsigned int index_hash = hashIndex(hash_table[index].name, strlen(hash_table[index].name));
//     int index_label = hashkey(index_hash, 0) % INDEX_SIZE;
//     for (int i = 0; i < INDEX_SIZE; i++)
//     {
//         if (index_table[index_label].status == USED_ITEM && index_table[index_label].code == itemCode)
//         {
//             index_table[index_label].status = DELETED_ITEM;
//             break;
//         }
//         index_label = (index_label + 1) % INDEX_SIZE;
//     }

//     return SUCCESS;
// }


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
    printf("%-5s %-20s %-10s %-5s\n", "Code", "Libelle", "Prix", "Index");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i].status == USED_ITEM)
        {
            printf("%-5d %-20s %-10f %-5d\n", hash_table[i].code, hash_table[i].name, hash_table[i].price, i);
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
        unsigned int index_hash = hashIndex(hash_table[index].name, strlen(hash_table[index].name));
        index = hashkey(index_hash, 0) % INDEX_SIZE;
        // index = hashkey(itemCode, i);
        if (hash_table[index].status == USED_ITEM && hash_table[index].code == itemCode)
        {
            strcpy(hash_table[index].name, itemName);
            hash_table[index].price = itemPrice;
            return SUCCESS;
        }
    }
    return UPDATE_NO_ROW;
}

// int updateItem(uint32_t itemCode, char *itemName, float itemPrice)
// {
//     // Ancien code de mise à jour de la table de hachage principale
//     /* ... (code existant) ... */

//     // Mettre à jour l'index (ajouté)
//     unsigned int index_hash = hashIndex(itemName, strlen(itemName));
//     int index_label = hashkey(index_hash, 0) % INDEX_SIZE;
//     for (int i = 0; i < INDEX_SIZE; i++)
//     {
//         if (index_table[index_label].status == USED_ITEM && strcmp(index_table[index_label].name, itemName) == 0)
//         {
//             index_table[index_label].code = itemCode;
//             index_table[index_label].price = itemPrice;
//             break;
//         }
//         index_label = (index_label + 1) % INDEX_SIZE;
//     }

//     return SUCCESS;
// }


/*----------------------------------------------------------------------------
 * la fonction de réorganisation in situ:
 *----------------------------------------------------------------------------*/
void rebuildTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i].dirty = 1;
    }
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i].dirty == 0)
            continue;
        switch (hash_table[i].status)
        {
        case DELETED_ITEM:
        case NULL_ITEM:
            hash_table[i].status = NULL_ITEM;
            hash_table[i].dirty = 0;
            break;
        case USED_ITEM:
            uint32_t codeTMP = hash_table[i].code;
            Item itemTMP = hash_table[i];
            hash_table[i].status = NULL_ITEM;
            hash_table[i].dirty = 0;
            printf("Rebuilding %d\n", codeTMP);
            for (int j = 0; j < TABLE_SIZE; j++)
            {
                int index = hashkey(codeTMP, j);
                if (hash_table[index].status == NULL_ITEM || hash_table[index].status == DELETED_ITEM)
                {
                    hash_table[index] = itemTMP;
                    hash_table[index].dirty = 0;
                    j = TABLE_SIZE;
                }
                else if (hash_table[index].dirty)
                {
                    Item itemTMP2 = hash_table[index];
                    hash_table[index] = itemTMP;
                    hash_table[index].dirty = 0;
                    itemTMP = itemTMP2;
                    codeTMP = itemTMP.code;
                    j = -1;
                }
            }
            break;
        default:
            break;
        }
    }
}

// Deuxième partie du TP

// Fonctions utilitaires pour gérer la liste chapinée de résultats
Result *createResult(Item *item)
{
    Result *newResult = (Result *)malloc(sizeof(Result));
    newResult->item = item;
    newResult->next = NULL;
    return newResult;
}

Result *insertResult(Result **head, Item *newItem)
{
    Result *newResult = (Result *)malloc(sizeof(Result));
    newResult->item = newItem;
    newResult->next = *head;
    *head = newResult;
    return newResult;
}

Result *removeResult(Result **head, Item *itemToRemove)
{
    Result *current = *head;
    Result *previous = (Result *)malloc(sizeof(Result));
    while (current != NULL && current->item != itemToRemove)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return NULL;
    if (previous == NULL)
        *head = current->next;
    else
        previous->next = current->next;
    free(current);
    return *head;
}

void printList(Result **head)
{
    Result *current = *head;
    while (current != NULL)
    {
        printf("%d\n", current->item->code);
        printf("%s\n", current->item->name);
        current = current->next;
    }
    printf("\n");
}

Result *findItem(char *itemName)
{
    Result *result = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i].status == USED_ITEM && strcmp(hash_table[i].name, itemName) == 0)
        {
            insertResult(&result, &hash_table[i]);
        }
    }
    return result;
}

unsigned int hashIndex(const char *buffer, int size)
{
    unsigned int h = 0;
    for (int i = 0; i < size; i++)
    {
        h = (h * 1103515245u) + 12345u + buffer[i];
    }
    return h / 2;
}

Result *findItemWithIndex(char *itemName)
{
    Result *preced = NULL;
    Result *ptr = index_table;
    unsigned int Code = hashIndex(itemName, strlen(itemName));

    uint32_t i = 0;
    uint32_t key = hashkey(Code, i);
    while (hash_table[key].status != NULL_ITEM && i < TABLE_SIZE)
    {
        if (hash_table[key].status == USED_ITEM && !strcmp(itemName, hash_table[key].name))
        {
            ptr->item = &(hash_table[key]);
            ptr->next = malloc(sizeof(Result));
            preced = ptr;
            ptr = ptr->next;
        }
        key = hashkey(Code, ++i);
    }

    preced->next = NULL;
    return ptr;
}