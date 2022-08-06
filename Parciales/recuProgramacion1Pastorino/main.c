#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y devuelva el valor del producto con un descuento del 5%. Realizar la llamada desde el main
//Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro y un carácter como segundo
//y devuelva la cantidad de veces que ese carácter aparece en la cadena
//Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
//Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main.

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    int precio;
} eNotebook;

int aplicarDescuento(int precio);
int contarCaracteres(char cadena[], char caracter);
//No me dio el tiempo para realizar la última función

int main()
{
    int precio = 300;
    char palabra[] = "Programacion";

    printf("%d\n\n", aplicarDescuento(precio));

    printf("La letra a en la palabra indicada aparece %d veces\n\n", contarCaracteres(palabra, 'a'));

    return 0;
}

int aplicarDescuento(int precio)
{
    return precio - precio * 5/100;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contador = 0;

    for(int i = 0; i<strlen(cadena); i++)
    {
        if(cadena[i] == caracter)
        {
            contador++;
        }
    }

    return contador;
}


