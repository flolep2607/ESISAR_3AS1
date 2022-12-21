#include "process.h"
void mode_interactif() {
  bool stop = false;
  while (!stop) {
    char *string = get_string_from_input();
    if (strcmp(string, "EXIT") == 0) {
      stop = true;
    } else {
      printf("read: |%s|\n", string);
    }
    free(string);
  }
}
void exec_file(FILE *fichier_bin, FILE *fichier_entree, FILE *fichier_stdout, char *fichier_nom_bin, bool pasapas) {
  bool stop = false;
  uint32_t resultat;
  printf("fichier bin out\n");
  while (!stop) {
    // TODO put an args that can be set to 0 if OEF
    char *string = get_string_from_file(fichier_entree, &stop);
    // printf("aled1:%s\n",string);
    if (string == NULL || string == 0) {
      // free(string);
      // stop=true;
      continue;
    }
    string = trim(string);
    if (string == NULL || string == 0) {
      free(string);
      stop = true;
      continue;
    }
    resultat = translate_line(string);
    fprintf(fichier_bin, "%08x\n", resultat);
    free(string);
  }
  fclose(fichier_entree);
  if (fichier_nom_bin != NULL) {
    fclose(fichier_bin);
    fichier_bin = openfile(fichier_nom_bin, "r");
  }
  register_pc *registre = create_register();
  stop = false;
  char buf[9] = {0};
  uint32_t instruction;
  uint32_t position = get_cursor_position(registre);
  long maximum = fsize(fichier_bin);
  while (!stop & (maximum > position)) {
    // printf("PC:%08x\n",registre->pc);
    int returnCode = fseek(fichier_bin, position, SEEK_SET);
    // printf("return code:%d %08x %d\n",returnCode,position,maximum>position);
    if (returnCode != 0) {
      printf("END of instructions");
      stop = true;
      exit(0);
      continue;
    }
    if (pasapas) {
      getchar();
    }
    memset(buf, 0, 8);
    fread(buf, 1, 8, fichier_bin);
    // printf(">>%s<<\n",buf);
    sscanf(buf, "%x", &instruction);
    // printf(">>%08x<<\n", instruction);
    if (pasapas) {
      printf("PC:%d\n", registre->pc);
      execute_instruction(instruction, registre);
    }
    printf_registre(registre);
    registre->pc += 4;
    position = get_cursor_position(registre);
  }
  if(fichier_stdout!=NULL){
    write_registre(registre, fichier_stdout);
  }
  free(registre);
}