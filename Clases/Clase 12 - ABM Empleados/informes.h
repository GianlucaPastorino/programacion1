#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


void listarEmpleadosSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int listarEmpleadosAllSectors(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int totalsueldoSector(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int totalADepositar(eEmpleado lista[], int tam, eSector sectores[], int tamS);
int sectorMayorSueldo(eEmpleado lista[], int tam, eSector sectores[], int tamS);

void almuerzosEmpleado(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams);
void totalAlmuerzoEmpleado(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams);
void totalAlmuerzosSector(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams);
void milanesasXSector(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams);
void sectorAmanteMilanesa(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc, eEmpleado lista[], int tame, eSector sectores[], int tams);
void listarTotalComidasFecha(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc);
void ingresoPorComidas(eAlmuerzo almuerzos[], int tama, eComida comidas[], int tamc);
