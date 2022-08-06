#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// Declarar un array de 5 enteros.
// Pedir al usuario los numeros.
// Informar cual fue el mayor.
// Quiero informar en cual o cuales posiciones se ingresó.

int main()
{
    int numeros[TAM];
    int mayor;
    int flag = 1;

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    for(int i=0; i<TAM; i++)
    {
        if(flag || numeros[i]>mayor)
        {
            mayor= numeros[i];
            flag = 0;
        }
    }

    printf("El mayor numero ingresado es %d y se ingreso en la o las posiciones ", mayor);

    for(int i=0; i<TAM; i++)
    {
        if(numeros[i] == mayor)
        {
            printf("%d ", i+1);
        }
    }
    printf("\n\n");

    return 0;
}
