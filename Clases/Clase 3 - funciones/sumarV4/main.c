#include <stdio.h>
#include <stdlib.h>

// TIPO F4, RECIBE, DEVUELVE.

int sumarv4(int a, int b); //Prototipo

int main()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    printf("%d", sumarv4(num1, num2));
  //  resultado = sumarv4(num1, num2); //Llamada a la función
 //   printf("El resultado es %d\n", resultado);

    return 0;
}

int sumarv4(int a, int b) //Función
{
    int resultado;

    resultado = a + b;

    return resultado;
    // Podría hacer directamente return a+b;
}
