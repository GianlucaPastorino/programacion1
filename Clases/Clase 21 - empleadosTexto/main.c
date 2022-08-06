#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include <ctype.h>

int main()
{
    int tam = 1;
    int cant;
    //int auxInt;
    //char auxCad[100];
    //char auxChar;
    //float auxFloat;

    char buffer[4][20];
    int indice;
    int flag = 0;
    eEmpleado* auxEmpleado = NULL;

    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*) * tam);
    if(lista== NULL)
    {
        printf("No se consiguio lugar para la lista.\n");
        exit(1);
    }

    if(inicializarEmpleados(lista, tam))
    {
        printf("Empleados inicializados con exito\n");
    }

    FILE* f = fopen("listaEmpleados.csv", "r");
    if(f== NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    //Lectura fantasma para saltar el encabezado
    //fscanf(f, "%s\n", auxCad);
    fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    // Itero sobre cada renglon
    while(!feof(f))
    {
        buscarLibreEmpleado(lista, tam, &indice);

        if(indice== -1)
        {
            if(!agrandarLista(&lista, &tam))
            {
                flag = 1; // 1 problema para conseguir lugar.
                break;
            }
        }
        else
        {
            // Leo y parseo una fila del archivo
            //cant = fscanf(f, "%d,%[^,],%c,%f\n", &auxInt, auxCad, &auxChar, &auxFloat);
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant == 4)
            {
                // Si la lectura fue exitosa creo un empleado con el constructor
                //auxEmpleado = newEmpleadoParam(auxInt, auxCad, tolower(auxChar), auxFloat);
                auxEmpleado = newEmpleadoStr(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(auxEmpleado != NULL)
                {
                    *(lista + indice) = auxEmpleado;
                    auxEmpleado = NULL;
                }
                else
                {
                    flag = 2; // 2 problema para crear el empelado
                    break;
                }
            }
            else
            {
                flag = 3; // 3 problema al leer el empleado
                break;
            }
        }
    }

    if(flag == 0)
    {
        printf("Empleados cargados correctamente!!!\n");
    }
    else if(flag == 1)
    {
        printf("No se pudo conseguir lugar\n");
    }
    else if(flag==2)
    {
        printf("No se pudo crear el empleado\n");
    }
    else if(flag == 3)
    {
        printf("Problema al leer el empleado\n");
    }

    fclose(f);

    mostrarEmpleados(lista, tam);

    // Guardo los empleados en otro archivo de texto

    f = fopen("listaEmpleados2.csv", "w");
    if(f== NULL)
    {
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    fprintf(f, "legajo,nombre,sexo,sueldo\n"); // escribo la primer linea

    for(int i = 0; i<tam; i++)
    {
        auxEmpleado = *(lista+i);
        if(auxEmpleado != NULL)
        {
            fprintf(f, "%d,%s,%c,%.2f\n", auxEmpleado->legajo, auxEmpleado->nombre, auxEmpleado->sexo, auxEmpleado->sueldo);
        }
        auxEmpleado=NULL;
    }
    fclose(f);

    free(lista);

    return 0;
}
