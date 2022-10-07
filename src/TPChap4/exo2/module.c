#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

size_t mystrlen(const char *s){
    size_t i=0;
    for(;s[i]!=0;i++){}
    return i;
}
char *mystrcpy(char *dest, const char *src){
    size_t i=0;
    do{
        dest[i]=src[i];
        i++;
    }while(src[i]!=0);
    return dest;
}
void affichageenhexa(char *string){
    for(size_t i=0;string[i]!=0;i++){
        printf("%x ",string[i]);
    }
    printf("\n");
}
void affichageenint(char *string){
    for(size_t i=0;string[i]!=0;i++){
        printf("%d ",(int)string[i]);
    }
    printf("\n");
}
char * mettreenmajuscule(char *string){
    char * converted_string = (char *)malloc(sizeof(char) * mystrlen(string));
    const char OFFSET = 'a' - 'A';
    for(size_t i=0;string[i]!=0;i++){
        if (string[i] >= 'a' && string[i] <= 'z'){
            converted_string[i]=string[i]-OFFSET;
        }else{
            converted_string[i]=string[i];
        }
    }
    return converted_string;
}
char * mettreenminuscule(char *string){
    char * converted_string = (char *)malloc(sizeof(char) * mystrlen(string));
    const char OFFSET = 'a' - 'A';
    for(size_t i=0;string[i]!=0;i++){
        if (string[i] >= 'A' && string[i] <= 'Z'){
            converted_string[i]=string[i] + OFFSET;
        }else{
            converted_string[i]=string[i];
        }
    }
    return converted_string;
}
char * transformerminmaj(char *string){
    char * converted_string = (char *)malloc(sizeof(char) * mystrlen(string));
    const char OFFSET = 'a' - 'A';
    for(size_t i=0;string[i]!=0;i++){
        if (string[i] >= 'A' && string[i] <= 'Z'){
            converted_string[i]=string[i] + OFFSET;
        }else if (string[i] >= 'a' && string[i] <= 'z'){
            converted_string[i]=string[i] - OFFSET;
        }else{
            converted_string[i]=string[i];
        }
    }
    return converted_string;
}
char * retournermot(char *string){
    size_t length = mystrlen(string);
    char * converted_string = (char *)malloc(sizeof(char) * length);
    for(size_t i=0;string[i]!=0;i++){
        converted_string[length-1-i]=string[i];
    }
    return converted_string;
}
int recherchercaractereg(char *string,char caract){
    int found=-1;
    for(int i=0;found==-1 && string[i]!=0;i++){
        if(string[i]==caract){
            found=i;
        }
    }
    return found;
}
int recherchercaractered(char *string,char caract){
    int found=-1;
    for(int i=mystrlen(string);found==-1 && string[i]!=0;i--){
        if(string[i]==caract){
            found=i;
        }
    }
    return found;
}
int estpalindrome(char *string,int f,int d){
    int palindrome=1;
    for(int i=d;string[i]!=0 && i<=(f-d)/2 && palindrome;i++){
        if(string[i]==string[f-d-1-i]){
            palindrome=0;
        }
    }
    return palindrome;
}
int comparerchaine(char *string1,char *string2){
    int value=0;
    for(int i=0;i<=mystrlen(string1) && i<=mystrlen(string2) && value==0;i++){
        if(string1[i]>string2[i]){
            value=42;
        }else if(string1[i]<string2[i]){
            value=-69;
        }
    }
    return value;
}
int valeurdecimale(char *string){
    int value=0;
    int done=0;
    const size_t length = mystrlen(string)-1;
    for(size_t i=0;string[i]!=0 && !done;i++){
        value+=(string[i]-48)*(int)pow(10,length-i);
    }
    return value;
}
void intverschaine(int value,char *string){
    sprintf(string, "%d", value);// AHAH
}