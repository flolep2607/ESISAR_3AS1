#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* inclusion de ctype pour l'utilisation
de la fonction isdigit() */
#include "pile.h"

/* evalue une chaine de charactere contenant une expression en post-script */
int evaluate(char *string){
	int i=0;
	char c;
	int nb, n2, n1;
	pileInt maPile = creerPile();
	while(string[i]!='\0'){
		c = string[i];
		//printf("c = %c\n",c);
		if(isdigit(c)){
			/*si le charactere est un nombre
			  on l'empile*/
			sscanf(&c,"%d",&nb);
			empiler(maPile,nb);
		} else {
			/*sinon on depile les deux derniers
			  et on applique l'operation decrite par le charactere*/
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
    
	char exp[]="42+5*67-/";// = -30
	printf("%s = %d\n",exp,evaluate(exp));

    return 0;
}
