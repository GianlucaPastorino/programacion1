#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//declarar un array de 5 enteros
//cargarlo secuencialmente con numeros ingresados por el usuario
//y mostrar solo los numeros pares

void cargarVectores(int vec[], int tam);
void mostrarPares(int vec[], int tam);

int main()
{
    int numeros[TAM];

    cargarVectores(numeros, TAM);

    mostrarPares(numeros, TAM);

    return 0;
}

//Cargo el vector secuencialmente a traves del usuario.
void cargarVectores(int vec[], int tam)
{
     for(int i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }
}

// Recorro el vector buscando numeros pares para mostrarlos.
void mostrarPares(int vec[], int tam)
{
    int flagPar=0;
    for(int i=0; i<tam; i++)
    {
       if(vec[i]%2==0)
       {
           if(flagPar == 0)
           {
               printf("Numeros pares: ");
               flagPar=1;
           }
           printf("%d, ", vec[i]);
       }
    }
    if(flagPar==0)
    {
        printf("No hay numero pares.");
    }
    printf("\n\n");
}
