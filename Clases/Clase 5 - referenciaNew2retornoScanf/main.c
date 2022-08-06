#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int x;
    int retorno;

    printf("Ingrese un numero: ");
    retorno=scanf("%d", &x);

    printf("Retorno: %d\n", retorno);
    printf("x: %d\n", x);
    */

    //El scanf si recibe lo correcto va a devolver un 1, si no puede hacer su tarea devuelve 0 (en caso de necesitar cargar una sola variable). Puede servir para validar.

    int dia;
    int mes;
    int anio;
    int retorno;

    printf("Ingrese la fecha dd/mm/aaaa: ");
    retorno = scanf("%d/%d/%d", &dia, &mes, &anio);

    printf("Retorno: %d\n", retorno);
    printf("La fecha ingresada es %d/%d/%d", dia, mes, anio);

    //En realidad el scanf me devulelve la cantidad de variables que pudo cargar de manera correcta. Pero si ya encuentra una que está mal, deja de funcionar en ese momento, se frena el scanf.
    //Si el primer valor está mal y todo el resto bien, sale del scanf al principío y me retorna 0.

    return 0;
}
