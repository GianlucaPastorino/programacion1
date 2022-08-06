#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "inputs.h"
#include "controller.h"
#include "informes.h"

int main()
{
    srand(time(NULL));
    char nombreArchivo[100];
    int tipoBici;
    char salir = 'n';
    int flag = 0;
    int flag2 = 0;

    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaMapBicicletas = NULL;
    LinkedList* listaBicicletasTipo = NULL;
    if(listaBicicletas == NULL)
    {
        printf("Error al crear la lista.\n\n");
        exit(1);
    }

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese el nombre del archivo (archivo.csv): ");
            fflush(stdin);
            gets(nombreArchivo);
            if(controller_loadFromText(nombreArchivo, listaBicicletas))
            {
                printf("Archivo cargado correctamente.\n\n");
            }
            else
            {
                printf("Error al cargar el archivo.\n\n");
            }
            system("pause");
            break;
        case 2:
            if(ll_len(listaBicicletas)>0)
            {
                system("cls");
                controller_ListBicicletas(listaBicicletas);
            }
            else
            {
                printf("No ha cargado el archivo o la lista se encuentra vacia.\n\n");
            }
            system("pause");
            break;
        case 3:
            if(ll_len(listaBicicletas)>0)
            {
                listaMapBicicletas = ll_map(listaBicicletas, bicicleta_map);
                if(listaMapBicicletas != NULL)
                {
                    ll_clear(listaBicicletas);
                    listaBicicletas = listaMapBicicletas;
                    flag = 1;
                    printf("Tiempo asignado correctamente.\n\n");
                }
                else
                {
                    printf("Error al asignar el tiempo.\n\n");
                }
            }
            else
            {
                printf("No ha cargado el archivo o la lista se encuentra vacia.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(flag)
            {
                getInt(&tipoBici, "Ingrese tipo (1 para bmx, 2 para playera, 3 para mtb o 4 para paseo): ", "Error. ", 1, 4);
                switch(tipoBici)
                {
                case 1:
                    listaBicicletasTipo = ll_filter(listaBicicletas, filterTipoBmx);
                    break;
                case 2:
                    listaBicicletasTipo = ll_filter(listaBicicletas, filterTipoPlayera);
                    break;
                case 3:
                    listaBicicletasTipo = ll_filter(listaBicicletas, filterTipoMtb);
                    break;
                case 4:
                    listaBicicletasTipo = ll_filter(listaBicicletas, filterTipoPaseo);
                    break;
                default:
                    printf("Error. No ha indicado ningun tipo de bicileta existente.\n\n");
                    break;
                }
                if(listaBicicletasTipo != NULL)
                {
                    system("cls");
                    controller_ListBicicletas(listaBicicletasTipo);
                    if(controller_saveAsText("bicicletasTipoSeleccionado.csv", listaBicicletasTipo))
                    {
                        printf("Archivo guardado con exito.\n\n");
                    }
                    else
                    {
                        printf("Error al guardar el archivo.\n\n");
                    }
                }
            }
            else
            {
                printf("Primero debe cargar el archivo y asignar tiempos.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(flag)
            {
                system("cls");
                ll_sort(listaBicicletas, bicicleta_sort, 1);
                controller_ListBicicletas(listaBicicletas);
                flag2 = 1;
            }
            else
            {
                 printf("Primero debe cargar el archivo y asignar tiempos.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(flag2)
            {
                if(controller_saveAsText("PosicionesBicicletas.csv", listaBicicletas))
                {
                    printf("Archivo guardado con exito.\n\n");
                }
                else
                {
                    printf("Error al guardar el archivo.\n\n");
                }
            }
            else
            {
                printf("Error. Antes de guardar, debe ordenar la lista por posiciones.\n\n");
            }
            system("pause");
            break;
        case 7:
            salir = confirm();
            break;
        default:
            printf("Error. Opcion invalida.\n\n");
            system("pause");
            break;
        }
    }
    while(salir == 'n');

    return 0;
}
