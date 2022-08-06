#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x= 'x';

    char y[10]={'x','x','x','x','x','x','x','x','x','x'};

    char z[3][10]={{'x','x','x','x','x','x','x','x','x','x'},
                   {'x','x','x','x','x','x','x','x','x','x'},
                   {'x','x','x','x','x','x','x','x','x','x'}};

    x='a';
    y[7]='a'; //Así guardo un único caracter en un vector.
    z[2][6]='a'; //Así guardo un único caracter en una matriz.

    strcpy(y, "Juan"); //Así guardo una cadena de caracteres en un vector.
    strcpy(z[1], "Juan"); //Así guardo una cadena de caracteres en una matriz.

    //muestro x
    printf("%c\n\n", x);

    //muestro y
    for(int i=0; i<10; i++)
    {
        printf("%c", y[i]);
    }
    printf("\n\n");

    //muestro z
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<10; j++)
        {
            printf("%c", z[i][j]);
        }
        printf("\n");
    }


    return 0;
}
