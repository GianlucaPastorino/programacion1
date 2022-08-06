#include <stdio.h>
#include <stdlib.h>
#define TAM 5

//Declarar array de sexos (5 personas)
// Inicializarlo por extension
//mostrarlo a traves de una función llamada mostrar sexos.

int mostrarSexos(char vec[], int tam);
int main()
{
    char sexos[TAM]= {'m', 'f', 'm', 'f', 'f'};
    mostrarSexos(sexos, TAM);

    return 0;
}

int mostrarSexos(char vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL & tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
        printf("%c ", vec[i]);
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

