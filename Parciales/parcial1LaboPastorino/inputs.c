#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

void getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int num;

    printf("%s", mensaje);
    while(scanf("%d",&num)!=1 || num<minimo || num>maximo)
    {
        fflush(stdin);
        printf("%s", mensajeError);
        printf("%s", mensaje);
    }
    *pResultado = num;
}

void getRodado(float *pRodado, char* mensaje, char* mensajeError)
{
    float num;

    printf("%s", mensaje);
    while(scanf("%f",&num)!=1 || (num!= 20 && num!= 26 && num!= 27.5 && num != 29))
    {
        fflush(stdin);
        printf("%s", mensajeError);
        printf("%s", mensaje);
    }
    *pRodado = num;
}

int arrayLetras(char cadena[])
{
    int ret=1;
    for(int i = 0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
        {
            ret = 0;
        }
    }
    return ret;
}

void validarCadenaCaracteres(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo)
{
    char auxCad[200];

    printf(mensaje);
    fflush(stdin);
    gets(auxCad);

    while(strlen(auxCad)>=maximo || arrayLetras(auxCad)==0)
    {
        printf(mensajeError);
        printf(mensaje);
        fflush(stdin);
        gets(auxCad);
    }

    strcpy(cadena, auxCad);
}

int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if( mes >= 1 && mes <= 12 )
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia >= 1 && dia <= 31)
            {
                todoOk = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia >= 1 && dia <= 30)
            {
                todoOk = 1;
            }
            break;
        case 2:
            if((anio%4 == 0 && anio%100 != 0) || anio%400 == 0)
            {
                if(dia >= 1 && dia <= 29)
                {
                    todoOk = 1;
                }
            }
            else
            {
                if(dia >= 1 && dia <= 28)
                {
                    todoOk = 1;
                }
            }
            break;
        }
    }
    return todoOk;
}

char confirmar()
{
    char respuesta;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    respuesta = getchar();

    while(respuesta != 's' && respuesta != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        respuesta = getchar();
    }

    return respuesta;
}
