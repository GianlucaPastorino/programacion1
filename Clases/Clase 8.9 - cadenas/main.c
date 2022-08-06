#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copiarCadena(char cadenaDestino[], char cadenaOrigen[]);
void arreglarFgets(char cadena[]);

int main()
{
    char cadena1[20] = "Jose"; // Así se hardcodea una cadena de caracteres.
    //Al ponerlo entre " dobles indico que es una cadena, entonces automáticamente me completa con el \0 (caracter terminador, indica dónde termina la cadena).
    char cadena2[20] = "Juan";
    // No puedo poner char cadena2[20]; y después cadena2="Juan"; porque cadena2 es un puntero al primer elemento de ese array.
    char cad1[20] = "Hola";
    char cad2[20] = "Mundo";
    char nombre[20];
    char auxNombre[100];

    printf("%s %s\n\n", cadena1, cadena2);

    strcpy(cadena1, cadena2);//Stringcopy. Lo que tengo en el 2do parametro se copia en el 1ro. Queda Juan Juan
    //copiarCadena(cadena1, cadena2);

    printf("%s %s\n\n", cadena1, cadena2);

    printf("Ingrese nombre: ");

    gets(cadena1); // Get string. Recibe el contenido del string indicado.

    puts(cadena1); // Put string. Escribe el contenido del string indicado. SOLO muestra el valor, no puedo escribir cosas como en printf.

    printf("El nombre ingresado es: %s\n\n", cadena1);

    int cant;
    cant = strlen(cadena1); // Devuele el largo de la cadena.
    printf("Cantidad de caracteres: %d\n\n", cant);

    strupr(cadena1); // String upper. Lo pasa a mayusculas.
    puts(cadena1);

    strlwr(cadena1); // String lower. Lo pasa a minusculas.
    puts(cadena1);

    strcat(cad1, cad2); // Concatenar cadenas. Me lo guarda en cad1. OJO, estamos limitados al largo de cad1 [20].
    puts(cad1);

    strcmp(cadena1, cadena2); // String compare. Compara cadenas. Devuelve 0 si es igual,
    // -1 si el 1er param está antes que el 2d0 en el ASCII y 1 si el 1er param está después que el 2do. Es case sensitive.

    stricmp(cadena1, cadena2); // NO es sensible a minus/mayus. Si es HOLA y hola va a devolver 0.

    // Validación para no desbordar.
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(auxNombre);

    while(strlen(auxNombre)>=20)
    {
        printf("Nombre demasiado largo. Reingrese nombre: ");
        fflush(stdin);
        gets(auxNombre);
    }
    strcpy(nombre, auxNombre);
    printf("%s\n\n", nombre);

    // Otra forma de validar para no desbordar.
    printf("Ingrese nombre: ");
    fflush(stdin);
    fgets(nombre, 19, stdin); // Del buffer de entrada, usa 19 y guarda en nombre. También toma el enter.

    arreglarFgets(nombre);

    printf("%s\n", nombre);

    return 0;
}

void copiarCadena(char cadenaDestino[], char cadenaOrigen[])
{
    int i = -1;

    do
    {
        i++;
        cadenaDestino[i] = cadenaOrigen[i];
    } while(cadenaOrigen[i]!='\0');
}

void arreglarFgets(char cadena[])
{
    for(int i=0; cadena[i] != '\0'; i++)
    {
        if(cadena[i]=='\n')
        {
            cadena[i]='\0';
        }
    }
}
