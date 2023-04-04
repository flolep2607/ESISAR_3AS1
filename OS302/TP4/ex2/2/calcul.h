#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <ctype.h>

typedef struct msg_data{
  char  message[100];
  pid_t pid;
} msg_data;

typedef struct msg_struct {
    long type;
    msg_data data;
} msg_struct;