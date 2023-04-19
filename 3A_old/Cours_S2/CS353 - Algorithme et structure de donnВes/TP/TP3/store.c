/******************************************************************************
 * Implementation du module gestion de stock d'un magasin
 * avec une table de hachage
 ******************************************************************************/

#include "store.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

Item hash_table[TABLE_SIZE];
Item *item_hash_table[TABLE_SIZE];

unsigned int hashIndex(const char *buffer, int size);

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
int insertItem(uint32_t itemCode, char *itemName, float itemPrice)
{
  uint32_t i = 0;
  uint32_t key = hashkey(itemCode, i);
  uint32_t first_deleted = TABLE_SIZE; // impossible index
  while (hash_table[key].status != NULL_ITEM && i < TABLE_SIZE)
  {

    /* Cas où on à trouvé l'objet */
    if (hash_table[key].status == USED_ITEM && hash_table[key].code == itemCode)
    {
      return (INSERT_ALREADY_EXIST);
    }
    else

      /* Cas où on trouve le premier objet supprimé dans la chaine */
      if (hash_table[key].status == DELETED_ITEM && first_deleted == TABLE_SIZE)
      {
        first_deleted = key;
      }

    // Essai suivant
    i++;
    key = hashkey(itemCode, i);
  }

  /* Cas où la table est pleine */
  if (hash_table[key].status == NULL_ITEM)
  {
    /* la cle cible le 1er suppr */
    if (first_deleted < TABLE_SIZE)
      key = first_deleted;

    /* remplir le [key] */
    hash_table[key].status = USED_ITEM;
    hash_table[key].code = itemCode;
    strncpy(hash_table[key].name, itemName, ITEM_NAME_SIZE);
    hash_table[key].price = itemPrice;

    int key_bak = key;
    i = 0;
    unsigned int Code = hashIndex(itemName, strlen(itemName));
    key = hashkey(Code, i);
    while (item_hash_table[key] && item_hash_table[key]->status != DELETED_ITEM && i < TABLE_SIZE)
      key = hashkey(Code, ++i);
    item_hash_table[key] = &hash_table[key_bak];

    return SUCCESS;
  }

  /* Cas où la table est pleine */
  return TABLE_FULL;
}

/*----------------------------------------------------------------------------
 * fonction de suppression d'un produit du magasin
 * Si le produit est supprimé avec succès, alors la fonction retourne SUCCESS (0)
 * Si le produit n'existe pas, alors la fonction retourne DELETE_NO_ROW (-4)
 *----------------------------------------------------------------------------*/
int suppressItem(unsigned int itemCode)
{
  uint32_t i = 0;
  uint32_t key = hashkey(itemCode, i);
  while (hash_table[key].status != NULL_ITEM && i < TABLE_SIZE)
  {
    /* Si on trouve l'objet */
    if (hash_table[key].status == USED_ITEM && hash_table[key].code == itemCode)
    {
      hash_table[key].status = DELETED_ITEM;
      return (SUCCESS);
    }
    // Sinon essai suivant
    key = hashkey(itemCode, ++i);
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
  // printf("%"STR(CODE_PRE)"s %-"STR(ITEM_NAME_SIZE)"s PRIX INDEX\n", "CODE", "LIBELLE");
  printf("┌──────────┬────────────────────────────────┬────┬─────┐\n");
  printf("│%-10s│%-32s│PRIX│INDEX│\n", "CODE", "LIBELLE");
  printf("├──────────┼────────────────────────────────┼────┼─────┤\n");
  for (int i = 0; i < TABLE_SIZE; i++)
  {
    if (hash_table[i].status == USED_ITEM)
      // printf("%"STR(CODE_PRE)"d %-"STR(ITEM_NAME_SIZE)"s %1.2f %d\n"
      printf("│%-10d│%-32s│%1.2f│%-5d│\n", hash_table[i].code, hash_table[i].name, hash_table[i].price, i);
  }
  printf("└──────────┴────────────────────────────────┴────┴─────┘\n");
}

/*----------------------------------------------------------------------------
 * Cette fonction trouve le produit dont le code est itemCode.
 * Cette fonction retourne NULL si le produit n'existe pas.
 * Cette fonction retourne un pointeur vers le produit si le produit existe.
 *----------------------------------------------------------------------------*/
Item *getItem(unsigned int itemCode)
{
  uint32_t i = 0;
  uint32_t key = hashkey(itemCode, i);
  while (hash_table[key].status != NULL_ITEM && i < TABLE_SIZE)
  {
    /* Si on trouve l'objet */
    if (hash_table[key].status == USED_ITEM && hash_table[key].code == itemCode)
      return &(hash_table[key]);
    // Sinon essai suivant
    key = hashkey(itemCode, ++i);
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
  Item *item = getItem(itemCode);
  int ret = UPDATE_NO_ROW;
  if (item)
  {
    item->code = itemCode;
    strncpy(item->name, itemName, ITEM_NAME_SIZE);
    item->price = itemPrice;
    ret = SUCCESS;
  }
  return ret;
}

#define DIRTY 1
#define CLEAN 0
/*----------------------------------------------------------------------------
 * la fonction de réorganisation in situ:
 *----------------------------------------------------------------------------*/
void rebuildTable()
{
  // On salit toutes les entrées de la table
  for (int i = 0; i < TABLE_SIZE; i++)
    hash_table[i].dirty = DIRTY;
  uint32_t j, key, done;
  Item to_find, tmp;
  for (int i = 0; i < TABLE_SIZE; i++)
  {

    if (hash_table[i].status == USED_ITEM)
    {
      to_find = hash_table[i];
      // clean
      hash_table[i].status = NULL_ITEM;
      done = 0;
      while (!done)
      {
        j = 0;
        key = hashkey(to_find.code, j);
        while (hash_table[key].dirty != DIRTY && j < TABLE_SIZE)
          key = hashkey(to_find.code, ++j);

        /* Si on trouve l'objet */
        if (hash_table[key].dirty == DIRTY)
        {
          tmp = hash_table[key];
          hash_table[key].status = NULL_ITEM;
          /* remplir le [key] */
          hash_table[key] = to_find;
          hash_table[key].dirty = CLEAN;
        }
        else
          printf("ERREUR in rebuild table");

        // Si il y a un nouvel item à placer
        if (tmp.status == USED_ITEM)
        {
          to_find = tmp;
        }
        else
          done = 1;
      }
    }
  }
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

Result *findItem(char *itemName)
{
  Result *liste = malloc(sizeof(Result));
  Result *preced = NULL;
  Result *ptr = liste;

  for (int i = 0; i < TABLE_SIZE; i++)
    if (hash_table[i].status == USED_ITEM && !strcmp(itemName, hash_table[i].name))
    {
      ptr->item = &hash_table[i];
      ptr->next = malloc(sizeof(Result));
      preced = ptr;
      ptr = ptr->next;
    }

  if (ptr == liste)
    liste = NULL;
  else
    preced->next = NULL;

  free(ptr);

  return liste;
}

Result *findItemWithIndex(char *itemName)
{
  Result *liste = malloc(sizeof(Result));
  Result *preced = NULL;
  Result *ptr = liste;
  unsigned int Code = hashIndex(itemName, strlen(itemName));

  uint32_t i = 0;
  uint32_t key = hashkey(Code, i);
  while (item_hash_table[key]->status != NULL_ITEM && i < TABLE_SIZE)
  {
    if (item_hash_table[key]->status == USED_ITEM && !strcmp(itemName, item_hash_table[key]->name))
    {
      ptr->item = item_hash_table[key];
      ptr->next = malloc(sizeof(Result));
      preced = ptr;
      ptr = ptr->next;
    }
    key = hashkey(Code, ++i);
  }

  if (ptr == liste)
    liste = NULL;
  else
    preced->next = NULL;

  return liste;
}
