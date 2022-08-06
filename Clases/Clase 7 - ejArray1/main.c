#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// Declarar un array de tamaño 5 y cargarlo secuencialmente
// Mostrarlo tal cual fue cargado
// Mostrarlo al reves (5, 3, 8, 1, 9 --> 9, 1, 8, 3, 5)
// Después hacer una función para mostrarlo al derecho o al reves, desde y hasta el indice que quiera.

/** \brief muestra por consola los elementos de un array de enteros
 *
 * \param vec[] int array que se va a mostrar
 * \param tam int tamanio del array
 * \param inicio int indice del primer elemento a mostrar
 * \param fin int indice del ultimo elemento a mostrar
 * \return int devuelve 0 si todo ok o 1 si hubo un error
 *
 */
int mostrarNumeros(int vec[], int tam, int inicio, int fin);


int main()
{
    int numeros[TAM];

    for(int i=0; i<TAM; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    printf("\n");

    /*for(int i=0; i<TAM; i++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n\n");

    for(int i=TAM-1; i>=0; i--)
    {
        printf("%d ", numeros[i]);
    }*/

    if (!mostrarNumeros(numeros, TAM, 0, 4))
    {
        printf("Hubo un error en los parametros.\n");
    }
    if (!mostrarNumeros(numeros, TAM, 4, 240))
    {
        printf("Hubo un error en los parametros.\n");
    }

    return 0;
}


int mostrarNumeros(int vec[], int tam, int inicio, int fin)
{
    int todoOk = 0;
    if(vec != NULL && tam>0 && inicio >=0 && inicio<tam && fin>=0 && fin < tam)
    {
       if(inicio<fin)
       {
           for(int i=inicio; i<=fin; i++)
           {
               printf("%d ", vec[i]);
           }
       }
       else
       {
           for(int i=inicio; i>=fin; i--)
           {
               printf("%d ", vec[i]);
           }
       }
       todoOk=1;
    }
    printf("\n");
    return todoOk;
}
