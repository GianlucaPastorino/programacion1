#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct // Defino un nuevo tipo de dato. Debo poner typedef.
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    float sueldo;
    eFecha fIngreso;
    int isEmpty;
} eEmpleado; // Nombre del tipo de dato "eEmpleado" por estructura Empleado

#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleado(eEmpleado unEmpleado);
void mostrarEmpleados(eEmpleado lista[], int tam);
void ordenarEmpleados(eEmpleado lista[], int tam);
void inicializarEmpleados(eEmpleado lista[], int tam);
