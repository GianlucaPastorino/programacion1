#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicios(eServicio servicios[], int tamS)
{
    printf("    LISTA DE SERVICIOS\n");
    printf(" ID   Descripcion  Precio\n");

    for(int i = 0; i<tamS; i++)
    {
        mostrarServicio(servicios[i]);
    }
}

void mostrarServicio(eServicio servicio)
{
    printf("%d %10s   %.2f\n", servicio.id, servicio.descripcion, servicio.precio);
}

int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[])
{
     int todoOk = 0;

    if(id>=20000 && id<=20003 && servicios != NULL && tam>0 && desc != NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(servicios[i].id == id)
            {
                strcpy(desc, servicios[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}
