#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    key_t cle;
    int semid;
    int arg[1] = {1};

    if ((cle = ftok(argv[1], 5)) == -1)
    {
        printf("Erreur de ftok\n");
        exit(10);
    }

    if ((semid = semget(cle, 1, IPC_CREAT | 0666)) == -1)
    {
        printf("Erreur de semget\n");
        exit(11);
    }

    printf("Sémaphore %d de cle %x cree \n", semid, cle);

    if (semctl(semid, 0, SETVAL, arg) == -1)
    {
        printf("Erreur de semctl\n");
        exit(11);
    }
}