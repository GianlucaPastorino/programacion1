#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

int cargarDescripcionSector(int id, eSector sectores[], int tam, char desc[])
{
    int todoOk = 0;

    if(id>=500 && id<=504 && sectores != NULL && tam>0 && desc != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(sectores[i].id == id)
            {
                strcpy(desc, sectores[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}

void mostrarSectores(eSector sectores[], int tam)
{
    printf("    Lista de sectores\n");
    printf("   ID   Descripcion\n");

    for(int i = 0; i<tam; i++)
    {
        mostrarSector(sectores[i]);
    }
}
void mostrarSector(eSector sector)
{
    printf("   %d    %10s\n", sector.id, sector.descripcion);
}

int buscarSector(int id, eSector sectores[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(sectores[i].id==id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
