#include "default.h"
#include "utils.h"
#include "process.h"
#ifndef LABEL
#define LABEL
typedef struct label {
  char *name;
  uint32_t address;
  struct label *next;
} labels;
#endif
void labels_set(labels **head_ref, char *new_name, uint32_t address);
labels *labels_get(labels *head, char *search_name);
void labels_findall(FILE* file,labels** labels_list);
void labels_show(labels *head);
void labels_free(labels *head);