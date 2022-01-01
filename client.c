#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
    printf("Saludos desde el archivo client.c\n");
    int pid = getpid();
    printf("PID cliente: %d", pid);
    return 0;
}