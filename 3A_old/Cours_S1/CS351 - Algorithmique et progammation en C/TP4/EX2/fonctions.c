#include <stdio.h>
#include <ctype.h>


int myStrlen(char *string){
	int i=0;
	while(string[i]!='\0') i++;
	
	return i;
}

void myStrcpy(char *string,char *copie){
	int i=0;
	while(string[i]!='\0') {
		copie[i]=string[i];
		i++;
	}
	copie[i]='\0';
}

void affichagerEnHexadecimal(char *string){
	int i=0;
	while(string[i]!='\0')
		printf("%2X ",string[i++]);
	printf("\n");
}

void affichagerEnDecimal(char *string){
	int i=0;
	while(string[i]!='\0')
		printf("%3d ",string[i++]);
	printf("\n");
}

void mettreEnMajuscule(char *string){
	int i=0;
	while(string[i]!='\0'){
		if(isalpha(string[i]))
			if(islower(string[i]))
				string[i]=toupper(string[i]);
		i++;
	}
}

void mettreEnMinuscule(char *string){
	int i=0;
	while(string[i]!='\0'){
		if(isalpha(string[i]))
			if(isupper(string[i]))
				string[i]=tolower(string[i]);
		i++;
	}
}

void transformerMinMaj(char *string){
	int i=0;
	while(string[i]!='\0'){
		if(isalpha(string[i])){
			if(islower(string[i]))
				string[i]=toupper(string[i]);
			if(isupper(string[i]))
				string[i]=tolower(string[i]);
		}
		i++;
	}
}

void retournerMot(char *string){
	char tmp;
	int len=myStrlen(string);
	for(int i=0; i<len/2; i++){
		tmp = string[i];
		string[i] = string[len-1-i];
		string[len-1-i] = tmp;
	}
}

/*Haha, bonne chance pour lire ça*/
int rechercherCaractereG(char *string, char *chaine_de_characteres_a_rechercher){
	int i;
	int trouve=0;
	int len_string = myStrlen(string);
	int longueur_de_la_chaine_de_characteres_a_rechercher = myStrlen(chaine_de_characteres_a_rechercher);
	for(i=(len_string-longueur_de_la_chaine_de_characteres_a_rechercher);i>=0;i--){
		if(string[i]==chaine_de_characteres_a_rechercher[0])
			for(int j=1; j<longueur_de_la_chaine_de_characteres_a_rechercher; j++){
				if(string[i+j]!=chaine_de_characteres_a_rechercher[j])
					break;
				else if (j==longueur_de_la_chaine_de_characteres_a_rechercher-1)
					trouve = 1;
			}
		if(trouve) break;
	}
	if (!trouve) i=-1;
	return i;
}

int rechercherCaractereD(char *string, char *str2){
	int i,j=1;
	int trouve=0;//flag pour arreter de chercher si on a trouvé une instance de str2
	int len_string = myStrlen(string);
	int len_str2 = myStrlen(str2);

	for(i=0; i<= (len_string-len_str2) ; i++){
		// La boucle s'arrête quand il y a moins de char à analyser que de char dans str2
		if(string[i]==str2[0]) //si le current char est le premier char de str2
			for(j=1; j<len_str2; j++){//alors on teste tous les autres (jusqu'à la fin de str2)
				if(string[i+j]!=str2[j])// si un char ne correspond 
					break;//  			   On sort de la boucle
				else if (j==len_str2-1)// si on a vérifié le dernier char
					trouve = 1;//         alors on a trouvé le mot.
			}
		if(trouve) break;//Si on à trouvé on quite la boucle
		// On pourrait écrire cette condition directement dans
		// notre boucle (while au lieu de for), mais je pense 
		// qu'ici cela n'à pas trop d'intérêt.
		i+=(j-1);//On augmente i de j-1
		/* car si on est rentré dans la boucle précédente et 
		  qu'on à déjà vérifié les char de i à i+(j-1), 
		  pas la peine de les revérifier */
		j=1;// On reset j à 1 pour la boucle suivante
	}
	if (!trouve) i=-1;// si on a pas trouvé str2 on doit renvoyer -1
	return i;
}

int estPalindrome(char *mot, int d,int f){
	char copie[1+f-d];
	for (int i=d; i<f; i++)
		copie[i-d]=mot[i];
	copie[f-d]='\0';
	char retourne[1+f-d];
	myStrcpy(copie, retourne);
	retournerMot(retourne);

	return (rechercherCaractereD(copie,retourne) + 1);

}

/** Version flegmme recursive 
 * Apparement la récursivité n'est pas autorisée :/
int comparerChaine(char *str1, char *str2){

	if(str1[0]==str2[0]){
		if(*str1 == '\0')// je suis passé à l'écriture avec pointeur
			return 0;//     car ça faisait moins de character à écrire
		else
			return comparerChaine( (str1+1), (str2+1) );
	}
	if(*str1>*str2)
		return 1;
	else
		return -1;
}
**/

int comparerChaine(char *str1, char *str2){
	int i=0;
	do{
		if(str1[i]!=str2[i]) {
			if(str1[i]>str2[i])// J'ai préféré mettre des returns
				return 1;//   dans la boucle même si ce n'est 
			else//            pas vraiment reccommandé
				return -1;
		}
	}while(str1[i++]!='\0');
//  J'ai choisi d'utiliser un do{}while
//  Comme ça on peut vérifier si les chaines ont la même longueur
//  Un simple while aurait ignoré ce cas
	return 0;
}

int valeurDecimale(char *string){
	int nombre;
	sscanf(string,"%d",&nombre);// sscanf lis la chaine string[]
	return nombre;//               au lieu de l'entrée standard
}

void intVersChaine(int nb, char *string){
	sprintf(string,"%d",nb);// sprintf écrit dans string[]
}//							   au lieu de la sortie standard