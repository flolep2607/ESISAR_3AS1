#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdbool.h>
#define TAILLE_MAX 20

int lire_valeur(const char *path)
{
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

void ecrire_valeur(const char *path, int valeur)
{
  FILE *fichier = fopen(path, "w");
  if (fichier != NULL) {
    fprintf(fichier, "%d", valeur);
    fclose(fichier);
  }
}

int tmp = 777888;

void lesig(int signum){}

int main()
{
    pid_t fils[6];
    bool father=true;
    for (size_t i = 0; i < 6; i++)
    {
        if (fils[i]=fork())
        {
            fils[i] = fork();
        }
        else
        {
            break;
        }
    }
    if(signal(SIGUSR1, lesig))
        {
            if(getpid() == tmp)
            {
                kill(fils[4], SIGKILL);
            }
            else
            {
                kill(fils[5], SIGUSR1);
            }
        }
    }
    else
    {
        if(signal(SIGUSR1, lesig))
        {
            if(getpid() == tmp)
            {
                kill(fils[3], SIGKILL);
            }
            else
            {
                kill(fils[4], SIGUSR1);
            }
        }
    }
    
    pid_t fils1 = fork();
    if (fils1 == 0)
    {
        pid_t fils2 = fork();
        if (fils2 == 0)
        {   
            pid_t fils3 = fork();
            if (fils3 == 0)
            {
                pid_t fils4 = fork();
                if (fils4 == 0)
                {
                    pid_t fils5 = fork();
                    if (fils5 == 0)
                    {
                        pid_t fils6 = fork();
                        if (fils6 == 0)
                        {
                            if(signal(SIGUSR1, lesig))
                                {
                                if(getpid() == tmp)
                                {
                                    kill(fils2, SIGKILL);
                                }
                                else
                                {
                                    kill(fils3, SIGUSR1);
                                }
                }
                        }
                        else 
                        {
                            if(signal(SIGUSR1, lesig))
                            {
                                if(getpid() == tmp)
                                {   
                                    kill(fils5, SIGKILL);
                                }
                                else
                                {
                                    kill(fils6, SIGUSR1);
                                }
                
                            }
                        }
                    }
                    else 
                    {
                        if(signal(SIGUSR1, lesig))
                        {
                            if(getpid() == tmp)
                            {
                                kill(fils4, SIGKILL);
                            }
                            else
                            {
                                kill(fils5, SIGUSR1);
                            }
                        }
                    }
                }
                else 
                {
                    if(signal(SIGUSR1, lesig))
                    {
                        if(getpid() == tmp)
                        {
                            kill(fils3, SIGKILL);
                        }
                        else
                        {
                            kill(fils4, SIGUSR1);
                        }
                    }
                }
            }
            else 
            {
                if(signal(SIGUSR1, lesig))
                {
                    if(getpid() == tmp)
                    {
                        kill(fils2, SIGKILL);
                    }
                    else
                    {
                        kill(fils3, SIGUSR1);
                    }
                
                }
            }
        }
        else 
        {
            if(signal(SIGUSR1, lesig))
            {
                if(getpid() == tmp)
                {
                    kill(fils1, SIGKILL);
                }
                else
                {
                    kill(getppid(), SIGUSR1);
                    kill(fils2, SIGUSR1);
                }
                
            }
        }
    }
    else 
    {
        kill(fils1, SIGUSR1);
    }
}