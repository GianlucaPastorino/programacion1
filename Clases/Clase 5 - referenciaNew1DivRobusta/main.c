#include <stdio.h>
#include <stdlib.h>

/** \brief realiza la división de dos enteros
 *
 * \param a int dividendo de la operación
 * \param b int divisor de la operación
 * \return float retorna el cociente entre divendo y divisor
 *
 */
float dividir(int a, int b);

/** \brief
 *
 * \param a int dividendo de la operacón
 * \param b int divisor de la operación
 * \param c float* puntero
 * \return int retorna 1 si pudo hacer la division o 0 si no pudo
 *
 */
int dividirRobusta(int a, int b, float* c);

int main()
{
    float resultado;
    int numero1 = 20;
    int numero2 = 5;

    /*if(numero2!=0)
    {
        resultado = dividir(numero1, numero2);
        printf("El resultado es %.2f\n", resultado);
    }
    else
    {
        printf("Error. No se puede dividir por 0.\n");
    }*/

    if(dividirRobusta(numero1, numero2, &resultado))
    {
        printf("El resultado de la division es %.2f\n", resultado);
    }
    else
    {
        printf("No se pudo realizar la division.\n");
    }
    return 0;
}

float dividir(int a, int b)
{
    /*
    float rdo;
    if(b!=0)
    {
        rdo=(float) a/b;
    }
    return rdo;
    */
    return (float) a/b; //Valido el divisor (no 0) en el main.
}

int dividirRobusta(int a, int b, float* c)
{
    int todoOk = 0;

    if(b!=0 && c!= NULL)
    {
        *c = (float) a/b;
        todoOk=1;
    }
    return todoOk;
}
