#include <stdio.h>
#include <stdlib.h>

/** \brief obtiene el mayor de 3 enteros
 *
 * \param a int primer entero a evaluar
 * \param b int segundo entero a evaluar
 * \param c int tercer entero a evaluar
 * \return int el valor del mayor entero evaluado
 *
 */
int maximum(int a, int b, int c);

int esPar(int numero);

int main()
{
    printf("%d\n", maximum(4,5,2));

    if(esPar(7))
    {
        printf("Es par\n");
    }
    else
    {
        printf("Es impar\n");
    }
    return 0;
}

int maximum(int a, int b, int c)
{
    int maximo = c;

    if(a>b && a>c)
    {
        maximo = a;
    }
    else
    {
        if(b>=a && b>c) //Atenti a esto, así es como se hace bien, no como con Octavio.
        {
            maximo=b;
        }
    }
    return maximo;
}

int esPar(int numero)
{
    /*int par = 0;
    if(numero%2==0)
    {
        par = 1;
    }
    return par;*/
    return!(numero%2);
}

