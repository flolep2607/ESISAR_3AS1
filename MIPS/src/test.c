#include "default.h"
#include "memory.h"
#include "opcodes.h"
#include "process.h"
#include "registre.h"
#include "translate.h"
#include "utils.h"
//#ifdef TEST
int translate_test(){
    // ADD $7, $5, $2
  // 00a23820
  // ADD $2,$3,$4
  // 00641020
  // printf("%08x\n", format_I(0b100000, 2, 3, 4, 0));
  // ADDI $2, $3, 200
  // 206200C8
  char string[] = "ADDI $2, $3, 200";
  uint8_t index = 0, i = 0;
  bool found = false;
  while (!found && LISTE_INSTRUCT[index].name != NULL)
  {
    i = 0;
    for (; LISTE_INSTRUCT[index].name[i] != 0 && LISTE_INSTRUCT[index].name[i] == string[i]; i++)
    {
    }
    if (string[i] == ' ' && LISTE_INSTRUCT[index].name[i] == 0)
    {
      found = true;
      int j=i;
      for (; string[j]!=0;j++)
      {
        string[j-i]=string[j];
      }
      string[j]=0;
    }
    else
    {
      index++;
    }
  }
  printf("is found: %d\n", found);
  uint16_t resultat = 0;
  //uint8_t args = get_args(string);
  uint8_t arg8_1,arg8_2,arg8_3;
  uint32_t arg32;
  uint16_t arg16;
  //! faut refaire ce truc
  switch (LISTE_INSTRUCT[index].format)
  {
  case J:
    printf(">%d\n",sscanf("%d",string, &arg32));
    resultat = format_J(LISTE_INSTRUCT[index].opcode, arg32);
    break;
  case I:
    printf(">%d\n",sscanf("$%d,$%d,%d",string, &arg8_1,&arg8_2,&arg8_3));
    resultat = format_I(LISTE_INSTRUCT[index].opcode,arg8_1,arg8_2,arg8_3, LISTE_INSTRUCT[index].special);
    break;
  case R:
    printf(">%d\n",sscanf(" $%d, $%d, %d",string, &arg8_1,&arg8_2,&arg8_3));
    resultat = format_R(LISTE_INSTRUCT[index].opcode,arg8_1,arg8_2,arg8_3);
    break;
  default:
    printf("IDK this command\n");
    exit(-1);
    break;
  }

  printf("%08x\n", resultat);
  return 0;
}

int main()
{
    int error_code=translate_test();
    if(error_code>0){
        printf("[ERROR] translate code:%d\n",error_code);
    }
}
//#endif