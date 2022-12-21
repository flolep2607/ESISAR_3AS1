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
      char *newp = realloc(p, i + sizeof(char));
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
  char *p = '\0';
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
      char *newp = realloc(p, i + sizeof(char));
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

char *ltrim(char *s) {
  while (isspace(*s))
    s++;
  return s;
}

char *rtrim(char *s) {
  char *back = s + strlen(s);
  while (isspace(*--back))
    ;
  *(back + 1) = '\0';
  return s;
}

char *trim(char *s) { return rtrim(ltrim(s)); }
uint32_t mask(uint8_t start, uint8_t end) {
  uint32_t result = 0;
  for (int i = start; i <= end; i++) {
    result |= 1u << i;
  }
  return result;
}
uint32_t set_part(uint32_t word, uint8_t start, uint8_t end) { return (word << start) & mask(start, end); }
uint32_t get_part(uint32_t word, uint8_t start, uint8_t end) { return ((word & mask(start, end)) >> start); }
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