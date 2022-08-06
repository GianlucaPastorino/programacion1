#include <stdio.h> //standard input output. Entrada teclado, salida monitor. h header
#include <stdlib.h> //standard library.

int main()
{
    int numero = 1234; // int asigna el tipo de numero entero. Equivalente a let numero = 1234
    int numero2 = 5678;
    float x = 3.14; //float asigna el tipo de numero con decimales.
    char sexo = 'f'; //para guardar UN caracter uso comillas simples
    char nombre [20] = "Jose"; // Con los corchetes asigno los espacios en memoria para la cantidad de caracteres.
    int edad = 23;
    float altura;
    char cadena [20];

    printf("La variable numero vale: %d y numero2 vale: %d\n", numero, numero2); //printf es igual a  console.log.
    printf("x vale: %.2f\n", x); //por default %f muestra precision de 6 decimales. el .2 hace que me muestre solo 2 decimales.
    printf("sexo: %c \n", sexo);
    printf("Usted se llama %s y tiene %d anios.\n", nombre, edad); //La ñ no está en el código ascii

    printf("Ingrese su altura:"); // no va barra n porque al tener un scanf, salta de linea al dar enter
    scanf("%f", &altura); //scanf pide un dato, una especie de prompt. En los parentesis va el tipo de dato a ingresar ("%f") y se pone un & antes del nombre de la variable para
    // indicar el espacio en memoria en el que se encuentra guardado esa variable.
    printf("Usted mide %.2f mts\n", altura);

    printf("Ingrese su nombre:");
    fflush(stdin); //Limpiar el buffer (solo en los casos de pedido de string o de caracter)
    scanf("%s", cadena); //En el pedido de tipo de dato string no va nunca el &, es el único caso.
    printf("Su nombre es: %s\n", cadena);

    return 0; // return es lo que devuelve/retorna la función (se le devuelve al sistema).
}
