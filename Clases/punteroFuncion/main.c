#include <stdio.h>
#include <stdlib.h>

int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);
void operar(int a, int b, int (*operacion)(int, int));

int main()
{
    /*int(*pepe)(int, int);

    pepe = sumar;
    printf("%d\n", pepe(4,6));

    pepe = restar;
    printf("%d\n", pepe(4,6));

    pepe = multiplicar;
    printf("%d\n", pepe(4,6));*/

    operar(2,6,sumar);
    operar(2,6,restar);
    operar(2,6,multiplicar);

    return 0;
}

int sumar(int a, int b)
{
    return a+b;
}

int restar(int a, int b)
{
    return a-b;
}

int multiplicar(int a, int b)
{
    return a*b;
}

void operar(int a, int b, int (*operacion)(int, int))
{
    printf("%d\n", operacion(a,b));

}
