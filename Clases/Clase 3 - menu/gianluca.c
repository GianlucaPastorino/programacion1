#include "gianluca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char menu()
{
   char opcion;
   system("cls"); //Limpiar pantalla, me borra todo lo que se muestra en pantalla cada vez que pasa por acá
   printf("*** Menu de opciones ***\n\n");
   printf("a. Saludar\n");
   printf("b. Brindar\n");
   printf("c. Despedir\n");
   printf("d. Salir\n\n");
   printf("Ingrese opcion: ");
   fflush(stdin);
   scanf("%c", &opcion);
   opcion=tolower(opcion);

   return opcion;
}
