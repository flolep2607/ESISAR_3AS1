#include "memory.h"
// #define int32_t unsigned char // unsigned char data;//char => 1octets 
/**
 * @brief Get the element object
 * 
 * @param mem 
 * @param address 
 * @return int32_t 
 */
int32_t get_element(memory* mem,unsigned long int address)
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
    int32_t value;
    if(done){
        value=elem->data;
    }else{
        value=(int32_t)(rand()%0xFF);
    }
    return value;
}
/**
 * @brief 
 * 
 * @param address 
 */
void checks(unsigned long int address){
    if(address>max_memory){
        //!ERROR c'est en dehors des 4Go
        exit(-1);
    }else if(address%sizeof(int32_t)!=0){
        //!ERROR c'est pas aligné
        exit(-2);
    }
}
/**
 * @brief 
 * 
 * @param address 
 * @param octets 
 * @return int32_t 
 */
int32_t gen_mask(unsigned long int* address,int octets){
    // 0000111100000000
    // (actual_value & (~mask)) | (value & mask)
    int32_t mask=0;
    short decalage = (*address)%sizeof(int32_t);//1 => 1 en trop
    unsigned long int start_address=*address-decalage;
    address=&start_address;
    for(short i=0;i<=octets;i++){
        mask|=(0xF)<<(4*(i+decalage));
    }
    return mask;
}
/**
 * @brief 
 * 
 * @param mem 
 * @param address 
 * @param data 
 */
void insert_element(memory* mem,unsigned long int address,int32_t data)
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
/**
 * @brief Get the value object
 * 
 * @param mem 
 * @param address 
 * @return int32_t 
 */
int32_t get_value(memory* mem,unsigned long int address){
    checks(address);
    return get_element(mem,address);
}
/**
 * @brief 
 * 
 * @param mem 
 * @param address 
 * @param data 
 */
void insert_value(memory* mem,unsigned long int address,int32_t data){
    checks(address);
    insert_element(mem,address,data);
}
/**
 * @brief 
 * 
 * @param mem 
 * @param address 
 */
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
/**
 * @brief 
 * 
 * @param mem 
 */
void aff_memory(memory* mem)
{
    memory* elem = mem;
    while(elem->next !=NULL)
    {
        elem = elem->next;
        printf("0x%08lX=>0x%08u\n",elem->address,elem->data);
    }
}
/**
 * @brief 
 * 
 * @param mem 
 */
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
/**
 * @brief Create a memory object
 * 
 * @return memory* 
 */
memory* create_memory(){
    memory* elem = malloc(sizeof(memory));
    elem->next = NULL;
    elem->data = 0;
    elem->address = -1;
    return elem;
}

// int main(){
//     memory* mem=create_memory();
//     insert_value(mem,0x4,1);
//     printf("0x%08x\n",get_value(mem,0x4));
//     aff_memory(mem);
//     free_memory(mem);
//     return 0;
// }