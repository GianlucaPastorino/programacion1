#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d %10s   %d   %c  %9.2f %02d/%02d/%d\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio
          );
}

void mostrarEmpleados(eEmpleado lista[], int tam)
{
    int flag=0;

    printf("         Listado de Empleados\n");
    printf("Legajo   Nombre  Edad Sexo  Sueldo  F.Ingreso\n");

    for(int i=0; i<tam; i++)
    {
       if(!lista[i].isEmpty)
       {
          mostrarEmpleado(lista[i]);
          flag=1;
       }
    }
    if(flag==0)
    {
        printf("       No hay empleados para mostrar.\n");
    }
    printf("\n");
}

void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].sexo < lista[j].sexo || (lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre) > 0))
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        lista[i].isEmpty=1;
    }
}

