#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

void cargarNombres(char n[][20],int tam);
void mostrarNombres(char n[][20], int tam);
void ordenarNombres(char n[][20],int tam);

int main()
{
    char nombres [TAM][20];

    cargarNombres(nombres,TAM);
    mostrarNombres(nombres,TAM);
    ordenarNombres(nombres,TAM);

    printf("::::Ordeno::::\n");
    mostrarNombres(nombres,TAM);


    return 0;
}

void cargarNombres(char n[][20],int tam)
{
    for(int i=0;i<tam;i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(n[i]);
    }
}

void mostrarNombres(char n[][20], int tam)
{
   for(int i=0; i<tam; i++)
    {
        printf("%s", n[i]);
        printf("\n");
    }
}

void ordenarNombres(char n[][20],int tam) // Ordena de a a z, si quiero que sea de z a a, cambio el signo del if.
{
    char aux[20];

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(n[i],n[j])>0) //Puede ser stricmp también para no diferenciar mayus y minus.
            {
                strcpy(aux,n[i]);
                strcpy(n[i],n[j]);
                strcpy(n[j],aux);
            }
        }
    }
}

