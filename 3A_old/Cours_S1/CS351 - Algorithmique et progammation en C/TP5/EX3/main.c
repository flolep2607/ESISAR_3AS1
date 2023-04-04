#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pile.h"

int evaluate(char *string){
	int i=0;
	char c;
	int nb, n2, n1;
	pileInt maPile = creerPile();
	while(string[i]!='\0'){
		c = string[i];
		printf("c = %c\n",c);
		if(isdigit(c)){
			sscanf(&c,"%d",&nb);
			empiler(maPile,nb);
		} else {
			n2 = depiler(maPile);
			n1 = depiler(maPile);
			switch(c){
				case '+':
					n1 += n2;
					break;
				case '-':
					n1 -= n2;
					break;
				case '*':
					n1 *= n2;
					break;
				case '/':
				case '\\':
					if(n2) n1 /= n2;
					else{
						perror("Division par zéro, aïe aïe aïe");
						exit(1);
					}
					break;
				
			}
			empiler(maPile, n1);
		}
		i++;
	}
	return depiler(maPile);
}

int main()
{
    int i;
    pileInt maPile = creerPile();
    i = 0;
    while (i<=25){
        empiler(maPile, i);
        i++;
    }

    while (!estPileVide(maPile)){
        printf("Je depile : %d\n", depiler(maPile));
    }

	char exp[]="42+5*67-/";// = -30
	printf("%s = %d\n",exp,evaluate(exp));

    return 0;
}
