#include "gianluca.h"

int myIsDigit(char x)
{
    int esDigito = 0; //Asumo que no es un d�gito, si lo es cambio el valor en el if. No es necesario el else.
    if(x >= '0' && x <= '9') //Puedo poner los equivalentes en c�digo ascii, if(x >= 48 && x <= 57)
    {
        esDigito=1;
    }
    /*else
    {
        esDigito=0;
    }*/

    return esDigito;
}
