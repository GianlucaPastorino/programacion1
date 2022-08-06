#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
} eEmpleado;

// void mostrarEmpleadoValor(eEmpleado e);
int mostrarEmpleado(eEmpleado* p);
int mostrarEmpleados(LinkedList* lista);
int buscarMayorId(LinkedList* lista, int* Id);

eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int legajo, char* nombre, char sexo, float sueldo);

int empleadoSetLegajo(eEmpleado* e, int legajo);
int empleadoSetNombre(eEmpleado* e, char* nombre);
int empleadoSetSexo(eEmpleado* e, char sexo);
int empleadoSetSueldo(eEmpleado* e, float sueldo);

int empleadoGetLegajo(eEmpleado* e, int* pLegajo);
int empleadoGetNombre(eEmpleado* e, char* pNombre);
int empleadoGetSexo(eEmpleado* e, char* pSexo);
int empleadoGetSueldo(eEmpleado* e, float* pSueldo);

void destroyEmpleado(eEmpleado* p);

int inicializarEmpleados(eEmpleado** vec, int tam);
int buscarLibreEmpleado(eEmpleado** vec, int tam, int* pIndice);
int agrandarLista(eEmpleado*** vec, int* pTam);

int ordenarEmpleados(eEmpleado** vec, int tam); // Ordenar por nombre alfabeticamente.

int empleadoCmpSexo(void* a, void* b);
int empleadoCmpSuedo(void* a, void* b);
int empleadoCmpNombre(void* a, void* b);

#endif // EMPLEADO_H_INCLUDED
