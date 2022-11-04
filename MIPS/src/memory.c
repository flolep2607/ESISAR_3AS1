#include "memory.h"

typedef struct _memory
{
    unsigned char data;//char => 1octets 
    unsigned long int address;//long int => minimum 32 bits = 0xFFFFFFFF
    struct _memory* next;
} memory;
unsigned char get_memory(memory* mem,unsigned long int address)
{
    bool done=false;
    memory* elem = mem;
    while(!done && elem->next !=NULL)
    {
        elem = elem->next;
        if(elem->address==address){
            done=true;
        }
    }
    unsigned char value;
    if(done){
        value=elem->data;
    }else{
        value=(unsigned char)(rand()%0xFF);
    }
    return value;
}
void insert_element(memory* mem,unsigned long int address,unsigned char data)
{
  memory* currentAdd = mem;
  while (currentAdd->next != NULL && (currentAdd->next)->address < address) {
    currentAdd = currentAdd->next;
  }
  if (currentAdd->next!=NULL && (currentAdd->next)->address == address) {
    (currentAdd->next)->data=data;
  } else {
    memory* newElem = (memory*)malloc(sizeof(memory));
    newElem->data = data;
    newElem->address=address;
    newElem->next = currentAdd->next;
    currentAdd->next = newElem;
  }
}
void insert_value(memory* mem,unsigned long int address,unsigned char data){
    if(address>0xFFFFFFFF){
        //!ERROR c'est en dehors des 4Go
    }else if(address%4!=0){
        //!ERROR c'est pas aligné
    }
    insert_element(mem,address,data);
}
void delelement(memory* mem,unsigned long int address)
{
    memory *prev_delete = mem;
    while (prev_delete->next != NULL && (prev_delete->next)->address<address)
    {
        prev_delete = prev_delete->next;
    }
    if((prev_delete->next)->address==address)
    {
        memory* mem_to_delete=prev_delete->next;
        prev_delete->next = mem_to_delete->next;
        free(mem_to_delete);
    }

}
void aff_memory(memory* mem)
{
    memory* elem = mem;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        printf("0x%08lX=>%d\n",elem->address,elem->data);
    }
}

void free_memory(memory* mem)
{
    memory* nextElem = mem;
    memory* current = mem;
    while (current!= NULL)
    {
        nextElem = current->next;
        free(current);
        current = nextElem;
    }
}

memory* create_memory(){
    memory* elem = malloc(sizeof(memory));
    elem->next = NULL;
    elem->data = 0;
    elem->address = -1;
    return elem;
}

/*
int main(){
    memory* mem=create_memory();
    insert_value(mem,0xFF,1);
    printf("%d\n",get_memory(mem,0xFF));
    aff_memory(mem);
    free_memory(mem);
    return 0;
}
*/