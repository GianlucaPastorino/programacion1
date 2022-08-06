#include <stdio.h>
#include <stdlib.h>

//TIPO F1, NI RECIBE, NI DEVUELVE.

//Prototipo de la función:
void sumarv1(void); // void es el "no tipo de dato", en este caso no recibe nada (void entre parentesis) ni devuelve nada (void al principio).

int main()
{
    sumarv1(); //Llamada de la función.
    return 0;
}

//Cuerpo de la función
void sumarv1()
{
    int num1;
    int num2;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &num1);
    printf("Ingrese otro numero: ");
    scanf("%d", &num2);

    resultado = num1 + num2;

    printf("El resultado es %d\n", resultado);
}
