#include <stdio.h>

int main()
{
    int i=2,j=3,k=4;
    printf("i&j=%d,i|1=%d,k|j=%d\n",i&j,i|1,k|j);
    // opérateurs bits a bits
    // i&j => 0010 & 0011 => 0010 2
    // i|1 => 0010 | 0001 => 0011 3
    // k|j => 0100 | 0011 => 0111 7
    if((i&k) || (i&j)){
        // i&k => 0010 & 0100 => 0000 0
        // OU
        // i&j => 0010 | 0011 => 0010 2>0 => 1
        printf("OK\n");
    }
    return 0;
}
