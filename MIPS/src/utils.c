#include "utils.h"
#include "default.h"
char *get_string_from_file(FILE *fichier){
  char *p = '\0';
  int i = 1;
  int c;
  bool stop = false;
  bool skip = false;
  while (!stop && (c = fgetc(fichier)) != EOF) {
    //TODO skip first spaces
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

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}