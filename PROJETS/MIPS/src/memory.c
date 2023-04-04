#include "memory.h"
// #define int32_t unsigned char // unsigned char data;//char => 1octets
/**
 * @brief Get the element object
 *
 * @param mem
 * @param address
 * @return int32_t
 */
int32_t get_element(memory *mem, unsigned long int address) {
  srand(time(NULL));
  bool done = false;
  memory *elem = mem;
  while (!done && elem->next != NULL) {
    elem = elem->next;
    if (elem->address == address) {
      done = true;
    }
  }
  int32_t value;
  if (done) {
    value = elem->data;
  } else {
    value = (int32_t)(rand() % UINT32_MAX);
  }
  return value;
}
/**
 * @brief
 *
 * @param address
 */
void checks(unsigned long int address) {
  // printf("%ld\n", address);
  if (address > max_memory) {
    //! ERROR c'est en dehors des 4Go
    printf("access memoire >4Go\n");
    exit(5);
  } else if (address % sizeof(int32_t) != 0) {
    //! ERROR c'est pas aligné
    printf("access memoire non aligné\n");
    exit(4);
  }
}

/**
 * @brief
 *
 * @param mem
 * @param address
 * @param data
 */
void insert_element(memory *mem, unsigned long int address, int32_t data) {
  memory *currentAdd = mem;
  while (currentAdd->next != NULL && (currentAdd->next)->address < address) {
    currentAdd = currentAdd->next;
  }
  if (currentAdd->next != NULL && (currentAdd->next)->address == address) {
    (currentAdd->next)->data = data;
  } else {
    memory *newElem = (memory *)malloc(sizeof(memory));
    newElem->data = data;
    newElem->address = address;
    newElem->next = currentAdd->next;
    currentAdd->next = newElem;
  }
}
/**
 * @brief Get the value object
 *
 * @param mem
 * @param address
 * @return int32_t
 */
uint32_t memory_get(memory *mem, unsigned long int address) {
  checks(address);
  return get_element(mem, address);
}
/**
 * @brief
 *
 * @param mem
 * @param address
 * @param data
 */
void memory_set(memory *mem, unsigned long int address, int32_t data) {
  checks(address);
  insert_element(mem, address, data);
}
/**
 * @brief
 *
 * @param mem
 * @param address
 */
void memory_delete(memory *mem, unsigned long int address) {
  memory *prev_delete = mem;
  while (prev_delete->next != NULL && (prev_delete->next)->address < address) {
    prev_delete = prev_delete->next;
  }
  if ((prev_delete->next)->address == address) {
    memory *mem_to_delete = prev_delete->next;
    prev_delete->next = mem_to_delete->next;
    free(mem_to_delete);
  }
}
/**
 * @brief
 *
 * @param mem
 */
void memory_show(memory *mem) {
  memory *elem = mem;
  while (elem->next != NULL) {
    elem = elem->next;
    printf("add:0x%08lX value:%08x\n", elem->address, elem->data);
  }
}
/**
 * @brief
 *
 * @param mem
 */
void memory_free(memory *mem) {
  memory *nextElem = mem;
  memory *current = mem;
  while (current != NULL) {
    nextElem = current->next;
    free(current);
    current = nextElem;
  }
}
/**
 * @brief Create a memory object
 *
 * @return memory*
 */
memory *memory_create() {
  memory *elem = malloc(sizeof(memory));
  elem->next = NULL;
  elem->data = 0;
  elem->address = -1;
  return elem;
}

// int main(){
//     memory* mem=create_memory();
//     insert_value(mem,0x4,1);
//     printf("0x%08x\n",get_value(mem,0x4));
//     aff_memory(mem);
//     free_memory(mem);
//     return 0;
// }