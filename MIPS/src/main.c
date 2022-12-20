/* binome
Lukas Moncorgé
Florian Leprat
*/
#include "default.h"
#include "process.h"
#include "translate.h"
#include "utils.h"
#include "execution.h"

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
    printf("fichier_nom_entree:%s\n",fichier_nom_entree);
    fichier_entree = openfile(fichier_nom_entree, "r");
  }
  if (fichier_nom_bin != 0) {
    printf("fichier_nom_bin:%s\n",fichier_nom_bin);
    fichier_bin = openfile(fichier_nom_bin, "w");
  }
  if (fichier_nom_stdout != 0) {
    printf("fichier_nom_stdout:%s\n",fichier_nom_stdout);
    fichier_stdout = openfile(fichier_nom_stdout, "w");
  }
  printf("fichier entrée:%s\n", fichier_nom_entree);
  printf("fichier bin:%s\n", fichier_nom_bin);
  printf("fichier stdout:%s\n", fichier_nom_stdout);
  printf("pas a pas:%d\n", pasapas);
  uint32_t resultat;
  if (fichier_entree != NULL && fichier_bin != NULL) {
    printf("fichier bin out\n");
    bool stop=false;
    while (!stop) {
        //TODO put an args that can be set to 0 if OEF
        char* string = get_string_from_file(fichier_entree);
        // printf("aled1:%s\n",string);
        if(string==NULL || string==0){
          free(string);
          stop=true;
          continue;
        }
        string=trim(string);
        if(string==NULL || string==0){
          free(string);
          stop=true;
          continue;
        }
        resultat=translate_line(string);
        fprintf(fichier_bin,"%08x\n",resultat);
        free(string);
    }
    fclose(fichier_entree);
    fclose(fichier_bin);
    fichier_bin = openfile(fichier_nom_bin, "r");
    register_pc *registre=create_register();
    stop=false;
    char buf[9]={0};
    uint32_t instruction;
    uint32_t position=get_cursor_position(registre);
    long maximum=fsize(fichier_bin);
    while (!stop & (maximum>position)) {
        //TODO put an args that can be set to 0 if OEF
        printf("PC:%08x\n",registre->pc);
        int returnCode=fseek(fichier_bin,position, SEEK_SET);
        //printf("return code:%d %08x %d\n",returnCode,position,maximum>position);
        if (returnCode != 0) {
          printf("END of instructions");
          stop=true;
          exit(0);
          continue;
        }
        // getchar();
        memset(buf, 0, 8);
        fread(buf, 1, 8, fichier_bin);
        // printf(">>%s<<\n",buf);
        sscanf(buf,"%x",&instruction);
        printf(">>%08x<<\n", instruction);
        execute_instruction(instruction, registre);
        //printf_registre(registre);
        registre->pc+=4;
        position=get_cursor_position(registre);
    }
    write_registre(registre,fichier_stdout);
    free(registre);
  } else if (fichier_entree != NULL) {
  } else {
    mode_interactif();
  }
  return 0;
}
#endif