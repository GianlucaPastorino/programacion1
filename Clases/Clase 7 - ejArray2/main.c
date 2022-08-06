#include <stdio.h>
#include <stdlib.h>
#define TAM 5

/** \brief pide al usuario numeros y deja la suma de los mismos en la ultima posicion
 *
 * \param vec[] int vector a cargar
 * \param tam int tamanio del vector
 * \return void
 *
 */
void cargarVectorTotalizador(int vec[], int tam);

int main()
{
    int numeros[TAM];
    cargarVectorTotalizador(numeros, TAM);

    printf("\n");

    for(int i=0; i<TAM; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n");

    return 0;
}

void cargarVectorTotalizador(int vec[], int tam)
{
    vec[tam-1]=0;
    for(int i = 0; i<tam-1; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
        vec[tam-1] += vec[i];
    }
}
