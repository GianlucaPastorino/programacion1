#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
} eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief muesta menu de opciones
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menu();

/** \brief pone todos los isempty en 1
 *
 * \param bicicletas[] eBicicleta estructura bicicleta
 * \param tam int tamanio de las bicicletas
 * \return void
 *
 */
void inicializarBicicletas(eBicicleta bicicletas[], int tam);

/** \brief busca espacio libre en la estructura de bicicletas
 *
 * \param bicis[] eBicicleta
 * \param tam int
 * \return int
 *
 */
int buscarLibre(eBicicleta bicis[], int tam);

/** \brief da de alta una bicicleta
 *
 * \param bicicletas[] eBicicleta
 * \param tam int
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param tamTipos int
 * \param tamColores int
 * \param pId int*
 * \return int
 *
 */
int altaBicicleta(eBicicleta bicicletas[], int tam, eTipo tipos[], eColor colores[], int tamTipos, int tamColores, int* pId);

/** \brief muestra una bicicleta
 *
 * \param unaBici eBicicleta
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param tamT int
 * \param tamC int
 * \return void
 *
 */
void mostrarBicicleta(eBicicleta unaBici, eTipo tipos[], eColor colores[], int tamT, int tamC);

/** \brief muestra varias/todas bicicletas
 *
 * \param bicis[] eBicicleta
 * \param tam int
 * \param tipos[] eTipo
 * \param colores[] eColor
 * \param tamT int
 * \param tamC int
 * \return void
 *
 */
void mostrarBicicletas(eBicicleta bicis[], int tam, eTipo tipos[], eColor colores[], int tamT, int tamC);

/** \brief busca una bicicleta con determinado id
 *
 * \param bicis[] eBicicleta
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarBicicleta(eBicicleta bicis[], int tam, int id);

/** \brief menu que muestra las opciones de los campos que pueden ser modificados
 *
 * \return int
 *
 */
int menuModificar();

/** \brief modifica una bicicleta
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipos[] eTipo
 * \param tamT int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int modificarBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC);

/** \brief da de baja una bicicleta
 *
 * \param bicicletas[] eBicicleta
 * \param tamB int
 * \param tipos[] eTipo
 * \param tamT int
 * \param colores[] eColor
 * \param tamC int
 * \return int
 *
 */
int bajaBicicleta(eBicicleta bicicletas[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC);

/** \brief ordena bicicletas por el criterio pedido
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void ordenarBicicletas(eBicicleta bicis[], int tamB, eTipo tipos[], int tamT);
