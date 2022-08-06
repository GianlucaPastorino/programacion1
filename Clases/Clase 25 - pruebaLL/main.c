#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int id;
    char nombre[20];
    char sexo;
    int edad;
}eMascota;

void mostrarMascota(eMascota* m);
void mostrarMascotas(LinkedList* list);
int filterHembras(void* pElement);
int filterCachorros(void* pElement); // Menos de 2 años
int filterBunny(void* pElement);

int main()
{
    LinkedList* lista = ll_newLinkedList();

    eMascota m1 = {1234, "Bobby", 'm', 2};
    eMascota m2 = {3322, "Pepe", 'm', 5};
    eMascota m3 = {6543, "Lola", 'h', 1};
    eMascota m4 = {1111, "Bunny", 'h', 7};
    eMascota m5 = {9891, "Susy", 'h', 2};
    eMascota m6 = {2310, "Lolo", 'm', 1};

    ll_add(lista, &m1);
    ll_add(lista, &m2);
    ll_add(lista, &m3);
    ll_add(lista, &m4);
    ll_add(lista, &m5);
    ll_add(lista, &m6);

    mostrarMascotas(lista);

    LinkedList* hembras = ll_filter(lista, filterHembras);
    mostrarMascotas(hembras);

    LinkedList* cachorros = ll_filter(lista, filterCachorros);
    mostrarMascotas(cachorros);

    LinkedList* Bunnys = ll_filter(lista, filterBunny);
    mostrarMascotas(Bunnys);

    return 0;
}

void mostrarMascota(eMascota* m)
{
    if(m != NULL)
    {
        printf(" %d  %10s   %c   %d\n", m->id, m->nombre, m->sexo, m->edad);
    }
}

void mostrarMascotas(LinkedList* list)
{
    int tam;
    if(list != NULL)
    {
        tam = ll_len(list);
        printf("  Id       Nombre Sexo Edad\n");
        for(int i = 0; i<tam; i++)
        {
            mostrarMascota((eMascota*) ll_get(list, i));
        }
        printf("\n\n");
    }
}

int filterHembras(void* pElement)
{
    int ret = 0;
    eMascota* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eMascota*) pElement;
        if(aux->sexo == 'h')
        {
            ret = 1;
        }
    }
    return ret;
}

int filterCachorros(void* pElement)
{
    int ret = 0;
    eMascota* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eMascota*) pElement;
        if(aux->edad < 2)
        {
            ret = 1;
        }
    }
    return ret;
}

int filterBunny(void* pElement)
{
    int ret = 0;
    eMascota* aux = NULL;
    if(pElement != NULL)
    {
        aux = (eMascota*) pElement;
        if(!strcmp(aux->nombre, "Bunny"))
        {
            ret = 1;
        }
    }
    return ret;
}
