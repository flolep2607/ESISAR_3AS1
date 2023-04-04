#include <stdio.h>
#include <stdlib.h>

int fibonnaci(int n){
	
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return fibonnaci(n-1) + fibonnaci(n-2);
	
}

int pgcd(int a, int b){
	
	if(b>a){
		int tmp = b;
		b = a;
		a = tmp;
	}
	
	if(b==0) return a;
	
	else return pgcd(b, a%b);
}

int palindrome(char *string, int taille){
	if (taille == 1)
		return 1;
	if (string[0] == string[taille-1])
		return palindrome(string+1, taille-2);
	else 
		return 0;
}

int main()
{
	int n=7;
	printf("fib(%d) = %d\n",n,fibonnaci(n));
	
	int a=9;
	int b=6;
	printf("pgcd(%d, %d) = %d\n",a,b,pgcd(a,b));
	
	char string[]="jaj";
	printf("%s est un palindrome: %d\n",string,palindrome(string,3));    

    return 0;
}
