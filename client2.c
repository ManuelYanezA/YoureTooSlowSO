#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sem.h>

#define TX 5
#define TY 5

#define FIFONAME "YourTooSlow"
#define FIFONAME_J2 "YourTooSlow_j2"

int main(){
    printf("Saludos desde el archivo client.c\n");
    int pid = getpid();
    printf("PID cliente: %d", pid);
    return 0;
}