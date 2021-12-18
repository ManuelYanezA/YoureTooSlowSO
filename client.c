#include <stdio.h>
#include <stdlib.h>


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