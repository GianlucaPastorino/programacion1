#include <stdio.h>
#include <stdlib.h>

// Pedir dos números e informar el promedio de los mismos.

int main()
{
    int numeroIngresado1;
    int numeroIngresado2;
    float promedio;

    printf("Ingrese un numero: ");
    scanf("%d", &numeroIngresado1);

    printf("Ingrese otro numero: ");
    scanf("%d", &numeroIngresado2);

    promedio= (float) (numeroIngresado1+numeroIngresado2)/2; //Poner el (float) se llama castear. Es obligar a la máquina que me trate el resultado como un flotante.
    printf("El promedio de los dos numeros es: %.2f\n", promedio);

    return 0;
}
