#include "default.h"
#include "utils.h"

void mode_interactif();
void mode_fichier(char* fichierin,char* fichierout,bool pasapas);
void exec_file(FILE* fichier_bin, FILE* fichier_entree,FILE* fichier_stdout,char* fichier_nom_bin, bool pasapas);