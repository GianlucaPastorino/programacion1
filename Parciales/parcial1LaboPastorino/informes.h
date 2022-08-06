#include "bicicleta.h"
#include "color.h"
#include "tipo.h"
#include "trabajo.h"
#include "servicio.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief muestra el menu de informes
 *
 * \return int
 *
 */
int menuInformes();

/** \brief muestra las bicicletas del color seleccionado por el usuario
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void listarBicicletasColor(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief  muestra las bicicletas del tipo seleccionado por el usuario
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void listarBicicletasTipo(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief muestra la o las bicicletas de menor rodado
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void bicicletaMenorRodado(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief muestra las bicicletas separadas por tipo
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void listarBicicletasPorTipos(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief pide y muestra la cantidad de bicicletas del mismo tipo y color
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamT int
 * \return void
 *
 */
void contarColorYTipo(eBicicleta bicis[], int tamB, eColor colores[], int tamC, eTipo tipos[], int tamT);

/** \brief muestra el color que posee la mayor cantidad de bicicletas
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param colores[] eColor
 * \param tamC int
 * \return void
 *
 */
void colorMasElegido(eBicicleta bicis[], int tamB, eColor colores[], int tamC);

/** \brief pide y muestra todos los trabajos realizados a una bicicleta
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return void
 *
 */
void trabajosABici(eBicicleta bicis[], int tamB, eTrabajo trabajos[], int tamTra, eColor colores[], int tamC, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);

/** \brief pide y muestra la suma de los importes de los servicios realizados a una bicicleta
 *
 * \param bicis[] eBicicleta
 * \param tamB int
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param colores[] eColor
 * \param tamC int
 * \param tipos[] eTipo
 * \param tamTip int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return void
 *
 */
void sumaImporteServiciosUnaBici(eBicicleta bicis[], int tamB, eTrabajo trabajos[], int tamTra, eColor colores[], int tamC, eTipo tipos[], int tamTip, eServicio servicios[], int tamSer);

/** \brief pide un servicio y muestra las bicicletas a las que se les realizo ese servicio y la fecha
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return void
 *
 */
void servicioHechoABicis(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);

/** \brief pide una fecha y muestra los servicios que se realizaron en la misma
 *
 * \param trabajos[] eTrabajo
 * \param tamTra int
 * \param servicios[] eServicio
 * \param tamSer int
 * \return void
 *
 */
void mostrarServiciosEnFechaX(eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
