#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"

void listarEmpleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int idSector;
    int indice;
    int flag = 0;

    system("cls");
    printf("    Informe de empleados de un sector\n");
    mostrarSectores(sectores, tamS);
    printf("Ingrese ID sector: ");
    scanf("%d", &idSector);
    indice= buscarSector(idSector, sectores, tamS);

    while(indice==-1)
    {
        printf("Id invalido. Ingrese id sector: ");
        scanf("%d", &idSector);
        indice= buscarSector(idSector, sectores, tamS);
    }

    printf("         Listado de Empleados Sector: %s\n", sectores[indice].descripcion);
    printf("Legajo   Nombre  Edad Sexo   Sueldo   F.Ingreso   Sector\n");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==0 && lista[i].idSector == idSector)
        {
            mostrarEmpleado(lista[i], sectores, tamS);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay empleados en el sector %s\n\n", sectores[indice].descripcion);
    }
}

int listarEmpleadosAllSectors(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int todoOk=0;
    int flag;
    system("cls");

    if(lista!= NULL && tam>0 && sectores!= NULL && tamS>0)
    {
        printf("Listado de empleados por sector\n\n");
        for(int i=0; i<tamS; i++)
        {
            flag=1;
            printf("Sector: %s\n\n", sectores[i].descripcion);

            for(int j=0; j<tam; j++)
            {
                if(lista[j].isEmpty==0 && lista[j].idSector == sectores[i].id)
                {
                    mostrarEmpleado(lista[j], sectores, tamS);
                    flag=0;
                    todoOk=1;
                }
            }
            if(flag)
            {
                printf("         No hay empleados en el sector\n");
            }
            printf("\n");
        }
    }
    return todoOk;
}

int totalsueldoSector(eEmpleado lista[], int tam, eSector sectores[], int tamS) //Esta baus la hizo distinta. Era mostrar una, se hacía en base a listarEmpleadosSector
{
    int todoOk=0;
    int flag;
    system("cls");
    float acumuladorSueldos;

    if(lista!= NULL && tam>0 && sectores!= NULL && tamS>0)
    {

        for(int i=0; i<tamS; i++)
        {
            acumuladorSueldos=0;
            flag=1;
            printf("Sector: %s\n", sectores[i].descripcion);

            for(int j=0; j<tam; j++)
            {
                if(lista[j].isEmpty==0 && lista[j].idSector == sectores[i].id)
                {
                    acumuladorSueldos+=lista[j].sueldo;
                    flag=0;
                    todoOk=1;
                }
            }
            if(flag)
            {
                printf("         No hay empleados en el sector\n");
            }
            else
            {
                printf("Total sueldo sector: %.2f", acumuladorSueldos);
            }
            printf("\n\n");
        }
    }
    return todoOk;
}

int totalADepositar(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int todoOk=0;
    system("cls");
    float acumuladorSueldos;
    float acumuladorSueldosTotal=0;

    if(lista!= NULL && tam>0 && sectores!= NULL && tamS>0)
    {

        for(int i=0; i<tamS; i++)
        {
            acumuladorSueldos=0;
            printf("Sector: %s\n", sectores[i].descripcion);

            for(int j=0; j<tam; j++)
            {
                if(lista[j].isEmpty==0 && lista[j].idSector == sectores[i].id)
                {
                    acumuladorSueldos+=lista[j].sueldo;
                    todoOk=1;
                }
            }
            acumuladorSueldosTotal+=acumuladorSueldos;
            printf("Total sueldo sector: %.2f", acumuladorSueldos);
            printf("\n\n");
        }
        printf("Sueldos a depositar: %.2f\n\n", acumuladorSueldosTotal);
    }
    return todoOk;
}

int sectorMayorSueldo(eEmpleado lista[], int tam, eSector sectores[], int tamS)
{
    int todoOk=0;
    system("cls");
    float acumuladorSueldos;
    float totales[tamS];
    float mayor;
    int flag = 0;

    if(lista!= NULL && tam>0 && sectores!= NULL && tamS>0)
    {

        for(int i=0; i<tamS; i++)
        {
            acumuladorSueldos=0;

            for(int j=0; j<tam; j++)
            {
                if(lista[j].isEmpty==0 && lista[j].idSector == sectores[i].id)
                {
                    acumuladorSueldos+=lista[j].sueldo;
                    todoOk=1;
                }
            }
            totales[i]=acumuladorSueldos;
        }
        for (int i =0; i<tamS; i++)
        {
            if(flag==0 || totales[i]>mayor)
            {
                mayor= totales[i];
                flag=1;
            }
        }
        for (int i =0; i<tamS; i++)
        {
            if(mayor==totales[i])
            {
                printf("%s\n", sectores[i].descripcion);
            }
        }
        printf("\n\n");
    }
    return todoOk;
}

void almuerzosEmpleado(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams)
{
    int legajo;
    int flag=1;
    printf("     Informe almuerzos de un empleado\n");
    mostrarEmpleados(lista, tame, sectores, tams);
    printf("Ingrese legajo empleado: ");
    scanf("%d", &legajo);

    while(buscarEmpleado(lista, tame, legajo)==-1)
    {
        printf("No existe un empleado con ese legajo. Reingrese legajo: ");
        scanf("%d", &legajo);
    }

    for(int i=0; i<tama; i++)
    {
        if(almuerzos[i].isEmpty==0 && almuerzos[i].legEmpleado == legajo)
        {
            mostrarAlmuerzo(almuerzos[i], comidas, tamc, lista, tame);
            flag=0;
        }
    }
    if(flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n", legajo);
    }
    printf("\n\n");
}

void totalAlmuerzoEmpleado(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams)
{
    int legajo;
    float total=0;
    int flag=1;
    printf("     Informe total almuerzos de un empleado\n");
    mostrarEmpleados(lista, tame, sectores, tams);
    printf("Ingrese legajo empleado: ");
    scanf("%d", &legajo);

    while(buscarEmpleado(lista, tame, legajo)==-1)
    {
        printf("No existe un empleado con ese legajo. Reingrese legajo: ");
        scanf("%d", &legajo);
    }

    for(int i=0; i<tama; i++)
    {
        if(almuerzos[i].isEmpty==0 && almuerzos[i].legEmpleado == legajo)
        {
            for(int j=0; j<tamc; j++)
            {
                if(comidas[j].id==almuerzos[i].idComida)
                {
                    total+=comidas[j].precio;
                }
            }
            flag=0;
        }
    }
    if(flag)
    {
        printf("El empleado de legajo %d no registra almuerzos.\n", legajo);
    }
    else
    {
        printf("Total almuerzos empleado legajo %d: $%.2f", legajo, total);
    }
    printf("\n\n");
}

void totalAlmuerzosSector(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams)
{
    float total;
    int indice;

    for(int s=0; s<tams; s++)
    {
        total=0;
        for(int e=0; e<tame; e++)
        {
            if(lista[e].isEmpty==0 && lista[e].idSector== sectores[s].id)
            {
                for(int a=0; a<tama; a++)
                {
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legEmpleado == lista[e].legajo)
                    {
                        indice= buscarComida(almuerzos[a].idComida, comidas, tamc);
                        total+= comidas[indice].precio;
                        /*for(int c=0; c<tamc; c++)
                        {
                            if(comidas[c].id==almuerzos[a].idComida)
                            {
                                total+=comidas[c].precio;
                            }
                        }*/
                    }
                }
            }
        }
        printf("Sector %s: $%.2f\n", sectores[s].descripcion, total);
    }
    printf("\n\n");
}

void milanesasXSector(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams)
{
    int totalMilanesas;

    for(int s=0; s<tams; s++)
    {
        totalMilanesas=0;
        for(int e=0; e<tame; e++)
        {
            if(lista[e].isEmpty==0 && lista[e].idSector== sectores[s].id)
            {
                for(int a=0; a<tama; a++)
                {
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legEmpleado == lista[e].legajo)
                    {
                        if(almuerzos[a].idComida==1000)//1000 id milanesa
                        {
                            totalMilanesas++;
                        }
                    }
                }
            }
        }
        printf("Total milanesas comidas por Sector %s: %d\n", sectores[s].descripcion, totalMilanesas);
    }
    printf("\n\n");
}

void sectorAmanteMilanesa(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams)
{

    int contadores[tams];
    int mayor;

    for(int s=0; s<tams; s++)
    {
        contadores[s]=0;
        for(int e=0; e<tame; e++)
        {
            if(lista[e].isEmpty==0 && lista[e].idSector== sectores[s].id)
            {
                for(int a=0; a<tama; a++)
                {
                    if(almuerzos[a].isEmpty==0 && almuerzos[a].legEmpleado == lista[e].legajo)
                    {
                        if(almuerzos[a].idComida==1000)//1000 id milanesa
                        {
                            contadores[s]++;
                        }
                    }
                }
            }
        }
    }

    for(int s=0; s<tams; s++)
    {
        if(s==0 || contadores[s]>mayor)
        {
            mayor=contadores[s];
        }
    }
    printf("Sector/es amantes milanesa: ");
    for(int s=0; s<tams; s++)
    {
        if(contadores[s]== mayor)
        {
            printf("%s ", sectores[s].descripcion);
        }
    }
    printf("\n\n");
}

void listarTotalComidasFecha(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc)
{
    eFecha fecha;
    //int contador;
    int contadores[tamc];

    for(int i=0; i<tamc; i++)
    {
        contadores[i]=0;
    }

    printf("TOTAL CONSUMIDO POR FECHA\n");

    printf("Ingrese fecha dd/mm/aaaa: ");
    fflush(stdin);
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio); // validar

    /*for(int c=0; c<tamc; c++)
    {
        contador=0;
        for(int a=0; a<tama; a++)
        {
            if(almuerzos[a].isEmpty==0 && comparaFechas(fecha, almuerzos[a].fecha) && comidas[c].id== almuerzos[a].idComida)
            {
                contador++;
            }
        }
        printf("%s: %d\n", comidas[c].descripcion, contador);
    }
    printf("\n\n");*/

    for(int a =0; a<tama; a++)
    {
        if(almuerzos[a].isEmpty==0 && comparaFechas(almuerzos[a].fecha, fecha))
        {
            contadores[buscarComida(almuerzos[a].idComida, comidas, tamc)]++;
        }
    }
    for(int c=0; c<tamc; c++)
    {
        printf("%s: %d\n", comidas[c].descripcion, contadores[c]);
    }
}

void ingresoPorComidas(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc)
{
    int contador;

    printf("Ingresos por cada comida\n");
    for(int c=0; c<tamc; c++)
    {
        contador=0;
        for(int a=0; a<tama; a++)
        {
            if(almuerzos[a].isEmpty==0 && comidas[c].id== almuerzos[a].idComida)
            {
                contador++;
            }
        }
        printf("%s: %.2f\n", comidas[c].descripcion, contador * comidas[c].precio);
    }
    printf("\n\n");
}
