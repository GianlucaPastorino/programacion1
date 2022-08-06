#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// Pedir 5 numeros e informar el promedio

void mostrarVectorEnteros(int vec [], int tam); // Así tengo que hacer si quiero pasarle un array a una funcion. NOMENCLATURA DE VECTORES
//void mostrarVectorEnteros(int *vec, int tam); Es lo mismo. NOMENCLATURA DE PUNTEROS.

int main()
{
    int numeros[TAM];
    int numeros2[TAM] = {3, 4, 5, 1, 9};
    // Asi se hace para cargar directamente los valores del array. Se llama inicializar el vector por extension. NO es obligatorio poner el TAM en este caso, solo [].
    // Si yo tengo un TAM de 10 pero inicializo solo 5 elementos del vector, el resto me los va a completar automaticamente con 0.
    int acumulador = 0;
    float promedio;

    mostrarVectorEnteros(numeros2, TAM);

    for(int i=0; i<TAM; i++) // 0 1 2 3 4 y cuando llega al 5 sale. Esto es recorrer un array de manera secuencial. Recorro del 0 al último elemento pasando por todos.
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    // Mostrar los numeros ingresados.
    printf("Los numeros ingresados son: ");
    for(int i=0; i<TAM; i++)
    {
        printf("%d, ", numeros[i]);
    }
    printf("\n\n");


    for(int i=0; i<TAM; i++)
    {
        acumulador += numeros[i];
    }

    promedio= (float) acumulador/ TAM;

    printf("El promedio es %.2f\n", promedio);

    return 0;
}

void mostrarVectorEnteros(int vec [], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
