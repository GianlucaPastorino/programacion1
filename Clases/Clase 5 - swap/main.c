#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b);

int main()
{
    int num1 = 3;
    int num2 = 5;
    swap(&num1, &num2);
    printf("%d\n", num1);
    printf("%d\n", num2);
    return 0;
}

void swap(int* a, int* b)
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}
