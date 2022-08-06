#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicleta.h"
#include "inputs.h"
#include "tipo.h"
#include "color.h"
#include "informes.h"

void mostrarBicicleta(eBicicleta unaBici, eTipo tipos[], eColor colores[], int tamT, int tamC)
{
    char descripcionTipo[20];
    char NombreColor[20];

    if(cargarNombreColor(unaBici.idColor, colores, tamC, NombreColor) && cargarDescripcionTipo(unaBici.idTipo, tipos, tamT, descripcionTipo))
    {
        printf("%d %10s   %.1f %10s %10s\n",
               unaBici.id,
               unaBici.marca,
               unaBici.rodado,
               NombreColor,
               descripcionTipo
              );
    }
}

void mostrarBicicletas(eBicicleta bicis[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamC)
{
    printf("         LISTADO DE BICICLETAS\n");
    printf("ID      Marca   Rodado     Color      Tipo\n");

    for(int i=0; i<tam; i++)
    {
        if(!bicis[i].isEmpty)
        {
            mostrarBicicleta(bicis[i], tipos, colores, tamT, tamC);
        }
    }
    printf("\n");
}

void ordenarBicicletas(eBicicleta bicis[], int tamB, eTipo tipos[], int tamT)
{
    eBicicleta auxBicicleta;
    char descripcionTipoA[20];
    char descripcionTipoB[20];

    for(int i=0; i<tamB-1; i++)
    {
        cargarDescripcionTipo(bicis[i].idTipo, tipos, tamT, descripcionTipoA);
        for(int j=i+1; j<tamB; j++)
        {
            cargarDescripcionTipo(bicis[j].idTipo, tipos, tamT, descripcionTipoB);
            if(strcmp(descripcionTipoA,descripcionTipoB) > 0 || (strcmp(descripcionTipoA,descripcionTipoB) == 0 && bicis[i].rodado > bicis[j].rodado))
            {
                auxBicicleta = bicis[i];
                bicis[i] = bicis[j];
                bicis[j] = auxBicicleta;
            }
        }
    }
}

int menu()
{
    char opcion;

    system("cls");
    printf("**********BICICLETERIA**********\n\n");
    printf("A.	ALTA BICICLETA\n");
    printf("B.	MODIFICAR BICICLETA\n");
    printf("C.	BAJA BICICLETA\n");
    printf("D.	LISTAR BICICLETAS\n");
    printf("E.	LISTAR TIPOS \n");
    printf("F.	LISTAR COLORES\n");
    printf("G.	LISTAR SERVICIOS\n");
    printf("H.	ALTA TRABAJO\n");
    printf("I.	LISTAR TRABAJOS\n");
    printf("J.	INFORMES\n");
    printf("K.	SALIR\n\n");

    printf("Ingrese opcion (A-K): ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}

void inicializarBicicletas(eBicicleta bicicletas[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        bicicletas[i].isEmpty=1;
    }
}

int buscarLibre(eBicicleta bicis[], int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(bicis[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int altaBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int* pId)
{
    int todoOk=0;
    eBicicleta nuevaBicicleta;
    int indice;
    int idTipo;
    int idColor;

    system("cls");
    printf("     ALTA BICICLETA\n\n");


    if(bicicletas!= NULL && tam>0 && pId!=NULL)
    {
        indice = buscarLibre(bicicletas, tam);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            printf("ID Bicicleta: %d\n", *pId);

            validarCadenaCaracteres(nuevaBicicleta.marca, "Ingrese Marca: ", "Error. ", 1, 20);

            mostrarTipos(tipos, tamTipos);
            getNumero(&idTipo, "Ingrese el ID de tipo: ", "Error. ", 1000, 1003);
            nuevaBicicleta.idTipo = idTipo;

            mostrarColores(colores, tamColores);
            getNumero(&idColor, "Ingrese el ID de color: ", "Error. ", 5000, 5004);
            nuevaBicicleta.idColor = idColor;

            getRodado(&nuevaBicicleta.rodado, "Ingrese rodado (20, 26, 27.5 o 29): ", "Error. ");

            nuevaBicicleta.id = *pId;
            nuevaBicicleta.isEmpty = 0;
            (*pId)++;

            bicicletas[indice] = nuevaBicicleta;

            todoOk=1;
        }
    }
    return todoOk;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Tipo\n");
    printf("2. Rodado\n");
    printf("3. Volver al menu de inicio\n");
    printf("\n");
    printf("Ingrese opcion (1-3): ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int buscarBicicleta(eBicicleta bicis[], int tam, int id)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(bicis[i].id == id && !bicis[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int modificarBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int id;
    int indice;
    int salir='n';
    int todoOk = 0;
    eBicicleta aux;

    system("cls");
    printf("          Modificar Bicicleta\n\n");
    mostrarBicicletas(bicicletas, tamB, tipos, colores, tamT, tamC);
    printf("Ingrese el ID de la bicicleta a modificar: ");
    scanf("%d", &id);
    printf("\n");

    indice = buscarBicicleta(bicicletas, tamB, id);

    if(indice == -1)
    {
        printf("El ID indicado no existe.\n\n");
    }
    else
    {
        printf("La bicicleta a modificar es:\n");
        mostrarBicicleta(bicicletas[indice], tipos, colores, tamT, tamC);
        printf("\n");

        if(confirmar() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    mostrarTipos(tipos, tamT);
                    getNumero(&aux.idTipo, "Ingrese el ID del nuevo tipo: ", "Error. ", 1000, 1003);
                    if(confirmar()=='s')
                    {
                        bicicletas[indice].idTipo = aux.idTipo;
                        printf("Tipo modificado con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de tipo cancelada.\n");
                    }
                    break;
                case 2:
                    getRodado(&aux.rodado, "Ingrese nuevo rodado (20, 26, 27.5 o 29): ", "Error. ");
                    if(confirmar()=='s')
                    {
                        bicicletas[indice].rodado=aux.rodado;
                        printf("Rodado modificado con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de rodado cancelada.\n");
                    }
                    break;
                case 3:
                    salir = confirmar();
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                printf("\n");
                system("pause");
                system("cls");
                if(todoOk==1)
                {
                    printf("Asi quedo modificada la bicicleta:\n\n");
                    mostrarBicicleta(bicicletas[indice], tipos, colores, tamT, tamC);
                    printf("\n");
                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

int bajaBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
    int bajaExitosa = 0;
    int id;
    int indice;

    system("cls");
    printf("          Baja bicicleta\n\n");
    mostrarBicicletas(bicicletas, tamB, tipos, colores, tamT, tamC);
    printf("Ingrese el id de la bicicleta a dar de baja: ");
    scanf("%d", &id);
    printf("\n");

    indice = buscarBicicleta(bicicletas, tamB, id);

    if(indice == -1)
    {
        printf("El ID indicado no existe.\n\n");
    }
    else
    {
        printf("La bicicleta a dar de baja es:\n");
        mostrarBicicleta(bicicletas[indice], tipos, colores, tamT, tamC);
        printf("\n");

        if(confirmar() == 's')
        {
            bicicletas[indice].isEmpty = 1;
            bajaExitosa = 1;
        }
        printf("\n");
    }
    return bajaExitosa;
}
