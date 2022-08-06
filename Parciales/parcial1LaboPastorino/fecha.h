#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#endif // FECHA_H_INCLUDED

/** \brief compara si dos fechas son iguales
 *
 * \param f1 eFecha
 * \param f2 eFecha
 * \return int
 *
 */
int comparaFechas(eFecha f1, eFecha f2);
