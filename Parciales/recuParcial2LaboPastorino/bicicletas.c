#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bicicletas.h"

eBicicleta* bicicleta_new()
{
    eBicicleta* newBicicleta = (eBicicleta*) malloc(sizeof(eBicicleta));
    if(newBicicleta != NULL)
    {
        newBicicleta->id_bike = 0;
        strcpy(newBicicleta->nombre, "");
        strcpy(newBicicleta->tipo, "");
        newBicicleta->tiempo = 0;
    }
    return newBicicleta;
}

eBicicleta* bicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* newBicicleta = bicicleta_new();

    if(newBicicleta != NULL)
    {
        if(!(bicicleta_setId(newBicicleta, atoi(idStr)) &&
                bicicleta_setNombre(newBicicleta, nombreStr) &&
                bicicleta_setTipo(newBicicleta, tipoStr) &&
                bicicleta_setTiempo(newBicicleta, atoi(tiempoStr))))
        {
            bicicleta_delete(newBicicleta);
            newBicicleta = NULL;
        }
    }
    return newBicicleta;
}

void bicicleta_delete(eBicicleta* p)
{
    free(p);
}

int bicicleta_setId(eBicicleta* this,int id)
{
    int ok =0;
    if(this!=NULL && id > 0)
    {
        this->id_bike = id;
        ok=1;
    }
    return ok;
}

int bicicleta_getId(eBicicleta* this,int* id)
{
    int ok =0;
    if(this != NULL && id != NULL)
    {
        *id = this->id_bike;
        ok =1;
    }
    return ok;
}

int bicicleta_setNombre(eBicicleta* this,char* nombre)
{
    int ok =0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        ok=1;
    }
    return ok;
}

int bicicleta_getNombre(eBicicleta* this,char* nombre)
{
    int ok =0;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        ok =1;
    }
    return ok;
}

int bicicleta_setTipo(eBicicleta* this,char* tipo)
{
    int ok =0;
    if(this != NULL && tipo != NULL)
    {
        strcpy(this->tipo, tipo);
        ok=1;
    }
    return ok;
}

int bicicleta_getTipo(eBicicleta* this,char* tipo)
{
    int ok =0;
    if(this != NULL)
    {
        strcpy(tipo, this->tipo);
        ok =1;
    }
    return ok;
}

int bicicleta_setTiempo(eBicicleta* this,int tiempo)
{
    int ok =0;
    if(this!=NULL && tiempo >= 0)
    {
        this->tiempo = tiempo;
        ok=1;
    }
    return ok;
}

int bicicleta_getTiempo(eBicicleta* this,int* tiempo)
{
    int ok =0;
    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        ok =1;
    }
    return ok;
}

void* bicicleta_map(void* this)
{
    int tiempo;

    eBicicleta* aux = NULL;

    if(this != NULL)
    {
        aux = bicicleta_new();
        if(aux != NULL)
        {
            bicicleta_getId(this, &aux->id_bike);
            bicicleta_getNombre(this, aux->nombre);
            bicicleta_getTipo(this, aux->tipo);
            tiempo = rand() % (120 - 50 + 1) + 50;

            if(!( bicicleta_setTiempo(aux, tiempo)))
            {
                bicicleta_delete(aux);
                aux = NULL;
            }
        }
    }

    return aux;
}

int bicicleta_sort(void* bici1, void* bici2)
{
    int ret = 0;

    eBicicleta* bicicleta1;
    eBicicleta* bicicleta2;

    if(bici1 != NULL && bici2 != NULL)
    {
        bicicleta1 = (eBicicleta*) bici1;
        bicicleta2 = (eBicicleta*) bici2;

        if(strcmp(bicicleta1->tipo, bicicleta2->tipo) > 0)
        {
            ret = 1;
        }
        else if(strcmp(bicicleta1->tipo, bicicleta2->tipo) < 0)
        {
            ret = -1;
        }
        else if(strcmp(bicicleta1->tipo, bicicleta2->tipo) == 0)
        {
            if(bicicleta1->tiempo > bicicleta2->tiempo)
            {
                ret = 1;
            }
            else
            {
                ret = -1;
            }
        }
    }
    return ret;
}

    int menu()
    {
        int opcion;

        system ("cls");
        printf("**********SISTEMA BICICLETAS**********\n\n");
        printf("1. Cargar archivo\n");
        printf("2. Imprimir lista\n");
        printf("3. Asignar tiempos\n");
        printf("4. Filtrar por tipo\n");
        printf("5. Mostrar posiciones\n");
        printf("6. Guardar posiciones\n");
        printf("7. Salir\n\n");

        printf("Ingrese opcion (1-7): ");
        fflush(stdin);
        scanf("%d", &opcion);

        return opcion;
    }

