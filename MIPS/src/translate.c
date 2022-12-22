#include "translate.h"

uint32_t format_strange(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(args[0], 21, 25);
  result |= part_set(opcode, 0, 6);
  return result;
}
uint32_t format_R_aled(uint8_t opcode, uint32_t args[], uint32_t special) {
  uint32_t result = 0;
  result |= part_set(special, 26, 30);
  result |= part_set(args[0], 11, 15);
  result |= part_set(opcode, 0, 5);
  return result;
}
uint32_t format_no_args(uint8_t opcode) {
  uint32_t result = 0;
  result |= part_set(opcode, 0, 5);
  return result;
}
uint32_t format_R_alternative(uint8_t opcode, uint32_t args[], uint32_t special) {
  uint32_t result = 0;
  result |= part_set(special, 26, 31);
  result |= part_set(args[0], 21, 25);
  result |= part_set(args[1], 16, 20);
  result |= part_set(opcode, 0, 5);
  return result;
}
uint32_t format_R_inversed(uint8_t opcode, uint32_t args[], uint32_t special) {
  uint32_t tmp = args[0];
  args[0] = args[1];
  args[1] = tmp;
  return format_R(opcode, args, special);
}
uint32_t format_R_inv_20(uint8_t opcode, uint32_t args[], uint32_t special) {
  uint32_t result = 0;
  result |= part_set(special, 26, 31);
  result |= part_set(args[1], 16, 20);
  result |= part_set(args[0], 11, 15);
  result |= part_set(args[2], 6, 10);
  result |= part_set(opcode, 0, 5);
  return result;
}
uint32_t format_R(uint8_t opcode, uint32_t args[], uint32_t special) {
  uint32_t result = 0;
  result |= part_set(special, 26, 31);
  result |= part_set(args[1], 21, 25);
  result |= part_set(args[2], 16, 20);
  result |= part_set(args[0], 11, 15);
  result |= part_set(opcode, 0, 5);
  return result;
}
uint32_t format_I_no_first(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(opcode, 26, 31);
  result |= part_set(args[0], 16, 20);
  result |= part_set(args[1], 0, 15);
  return result;
}
uint32_t format_I_oof(uint8_t opcode, uint32_t args[]) {
  uint32_t tmp = args[0];
  args[0] = args[1];
  args[1] = tmp;
  return format_I(opcode, args);
}
uint32_t format_I3(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(opcode, 26, 31);
  result |= part_set(args[2], 21, 25);
  result |= part_set(args[0], 16, 20);
  result |= part_set(args[1], 0, 15);
  return result;
}
uint32_t format_I2(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(opcode, 26, 31);
  result |= part_set(args[0], 21, 25);
  result |= part_set(args[1], 0, 15);
  return result;
}
uint32_t format_I(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(opcode, 26, 31);
  result |= part_set(args[1], 21, 25);
  result |= part_set(args[0], 16, 20);
  result |= part_set(args[2], 0, 15);
  return result;
}
uint32_t format_J(uint8_t opcode, uint32_t args[]) {
  uint32_t result = 0;
  result |= part_set(opcode, 26, 31);
  result |= part_set(args[0], 0, 26);
  return result;
}

uint32_t *parse_parameters(char *string, int index, int nb_arg_max) {
  if (nb_arg_max == 0) {
    uint32_t *args = calloc(1, sizeof(uint32_t));
    return args;
  }
  bool address = false;
  uint32_t *args = calloc(nb_arg_max, sizeof(uint32_t));
  int length;
  int nb_arg = 0;
  uint8_t length_string=strlen(string);
  while (index<length_string && string[index] != '\0' && nb_arg < nb_arg_max) {
    if (string[index] == ' ') {
      index++;
    } else if (string[index] == '$') {
      address = true;
      index++;
    } else if (string[index] == ',' || string[index] =='(') {
      index++;
    } else {
      if (address) {
        sscanf(string + index, "%u%n", &args[nb_arg], &length);
        if (length == 0) {
          int8_t index_mnemo = find_in_list(string + index, NEMO);
          if (index_mnemo < 0) {
            args[nb_arg] = 0;
          } else {
            length = strlen(NEMO[index_mnemo].name);
            args[nb_arg] = NEMO[index_mnemo].opcode;
          }
        }
      } else {
        sscanf(string + index, "%u%n", &args[nb_arg], &length);
        if (length == 0) {
          // TODO
          //  else {
          //    char *stringmachin;
          //    sscanf("%s",string[index], stringmachin);
          //    args[nb_arg] = label_to_adress(stringmachin);
          //  }
        }
      }
      nb_arg++;
      index += length;
      address = false;
    }
  }
  return args;
}

uint32_t translate_line(char string[]) {
  int8_t index_instruction = find_in_list(string, LISTE_INSTRUCT);
  if (index_instruction < 0) {
    printf("[ERROR] Instruction not found: %s", string);
    exit(-1);
  }
  uint32_t resultat = 0;
  // uint32_t arg1, arg2, arg3;
  //! faut refaire ce truc
  uint32_t *parameters = NULL;
  // TODO just 1 R malloc here
  // TODO
  switch (LISTE_INSTRUCT[index_instruction].format) {
  case J:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 2);
    resultat = format_J(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case R_strange:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 1);
    resultat = format_strange(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case R_inv_20:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_R_inv_20(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
    break;
  case R_reverse:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_R_inversed(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
    break;
  case R_alternative:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 2);
    resultat = format_R_alternative(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
    break;
  case R_aled:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 1);
    resultat = format_R_aled(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
    break;
  case R:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_R(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
    break;
  case I_oof:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_I_oof(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case I:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_I(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case I2:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_I2(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case I3:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
    resultat = format_I3(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case I_no_first:
    parameters = parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 2);
    resultat = format_I_no_first(LISTE_INSTRUCT[index_instruction].opcode, parameters);
    break;
  case no_args:
    resultat = format_no_args(LISTE_INSTRUCT[index_instruction].opcode);
    break;
  default:
    printf("IDK this command\n");
    exit(-1);
    break;
  }
  if (parameters != NULL) {
    free(parameters);
  }
  // show command debug
  printf("%s=>%08x\n",string,resultat);
  return resultat;
}
// string : (" $4,$3,2",1)=> "3"
/*uint8_t get_args(char *string, int arg_number)
{
  printf(">%s\n",string);
  char ARG[20]={0};
  uint8_t resultat;
  switch (arg_number)
  {
  case 0:
    sscanf(string,"%s", ARG);
    break;
  case 1:
    sscanf(string,"%s,%s", NULL, ARG);
    break;
  case 2:
    sscanf(string,"%s,%s,%s", NULL, NULL, ARG);
    break;
  default:
    printf("Invalid.\n");
    break;
  }
  printf(">%s\n",ARG);
  sscanf("%d", ARG, resultat);
  return resultat;
}*/
/*uint8_t get_args(char* string){
    uint8_t args=0;
    for (int i=0; string[i];i++){
        if(string[i]==',') args++;
    }
    return args+1;
}*/