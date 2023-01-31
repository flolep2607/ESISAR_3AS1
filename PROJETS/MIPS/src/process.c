#include "process.h"
void mode_interactif() {
  bool stop = false;
  uint32_t instruction;
  register_pc *registre = register_create();
  memory *ram = memory_create();
  labels *labels_list = NULL;
  int i = 0;
  while (!stop) {
    int is_instruction = true;
    char *string = get_string_from_input();
    if (string == NULL || string[0] == 0) {
      printf("no info\n");
      continue;
    }
    string = trim(string);
    if (strcmp(string, "EXIT") == 0) {
      stop = true;
    } else {
      instruction = translate_line(string, i, labels_list, &is_instruction);
      if (!is_instruction) {
        continue;
      }
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
  labels_free(labels_list);
}

void exec_file(FILE *fichier_bin, FILE *fichier_entree, FILE *fichier_stdout, bool pasapas) {
  register_pc *registre = register_create();
  memory *ram = memory_create();
  labels *labels_list = NULL;
  int i_max = 0;
  bool stop = false;
  int is_instruction = true;
  uint32_t resultat;
  labels_findall(fichier_entree, &labels_list);
  labels_show(labels_list);
  char *string = NULL;
  char *string_malloc = NULL;
  while (!stop) {
    if (string_malloc != NULL) {
      free(string_malloc);
      string_malloc = NULL;
    }
    if (string != NULL) {
      free(string);
      string = NULL;
    }
    is_instruction = true;
    string_malloc = get_line_from_file(fichier_entree, &stop);
    if (string_malloc == NULL || string_malloc == 0 || *string_malloc == 0) {
      continue;
    }
    string = trim_alloc(string_malloc);
    if (string == NULL || string == 0 || *string == 0) {
      // stop = true;
      continue;
    }
    // printf("string|%s|\n", string);
    resultat = translate_line(string, i_max, labels_list, &is_instruction);
    if (!is_instruction) {
      continue;
    }
    if (is_instruction == -1) {
      if (string_malloc != NULL) {
        free(string_malloc);
      }
      if (string != NULL) {
        free(string);
      }
      free(registre);
      memory_free(ram);
      labels_free(labels_list);
      exit(3);
    }
    memory_set(ram, 4 * i_max, resultat);
    fprintf(fichier_bin, "%08X\n", resultat);
    i_max++;
  }
  fclose(fichier_bin);
  fclose(fichier_entree);
  if (string_malloc != NULL) {
    free(string_malloc);
    string_malloc = NULL;
  }
  if (string != NULL) {
    free(string);
    string = NULL;
  }
  memory_set(ram, 4 * i_max, translate_line("syscall", i_max, labels_list, &is_instruction)); // to end the prog a the end without counter

  if (pasapas) {
    memory_show(ram);
  }
  uint32_t instruction;
  int i = 0;
  uint32_t delayslot=0;
  while (!(registre->error) && i<100) {
    if (pasapas) {
      printf("PC:%08x\n", registre->pc);
      getchar();
    }
    delayslot=registre->pc+4;
    instruction = memory_get(ram, registre->pc);
    printf("%02d,%d=>%08X\n",i,registre->pc/4+1,instruction);
    execute_instruction(instruction, registre, ram);
    if (pasapas) {
      memory_show(ram);
      registre_show(registre);
    }
    if(registre->delayslot){
      instruction = memory_get(ram, delayslot);
      printf("delai sloted|%02d,%d=>%08X\n",i,registre->pc/4+1,instruction);
      execute_instruction(instruction, registre, ram);
      if (pasapas) {
        memory_show(ram);
        registre_show(registre);
      }
      registre->delayslot=false;
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
  labels_free(labels_list);
}