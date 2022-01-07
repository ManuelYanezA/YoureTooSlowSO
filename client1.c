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


#define FIFONAME "YourTooSlow"
#define FIFONAME_J1 "YourTooSlow_j1"

int main(){
    int n, fd_g, fd_c1;
    char buffer[1024];
    if ((fd_c1 = open(FIFONAME_J1, O_RDWR)) < 0)
    {
       perror("open C1");
       exit(1);
    }
    if ((fd_g = open(FIFONAME, O_RDWR)) < 0)
    {
        perror("open FDG");
        exit(1);
    }
    while(1){
        //Envía coordenadas al servidor
        printf("Coordenada x : \n");
        if ((n = read(0, buffer, sizeof(buffer))) > 0)
        {
            write(fd_g, buffer, n);
        }

        printf("Coordenada y : \n");
        if ((n = read(0, buffer, sizeof(buffer))) > 0)
        {
            write(fd_g, buffer, n);
        }

        if ((n = read(fd_c1, buffer, sizeof(buffer))) > 0)
        {
            write(1, buffer, n);
        }
    }
}