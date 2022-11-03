#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "process.h"
#include "translate.h"

int main(int argc, char *argv[]) {
  //* - interactif
  //* - fichier(?pas a pas) -> console
  //* - fichier(?pas a pas) -> fichiers
  bool pasapas = false;
  char *fichier_entree = "";
  char *fichier_sortie = "";
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-pas") == 0) {
      pasapas = true;
    } else if (fichier_entree[0] == 0) {
      fichier_entree = argv[i];
    } else {
      fichier_sortie = argv[i];
    }
  }

  if (fichier_entree == 0) {
  }
  printf("fichier entrée:%s\n", fichier_entree);
  printf("fichier sortie:%s\n", fichier_sortie);
  printf("pas a pas:%d\n", pasapas);
  mode_interactif();
  return 0;
}
