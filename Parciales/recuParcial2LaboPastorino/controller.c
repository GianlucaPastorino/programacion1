#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "inputs.h"
#include "parser.h"
#include "controller.h"

int controller_loadFromText(char* path, LinkedList* pListaBicicletas)
{
    int ok = 0;
    char respuesta;

    FILE* f = NULL;

    if(path != NULL && pListaBicicletas != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            if(ll_len(pListaBicicletas) > 0)
            {
                printf("Hay bicicletas en la lista y las va a sobrescribir.\n");
                respuesta = confirm();
            }
            if(ll_len(pListaBicicletas) == 0 || respuesta == 's')
            {
                ll_clear(pListaBicicletas);
                if(parser_BiciciletasFromText(f, pListaBicicletas))
                {
                    ok = 1;
                }
            }
        }
        fclose(f);
    }

    return ok;
}

int controller_saveAsText(char* path, LinkedList* pListaBicicletas)
{
    int ok = 0;
    char respuesta = 's';
    int id_bike;
    char nombre[100];
    char tipo[100];
    int tiempo;
    FILE* f = NULL;
    eBicicleta* aux = NULL;

    if(path != NULL && pListaBicicletas != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            printf("El archivo existe y se va a sobreescribir.\n");
            respuesta = confirm();
        }
        fclose(f);

        if(respuesta == 's')
        {
            f = fopen(path, "w");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo.\n\n");
            }
            else
            {
                fprintf(f,"id_bike,nombre,tipo,tiempo\n");
                for(int i=0; i < ll_len(pListaBicicletas); i++)
                {
                    aux = (eBicicleta*) ll_get(pListaBicicletas, i);
                    if(aux != NULL)
                    {
                        if(bicicleta_getId(aux, &id_bike) &&
                                bicicleta_getNombre(aux, nombre) &&
                                bicicleta_getTipo(aux, tipo) &&
                                bicicleta_getTiempo(aux, &tiempo))
                        {
                            fprintf(f, "%d,%s,%s,%d\n", id_bike, nombre, tipo, tiempo);
                        }
                    }
                }
                fclose(f);
                ok = 1;
            }
        }
    }
    return ok;
}

int controller_ListBicicletas(LinkedList* pListaBicicletas)
{
    int id_bike;
    char nombre[100];
    char tipo[100];
    int tiempo;
    int ok =0;
    eBicicleta* aux = NULL;

    if(pListaBicicletas != NULL)
    {
        printf("         *****BICICLETAS*****\n\n");
        printf("  ID    NOMBRE       TIPO      TIEMPO\n");

        for(int i = 0; i < ll_len(pListaBicicletas); i++)
        {
            aux = (eBicicleta*) ll_get(pListaBicicletas, i);
            if(bicicleta_getId(aux, &id_bike)
                    && bicicleta_getNombre(aux, nombre)
                    && bicicleta_getTipo(aux, tipo)
                    && bicicleta_getTiempo(aux, &tiempo))
            {
                printf(" %03d    %-10s   %-10s  %03d\n", id_bike, nombre, tipo, tiempo);
            }
        }
        ok = 1;
    }
    printf("\n");
    return ok;
}
