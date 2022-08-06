#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 //Pido nombre y apellido
// Nombre completo quiero que quede Baus, Christian German. Iniciales en mayusuculas y resto en minusculas.

int main()
{
    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]; // A determinar por nosotros. Acá tengo que hacer todos los cambios usando las funciones.
    char auxCad[100];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=20)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(nombre, auxCad);
    printf("\n");

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=20)
    {
        printf("Apellido demasiado largo. Reingrese apellido: ");
        fflush(stdin);
        gets(auxCad);
    }
    strcpy(apellido, auxCad);
    printf("\n");

    strcpy(nombreCompleto, apellido);
    strcat(nombreCompleto, ", ");
    strcat(nombreCompleto, nombre);

    strlwr(nombreCompleto);
    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for(int i=0; nombreCompleto[i]!='\0'; i++)
    {
        if(nombreCompleto[i]==' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }

    puts(nombreCompleto);

    return 0;
}
