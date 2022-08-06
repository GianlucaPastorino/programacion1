#include <stdio.h>
#include <stdlib.h>

int mostrarEnteros(int* vector, int tam);

int main()
{
    //int numeros[5];

    int tam = 5;

    int* aux = NULL; // Tengo que inicializarla con null si es que no la inicializo, como buena práctica.
    int* vec = (int*) malloc(tam * sizeof(int));

    if(vec == NULL)
    {
        printf("No se pudo conseguir memoria.\n\n");
        system("pause");
        exit(1);
    }

    /*for(int i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }

    for(int i=0; i<5; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n\n");*/


    for(int i=0; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i); // vec es la posición del primer elemento, i va a ser el desplazamiento en el vector.
        //scanf("%d", &vec[i]);
    }

    mostrarEnteros(vec, tam);

    /*
    for(int i=0; i<tam; i++)
    {
        printf("%d ", *(vec+i)); // notacion de punteros
        //printf("%d ", vec[i]); // notacion vectorial
    }
    */

    // Agrando el vector
    aux = (int*) realloc(vec, sizeof(int) * 10);

    if( aux == NULL)
    {
        printf("No se pudo conseguir memoria.\n\n");
        system("pause");
        exit(1);
    }
    vec = aux;
    aux = NULL;
    tam += 5;
    printf("Vector agrandado con exito.\n"); // No hace falta que lo ponga en un else porque si entra al if ya termina el programa, pero si no entra ejecuta esto.

    for(int i=5; i<tam; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vec + i);
    }

    mostrarEnteros(vec, tam);

    // Achico el vector
    printf("Me achico en 3 posiciones.\n");
    vec = (int*)realloc(vec, sizeof(int) * 7); // No hace falta poner vec = en este caso al principio.
    tam -= 3;

    mostrarEnteros(vec, tam);

    free(vec);
    return 0;
}

int mostrarEnteros(int* vector, int tam)
{
    int todoOk = 0;

    if(vector != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            printf("%d ", *(vector+i));
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;
}
