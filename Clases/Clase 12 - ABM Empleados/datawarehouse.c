#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

char nombres[10][20] = {
    "Donato",
    "Carmen",
    "Chepi",
    "Alex",
    "German",
    "Maria",
    "Damian",
    "Daniel",
    "Andrea",
    "Candela"
};

char sexos[10] = {'m', 'f', 'f', 'm', 'm', 'f', 'm', 'm', 'f', 'f'};

int edades[10] = {56, 71, 39, 30, 52, 45, 44, 58, 38, 29};

float sueldos[10] = {10000, 12000, 11000, 13200, 11500, 10800, 13900, 12100, 11500, 12400};

eFecha fechas[10] = {
    {4,3,2011},
    {26,4,2019},
    {30,8,2010},
    {10,11,2000},
    {15,7,2014},
    {25,12,2005},
    {18,1,2016},
    {21,2,2008},
    {7,9,2020},
    {3,5,2021}
    };

    eFecha fechas2[] = {
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
    };

int legajos[] = {20000, 20006, 20001, 20005, 20007, 20002, 20000, 20004, 20001, 20003, 20008, 20001, 20006, 20003, 20004, 20008, 20005, 20000, 20005, 20003, 20007, 20009, 20004};

int idComidas[] = {1000, 1003, 1002, 1000, 1000, 1004, 1002, 1001, 1004, 1003, 1003, 1004, 1000, 1002, 1004, 1004, 1001, 1001, 1000, 1001, 1002, 1002, 1000};

int idSectores[10] = {500, 504, 502, 502, 501, 500, 503, 502, 500, 504};

int hardcodearEmpleados(eEmpleado lista[], int tam, int cant, int* pLegajo)
{
    int cantidad = 0;

    if(lista!= NULL && tam > 0 && cant >= 0 && cant <= tam && pLegajo != NULL)
    {
         for(int i=0; i < cant; i++)
         {
             lista[i].legajo = *pLegajo;
             (*pLegajo)++;
             strcpy(lista[i].nombre, nombres[i]);
             lista[i].edad = edades[i];
             lista[i].sexo = sexos[i];
             lista[i].sueldo = sueldos[i];
             lista[i].fIngreso = fechas[i];
             lista[i].idSector = idSectores[i];
             lista[i].isEmpty = 0;
             cantidad++;
         }
    }

    return cantidad;
}

int hardcodearAlmuerzos(eAlmuerzo almuerzos[], int tam, int cant, int* pId)
{
   int cantidad = 0;

    if(almuerzos!= NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
         for(int i=0; i < cant; i++)
         {
             almuerzos[i].id = *pId;
             (*pId)++;
             almuerzos[i].legEmpleado = legajos[i];
             almuerzos[i].idComida = idComidas[i];
             almuerzos[i].fecha = fechas2[i];
             almuerzos[i].isEmpty = 0;
             cantidad++;
         }
    }

    return cantidad;
}
