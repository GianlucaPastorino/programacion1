#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "almuerzo.h"


int altaAlmuerzo(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int legajo;
    int idComida;
    eAlmuerzo nuevoAlmuerzo;

    if(almuerzos != NULL && comidas != NULL && lista != NULL && sectores != NULL && pNextId != NULL && tama > 0 && tamc >0 && tame >0 && tams>0)
    {
        printf("     Alta almuerzos\n");
        indice= buscarLibreAlmuerzo(almuerzos, tama);
        if(indice==-1)
        {
            printf("No hay lugar para mas almuerzos\n\n");
        }
        else
        {
            mostrarEmpleados(lista, tame, sectores, tams);
            printf("Ingrese legajo empleado: ");
            scanf("%d", &legajo);

            while(buscarEmpleado(lista, tame, legajo)==-1)
            {
                printf("No existe un empleado con ese legajo. Reingrese legajo: ");
                scanf("%d", &legajo);
            }
            nuevoAlmuerzo.legEmpleado=legajo;

            mostrarComidas(comidas, tamc);
            printf("Ingrese ID comida: ");
            scanf("%d", &idComida);
            while(!validarIdComida(idComida, comidas, tamc))
            {
               printf("Id invalido. Reingrese ID comida: ");
               scanf("%d", &idComida);
            }
            nuevoAlmuerzo.idComida= idComida;
            printf("Ingrese fecha dd/mm/aaaa:");
            scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia, &nuevoAlmuerzo.fecha.mes, &nuevoAlmuerzo.fecha.anio);

            nuevoAlmuerzo.id = *pNextId;
            (*pNextId)++;
            nuevoAlmuerzo.isEmpty=0;
            almuerzos[indice]= nuevoAlmuerzo;
            todoOk=1;
        }
    }
    return todoOk;
}

void mostrarAlmuerzos(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame)
{
    int flag=0;

    printf("         Listado de Almuerzos\n");
    printf("  Id   Legajo    Nombre   Comida   Fecha\n\n");

    for(int i=0; i<tama; i++)
    {
        if(!almuerzos[i].isEmpty)
        {
            mostrarAlmuerzo(almuerzos[i], comidas, tamc, lista, tame);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("       No hay almuerzos que mostrar.\n");
    }
    printf("\n");
}

void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamc, eEmpleado lista[], int tame)
{
    char nombreEmpleado[20];
    char descComida[20];

    if(cargarNombreEmpleado(unAlmuerzo.legEmpleado, lista, tame, nombreEmpleado) && cargarDescripcionComida(unAlmuerzo.idComida, comidas, tamc, descComida))
    {
        printf("  %d   %d   %10s    %10s     %02d/%02d/%02d\n", unAlmuerzo.id, unAlmuerzo.legEmpleado, nombreEmpleado, descComida, unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio);
    }

}

int buscarLibreAlmuerzo(eAlmuerzo almuerzos[], int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(almuerzos[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        almuerzos[i].isEmpty=1;
    }
}
