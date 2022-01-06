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
#define FIFONAME_J1 "YourTooSlow_j1"
#define FIFONAME_J2 "YourTooSlow_j2"
#define FIFONAME_J3 "YourTooSlow_j3"
#define FIFONAME_J4 "YourTooSlow_j4"


int main (){
    //En caso de existir, cierra las tuberías abiertas.
    unlink(FIFONAME);
    unlink(FIFONAME_J1);
    unlink(FIFONAME_J2);
    unlink(FIFONAME_J3);
    unlink(FIFONAME_J4);

    int numerojugadores = 5;
    int tamano;
    int valores;
    int randomx,randomy;
    do{
        printf ("Ingrese el numero de jugadores ");
        scanf ("%d", &numerojugadores);
        if (numerojugadores > 4){
            printf("el numero de jugadores es muy alto intentelo nuevamente. ");
        }
        else if (numerojugadores < 2){
            printf("el numero de jugadores es muy bajo intentelo nuevamente. ");
        }
    }while (numerojugadores > 4 || numerojugadores < 2);
    switch (numerojugadores){
        case 2:
            tamano = 8;
            valores = 16;
            break;
        case 3:
            tamano = 10;
            valores = 25;
            break;
        case 4:
            tamano = 12;
            valores = 36;
            break;
    }
    int matriz[tamano][tamano];
    int array[50];
    int i, j;
    for (i = 0; i < tamano; i++){
        for (j = 0; j < tamano; j++){
            matriz[i][j] = 0;
        }
    }
    for (i = 0; i < 50; i++){
        array[i] = i + 1;
    }
    for (i = 0; i < 50; i++){
        int temp = array[i];
        int randomIndex = rand () % 51;
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
    for (i = 0; i < valores; i++){
        do{
            randomx = rand () % (tamano + 1);
            randomy = rand () % (tamano + 1);
        }while(matriz[randomx][randomy]!=0);
        matriz[randomx][randomy]=array[i];
    }
    if(numerojugadores>=2){
        int j1, j2;

        //Crea las tuberías, retorna un error de salir algo mal en el proceso
        if(mkfifo(FIFONAME, 666)){ //Nombre tubería, permisos
            perror("mkfifo");
            return(1);
        }
        if(mkfifo(FIFONAME_J1, 666)){
            perror("mkfifo");
            return(1);
        }
        if(mkfifo(FIFONAME_J2, 666)){
            perror("mkfifo");
            return(1);
        }

        //Definiciones para guardar el valor retornado al abrir tuberías
        int fd_g, fd_c1, fd_c2;

        //Abre tubería general y de jugadores 1 y 2
        if(fd_g = open(FIFONAME, O_RDWR) < 0){
            perror("open");
            return(2);
        }
        if(fd_c1 = open(FIFONAME_J1, O_RDWR) < 0){
            perror("open");
            return(2);
        }
        if(fd_c2 = open(FIFONAME_J2, O_RDWR) < 0){
            perror("open");
            return(2);
        }

        j1 = fork(); //Se hace fork y el pid se almacena en j1
        if(j1 == 0){ //Caso en el que el fork retorne 0, es decir, esta parte se ejecuta en el hijo (o client)
            printf("Cliente Jugador 1\n");
        }
        else{ //Caso en el que el fork retorna un PID, es decir, esta parte la ejecuta el server
            printf("PID Jugador 1: %d\n", j1);
        }

        j2 = fork();
        if(j2 == 0){ //Ejecutado por cliente
            printf("Cliente Jugador 2\n");
        }
        else{ //Ejecutado aquí en server
            printf("PID Jugador 2: %d\n", j2);
        }
    }
    if(numerojugadores>=3){
        int j3, fd_c3;

        

        //Tubería de Jugador 3
        if(mkfifo(FIFONAME_J3, 666)){
            perror("mkfifo");
            return(1);
        }
        //Abre tubería de jugador 3
        if(fd_c3 = open(FIFONAME_J3, O_RDWR) < 0){
            perror("open");
            return(2);
        }

        j3 = fork();
        if(j3 == 0){ //Ejecutado por cliente
            printf("Cliente Jugador 3\n");
        }
        else{ //Ejecutado aquí en server
            printf("PID Jugador 3: %d\n", j3);
        }        
    }
    if(numerojugadores==4){
        int j4, fd_c4;

        //Tubería de Jugador 4
        if(mkfifo(FIFONAME_J4, 666)){
            perror("mkfifo");
            return(1);
        }
        //Abre tubería de jugador 4
        if(fd_c4 = open(FIFONAME_J3, O_RDWR) < 0){
            perror("open");
            return(2);
        }

        j4 = fork();
        if(j4 == 0){ //Ejecutado por cliente
            printf("Cliente Jugador 4\n");
        }
        else{ //Ejecutado aquí en server
            printf("PID Jugador 4: %d\n", j4);
        }
    }
    return 0;
}
/*
for(i=0;i<tamano;i++){
    for(j=0;j<tamano;j++){
        printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
*/