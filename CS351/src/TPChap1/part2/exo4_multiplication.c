#include <stdio.h>

void jeuMulti(int number){
    int erreur=0;
    int answer;
    for(int i=1;i<=9 && erreur==0;i++){
        printf("%d x %d = ",i,number);
        scanf("%d",&answer);
        if(answer!=number*i){
            erreur++;
            printf("Erreur ! %d x %d = %d pas %d\n",i,number,i*number,answer);
        }
    }
    if(erreur==0){
        printf("Felicitation 0 erreur\n");
    }
}
void jeuMultiPoints(int number){
    int erreur=0;
    int answer;
    for(int i=1;i<=9;i++){
        printf("%d x %d = ",i,number);
        scanf("%d",&answer);
        if(answer!=number*i){
            erreur++;
            printf("Erreur ! %d x %d = %d pas %d\n",i,number,i*number,answer);
        }
    }
    if(erreur==0){
        printf("Felicitation 0 erreur\n");
    }else{
        printf("%d erreurs\n",erreur);
    }
}
int main()
{
    int number=0;
    printf("Valeur de n:");
    scanf("%d",&number);
    while(number<2 && number>9){
        printf("Valeur non comprise entre 2 et 9\nValeur de n:");
        scanf("%d",&number);
    }
    jeuMulti(number);
    return 0;
}
