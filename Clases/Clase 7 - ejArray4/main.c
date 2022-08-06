#include <stdio.h>
#include <stdlib.h>
#define TAM 6

/** \brief busca un caracter dentro de un array de caracteres y reemplaza por el caracter dado
 *
 * \param vec[] char vector sobre el cual se realiza la busqueda
 * \param tam int tamaño del vector
 * \param buscar char caracter a buscar
 * \param reemplazar char caracter a reemplazar
 * \return int devuelve la cantidad de caracteres que se pudo reemplazar
 *
 */
int buscarReemplazar(char vec[], int tam, char buscar, char reemplazar);

int main()
{
    char letras[TAM]={'a', 'e', 'x', 'j', 'h', 'h'};
    int cantidadDeReemplazos;

    for(int i= 0; i<TAM; i++)
    {

        printf("%c, ", letras[i]);

    }

    cantidadDeReemplazos = buscarReemplazar(letras, TAM, 'h', 'y');

    printf("\n%d\n", cantidadDeReemplazos);

    for(int i= 0; i<TAM; i++)
    {

        printf("%c, ", letras[i]);

    }
    return 0;
}

int buscarReemplazar(char vec[], int tam, char buscar, char reemplazar)
{
    int i;
    int contadorDeReemplazos = 0;

    for(i = 0; i < tam; i ++)
    {

        if(buscar == vec[i])
        {
            vec[i] = reemplazar;
            contadorDeReemplazos++;

        }

    }
    return contadorDeReemplazos;
}
