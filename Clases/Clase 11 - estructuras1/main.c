#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

#define TAM 3

int main()
{
    eEmpleado emp1 = {5546, "Miguel", 32, 'm', 567000, {26, 4, 2021}}; // Así puedo hardcodear la estructura.
    // La fecha al ser otra estructura, tengo que declararla también entre {}.
    eEmpleado emp2;

    /*emp1.legajo=1111; // Con el . accedo a las variables de mi estructura.
    strcpy(emp1.nombre, "Lucia");
    emp1.edad = 29;
    emp1.sexo = 'f';
    emp1.sueldo= 134000*/

    // Pedido de datos
    /*printf("Ingrese legajo: ");
    scanf("%d", &emp1.legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(emp1.nombre);

    printf("ingrese edad: ");
    scanf("%d", &emp1.edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &emp1.sexo);

    printf("Ingrese sueldo: ");
    scanf("%f", &emp1.sueldo);

    printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
    scanf("%d/%d/%d", &emp1.fIngreso.dia, &emp1.fIngreso.mes, &emp1.fIngreso.anio);*/

    //printf("%d, %s, %c, %.2f\n", emp1.legajo, emp1.nombre, emp1.sexo, emp1.sueldo);
    mostrarEmpleado(emp1);

    emp2 = emp1; // Copio absolutamente todo de una estructura a la otra.

    mostrarEmpleado(emp2);
    printf("\n");

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    eEmpleado nomina[TAM] = {
                            {5546, "Miguel", 32, 'm', 56700, {26, 4, 2021}, 0},
                            {7485, "Carlos", 75, 'm', 43000, {3, 11, 2010}, 0},
                            {1111, "Gabriela", 43, 'f', 90000, {12, 1, 2017}, 0},
                            };

    //inicializarEmpleados(nomina, TAM);

    /*for(int i=0; i<TAM; i++)
    {
    printf("Ingrese legajo: ");
    scanf("%d", &nomina[i].legajo);

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nomina[i].nombre);

    printf("Ingrese edad: ");
    scanf("%d", &nomina[i].edad);

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", &nomina[i].sexo);

    printf("Ingrese sueldo: ");
    scanf("%f", &nomina[i].sueldo);

    printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
    scanf("%d/%d/%d", &nomina[i].fIngreso.dia, &nomina[i].fIngreso.mes, &nomina[i].fIngreso.anio);
    }*/

    /*for(int i=0; i<TAM; i++)
    {
        mostrarEmpleado(nomina[i]);
    }
    printf("\n");*/

    mostrarEmpleados(nomina, TAM);
    ordenarEmpleados(nomina, TAM);
    mostrarEmpleados(nomina, TAM);

    return 0;
}
