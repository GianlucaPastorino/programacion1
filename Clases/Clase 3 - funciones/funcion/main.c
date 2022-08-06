#include <stdio.h>
#include <stdlib.h>

// Pedir dos numeros e informar la suma de los mismos

int main()
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

    return 0;
}
