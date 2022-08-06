#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bicicleta.h"
#include "inputs.h"
#include "trabajo.h"
#include "servicio.h"
#include "fecha.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("**********INFORMES**********\n\n");
    printf("1. Mostrar bicicletas de un color\n");
    printf("2. Mostrar bicicletas de un tipo\n");
    printf("3. Informar la o las bicicletas de menor rodado\n");
    printf("4. Mostrar un listado de las bicicletas separadas por tipo\n");
    printf("5. Contar cuantas bicicletas hay de un color y un tipo determinado\n");
    printf("6. Mostrar el o los colores mas elegidos por los clientes\n");
    printf("7. Mostrar todos los trabajos que se le hicieron a una bicicleta en particular\n");
    printf("8. Informar la suma de los importes de los servicios que se le hicieron a una bicicleta\n");
    printf("9. Mostrar las bicicletas a las que se les realizo un determinado servicio y la fecha\n");
    printf("10. Mostrar todos los servicios realizados en una fecha determinada\n");
    printf("11. Volver al menu inicial\n\n");

    printf("Ingrese opcion (1-11): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void listarBicicletasColor(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int idColor;
    int indice=-1;
    int flag = 0;

    system("cls");
    printf("    Informe de bicicleta de un color\n");
    mostrarColores(colores, tamC);
    getNumero(&idColor, "Ingrese ID color: ", "Error. ", 5000, 5004);

    for(int i=0; i<tamC; i++)
    {
        if(colores[i].id==idColor)
        {
            indice = i;
            break;
        }
    }

    printf("\n");
    printf("         Listado de bicicletas color: %s\n", colores[indice].nombreColor);


    for(int i=0; i<tamB; i++)
    {
        if(bicis[i].isEmpty==0 && bicis[i].idColor == idColor)
        {
            printf("ID      Marca   Rodado     Color      Tipo\n");
            mostrarBicicleta(bicis[i], tipos, colores, tamT, tamC);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay bicicletas de color %s\n\n", colores[indice].nombreColor);
    }
}

void listarBicicletasTipo(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int idTipo;
    int indice=-1;
    int flag = 0;

    system("cls");
    printf("Informe de bicicleta de un tipo\n\n");
    mostrarTipos(tipos, tamT);
    getNumero(&idTipo, "Ingrese ID tipo: ", "Error. ", 1000, 1003);

    for(int i=0; i<tamT; i++)
    {
        if(tipos[i].id==idTipo)
        {
            indice = i;
            break;
        }
    }

    printf("\n");
    printf("         Listado de bicicletas tipo: %s\n", tipos[indice].descripcion);


    for(int i=0; i<tamB; i++)
    {
        if(bicis[i].isEmpty==0 && bicis[i].idTipo == idTipo)
        {
            printf("ID      Marca   Rodado     Color      Tipo\n");
            mostrarBicicleta(bicis[i], tipos, colores, tamT, tamC);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay bicicletas de tipo %s\n\n", tipos[indice].descripcion);
    }
}

void bicicletaMenorRodado(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    system("cls");
    float menor;
    int flag=0;

    for(int i=0; i<tamB; i++)
    {
        if(bicis[i].isEmpty==0)
        {
            if(flag==0 || bicis[i].rodado<menor)
            {
                menor= bicis[i].rodado;
                flag=1;
            }
        }
    }
    printf("Bicicleta/s de menor rodado: \n\n");
    printf("ID      Marca   Rodado     Color      Tipo\n");
    for (int i =0; i<tamB; i++)
    {
        if(menor==bicis[i].rodado)
        {
            mostrarBicicleta(bicis[i], tipos, colores, tamT, tamC);
        }
    }
    printf("\n\n");
}

void listarBicicletasPorTipos(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int flag;
    system("cls");

    printf("Listado de bicicletas por tipo\n\n");
    for(int i=0; i<tamT; i++)
    {
        flag=1;
        printf("Tipo: %s\n\n", tipos[i].descripcion);
        printf("ID      Marca   Rodado     Color      Tipo\n");
        for(int j=0; j<tamB; j++)
        {
            if(bicis[j].isEmpty==0 && bicis[j].idTipo == tipos[i].id)
            {
                mostrarBicicleta(bicis[j], tipos, colores, tamT, tamC);
                flag=0;
            }
        }
        if(flag)
        {
            printf("No hay bicicletas de este tipo.\n");
        }
        printf("\n");
    }
}

void contarColorYTipo(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
    int idColor;
    int idTipo;
    int contador=0;

    system("cls");
    printf("    Contador bicicletas de mismo color y tipo\n");
    mostrarColores(colores, tamC);
    getNumero(&idColor, "Ingrese ID color: ", "Error. ", 5000, 5004);

    printf("\n");
    mostrarTipos(tipos, tamT);
    getNumero(&idTipo, "Ingrese ID de tipo: ", "Error. ", 1000, 1003);

    for(int i=0; i<tamB; i++)
    {
        if(bicis[i].idColor==idColor && bicis[i].idTipo==idTipo)
        {
            contador++;
        }
    }

    printf("\n");
    printf("Cantidad de bicicletas del tipo y color seleccionado: %d.\n\n", contador);
}

void colorMasElegido(eBicicleta bicis[], int tamB, eColor colores[], int tamC)
{
    system("cls");
    int acumuladorColores;
    int totales[tamC];
    int mayor;
    int flag=0;

    for(int i=0; i<tamC; i++)
    {
        acumuladorColores=0;

        for(int j=0; j<tamB; j++)
        {
            if(bicis[j].isEmpty==0 && bicis[j].idColor == colores[i].id)
            {
                acumuladorColores++;
            }
        }
        totales[i]=acumuladorColores;
    }
    for (int i =0; i<tamC; i++)
    {
        if(flag==0 || totales[i]>mayor)
        {
            mayor= totales[i];
            flag=1;
        }
    }
    printf("El/Los colores mas elegidos por los clientes es/son: ");
    for (int i =0; i<tamC; i++)
    {
        if(mayor==totales[i])
        {
            printf("%s ", colores[i].nombreColor);
        }
    }
    printf("\n\n");
}

void trabajosABici(eBicicleta bicis[], int tamB, eTrabajo trabajos[], int tamTra, eColor colores[], int tamC, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer)
{
    system("cls");
    int idBici;
    int flag=0;

    printf("   Trabajos hechos a una bicicleta\n\n");

    mostrarBicicletas(bicis, tamB, tipos, colores, tamTip, tamC);
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

    printf("Id Trab  Id Bici  Servicio     Fecha\n");
    for(int i=0; i<tamTra; i++)
    {
        if(bicis[buscarBicicleta(bicis, tamB, idBici)].id==trabajos[i].idBicicleta && trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamSer);
            flag=1;
        }
    }
    if(!flag)
    {
        printf("No se le han realizado trabajos a esta bicicleta.\n\n");
    }
}

void sumaImporteServiciosUnaBici(eBicicleta bicis[], int tamB, eTrabajo trabajos[], int tamTra, eColor colores[], int tamC, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer)
{
    system("cls");
    int idBici;
    float acumulador=0;


    printf("   Suma importes servicios realizados a una bicicleta\n\n");

    mostrarBicicletas(bicis, tamB, tipos, colores, tamTip, tamC);
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


    for(int i=0; i<tamTra; i++)
    {
        if(bicis[buscarBicicleta(bicis, tamB, idBici)].id==trabajos[i].idBicicleta && trabajos[i].isEmpty==0)
        {
            for(int j=0; j<tamSer; j++)
            {
                if(trabajos[i].idServicio==servicios[j].id)
                {
                    acumulador+=servicios[j].precio;
                }
            }
        }
    }
    printf("La suma de los importes de los servicios realizados a esta bicicleta es de: $%.2f\n\n", acumulador);
}

void servicioHechoABicis(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    system("cls");

    int idServicio;
    int flag=0;
    printf("   Servicio realizado a bicicletas\n\n");

    mostrarServicios(servicios, tamSer);
    getNumero(&idServicio, "Ingrese ID servicio: ", "Error. ", 20000, 20003);

    printf("\n");
    printf("Id Trab  Id Bici  Servicio     Fecha\n");
    for(int t=0; t<tamTra; t++)
    {
        if(trabajos[t].isEmpty==0 && trabajos[t].idServicio==idServicio)
        {
            mostrarTrabajo(trabajos[t], servicios, tamSer);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No se encontraron bicicletas a las cuales se le haya realizado el servicio seleccionado.\n\n");
    }
}

void mostrarServiciosEnFechaX(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    system("cls");
    eFecha fecha;
    int flag=0;

    printf("    Servicios realizados en una fecha\n\n");

    printf("Ingrese fecha dd/mm/aaaa: ");
    fflush(stdin);
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    if(!validarFecha(fecha.dia, fecha.mes, fecha.anio))
    {
        printf("Error. Ingrese fecha dd/mm/aaaa: ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
    }
    printf("\n");
    printf("Id Trab  Id Bici  Servicio     Fecha\n");

    for(int t =0; t<tamTra; t++)
    {
        if(trabajos[t].isEmpty==0 && comparaFechas(trabajos[t].fecha, fecha))
        {
            mostrarTrabajo(trabajos[t], servicios, tamSer);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("No se realizo ningun servicio en la fecha indicada.\n\n");
    }
}
