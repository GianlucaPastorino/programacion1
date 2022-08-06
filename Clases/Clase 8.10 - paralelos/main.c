#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

float calcularPromedio(int a, int b);
int calcularPromedioRef(int a, int b, float* c);
void mostrarAlumnos(char n[][20], int leg[], char sex[], int n1[], int n2[], float proms[], int tam);
void ordenarAlumnos(char n[][20], int leg[], char sex[], int n1[], int n2[], float proms[], int tam);
void mostrarAlumno(char n[], int leg, char sex, int n1, int n2, float proms);

int main()
{
    char nombres[TAM][20]={"Donato", "Maria", "Chepi", "Carmen", "Gunda", "Damian", "German", "Alex", "Sol", "Flavia"};
    int legajos[TAM]={1122,5644,1234,5321,8977,5544,3412,7812,6789,5467};
    char sexos[TAM]={'m','f','f','f','f','m','m','m','f','f'};
    int notas1[TAM]={5,4,8,7,6,10,9,2,1,5};
    int notas2[TAM]={3,3,10,8,1,7,6,5,4,2};
    float promedios[TAM];
    //float auxFloat;
    //int auxInt;

    //Pido notas y calculo promedio
    for(int i=0; i<TAM; i++)
    {
       /* printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese nota 1er parcial: ");
        scanf("%d", &notas1[i]);

        printf("Ingrese nota 2do parcial: ");
        scanf("%d", &notas2[i]);*/

        //promedios[i] = calcularPromedio(notas1[i], notas2[i]);
        if(!calcularPromedioRef(notas1[i], notas2[i], &promedios[i]))
        {
            printf("Hubo un problema al calcular el promedio\n");
        }
    }
    printf("\n");

    //Muestro notas
    mostrarAlumnos(nombres, legajos, sexos, notas1, notas2, promedios, TAM);

    // Ordeno el listado por promedios decrecientes
    ordenarAlumnos(nombres, legajos, sexos, notas1, notas2, promedios, TAM);
    /*for(int i=0; i<TAM-1; i++)
    {
        for(int j=i+1; j<TAM; j++)
        {
            if(promedios[i]<promedios[j])
            {
                auxFloat = promedios[i];
                promedios[i]=promedios[j];
                promedios[j]=auxFloat;

                auxInt = notas1[i];
                notas1[i] = notas1[j];
                notas1[j] = auxInt;

                auxInt = notas2[i];
                notas2[i] = notas2[j];
                notas2[j] = auxInt;
            }
        }
    }*/

    // Muestro notas de nuevo ordenadas por promedios
    mostrarAlumnos(nombres, legajos, sexos, notas1, notas2, promedios, TAM);


    /*printf("****Listado de notas****\n");
    printf("Nota1    Nota2    Promedio\n");
    for(int i = 0; i<TAM; i++)
    {
       printf("  %2d      %2d       %5.2f\n", notas1[i], notas2[i], promedios[i]);
        //Al poner un %2d, hago que el numero ocupe 2 cifras.
    }
    printf("\n\n");*/

    return 0;
}


float calcularPromedio(int a, int b)
{
    return (float) (a+b)/2;
}

int calcularPromedioRef(int a, int b, float* c)
{
    int todoOk = 0;
    if(c!= NULL)
    {
        *c = (float) (a+b)/2;
        todoOk=1;
    }

    return todoOk;
}

void mostrarAlumnos(char n[][20], int leg[], char sex[], int n1[], int n2[], float proms[], int tam)
{
    printf("****Listado de alumnos****\n");
    printf("Legajo   Nombre    Sexo    Nota1    Nota2    Promedio\n");
    for(int i = 0; i<tam; i++)
    {
       mostrarAlumno(n[i], leg[i], sex[i], n1[i], n2[i], proms[i]);
       //printf(" %2d    %-10s  %c      %2d       %2d       %5.2f\n", leg[i], n[i], sex[i], n1[i], n2[i], proms[i]);
        //Al poner un %2d, hago que el numero ocupe 2 cifras.
    }
    printf("\n");
}

void mostrarAlumno(char n[], int leg, char sex, int n1, int n2, float proms)
{
    printf(" %2d    %-10s  %c      %2d       %2d       %5.2f\n", leg, n, sex, n1, n2, proms);
    //%10s alineo a la derecha, %-10s alineo a la izquierda.
}

void ordenarAlumnos(char n[][20], int leg[], char sex[], int n1[], int n2[], float proms[], int tam)
{
    for(int i=0; i<tam-1; i++)
    {
        float auxFloat;
        int auxInt;
        char auxChar;
        char auxCad[20];

        for(int j=i+1; j<tam; j++)
        {
            if(sex[i]<sex[j] || (sex[i]==sex[j] && strcmp(n[i], n[j])>0)) // Orden por 2 criterios.
            {
                auxFloat = proms[i];
                proms[i]=proms[j];
                proms[j]=auxFloat;

                auxInt = n1[i];
                n1[i] = n1[j];
                n1[j] = auxInt;

                auxInt = n2[i];
                n2[i] = n2[j];
                n2[j] = auxInt;

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                strcpy(auxCad,n[i]);
                strcpy(n[i],n[j]);
                strcpy(n[j],auxCad);
            }
        }
    }
}
