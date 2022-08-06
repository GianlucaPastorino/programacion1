#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eTipo;

#endif // TIPO_H_INCLUDED

/** \brief muestra varios o todos los tipos
 *
 * \param tipos[] eTipo
 * \param tam int
 * \return void
 *
 */
void mostrarTipos(eTipo tipos[], int tam);

/** \brief muestra un tipo
 *
 * \param tipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);

/** \brief carga la descripcion de tipo en la variable indicada
 *
 * \param id int
 * \param tipos[] eTipo
 * \param tam int
 * \param desc[] char
 * \return int
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tam, char desc[]);
