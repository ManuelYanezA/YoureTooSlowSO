#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main (){
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
        int pid1[2],pid2[2],pid3[2],pid4[2];
        int j1, j2;

        pipe(pid1); //PID Impar: De server a client
        pipe(pid2); //PID Par: De client a server

        j1 = fork(); //Se hace fork y el pid se almacena en j1
        if(j1 == 0){ //Caso en el que el fork retorne 0, es decir, esta parte se ejecuta en el hijo (o client)
            char *args[] = {"./client",NULL};
            execvp(args[0],args);
        }
        else{ //Caso en el que el fork retorna un PID, es decir, esta parte la ejecuta el server
            printf("PID Jugador 1: %d\n", j1);
        }

        pipe(pid3);
        pipe(pid4);

        j2 = fork();
        if(j2 == 0){ //Ejecutado por cliente
            char *args[] = {"./client",NULL};
            execvp(args[0],args);
        }
        else{ //Ejecutado aquí en server
            printf("PID Jugador 2: %d\n", j2);
        }
    }
    if(numerojugadores>=3){
        int pid5[2],pid6[2];
        int j3;

        pipe(pid5);
        pipe(pid6);

        j3 = fork();
        if(j3 == 0){ //Ejecutado por cliente
            char *args[] = {"./client",NULL};
            execvp(args[0],args);
        }
        else{ //Ejecutado aquí en server
            printf("PID Jugador 3: %d\n", j3);
        }        
    }
    if(numerojugadores==4){
        int pid7[2],pid8[2];
        int j4;

        pipe(pid7);
        pipe(pid8);

        j4 = fork();
        if(j4 == 0){ //Ejecutado por cliente
            char *args[] = {"./client",NULL};
            execvp(args[0],args);
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