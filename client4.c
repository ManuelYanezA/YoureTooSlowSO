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
#define FIFONAME_J4 "YourTooSlow_j4"

int main(){
     int n, fd_g, fd_c4;
    char buffer[1024];
    if ((fd_c4 = open(FIFONAME_J4, O_RDWR)) < 0)
    {
       perror("open C4");
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

        if ((n = read(fd_c4, buffer, sizeof(buffer))) > 0)
        {
            write(1, buffer, n);
        }
    }
}