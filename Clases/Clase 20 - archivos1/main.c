#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main()
{
    int numero = 45;
    int numeros[TAM] = {34, 21, 56, 43, 88};

    int x;
    int vec[TAM];
/*
    FILE* f = fopen("datos.bin", "wb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    if(fwrite(numeros, sizeof(int), TAM, f) == TAM)
    {
        printf("Se guardaron los datos con exito!!!\n");
    }
    else
    {
        printf("Hubo un problema al guardar los datos\n");
    }
    // No es necesario hacerlo con if.

    fclose(f);
*/
    FILE* f= fopen("datos.bin", "rb");
    if(f == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }

    int cont = 0;
    // Si no conozco la cantidad de repeticiones voy leyendo de a uno.
    while(!feof(f)) // Mientras no haya llegado al final del fichero sigo iterando.
    {
        if(fread(&vec[cont], sizeof(int), 1, f) < 1)
        {
            break;
        }
        cont++;
    }

    if(fread(vec, sizeof(int), TAM, f) == TAM)
    {
        printf("Datos leidos con exito!!!\n");
    }
    else
    {
        printf("Hubo un problema al leer los datos\n");
    }

    fclose(f);

    for(int i = 0; i<TAM; i++)
    {
        printf("%d\n", vec[i]);
    }
    printf("\n\n");

    return 0;
}
