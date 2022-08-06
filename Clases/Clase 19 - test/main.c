#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int x;
    int* p = &x; // &x direccion de memoria de x. x==*p.
    int** q = &p; //&p direccion de memoria de p. p==*q.

    // maneras de asignar 10 a la variable x:
    //x = 10 // *(&x)
    // *p = 10; // *(*(&p))
    **q = 10; // *(*(*(&q)))

    printf("x vale: %d\n", x);
    */

    int* p = (int*) malloc(sizeof(int));
    int** q = (int**) malloc(sizeof(int*));

    *q = p;

    **q = 10;

    printf("%d\n", **q);


    return 0;
}
