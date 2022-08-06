#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"


void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descripcion[20];

    if(cargarDescripcionSector(unEmpleado.idSector, sectores, tam, descripcion))
    {
        printf("%d %10s   %d   %c  %9.2f %02d/%02d/%d   %s\n",
           unEmpleado.legajo,
           unEmpleado.nombre,
           unEmpleado.edad,
           unEmpleado.sexo,
           unEmpleado.sueldo,
           unEmpleado.fIngreso.dia,
           unEmpleado.fIngreso.mes,
           unEmpleado.fIngreso.anio,
           descripcion
           );
    }
}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int flag=0;

    printf("         Listado de Empleados\n");
    printf("Legajo   Nombre  Edad Sexo   Sueldo   F.Ingreso   Sector\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarEmpleado(lista[i], sectores, tamSec);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("       No hay empleados para mostrar.\n");
    }
    printf("\n");
}

void ordenarEmpleados(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].sexo < lista[j].sexo || (lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre,lista[j].nombre) > 0))
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }
        }
    }
}

void inicializarEmpleados(eEmpleado lista[], int tam)
{
    for(int i = 0; i<tam; i++)
    {
        lista[i].isEmpty=1;
    }
}

int menu()
{
    int opcion;

    system ("cls");
    printf("**********ABM EMPLEADOS**********\n\n");
    printf("1. Alta empleado\n");
    printf("2. Baja empleado\n");
    printf("3. Modificar empleado\n");
    printf("4. Listar empleados\n");
    printf("5. Ordenar empleados\n");
    printf("6. Listar sectores\n");
    printf("7. Listar comidas\n");
    printf("8. Listar almuerzos\n");
    printf("9. Alta almuerzo\n");
    printf("10. Almuerzos empleado\n");
    printf("11. Informes\n");
    printf("12. Filtrar empleados sector\n");
    printf("13. Mostrar empleados de todos los sectores\n");
    printf("14. Total de sueldos de un sector\n"); // Acá la cagué e hice de todos los sectores.
    printf("15. Totales sueldos\n");
    printf("16. Sector/es que mas ganan\n");
    printf("17. Total a pagar almuerzos empleado\n");
    printf("18. Total a pagar almuerzos sectores\n");
    printf("19. Total milanesas por sector\n");
    printf("20. Sector amante de las milanesas\n");
    printf("21. Total comidas por fecha\n");
    printf("22. Ingreso por comidas\n");
    printf("30. Salir\n\n");

    printf("Ingrese opcion (1-7): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo)
{
    int todoOk=0;
    eEmpleado nuevoEmpleado;
    int indice;
    int idSector;

    system("cls");
    printf("     Alta empleado\n\n");
    printf("Legajo: %d\n", *pLegajo);

    if(lista!= NULL && tam>0 && pLegajo!=NULL)
    {
        indice = buscarLibre(lista, tam);

        if(indice==-1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else // Todos los datos que pido a continuación, tengo que validarlos. No están validados acá.
        {

            validarCadenaCaracteres(nuevoEmpleado.nombre, "Ingrese nombre: ", "Error. ", 1, 20);
            /*printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);*/

            /*printf("Ingrese edad: ");
            fflush(stdin);
            scanf("%d", &nuevoEmpleado.edad);*/
            getNumero(&nuevoEmpleado.edad, "Ingrese edad: ", "Error. ", 18, 100);

            /*printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);*/
            validarSexo(&nuevoEmpleado.sexo, "Ingrese sexo (m o f): ", "Error. ");

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
            fflush(stdin);
            scanf("%d/%d/%d", &nuevoEmpleado.fIngreso.dia, &nuevoEmpleado.fIngreso.mes, &nuevoEmpleado.fIngreso.anio);

            mostrarSectores(sectores, tamSec);
            /*printf("Ingrese el id del sector: ");
            fflush(stdin);
            scanf("%d", &idSector);*/
            //validar
            getNumero(&idSector, "Ingrese el id del sector: ", "Error. ", 500, 504);

            nuevoEmpleado.idSector = idSector;

            nuevoEmpleado.legajo = *pLegajo;
            nuevoEmpleado.isEmpty = 0;
            (*pLegajo)++; // *pLegajo = *pLegajo + 1;

            lista[indice] = nuevoEmpleado;

            todoOk=1;
        }
    }

    return todoOk;
}

int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(lista[i].legajo == legajo && !lista[i].isEmpty)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int bajaExitosa = 0;
    int legajo;
    int indice;

    system("cls");
    printf("          Baja empleado\n\n");
    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("Ingrese el legajo del empleado a dar de baja: ");
    scanf("%d", &legajo);
    printf("\n");

    indice = buscarEmpleado(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El legajo indicado no existe.\n\n");
    }
    else
    {
        printf("El empleado a dar de baja es:\n");
        mostrarEmpleado(lista[indice], sectores, tamSec);
        printf("\n");

        if(confirmar() == 's')
        {
            lista[indice].isEmpty = 1;
            bajaExitosa = 1;
        }
        printf("\n");
    }

    return bajaExitosa;
}

int menuModificar()
{
    int opcion;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Nombre\n");
    printf("2. Edad\n");
    printf("3. Sexo\n");
    printf("4. Sueldo\n");
    printf("5. Fecha de ingreso\n");
    printf("6. Volver al menu de inicio\n");
    printf("\n");
    printf("Ingrese opcion (1-6): ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");

    return opcion;
}

int modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec)
{
    int legajo;
    int indice;
    int salir='n';
    int todoOk = 0;
    eEmpleado aux;

    system("cls");
    printf("          Modificar empleado\n\n");
    mostrarEmpleados(lista, tam, sectores, tamSec);
    printf("Ingrese el legajo del empleado a modificar: ");
    scanf("%d", &legajo);
    printf("\n");

    indice = buscarEmpleado(lista, tam, legajo);

    if(indice == -1)
    {
        printf("El legajo indicado no existe.\n\n");
    }
    else
    {
        printf("El empleado a modificar es:\n");
        mostrarEmpleado(lista[indice], sectores, tamSec);
        printf("\n");

        if(confirmar() == 's')
        {
            do
            {
                switch(menuModificar())
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(aux.nombre);
                    if(confirmar()=='s')
                    {
                        strcpy(lista[indice].nombre,aux.nombre);
                        printf("Nombre modificado con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de nombre cancelada.\n");
                    }
                    break;
                case 2:
                    printf("Ingrese nueva edad: ");
                    fflush(stdin);
                    scanf("%d", &aux.edad);
                    if(confirmar()=='s')
                    {
                        lista[indice].edad=aux.edad;
                        printf("Edad modificada con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de edad cancelada.\n");
                    }

                    break;
                case 3:
                    printf("Ingrese nuevo sexo: ");
                    fflush(stdin);
                    scanf("%c", &aux.sexo);
                    if(confirmar()=='s')
                    {
                        lista[indice].sexo=aux.sexo;
                        printf("Sexo modificado con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de sexo cancelada.\n");
                    }
                    break;
                case 4:
                    printf("Ingrese nuevo sueldo: ");
                    fflush(stdin);
                    scanf("%f", &aux.sueldo);
                    if(confirmar()=='s')
                    {
                        lista[indice].sueldo=aux.sueldo;
                        printf("Sueldo modificado con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de sueldo cancelada.\n");
                    }
                    break;
                case 5:
                    printf("Ingrese nueva fecha de ingreso dd/mm/aaaa: ");
                    fflush(stdin);
                    scanf("%d/%d/%d", &aux.fIngreso.dia, &aux.fIngreso.mes, &aux.fIngreso.anio);
                    if(confirmar()=='s')
                    {
                        lista[indice].fIngreso=aux.fIngreso;
                        printf("Fecha de ingreso modificada con exito.\n");
                        todoOk = 1;
                    }
                    else
                    {
                        printf("Modificacion de fecha de ingreso cancelada.\n");
                    }
                    break;
                case 6:
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
                    printf("Asi quedo modificado el empleado:\n\n");
                    mostrarEmpleado(lista[indice], sectores, tamSec);
                    printf("\n");
                }
            }
            while(salir == 'n');
        }
    }
    return todoOk;
}

char confirmar()
{
    char respuesta;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}

int cargarNombreEmpleado(int legajo, eEmpleado lista[], int tam, char nombre[])
{
    int todoOk = 0;
    int indice;

    if(lista != NULL && tam>0 && nombre != NULL )
    {
        indice=buscarEmpleado(lista, tam, legajo);
        if(indice!=-1)
        {
                strcpy(nombre, lista[indice].nombre);
                todoOk=1;
        }
    }
    return todoOk;
}
