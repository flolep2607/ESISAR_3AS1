#include "utils.h"

char *get_string_from_file(FILE *fichier,bool* end) {
  char *p = '\0';
  int i = 1;
  int c;
  bool stop = false;
  bool skip = false;
  while (!stop && (c = fgetc(fichier)) != EOF) {
    // TODO skip first spaces
    if (c == '\n') {
      stop = true;
    } else if (skip || c == '#') {
      // skip until \n cause useless
      skip = true;
    } else {
      char *newp = realloc(p, (i+1) *sizeof(char));
      //! if error return NULL
      if (newp == NULL) {
        free(p);
        return NULL;
      }
      p = newp;
      p[i++ - 1] = c;
      p[i - 1] = '\0';
    }
  }
  *end=(c==EOF);
  return p;
}

char *get_string_from_input() {
  printf(">");
  char *p = "";
  int i = 1;
  int c;
  bool stop = false;
  bool skip = false;
  while (!stop && (c = getchar()) != EOF) {
    if (c == '\n') {
      stop = true;
    } else if (skip) {
    } else if (c == '#') {
      // skip until \n cause useless
      skip = true;
    } else {
      char *newp = realloc(p, (i+1) * sizeof(char));
      if (newp == NULL) {
        free(p);
        return NULL;
      }
      p = newp;
      p[i++ - 1] = c;
      p[i - 1] = '\0';
    }
  }
  return p;
}

char *trim(char *s) {
  //left trim
  while (isspace(*s)){s++;}
  //right trim
  char *back = s + strlen(s);
  while (isspace(*(--back)));
  *(back + 1) = '\0';
  return s;
  // return right_trim(left_trim(s)); 
}
uint32_t mask(uint8_t start, uint8_t end) {
  uint32_t result = 0;
  for (int i = start; i <= end; i++) {
    result |= 1u << i;
  }
  return result;
}
uint32_t part_set(uint32_t word, uint8_t start, uint8_t end) { return (word << start) & mask(start, end); }
uint32_t part_get(uint32_t word, uint8_t start, uint8_t end) { return ((word & mask(start, end)) >> start); }
long fsize(FILE *file) {
  long size = 0;
  if (fseek(file, 0, SEEK_END) == 0) {
    size = ftell(file);
  }
  return size;
}
uint32_t get_cursor_position(register_pc* registre){
  return (registre->pc/4)+registre->pc*2;
}
FILE *openfile(char *filename, const char *open_mode) {
  FILE *file;
  file = fopen(filename, open_mode);
  if (file == NULL) {
    printf("Error opening file:%s\n", filename);
    exit(1);
  }
  return file;
}
int8_t find_in_list(char string[],const instruction liste[]) {
  uint8_t index_instruction = 0, i = 0;
  bool found = false;
  while (!found && liste[index_instruction].name != NULL) {
    i = 0;
    for (; liste[index_instruction].name[i] != 0 && string[i] != 0 && toupper(liste[index_instruction].name[i]) == toupper(string[i]); i++) {
    }
    // printf("|%c|%c|\n",string[i],liste[index_instruction].name[i]);
    if ((string[i] == ' ' ||string[i] == ',' || string[i] == 0) && liste[index_instruction].name[i] == 0) {
      found = true;
      /*int j = i;
      for (; string[j] != 0; j++)
      {
          string[j - i] = string[j];
      }
      string[j] = 0;*/
    } else {
      index_instruction++;
    }
  }
  if (!found) {
    return -1;
  }
  return index_instruction;
}
