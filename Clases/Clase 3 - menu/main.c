#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "gianluca.h"

int main()
{

    char salir = 'n';
    int flagSaludo = 0;
    int flagBrindar = 0;

    do
    {
        switch(menu())
        {
            case 'a':
                printf("Hola, que tal?\n\n");
                flagSaludo=1;
                system("pause"); // Pauso el programa. Me muestra un mensaje que dice "Presione una tecla para continuar..."
                break;
            case 'b':
                if(flagSaludo)
                {
                    printf("Chin chin\n\n");
                    flagBrindar=1;
                }
                else
                {
                    printf("Antes de brindar, primero deberiamos saludarnos\n\n");
                }
                system("pause");
                break;
            case 'c':
                if(!flagSaludo)
                {
                    printf("Antes de despedirte, primero deberiamos saludarnos\n\n");
                }
                else
                {
                    if(!flagBrindar)
                    {
                        printf("Antes de despedirte, primero deberiamos brindar\n\n");
                    }
                    else
                    {
                        printf("Chau, nos vemos\n\n");
                    }
                }
                system("pause");
                break;
            case 'd':
                printf("Esta seguro que desea salir? ");
                fflush(stdin);
                salir = getchar(); // Getchar, getch y getche explicados en el bloc de notas clase 3
                break;
            default:
                printf("Opcion invalida!\n");
                system("pause");
                break;
        }
    }
    while(salir == 'n');
    return 0;
}
