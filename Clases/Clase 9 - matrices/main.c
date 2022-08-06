#include <stdio.h>
#include <stdlib.h>
#define TAM 5
#define FILAS 3
#define COLUMNAS 5

void mostrarMatriz(int mat[][5], int filas); // Debo cargar cantidad de columnas

int main()
{
    int x = 4;
    int y[TAM] = {3,2,8,6,5};
    int z[FILAS][COLUMNAS] = {{2,1,6,5,9},{8,3,5,7,2},{3,9,1,4,2}}; //filas, columnas.

    x = 10;
    y[2] = 8;
    z[2][4] = 8;
    z[0][4] = 7;
    z[1][1] = 5;
    z[1][3] = 4;

    //Así se le pide al usuario que cargue los datos de la matriz.
    for(int i=0; i<FILAS; i++)
    {
        for(int j=0; j<COLUMNAS; j++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", &z[i][j]);
        }
    }

    // Escribo en la fila 1 de todas las columnas, todos 6. .
    for(int i=0; i<COLUMNAS; i++)
    {
        z[1][i]=6;
    }

    // Escribo en la columna 2 de todas las filas, todos 8
    for(int f = 0; f < FILAS; f++)
        {
            z[f][2]= 8;
        }

    // Muestro el valor de x
    printf("%d\n", x);

    // Muestro los valores de y
    for(int i = 0; i<TAM; i++)
    {
        printf("%d ", y[i]);
    }
    printf("\n\n");

    // Muestro los valores de z
    mostrarMatriz(z, FILAS);
    /*for(int f = 0; f<FILAS; f++)
    {
        for(int c = 0; c<COLUMNAS; c++)
        {
            printf("%d ", z[f][c]);
        }
        printf("\n");
    }*/

    return 0;
}

void mostrarMatriz(int mat[][5], int filas)
{
   for(int f = 0; f<filas; f++)
    {
        for(int c = 0; c<5; c++)
        {
            printf("%d ", mat[f][c]);
        }
        printf("\n");
    }

}
