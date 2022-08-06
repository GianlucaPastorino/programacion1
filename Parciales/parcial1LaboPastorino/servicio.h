#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief muestra varios o todos los servicios
 *
 * \param servicios[] eServicio
 * \param tamS int
 * \return void
 *
 */
void mostrarServicios(eServicio servicios[], int tamS);

/** \brief muestra un servicio
 *
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);

/** \brief carga el nombre del servicio en la variable indicada
 *
 * \param id int
 * \param servicios[] eServicio
 * \param tam int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[], int tam, char desc[]);
