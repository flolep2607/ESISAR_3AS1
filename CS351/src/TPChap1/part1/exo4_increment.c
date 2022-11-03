#include <stdio.h>

int main()
{
    int i,j,k,l;
    i=j=k=l=0;
    while(i<9){
        printf("i++=%d,++j=%d,k--=%d,--l=%d\n",i++,++j,k--,--l);
        // i incrementé apres son affichage
        // i incrementé avant son affichage
        // i décrementé apres son affichage
        // i décrementé avant son affichage
    }
    printf("i=%d,j=%d,k=%d,l=%d\n",i,j,k,l);
    return 0;
}
