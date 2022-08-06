#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;

#endif // COLOR_H_INCLUDED

/** \brief muestra los colores
 *
 * \param colores[] eColor
 * \param tam int
 * \return void
 *
 */
void mostrarColores(eColor colores[], int tam);

/** \brief muestra un color
 *
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color);

/** \brief carga el nombre del color en la variable indicada
 *
 * \param id int
 * \param colores[] eColor
 * \param tam int
 * \param nombre[] char
 * \return int
 *
 */
int cargarNombreColor(int id, eColor colores[], int tam, char nombre[]);
