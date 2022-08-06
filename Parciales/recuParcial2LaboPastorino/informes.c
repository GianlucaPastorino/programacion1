#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "bicicletas.h"

int filterTipoBmx(void* pElement)
{
    int ret = 0;
    eBicicleta* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eBicicleta*) pElement;
        if(!strcmp(aux->tipo, "BMX"))
        {
            ret = 1;
        }
    }
    return ret;
}

int filterTipoPlayera(void* pElement)
{
    int ret = 0;
    eBicicleta* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eBicicleta*) pElement;
        if(!strcmp(aux->tipo, "PLAYERA"))
        {
            ret = 1;
        }
    }
    return ret;
}

int filterTipoMtb(void* pElement)
{
    int ret = 0;
    eBicicleta* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eBicicleta*) pElement;
        if(!strcmp(aux->tipo, "MTB"))
        {
            ret = 1;
        }
    }
    return ret;
}

int filterTipoPaseo(void* pElement)
{
    int ret = 0;
    eBicicleta* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eBicicleta*) pElement;
        if(!strcmp(aux->tipo, "PASEO"))
        {
            ret = 1;
        }
    }
    return ret;
}
