#include "translate.h"
#include "opcodes.h"

uint32_t mask(uint8_t start, uint8_t end)
{
  uint32_t result = 0;
  for (int i = start; i <= end; i++)
  {
    result |= 1u << i;
  }
  return result;
}

uint32_t format_I(uint8_t opcode, int args[], uint32_t special)
{
  uint32_t result = 0;
  result |= (special << 26) & mask(26, 30);
  result |= (args[1] << 21) & mask(21, 25);
  result |= (args[2] << 16) & mask(16, 20);
  result |= (args[0] << 11) & mask(11, 15);
  result |= opcode & mask(0, 10);
  return result;
}
uint32_t format_R(uint8_t opcode, int args[])
{
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= (args[1] << 21) & mask(21, 25);
  result |= (args[0] << 16) & mask(16, 20);
  result |= args[2] & mask(0, 15);
  return result;
}
uint32_t format_J(uint8_t opcode, int args[])
{
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= args[0] & mask(0, 26);
  return result;
}
int find_instruction(char string[])
{
    uint8_t index_instruction = 0,i=0;
    bool found = false;
    while (!found && LISTE_INSTRUCT[index_instruction].name != NULL)
    {
        i = 0;
        for (; LISTE_INSTRUCT[index_instruction].name[i] != 0 && LISTE_INSTRUCT[index_instruction].name[i] == string[i]; i++)
        {
        }
        if (string[i] == ' ' && LISTE_INSTRUCT[index_instruction].name[i] == 0)
        {
            found = true;
            /*int j = i;
            for (; string[j] != 0; j++)
            {
                string[j - i] = string[j];
            }
            string[j] = 0;*/
        }
        else
        {
            index_instruction++;
        }
    }
    return index_instruction;
}

uint32_t* parse_parameters(char *string, int index, int nb_arg_max){
  bool address = false;
  uint32_t* args = malloc(sizeof(uint32_t)*nb_arg_max);
  int length;
  int nb_arg = 0;
  while (string[index] != '\0' && nb_arg < nb_arg_max)
  {
    if (string[index] == ' ')
    {
      index ++;
    }
    else if (string[index] == '$')
    {
      address = true;
      index++;
    }
    else if (string[index] == ',')
    {
      index++;
    }
    else {
      if (address)
      {
        sscanf(string+index,"%x%n", &args[nb_arg], &length);
      }
      else {
        sscanf(string+index,"%u%n", &args[nb_arg], &length);
      }
      if (length == 0){
        if (address)
        {
          args[nb_arg] = 0;
        }
        //TODO
        // else {
        //   char *stringmachin;
        //   sscanf("%s",string[index], stringmachin);
        //   args[nb_arg] = label_to_adress(stringmachin);
        // }
      }
      nb_arg++;
      index += length;
      address=false;
    }
  }
  return args;
}

uint32_t translate_line(char string[]){
    uint8_t index_instruction=find_instruction(string);
    uint32_t resultat = 0;
    uint32_t arg1, arg2, arg3;
    //! faut refaire ce truc
    int* parameters;
    switch (LISTE_INSTRUCT[index_instruction].format)
    {
    case J:
        parameters=parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 2);
        resultat = format_J(LISTE_INSTRUCT[index_instruction].opcode, parameters);
        break;
    case I:
        parameters=parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
        resultat = format_I(LISTE_INSTRUCT[index_instruction].opcode, parameters, LISTE_INSTRUCT[index_instruction].special);
        break;
    case R:
        parameters=parse_parameters(string, strlen(LISTE_INSTRUCT[index_instruction].name), 3);
        resultat = format_R(LISTE_INSTRUCT[index_instruction].opcode, parameters);
        break;
    default:
        printf("IDK this command\n");
        exit(-1);
        break;
    }
    free(parameters);
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