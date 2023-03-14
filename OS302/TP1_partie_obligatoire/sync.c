#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SLEEP_TIME 30

/*
Le programme va lancer un processus et le fork. Ensuite, il va attendre la fin de son fils, qui va sleep pendant 30 secondes. Enfin, si le processus s'est passé sans problème, il va return un EXIT_SUCCESS.
*/

int main(void)
{
    pid_t pid_fils;
    pid_t ret_wait;
	int	etat;

    printf("Je suis le processus pere de pid %d\n", getpid());
    pid_fils = fork();
    switch (pid_fils) {
    case 0:
        printf("*** FILS ***\n");
        printf("Processus fils de pid %d\n", getppid());
		printf("Pere de pid %d\n", getppid());
        printf("Je vais dormir 30 secondes ...\n");
        sleep(SLEEP_TIME);
        printf("Je me reveille\n");
		printf("Je termine mon execution par un `return EXIT_SUCCESS`\n");
		return EXIT_SUCCESS;
    case -1:
        perror("Le fork a echoue");
		return EXIT_FAILURE;
    default:
        printf("*** PERE ***\n");
        printf("Processus pere de pid %d\n", getpid());
		printf("Fils de pid %d\n", pid_fils);
        printf("J'attends la fin de mon fils...\n");
        ret_wait = wait(&etat);
        printf("Mon fils de pid %d est termine\n", ret_wait);
		printf("Son etat etait : %04x\n", etat);
    }
    return EXIT_SUCCESS;
}
