#include <stdio.h>
#include <stdlib.h>

#define TAM 5
#define ASC 1
#define DESC 0

void mostrarEnteros(int vec[], int tam);
void ordenarEnterosAsc(int vec[], int tam);
void ordenarEnterosDesc(int vec[], int tam);
// Criterio 1 asc, criterio 0 desc.
void ordenarEnteros(int vec[], int tam, int criterio);

int main()
{
    int numeros[TAM] = {3,5,2,9,4};

    // Muestro los números en el orden actual
    mostrarEnteros(numeros, TAM);

    // Ordeno de menor a mayor
    //ordenarEnterosAsc(numeros, TAM);
    ordenarEnteros(numeros, TAM, ASC);
    mostrarEnteros(numeros, TAM);

    // Ordeno de mayor a menor
    //ordenarEnterosDesc(numeros, TAM);
    ordenarEnteros(numeros, TAM, DESC);
    mostrarEnteros(numeros, TAM);

    return 0;
}

void mostrarEnteros(int vec[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

// Si quiero cambiar de mayor a menor o de menor a mayor, sólo cambio en el if el signo de > a <
void ordenarEnterosAsc(int vec[], int tam)
{
    int aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i]>vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

void ordenarEnterosDesc(int vec[], int tam)
{
   int aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i]<vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}

void ordenarEnteros(int vec[], int tam, int criterio)
{
    int aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(criterio && vec[i]>vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
            else if(!criterio && vec[i]<vec[j])
            {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
}
