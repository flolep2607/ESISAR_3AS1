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
void ignore_signal(int signum) {}

void f_fils(int valeur) {
    bool dead = false;
    signal(SIGUSR1, ignore_signal);
    sigset_t set;
    sigemptyset(&set);

    while (!dead) {
        sigsuspend(&set);
        lire_valeur("/tmp/barillet");
    }
    exit(0);
}
int tmp = 777888;
int main() {
    pid_t fils[6];
    for (size_t i = 0; i < 6; i++) {
        fils[i] = fork();
        if (fils[i] == 0) {
            f_fils(i + 1);
        }
    }
    signal(SIGUSR1, ignore_signal);
    ecrire_valeur("/tmp/barillet", );
}