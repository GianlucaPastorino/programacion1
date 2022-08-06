#include "sector.h"
#include "fecha.h"
#include "datawarehouse.h"
#include "inputs.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct // Defino un nuevo tipo de dato. Debo poner typedef.
{
    int legajo; //pk
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fIngreso;
    int idSector; //fk
    int isEmpty;
} eEmpleado; // Nombre del tipo de dato "eEmpleado" por estructura Empleado

#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
void ordenarEmpleados(eEmpleado lista[], int tam);
void inicializarEmpleados(eEmpleado lista[], int tam);
int menu();
int altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec, int* pLegajo);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
int bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int modificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSec);
int menuModificar();
char confirmar();
int cargarNombreEmpleado(int legajo, eEmpleado lista[], int tam, char nombre[]);
