#include <stdio.h>
#include <stdlib.h>

void duplicar (int *p); // El parametro formal de la funcion recibe una dirección de memoria. PASO POR REFERENCIA.

int main()
{
    int numero = 15;

    // *(&numero)=10; // El valor en la dirección de memoria de numero.

    // int *punt = &numero; // Creo una variable que es un puntero a numero (su direc de memoria)

    // *punt = 45; // Le asigno 45 a numero, sería lo mismo que *(&numero) = 45;

    printf("Antes de llamar a duplicar numero vale: %d\n", numero);

    duplicar(&numero);

    printf("Despues de llamar a duplicar numero vale: %d\n", numero);

    return 0;
}

void duplicar(int *p)
{
    *p = *p * 2;
}
