#include <stdio.h>
#include <stdlib.h>
#define SIZE 1
//nw
//nn
void grrossfiak(int n){
for(int x=0;x<n*2;x++){
	for(int l=0;l<=x/2;l++){
		if(x%2==0){printf("##");}
		else{printf("# ");}
	}
	if(x%2==1){printf("\n");}
}
}
int main()
{
grrossfiak(1);
    return 0;
}
