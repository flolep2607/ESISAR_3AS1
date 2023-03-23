#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#define TAILLE_MAX 20

int lire_valeur(const char *path) {
    FILE *fichier;
    char chaine[TAILLE_MAX];
    int valeur;
    fichier = fopen(path, "r");
    if (fichier != NULL) {
        /* On lit au maximum TAILLE_MAX caractères du fichier, ce qui est lu est stocké dans `chaine` */
        fgets(chaine, TAILLE_MAX, fichier);
        fclose(fichier);
        valeur = atoi(chaine);
    }
    return valeur;
}

void ecrire_valeur(const char *path, int valeur) {
    FILE *fichier = fopen(path, "w");
    if (fichier != NULL) {
        fprintf(fichier, "%d", valeur);
        fclose(fichier);
    }
}

void o(){}
void f_fils(int valeur) {
    bool dead = false;
    while (!dead) {
        if(signal(SIGUSR1, o)){
            if(lire_valeur("/tmp/barillet") == valeur) {
                printf("Le fils %d est mort\n", valeur);
                dead = true;
            }
            kill(getppid(), SIGUSR1);
        }else if(signal(SIGUSR2, o)){
            printf("liberez tous mes bannis\n");
            dead=true;
        }
    }
    exit(0);
}

int main() {
    pid_t fils[6];
    for (size_t i = 0; i < 6; i++) {
        fils[i] = fork();
        if (fils[i] == 0) {
            f_fils(i + 1);
        }
    }
    signal(SIGUSR1, o);
    bool one_dead=false;
    while(!one_dead){
        for(int i=0;i<6;i++){
            ecrire_valeur("/tmp/barillet", (rand()%6)+1);
            kill(fils[i],SIGUSR1);
        }
    }
}