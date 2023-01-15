#include "labels.h"
void labels_show(labels *head) {
  labels *current = head;
  printf("LABELS:\n");
  while (current != NULL) {
    printf("|%s|->%08x\n", current->name, current->address);
    current = current->next;
  }
}

// Function to create a new node in the linked list
labels *create_node(char *string, int value) {
  // Allocate memory for the new node
  labels *node = (labels*)malloc(sizeof(labels));
  if (node == NULL) {
    fprintf(stderr, "Error: unable to allocate memory for new node\n");
    exit(1);
  }

  // Initialize the new node
  node->name = string;  // Make a copy of the string
  node->address = value;
  node->next = NULL;

  return node;
}

// Function to search for a node with a given string in the linked list
labels *labels_get(labels *head, char *string) {
  labels *current = head;
  while (current != NULL) {
    if (strcmp(current->name, string) == 0) {
      // Found a matching string
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Function to add a new node to the end of the linked list
void labels_set(labels **head, char *string, uint32_t value) {
  labels *new_node = create_node(string, value);

  // Special case: adding to an empty list
  if (*head == NULL) {
    *head = new_node;
    return;
  }

  // Find the last node in the list
  labels *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  // Append the new node to the end of the list
  current->next = new_node;
}

// Function to free the memory used by a linked list
void labels_free(labels *head) {
  labels *current = head;
  while (current != NULL) {
    labels *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
}

void labels_findall(FILE *file, labels **labels_list) {
  bool end = false;
  int lines = 0;
  char *malloced_string=NULL;
  char* string=NULL;
  while (!end) {
    if(malloced_string!=NULL){free(malloced_string);malloced_string=NULL;}
    if(string!=NULL){free(string);string=NULL;}
    malloced_string = get_line_from_file(file, &end);
    string = trim_alloc(malloced_string);
    if (string != NULL && string != 0 && string[0] != 0) {
      if (string[(strlen(string) - 1)] == ':') {
        char *dist = strpbrk(string, " :");
        char *tmp_label = (char *)calloc((dist - string + 1) * sizeof(char *), 1);
        strncpy(tmp_label, string, dist - string);
        if (tmp_label == NULL) {
          printf("[ERROR] not a label\n");
          exit(7);
        }
        if (labels_get(*labels_list, tmp_label) == NULL) {
          labels_set(labels_list, tmp_label, lines);
          // printf("ADD LABEL |%s|%08x|\n",tmp_label,lines * 4);
          continue;
        } else {
          printf("Redefinition of the label:%s\n", tmp_label);
          free(tmp_label);
          exit(6);
        }
      } else {
        lines++;
      }
    }
  }
  if(malloced_string){free(malloced_string);}
  if(string){free(string);}
  fseek(file, 0, SEEK_SET);
}