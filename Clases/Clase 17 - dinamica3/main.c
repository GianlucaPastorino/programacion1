#include <stdio.h>
#include <stdlib.h>

int mostrarEnteros(int* vector, int tam);

int main()
{

    int* vec = (int*) calloc(5, sizeof(int)); // "Quiero 5 (tamaño) de --- este tamaño (int)". Me inicializa todo a 0.

    mostrarEnteros(vec, 5);

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
