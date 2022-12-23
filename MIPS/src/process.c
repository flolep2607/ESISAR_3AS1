#include "process.h"
void mode_interactif() {
  bool stop = false;
  uint32_t instruction;
  register_pc *registre = register_create();
  memory *ram = memory_create();
  int i = 0;
  while (!stop) {
    char *string = get_string_from_input();
    if (string == NULL || string[0] == 0) {
      printf("no info\n");
    }
    if (strcmp(string, "EXIT") == 0) {
      stop = true;
    } else {
      instruction = translate_line(string);
      printf("read: |%s|=>%08x\n", string, instruction);
      if (instruction) {
        memory_set(ram, 4 * i, instruction);
        execute_instruction(instruction, registre, ram);
        registre->pc += 4;
        i++;
      }
    }
    printf("=====\n");
    memory_show(ram);
    registre_show(registre);
    // no need to increase pc cause not used (technically we can easily)
    free(string);
  }
  free(registre);
  memory_free(ram);
}
void exec_file(FILE *fichier_bin, FILE *fichier_entree, FILE *fichier_stdout, char *fichier_nom_bin, bool pasapas) {
  register_pc *registre = register_create();
  memory *ram = memory_create();
  int i_max = 0;
  bool stop = false;
  uint32_t resultat;
  bool syscall=false;
  while (!stop) {
    char *string = get_string_from_file(fichier_entree, &stop);
    if (string == NULL || string == 0) {
      continue;
    }
    string = trim(string);
    if (string == NULL || string == 0) {
      free(string);
      stop = true;
      continue;
    }
    resultat = translate_line(string);
    memory_set(ram, 4 * i_max, resultat);
    if(resultat==translate_line("syscall")){
      syscall=true;
    }
    fprintf(fichier_bin, "%08x\n", resultat);
    free(string);
    i_max++;
  }
  if(!syscall){
    memory_set(ram, 4 * i_max, translate_line("syscall")); // to end the prog a the end without counter
  }
  if(pasapas){
    memory_show(ram);
  }
  fclose(fichier_entree);
  uint32_t instruction;
  int i = 0;
  while (!(registre->error)) { 
    if (pasapas) {
      printf("PC:%08x\n", registre->pc);
      getchar();
    }
    instruction = memory_get(ram, registre->pc);
    execute_instruction(instruction, registre, ram);
    if (pasapas) {
      memory_show(ram);
      registre_show(registre);
    }
    registre->pc += 4;
    i++;
  }
  if (registre->error) {
    printf("There is an error\n");
  }
  printf("=====\n");
  memory_show(ram);
  registre_show(registre);
  if (fichier_stdout != NULL) {
    registre_write(registre, fichier_stdout);
  }
  free(registre);
  memory_free(ram);
}