#include <stdio.h>
#include <stdlib.h>

// TIPO F3, NO RECIBE, DEVUELVE.

int sumarv3(void); //Prototipo

int main()
{
    int resultado;

    resultado = sumarv3(); //Llamada a la función
    printf("El resultado es %d\n", resultado);

    return 0;
}

int sumarv3() //Función
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    return resultado;
}
