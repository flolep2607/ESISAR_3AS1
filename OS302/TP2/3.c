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
#define NB_ENFANTS 6

int lire_valeur(const char *path)
{
  FILE *fichier;
  char chaine[TAILLE_MAX];
  int valeur;
  fichier = fopen(path, "r");
  if (fichier != NULL)
  {
    /* On lit au maximum TAILLE_MAX caractères du fichier, ce qui est lu est stocké dans `chaine` */
    fgets(chaine, TAILLE_MAX, fichier);
    fclose(fichier);
    valeur = atoi(chaine);
  }
  return valeur;
}

void ecrire_valeur(const char *path, int valeur)
{
  FILE *fichier = fopen(path, "w");
  if (fichier != NULL)
  {
    fprintf(fichier, "%d", valeur);
    fclose(fichier);
  }
}

void wakeUp(int sig) {} // Fonction placée en tant que handler pour les signaux SIGUSR1 et SIGUSR2
void fin(int sig)
{ // Fonction placée en tant que handler pour le signal SIGCHLD
  kill(0, SIGUSR2);
  sleep(1);
  exit(0);
}

void f_fils(int valeur)
{
  while (1)
  {
    pause(); // On attend le signal SIGUSR1 du père

    int barillet = lire_valeur("/tmp/barillet"); 
    if (barillet == valeur)
    { // Le fils compare son numéro à celui du fichier, et se tue si c'est le même
      printf("Le fils %d est mort\n", valeur);
      kill(getpid(), SIGKILL); // SIGKILL pour tuer le fils
    }
    else
    { // Les fils toujours vivants affichent leur numéro
      printf("%d a survécu !\n", valeur);
      pid_t pere = getppid();
      kill(pere, SIGUSR1);
    }
  }
  exit(0);
}

int main()
{
  signal(SIGUSR1, wakeUp);
  signal(SIGUSR2, wakeUp); 
  signal(SIGCHLD, fin);
  pid_t fils[NB_ENFANTS];
  for (size_t i = 0; i < NB_ENFANTS; i++)
  {
    fils[i] = fork();
    if (fils[i] == 0)
    {
      f_fils(i + 1);
    }
  }
  sleep(1); // Pause pour être sûr que le fils soit bien lancé
  ecrire_valeur("/tmp/barillet", (rand() % 6) + 1);
  for (int i = 0; i < NB_ENFANTS; i++)
  {
    kill(fils[i], SIGUSR1); // Chaque fils reçoit le signal lorsque c'est son tour
    pause();                // On attend le signal de la part du fils
  }
  return 0;
}
