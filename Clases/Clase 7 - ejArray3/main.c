#include <stdio.h>
#include <stdlib.h>
#define TAM 6

/** \brief busca un caracter en un array de caracteres
 *
 * \param vec[] char vector sobre el cual se realiza la busqueda
 * \param tam int tamanio del vector
 * \param caracter char caracter a buscar
 * \return int 1 si está el caracter dentro del array, 0 si no se encuentra (el buscar2 retorna el indice de la 1ra aparicion del char o -1 si no está)
 // Si querría buscar el de la última aparición simplemente tendría que sacar el break en la función.
 *
 */
int buscarCaracter(char vec[], int tam, char caracter);

int buscarCaracter2(char vec[], int tam, char caracter);

int main()
{
    char letras[TAM]={'a', 'e', 'c', 'j', 't', 'h'};
    if(buscarCaracter(letras, TAM, 'c'))
    {
        printf("Esta el caracter.\n");
    }
    else
    {
        printf("No esta el caracter.\n");
    }

    int posicion= (buscarCaracter2(letras, TAM, 'c'));
    if(posicion==-1)
    {
        printf("No esta el caracter.\n");
    }
    else
    {
        printf("El caracter esta en la posicion %d\n", posicion);
    }

    return 0;
}

int buscarCaracter(char vec[], int tam, char caracter)
{
    int i;
    int todoOk = 0;

    for(i=0; i<tam; i++)
    {
        if(caracter==vec[i])
        {
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

int buscarCaracter2(char vec[], int tam, char caracter)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(caracter==vec[i])
        {
            indice=i;
            break;
        }
    }
    return indice;
}
