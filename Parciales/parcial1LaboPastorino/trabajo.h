#include "fecha.h"
#include "bicicleta.h"
#include "servicio.h"
#include "tipo.h"
#include "color.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    int idBicicleta;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

/** \brief da de alta un trabajo
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param servicios[] eServicio
 * \param tamS int
 * \param tipos[] eTipo
 * \param tamTipo int
 * \param colores[] eColor
 * \param tamColores int
 * \param pNextId int*
 * \return int
 *
 */
int altaTrabajo(eTrabajo trabajos[], int tamTra, eBicicleta bicis[], int tamB, eServicio servicios[], int tamS, eTipo tipos[], int tamTipo, eColor colores[], int tamColores, int* pNextId);

/** \brief busca una direccion de memoria libre en la estructura de trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return int
 *
 */
int buscarLibreTrabajos(eTrabajo trabajos[], int tam);

/** \brief pone todos los isempty de trabajos en 1
 *
 * \param trabajos[] eTrabajo
 * \param tam int
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[], int tam);

/** \brief muestra un trabajo
 *
 * \param trabajo eTrabajo
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tamS);

/** \brief muestra varios o todos los trabajos
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamS);
