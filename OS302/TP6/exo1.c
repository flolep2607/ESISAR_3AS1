#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int semid, status;
    struct sembuf sb;
    pid_t pid;

    semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);  // création d'un nouvel ensemble d'un sémaphore
    if (semid == -1) {
        printf("Erreur de création du sémaphore");
        exit(EXIT_FAILURE);
    }
    semctl(semid, 0, SETVAL, 1);  // initialisation de la valeur initiale du sémaphore à 1

    for (int i = 4; i > 0; i--) {
        pid = fork();
        if (pid == 0) {
            sb.sem_num = 0;
            sb.sem_op = -1;
            sb.sem_flg = 0;
            semop(semid, &sb, 1);  // réduction du sémaphore
            printf("%d\n", i);
            fflush(stdout);
            sb.sem_num = 0;
            sb.sem_op = 1;
            sb.sem_flg = 0;
            semop(semid, &sb, 1);  // augmentation du sémaphore
            exit(0);
        }
    }

    for (int i = 0; i < 3; i++) {
        wait(&status);
    }

    semctl(semid, 0, IPC_RMID);  // suppression de l'ensemble de sémaphores

    return 0;
}