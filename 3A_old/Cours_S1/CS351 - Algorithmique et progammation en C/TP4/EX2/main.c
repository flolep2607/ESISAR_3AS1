#include <stdio.h>
#include <string.h>
#include "fonctions.h"


int main(){
	
	char string[] = "test";
	
	char copie[20];
	
	printf("strlen: %d = %ld\n",myStrlen(string),strlen(string));
	myStrcpy(string, copie);
	printf("strcpy: %s = %s\n",string,copie);

	printf("%s en Hexadecimal: ",string);
	affichagerEnHexadecimal(string);
	printf("%s en Decimal: ",string);
	affichagerEnDecimal(string);

	mettreEnMajuscule(copie);
	printf("%s en majuscule: %s\n",string,copie);
	printf("%s en minuscule: ",copie);
	mettreEnMinuscule(copie);
	printf("%s\n",copie);

	printf("%s retourné: ",copie);
	retournerMot(copie);
	printf("%s\n",copie);

	printf("est is in %s at index: %d\n",string, rechercherCaractereD(string, "est"));

	printf("jaj est un palindrome: %d\n",estPalindrome("jaj",0,3));

	printf("toto == toto : %d\n",comparerChaine("toto","toto"));
	printf("toto > titi : %d\n",comparerChaine("toto","titi"));
	printf("titi < toto : %d\n",comparerChaine("titi","toto"));

	printf("2546 = %d\n",valeurDecimale("2546"));
	intVersChaine(2546,copie);
	printf("2546 = %s\n",copie);
	
	return 0;
}

