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
uint32_t format_I(uint8_t opcode, uint8_t rd, uint8_t rs, uint8_t rt, uint16_t special)
{
  uint32_t result = 0;
  result |= (special << 26) & mask(26, 30);
  result |= (rs << 21) & mask(21, 25);
  result |= (rt << 16) & mask(16, 20);
  result |= (rd << 11) & mask(11, 15);
  result |= opcode & mask(0, 10);
  return result;
}
uint32_t format_R(uint8_t opcode, uint8_t rt, uint8_t rs, uint16_t i)
{
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= (rs << 21) & mask(21, 25);
  result |= (rt << 16) & mask(16, 20);
  result |= i & mask(0, 15);
  return result;
}
uint32_t format_J(uint8_t opcode, uint32_t address)
{
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= address & mask(0, 26);
  return result;
}

void translate(char *line) {}
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