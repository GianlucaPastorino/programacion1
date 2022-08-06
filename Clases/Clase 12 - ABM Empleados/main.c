#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comida.h"
#include "almuerzo.h"
#include "datawarehouse.h"

#define TAM 15
#define TAMSEC 5
#define TAMC 5
#define TAMA 50

int main()
{
    int nextLegajo = 20000;
    int nextIdAlmuerzo = 50000;
    eSector sectores[TAMSEC] = {{500, "Sistemas"}, {501, "Legales"}, {502, "RRHH"}, {503, "Contable"}, {504, "Ventas"},};
    eComida comidas[TAMC] = {{1000, "Milanesa", 150}, {1001, "Ensalada", 190}, {1002, "Fideos", 140}, {1003, "Pizza", 120}, {1004, "Sopa", 110}};
    eAlmuerzo almuerzos[TAMA];
    eEmpleado nomina[TAM];
    inicializarEmpleados(nomina, TAM);
    inicializarAlmuerzos(almuerzos, TAMA);

    hardcodearEmpleados(nomina, TAM, 10, &nextLegajo);
    hardcodearAlmuerzos(almuerzos, TAMA, 23, &nextIdAlmuerzo);

    char salir = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            if(altaEmpleado(nomina, TAM, sectores, TAMSEC, &nextLegajo))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;
        case 2:
            if(bajaEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("Baja exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar la baja.\n\n");
            }
            break;
        case 3:
            if(modificarEmpleado(nomina, TAM, sectores, TAMSEC))
            {
                printf("Modificacion exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar la modificacion.\n\n");
            }
            break;
        case 4:
            system("cls");
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);

            break;
        case 5:
            ordenarEmpleados(nomina, TAM);
            mostrarEmpleados(nomina, TAM, sectores, TAMSEC);
            break;
        case 6:
            system("cls");
            mostrarSectores(sectores, TAMSEC);
            break;
        case 7:
            system("cls");
            mostrarComidas(comidas, TAMC);
            break;
        case 8:
            system("cls");
            mostrarAlmuerzos(almuerzos, TAMA, comidas, TAMC, nomina, TAM);
            break;
        case 9:
            if(altaAlmuerzo(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC, &nextIdAlmuerzo))
            {
                printf("Alta exitosa!\n\n");
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;
        case 10:
            system("cls");
            almuerzosEmpleado(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC);
            break;
        case 11:
            //Informes
            break;
        case 12:
            listarEmpleadosSector(nomina, TAM, sectores, TAMSEC);
            break;
        case 13:
            listarEmpleadosAllSectors(nomina, TAM, sectores, TAMSEC);
            break;
        case 14:
            totalsueldoSector(nomina, TAM, sectores, TAMSEC);
            break;
        case 15:
            totalADepositar(nomina, TAM, sectores, TAMSEC);
            break;
        case 16:
            sectorMayorSueldo(nomina, TAM, sectores, TAMSEC);
            break;
         case 17:
            system("cls");
            totalAlmuerzoEmpleado(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC);
            break;
        case 18:
            system("cls");
            totalAlmuerzosSector(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC);
            break;
        case 19:
            system("cls");
            milanesasXSector(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC);
            break;
        case 20:
            system("cls");
            sectorAmanteMilanesa(almuerzos, TAMA, comidas, TAMC, nomina, TAM, sectores, TAMSEC);
            break;
        case 21:
            system("cls");
            listarTotalComidasFecha(almuerzos, TAMA, comidas, TAMC);
            break;
        case 22:
            system("cls");
            ingresoPorComidas(almuerzos, TAMA, comidas, TAMC);
            break;
        case 30:
            salir = confirmar();
            break;
        default:
            printf("Opcion invalida!\n");
            break;
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

