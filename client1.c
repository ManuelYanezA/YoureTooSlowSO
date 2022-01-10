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
#define FIFONAME_J2 "YourTooSlow_j2"
#define FIFONAME_J3 "YourTooSlow_j3"
#define FIFONAME_J4 "YourTooSlow_j4"

int main(){
    int jugador=0;
    int n, fd_g, fd_j;
    char buffer[1024];
    do{
        printf ("Seleccione su numero de jugador ");
        scanf ("%d", &jugador);
    }while(jugador<1 || jugador>4);
    if ((fd_g = open(FIFONAME, O_RDWR)) < 0)
    {
        perror("open FDG");
        exit(1);
    }
    switch(jugador){
        case 1:
            if ((fd_j = open(FIFONAME_J1, O_RDWR)) < 0)
            {
                perror("open C1");
                exit(1);
            }
            break;
        case 2:
            if ((fd_j = open(FIFONAME_J2, O_RDWR)) < 0)
            {
                perror("open C2");
                exit(1);
            }
            break;
        case 3:
            if ((fd_j = open(FIFONAME_J3, O_RDWR)) < 0)
            {
                perror("open C3");
                exit(1);
            }
            break;
        case 4:
            if ((fd_j = open(FIFONAME_J4, O_RDWR)) < 0)
            {
                perror("open C4");
                exit(1);
            }
            break;
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
        if ((n = read(fd_j, buffer, sizeof(buffer))) > 0)
        {
            write(1, buffer, n);
        }
    }
}