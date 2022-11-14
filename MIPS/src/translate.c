#include "translate.h"
#include "opcodes.h"

uint32_t mask(uint8_t start, uint8_t end) {
  uint32_t result = 0;
  for (int i = start; i <= end; i++) {
    result |= 1u << i;
  }
  return result;
}
uint32_t format_I(uint8_t opcode, uint8_t rd, uint8_t rs, uint8_t rt, uint16_t special) {
  uint32_t result = 0;
  result |= (special << 26) & mask(26, 30);
  result |= (rs << 21) & mask(21, 25);
  result |= (rt << 16) & mask(16, 20);
  result |= (rd << 11) & mask(11, 15);
  result |= opcode & mask(0, 10);
  return result;
}
uint32_t format_R(uint8_t opcode, uint8_t rt, uint8_t rs, uint16_t i) {
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= (rs << 21) & mask(21, 25);
  result |= (rt << 16) & mask(16, 20);
  result |= i & mask(0, 15);
  return result;
}
uint32_t format_J(uint8_t opcode, uint32_t address) {
  uint32_t result = 0;
  result |= (opcode << 26) & mask(26, 31);
  result |= address & mask(0, 26);
  return result;
}

void translate(char *line) {}
// string : (" $4,$3,2",1)=> "4"
uint8_t get_args(char* string,int arg_number){
  int start=0;
  int end=0;
  for(int i=0;;i++){

  }
  return args+1;
}
/*uint8_t get_args(char* string){
    uint8_t args=0;
    for (int i=0; string[i];i++){
        if(string[i]==',') args++;
    }
    return args+1;
}*/

int main() {
  // ADD $7, $5, $2
  // 00a23820
  // ADD $2,$3,$4
  // 00641020
  // printf("%08x\n", format_I(0b100000, 2, 3, 4, 0));
  // ADDI $2, $3, 200
  // 206200C8
  char string[] = "ADDI 2, 3, 200";
  uint8_t index = 0, i = 0;
  bool found = false;
  while (!found && LISTE_INSTRUCT[index].name != NULL) {
    i = 0;
    for (; LISTE_INSTRUCT[index].name[i] != 0 && LISTE_INSTRUCT[index].name[i] == string[i]; i++) {
    }
    if (string[i] == ' ' && LISTE_INSTRUCT[index].name[i]==0) {
      found = true;
    }else{
      index++;
    }
  }
  printf("is found: %d\n",found);
  uint8_t number_args = 0;
  uint16_t resultat=0;
  uint8_t args = get_args(string);
  switch (LISTE_INSTRUCT[index].format) {
  case J:
    number_args = 1;
    resultat=format_J(LISTE_INSTRUCT[index].opcode,42);
    break;
  case I:
    number_args = 3;
    resultat=format_I(LISTE_INSTRUCT[index].opcode, 2, 3,LISTE_INSTRUCT[index].special);
    break;
  case R:
    number_args = 3;
    resultat=format_R(LISTE_INSTRUCT[index].opcode, 2, 3, 200);
    break;
  default:
    printf("IDK this command\n");
    exit(-1);
    break;
  }
  
  printf("%08x\n", resultat);
  return 0;
}