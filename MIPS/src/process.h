#ifndef PROCESS
#define PROCESS
#include "default.h"
#include "memory.h"
#include "utils.h"
#include "execution.h"
#include "translate.h"

void mode_interactif();
void mode_fichier(char* fichierin,char* fichierout,bool pasapas);
void exec_file(FILE* fichier_bin, FILE* fichier_entree,FILE* fichier_stdout, bool pasapas);
#endif