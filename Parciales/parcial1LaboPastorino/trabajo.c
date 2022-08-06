#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "color.h"
#include "fecha.h"
#include "tipo.h"
#include "servicio.h"
#include "bicicleta.h"
#include "inputs.h"

int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicis[], int tamB, eServicio servicios[], int tamS, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, int* pNextId)
{
    int todoOk = 0;
    int indice;
    int idBici;
    int idServicio;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && bicis != NULL && servicios != NULL && tipos != NULL && colores != NULL && pNextId != NULL && tamB>0 && tamColores>0 && tamS>0 && tamTipo>0 && tamTra>0)
    {
        printf("            ALTA TRABAJO\n\n");
        indice= buscarLibreTrabajos(trabajos, tamTra);
        if(indice==-1)
        {
            printf("No hay lugar para mas trabajos\n\n");
        }
        else
        {
            mostrarBicicletas(bicis, tamB, tipos, colores, tamTipo, tamColores);
            printf("Ingrese ID bicicleta: ");
            fflush(stdin);
            scanf("%d", &idBici);

            while(buscarBicicleta(bicis, tamB, idBici)==-1)
            {
                printf("No existe una bicicleta con ese ID. Reingrese ID: ");
                fflush(stdin);
                scanf("%d", &idBici);
            }
            printf("\n");
            nuevoTrabajo.idBicicleta=idBici;

            mostrarServicios(servicios, tamS);
            printf("\n");
            getNumero(&idServicio, "Ingrese ID servicio: ", "Error. ", 20000, 20003);

            nuevoTrabajo.idServicio= idServicio;

            printf("Ingrese fecha dd/mm/aaaa:");
            fflush(stdin);
            scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            while(!validarFecha(nuevoTrabajo.fecha.dia, nuevoTrabajo.fecha.mes, nuevoTrabajo.fecha.anio))
            {
                printf("Error. Ingrese fecha dd/mm/aaaa:");
                fflush(stdin);
                scanf("%d/%d/%d", &nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);
            }

            nuevoTrabajo.id = *pNextId;
            (*pNextId)++;
            nuevoTrabajo.isEmpty=0;
            trabajos[indice]= nuevoTrabajo;
            todoOk=1;
        }
    }
    return todoOk;
}

int buscarLibreTrabajos(eTrabajo trabajos[], int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(trabajos[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarTrabajos(eTrabajo trabajos[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        trabajos[i].isEmpty=1;
    }
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS)
{
        char descripcionServicio[20];
        if(cargarDescripcionServicio(trabajo.idServicio, servicios, tamS, descripcionServicio))
        {
            printf("  %d      %d  %10s   %02d/%02d/%02d\n", trabajo.id, trabajo.idBicicleta, descripcionServicio, trabajo.fecha.dia, trabajo.fecha.mes, trabajo.fecha.anio);
        }
}

void mostrarTrabajos(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS)
{
    printf("            LISTADO DE TRABAJOS\n");
    printf("Id Trab  Id Bici  Servicio     Fecha\n");

    for(int i=0; i<tamTra; i++)
    {
        if(!trabajos[i].isEmpty)
        {
            mostrarTrabajo(trabajos[i], servicios, tamS);
        }
    }
    printf("\n");
}



