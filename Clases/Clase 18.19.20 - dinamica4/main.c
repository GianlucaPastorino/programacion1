#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "LinkedList.h"

int main()
{
    int nextId = 1;
    char path[50];
    char confirma = 's';
    FILE* f = NULL;
    eEmpleado* auxEmp;
    LinkedList* lista = ll_newLinkedList();

    auxEmp = newEmpleadoParam(nextId, "Jose", 'm', 45000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    auxEmp = newEmpleadoParam(nextId, "Carmen", 'f', 48000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    auxEmp = newEmpleadoParam(nextId, "Miguel", 'm', 49000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

     auxEmp = newEmpleadoParam(nextId, "Andrea", 'f', 47000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

     auxEmp = newEmpleadoParam(nextId, "Luis", 'm', 39000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    mostrarEmpleados(lista);

    ll_sort(lista, empleadoCmpNombre, 1);
     mostrarEmpleados(lista);

   // ll_sort(lista, empleadoCmpSexo, 1);

/*
    auxEmp = newEmpleadoParam(nextId, "Jose", 'm', 45000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    auxEmp = newEmpleadoParam(nextId, "Carmen", 'f', 48000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    auxEmp = newEmpleadoParam(nextId, "Miguel", 'm', 49000);
    if(!ll_add(lista, auxEmp))
    {
        nextId++;
    }

    mostrarEmpleados(lista);

    printf("Ingrese path: ");
    fflush(stdin);
    gets(path);
    f = fopen(path, "rb");
    if(f != NULL)
    {
        printf("Cuidado, el archivo existe y se va a sobrescribir. Confirma?\n");
        fflush(stdin);
        scanf("%c", &confirma);
    }
    fclose(f);

    if(confirma == 's')
    {
        f = fopen(path, "wb");
        if( f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            for(int i = 0; i<ll_len(lista); i++)
            {
                auxEmp = (eEmpleado*) ll_get(lista, i);

                fwrite(auxEmp, sizeof(eEmpleado), 1, f);
            }
        }
        fclose(f);
    }
*/
/*
        printf("Ingrese path: ");
        fflush(stdin);
        gets(path);
        f = fopen(path, "rb");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo.\n");
        }
        else
        {
            if(ll_len(lista) > 0)
            {
                printf("Cuidado se van a sobrescribir los empleados! s para confirmar\n");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(ll_len(lista) == 0 || confirma == 's')
            {
                ll_clear(lista);
                while(!feof(f))
                {
                    auxEmp = newEmpleado();
                    if(auxEmp != NULL)
                    {
                        if(fread(auxEmp, sizeof(eEmpleado), 1, f) < 1)
                        {
                            break;
                        }
                        ll_add(lista, auxEmp);
                    }
                }
            }
        }
        fclose(f);

        buscarMayorId(lista, &nextId);

        mostrarEmpleados(lista);

        printf("nextId: %d", nextId);

*/

//    eEmpleado* auxEmpleado;
//    char nombre[20];
//
//    if(lista == NULL)
//    {
//        printf("No se pudo crear el linkedlist\n");
//        exit(1);
//    }
//
//    auxEmpleado = newEmpleadoParam(1234, "Juan", 'm', 200);
//
//    /*auxEmpleado = newEmpleado();
//    printf("Ingrese nombre: ");
//    fflush(stdin);
//    gets(nombre);
//
//    empleadoGetNombre(auxEmpleado, nombre);*/
//
//    printf("tam: %d\n", ll_len(lista));
//
//    printf("Agrego un empleado\n");
//    ll_add(lista, auxEmpleado);
//
//    printf("tam: %d\n", ll_len(lista));
//
//    auxEmpleado = newEmpleadoParam(4444, "Ana", 'f', 300);
//    ll_add(lista, auxEmpleado);
//
//    printf("tam: %d\n", ll_len(lista));
//
//    auxEmpleado = (eEmpleado*) ll_get(lista, 1);
//
//    mostrarEmpleado(auxEmpleado);


//    // empleado estatico
//    //eEmpleado emp1;
//
//    // empleado dinamico
//    eEmpleado* emp2 = newEmpleado();
//    if(emp2==NULL)
//    {
//        printf("No se pudo conseguir memoria\n");
//        system("pause");
//        exit(1);
//    }
//
//    empleadoSetLegajo(emp2, 1234);
//
//    int legajo;
//
//    /*int legajo = emp2->legajo;*/ // ASÍ NO
//    if(empleadoGetLegajo(emp2, &legajo)) // ASÍ SI
//    {
//        printf("Legajo: %d\n", legajo);
//    }
//    else
//    {
//        printf("Problema al leer el legajo.\n");
//    }
//
//    eEmpleado* emp3 = newEmpleadoParam(3240, "Jose", 'm', 24000);
//    if(emp3==NULL)
//    {
//        printf("No se pudo conseguir memoria\n");
//        system("pause");
//        exit(1);
//    }
//
//    mostrarEmpleado(emp2);
//    mostrarEmpleado(emp3);
//
//    /*emp1.legajo = 1234;
//    strcpy(emp1.nombre, "Juan");
//    emp1.sexo = 'm';
//    emp1.sueldo = 56000;*/
//
//    /*printf("Ingrese legajo: ");
//    scanf("%d", &emp1.legajo);
//
//    printf("Ingrese nombre: ");
//    fflush(stdin);
//    gets(emp1.nombre);
//
//    printf("Ingrese sexo: ");
//    fflush(stdin);
//    scanf("%c", &emp1.sexo);
//
//    printf("Ingrese sueldo: ");
//    scanf("%f", &emp1.sueldo);*/
//
//    /*mostrarEmpleadoValor(emp1);
//    //mostrarEmpleado(&emp1);*/
//
//    printf("Ingrese legajo: ");
//    scanf("%d", &emp2->legajo);
//
//    printf("Ingrese nombre: ");
//    fflush(stdin);
//    gets(emp2->nombre);
//
//    printf("Ingrese sexo: ");
//    fflush(stdin);
//    scanf("%c", &emp2->sexo);
//
//    printf("Ingrese sueldo: ");
//    scanf("%f", &emp2->sueldo);
//
//    /*(*emp2).legajo = 3344;
//    strcpy((*emp2).nombre, "Analia");       ASÍ NO SE HACE.
//    (*emp2).sexo = 'f';
//    (*emp2).sueldo = 56000;*/
//
//    /*emp2->legajo = 3344;
//    strcpy(emp2->nombre, "Analia");
//    emp2->sexo = 'f';                      ASÍ SÍ.
//    emp2->sueldo = 56000;*/
//
//    //mostrarEmpleadoValor(*emp2);
//    mostrarEmpleado(emp2);
//
//    destroyEmpleado(emp2);
//    destroyEmpleado(emp3);

    // CLASE 19

//    int tam = 1;
//    int indice;
//    int legajo;
//    char nombre[20];
//    char sexo;
//    float sueldo;
//    eEmpleado* auxEmpleado = NULL;
//    eEmpleado** lista = (eEmpleado**) malloc(sizeof(eEmpleado*) * tam);
//    if(lista== NULL)
//    {
//        printf("No se consiguio lugar para la lista.\n");
//        exit(1);
//    }
//
//    if(inicializarEmpleados(lista, tam))
//    {
//        printf("Inicializacion exitosa\n"); // Esto no es necesario.
//    }
//    /*
//        buscarLibreEmpleado(lista, tam, &indice);
//        *(lista + indice) = newEmpleadoParam(1234, "Esteban", 'm', 450);
//        buscarLibreEmpleado(lista, tam, &indice);
//        *(lista + indice) = newEmpleadoParam(1111, "Mara", 'f', 550);
//        buscarLibreEmpleado(lista, tam, &indice);
//        *(lista + indice) = newEmpleadoParam(4444, "Ramona", 'f', 400);
//
//        mostrarEmpleados(lista, tam);
//    */
//    FILE* f = fopen("datosEmpleados.bin", "rb");
//    if(f == NULL)
//    {
//        printf("No se pudo abrir el archivo.\n");
//        exit(1);
//    }
//
//    int cant;
//    do
//    {
//        buscarLibreEmpleado(lista, tam, &indice);
//        if(indice!= -1)
//        {
//            auxEmpleado = newEmpleado();
//            if(auxEmpleado!=NULL)
//            {
//                cant = fread(auxEmpleado, sizeof(eEmpleado), 1, f);
//                if(cant==1)
//                {
//                    *(lista + indice) = auxEmpleado;
//                }
//            }
//        }
//        else
//        {
//            printf("No hay lugar me agrando\n");
//            agrandarLista(&lista, &tam);
//        }
//    }
//    while(!feof(f));
//        /*
//            int flag= 0;
//            for(int i = 0; i<tam; i++)
//            {
//
//                if(*(lista+i) != NULL)
//                {
//                    if(fwrite(*(lista+i), sizeof(eEmpleado), 1, f) < 1)
//                    {
//                        flag = 1;
//                        break;
//                    }
//                }
//            }
//            if(flag)
//            {
//                exit(1);
//            }
//            printf("Empleados guardados con exito\n");
//        */
//        fclose(f);
//
//    mostrarEmpleados(lista, tam);
//
//    /*    printf("Indice: %d\n", indice);
//
//        auxEmpleado = newEmpleado();
//
//        printf("Ingrese legajo: ");
//        scanf("%d", &legajo);
//        while(!empleadoSetLegajo(auxEmpleado, legajo))
//        {
//            printf("Legajo invalido. Reingrese legajo: ");
//            scanf("%d", &legajo);
//        }
//
//        printf("Ingrese nombre: ");
//        fflush(stdin);
//        gets(nombre);
//        while(!empleadoSetNombre(auxEmpleado, nombre))
//        {
//            printf("Nombre invalido. Reingrese nombre: ");
//            fflush(stdin);
//            gets(nombre);
//        }
//
//        printf("Ingrese sexo: ");
//        fflush(stdin);
//        scanf("%c", &sexo);
//        while(!empleadoSetSexo(auxEmpleado, sexo))
//        {
//            printf("Sexo invalido. Reingrese sexo: ");
//            fflush(stdin);
//            scanf("%c", &sexo);
//        }
//
//        printf("Ingrese sueldo: ");
//        scanf("%f", &sueldo);
//        while(!empleadoSetSueldo(auxEmpleado, sueldo))
//        {
//            printf("Sueldo invalido. Reingrese sueldo: ");
//            scanf("%f", &sueldo);
//        }
//
//        *(lista + indice) = auxEmpleado; //Lista es la dir de memo del 1er elemento, indice es el desplazamiento. Con * es el valor de...
//
//        mostrarEmpleados(lista, tam);
//
//        buscarLibreEmpleado(lista, tam, &indice);
//        printf("Indice: %d\n", indice);
//
//        *(lista + indice) = newEmpleadoParam(1234, "Esteban", 'm', 450);
//
//        mostrarEmpleados(lista, tam);
//
//        buscarLibreEmpleado(lista, tam, &indice);
//        printf("Indice: %d\n", indice);
//
//        *(lista + indice) = newEmpleadoParam(4545, "Alicia", 'f', 500);
//
//        mostrarEmpleados(lista, tam);
//
//        buscarLibreEmpleado(lista, tam, &indice);
//        if(indice == -1)
//        {
//            printf("No hay mas lugar\n");
//        }
//
//        printf("Camos a intentar agrandar el array\n");
//
//        if(agrandarLista(&lista, &tam))
//        {
//            printf("Lista redimensionada!!!\n");
//        }
//
//         buscarLibreEmpleado(lista, tam, &indice);
//        printf("Indice: %d\n", indice);
//
//        *(lista + indice) = newEmpleadoParam(9999, "Pedro", 'm', 600);
//
//        mostrarEmpleados(lista, tam);
//
//        ordenarEmpleados(lista, tam);
//        printf("Empleados ordenados por nombre \n\n");
//
//        mostrarEmpleados(lista, tam);
//    */
//    free(lista);
    return 0;
}
