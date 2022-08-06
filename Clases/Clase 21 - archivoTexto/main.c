#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x = 20;
    int y;
    int cant;
    char auxCad[5];
    char caracter;

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;

    char buffer[4][20];

/*
    FILE* f = fopen("variables.txt", "w");
    if(f== NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    cant = fprintf(f, "%d", x); // Guardar archivo como texto

    if(cant != 1)
    {
        printf("Se guardaron los datos correctamente\n\n");
    }
    else
    {
        printf("Ocurrio un problema al guardar los datos\n\n");
    }
*/
/*
    FILE* f = fopen("variables.txt", "r");
    if(f== NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    //cant = fscanf(f, "%d", &y);
    cant = fscanf(f, "%s", auxCad);



    if(cant==1)
    {
        printf("Se leyeron los datos correctamente\n");
    }
    else
    {
        printf("Problema al leer los datos\n");
    }

    y = atoi(auxCad);
    printf("Y: %d\n", y);
*/

    FILE* f = fopen("variables.txt", "r");
    if(f== NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    //cant = fscanf(f, "%d,%[^,],%c,%f", &legajo, nombre, &sexo, &sueldo);
    cant = fscanf(f, "%[^,],%[^,],%[^,],%s", buffer[0], buffer[1], buffer[2], buffer[3]); // Le pongo un %s al final porque es lo último que tiene que leer,
    // no tengo que leer hasta ninguna coma.
    printf("Cant: %d\n", cant);

    printf("Legajo: %s\nNombre: %s\nSexo: %s\nSueldo: %s\n", buffer[0], buffer[1], buffer[2], buffer[3]);
    printf("Legajo: %d\nNombre: %s\nSexo: %c\nSueldo: %.2f\n", atoi(buffer[0]), buffer[1], buffer[2][0], atof(buffer[3]));
/*
    while(!feof(f))
    {
       //caracter = fgetc(f);
       //printf("%c", caracter);
       fgets(auxCad, 5, f); // Desde f leete 5 (tamaño de auxCad) caracteres y copialos en auxCad.
       printf("%s", auxCad);
    }
    printf("\n\n");
*/
    fclose(f);

    return 0;
}
