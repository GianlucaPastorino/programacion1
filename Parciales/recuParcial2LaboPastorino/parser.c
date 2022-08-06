#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"

int parser_BiciciletasFromText(FILE* pFile, LinkedList* lista)
{
    int ok = 0;
    char buffer[4][128];
    eBicicleta* aux = NULL;

    if(pFile != NULL && lista != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4)
            {
                aux = bicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(aux != NULL)
                {
                    ll_add(lista, aux);
                    ok=1;
                }
            }
        }
    }
    return ok;
}
