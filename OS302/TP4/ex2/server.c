#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <ctype.h>
#include <sys/msg.h>
#define KEY_FILE "/tmp/key_"
// #define KEY_FILE "/home/flo/ESISAR_3AS1/OS302/TP4/ex2/cle1"
#define MSG_SIZE sizeof(msg_contenu)
int msg_send_id,msg_recv_id;
#define MAX_MSG_SIZE 100

typedef struct msg_contenu {
    char msg[MAX_MSG_SIZE];
    pid_t pid;
} msg_contenu;

typedef struct msg_struct {
    long type;
    msg_contenu data;
} msg_struct;

char * to_upper(char * str){
    for (int i=0;str[i]!='\0';i++){
        str[i]=toupper(str[i]);
    }
    return str;
}
void close_main(){
    printf("close\n");
    if (msgctl(msg_send_id, IPC_RMID, NULL) < 0|| msgctl(msg_recv_id, IPC_RMID, NULL) < 0) {
        perror("msgctl");
    }
}

int main(int argc, char const *argv[])
{
    for (int i_sig = 0 ; i_sig < NSIG ; i_sig++) {
            signal(i_sig,close_main); 
    }

    struct msg_struct message;
    int pid=getpid();
    key_t send_key = ftok(KEY_FILE, 1) ;
    key_t recv_key = ftok(KEY_FILE, 0) ;
    if(send_key == -1 || recv_key== -1)
        perror("ftok");
    msg_send_id = msgget(send_key, IPC_CREAT | S_IWUSR | S_IROTH );
    msg_recv_id = msgget(recv_key, IPC_CREAT | S_IRUSR | S_IWOTH );
    if(msg_send_id == -1 || msg_recv_id== -1)
        perror("ftok");
    printf("msg_send_id : %d|%d\n",msg_send_id,msg_recv_id);
    while(1){
        if (msgrcv(msg_recv_id, &message, MSG_SIZE, 1, 0) == -1 ) {
            close_main();
            perror("error during msgrcv");
            exit(1);
        }
        if(message.data.msg[0]=='@')
            close_main();
            exit(0);
        printf("Message serv reçu : %s\n", message.data.msg);
        message.type=message.data.pid;
        to_upper(message.data.msg);
        message.data.pid=pid;
        if (msgsnd(msg_send_id, &message, MSG_SIZE, 0) == -1 ) {
            perror("error during msgsnd");
            close_main();
            exit(1);
        }
    }
    close_main();
}