#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief pide un numero y lo valida
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \return void
 *
 */
void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief pide un rodado y lo valida
 *
 * \param pRodado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \return void
 *
 */
void getRodado(float *pRodado, char* mensaje, char* mensajeError);

/** \brief valida que un array sea de caracteres
 *
 * \param cadena[] char
 * \return int
 *
 */
int arrayLetras(char cadena[]);

/** \brief valida una cadena de caracteres
 *
 * \param cadena[] char
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \return void
 *
 */
void validarCadenaCaracteres(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief pregunta si desea confirmar
 *
 * \return char
 *
 */
char confirmar();

/** \brief valida que el formato ingresado de una fecha sea valido
 *
 * \param dia int
 * \param mes int
 * \param anio int
 * \return int
 *
 */
int validarFecha(int dia, int mes, int anio);
