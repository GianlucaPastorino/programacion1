#include <stdio.h>
#include <stdlib.h>

#define FILAS 4
#define COLUMNAS 13

// Tengo 3 lineas de bondi (linea 1, linea 2, linea 3).
// Cada linea tiene 12 colectivos (internos).
// Un bondi hace un viaje y vuelve. Pasa la data de lo que recaudó.
// Ingrese linea, ingrese interno, ingrese recaudación. ¿Desea ingresar otro?

void mostrarRecaudaciones(int m[][13], int filas);

int main()
{
    int matriz[FILAS][COLUMNAS] = {0};
    int linea;
    int interno;
    int recaudacion;
    int respuesta;

    do{
        printf("Ingrese linea: ");
        scanf("%d", &linea);
        if(linea<1 || linea>3)
        {
            printf("Error. Ingrese linea: ");
            scanf("%d", &linea);
        }
        printf("\n");

        printf("Ingrese interno: ");
        scanf("%d", &interno);
        if(interno<1 || interno>12)
        {
           printf("Error. Ingrese interno: ");
           scanf("%d", &interno);
        }
        printf("\n");

        printf("Ingrese recaudacion: ");
        scanf("%d", &recaudacion);
        if(recaudacion<1)
        {
            printf("Error. Ingrese recaudacion: ");
            scanf("%d", &recaudacion);
        }
        printf("\n");

        matriz[linea-1][interno-1] += recaudacion;

        printf("Ingrese 1 para entrar nuevamente al sistema: ");
        scanf("%d", &respuesta);

        system("cls");
    }
    while(respuesta==1);


    for(int i=0; i<FILAS-1; i++)
    {
        for(int j=0; j<COLUMNAS-1; j++)
        {
            matriz[i][COLUMNAS-1] += matriz[i][j];
        }
    }

    for(int i=0; i<COLUMNAS; i++)
    {
        for(int j=0; j<FILAS-1; j++)
        {
            matriz[FILAS-1][i] += matriz[j][i];
        }
    }

    /*for(int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }*/

    mostrarRecaudaciones(matriz, FILAS);

    return 0;
}

void mostrarRecaudaciones(int m[][13], int filas)
{
    printf("---------***Recaudaciones***---------\n");
    printf("Intenos    1    2    3    4    5    6    7    8    9   10   11  12 Totales\n");
     for(int i=0; i<filas; i++)
    {
        if(i!= filas-1)
        {
            printf("Linea %d ", i+1);
        }
        else
        {
            printf("Totales ");
        }
        for(int j=0; j<13; j++)
        {
            printf("%4d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
