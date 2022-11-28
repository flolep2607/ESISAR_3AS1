/* binome
Lukas Moncorgé
Florian Leprat
*/
#include "default.h"
#include "process.h"
#include "translate.h"
FILE *openfile(char *filename, const char *open_mode) {
  FILE *file;
  file = fopen(filename, open_mode);
  if (file == NULL) {
    printf("Error opening file:%s\n", filename);
    exit(1);
  }
  return file;
}
#ifndef TEST
int main(int argc, char *argv[]) {
  // - interactif
  // - fichier(?pas a pas) -> console
  // - fichier(?pas a pas) -> fichiers
  bool pasapas = false;
  char *fichier_nom_entree = "";
  char *fichier_nom_bin = "";
  char *fichier_nom_stdout = "";
  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-pas") == 0) {
      pasapas = true;
    } else if (fichier_nom_entree[0] == 0) {
      fichier_nom_entree = argv[i];
    } else if (fichier_nom_bin[0] == 0) {
      fichier_nom_bin = argv[i];
    } else {
      fichier_nom_stdout = argv[i];
    }
  }
  FILE *fichier_entree = NULL;
  FILE *fichier_bin = NULL;
  FILE *fichier_stdout = NULL;
  if (fichier_nom_entree != 0) {
    fichier_entree = openfile(fichier_nom_entree, "r");
  }
  if (fichier_nom_bin != 0) {
    fichier_bin = openfile(fichier_nom_bin, "w");
  }
  if (fichier_nom_stdout != 0) {
    fichier_stdout = openfile(fichier_nom_stdout, "w");
  }
  printf("fichier entrée:%s\n", fichier_nom_entree);
  printf("fichier bin:%s\n", fichier_nom_bin);
  printf("fichier stdout:%s\n", fichier_nom_stdout);
  printf("pas a pas:%d\n", pasapas);
  if (fichier_entree != NULL && fichier_nom_bin != NULL) {
  } else if (fichier_entree != NULL) {
  } else {
    mode_interactif();
  }
  return 0;
}
#endif