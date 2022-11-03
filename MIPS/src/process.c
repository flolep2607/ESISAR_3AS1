#include "utils.h"
#include "process.h"
void mode_interactif() {
  bool stop = false;
  while (!stop) {
    char* string = get_input();
    if (strcmp(string, "EXIT") == 0) {
      stop = true;
    } else {
      printf("read: |%s|\n", string);
    }
    free(string);
  }
}
void mode_fichier(char* fichierin, char* fichierout, bool pasapas);