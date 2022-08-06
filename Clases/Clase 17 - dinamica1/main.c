#include <stdio.h>
#include <stdlib.h>

typedef struct{
int legajo;
char nombre[20];
char sexo;
float sueldo;
}eEmpleado;

int main()
{
    //int estatica;

    int* pDinamica = (int*) malloc(sizeof(int));
    //float* pPi = (float*) malloc(sizeof(float));
    //char* pSexo = (char*) malloc(sizeof(char));

    *pDinamica = 20;
    if(pDinamica == NULL)
    {
        printf("No se pudo conseguir memoria.\n\n");
        system("pause");
        exit(1);
    }

    printf("%d", *pDinamica);

    /*printf("%d\n", sizeof(int*));
    printf("%d\n", sizeof(float*));
    printf("%d\n", sizeof(char*));
    printf("%d\n", sizeof(eEmpleado*));*/
    // TODOS los punteros van a tener de tama�o 8 en este caso, porque son todos del mismo tama�o siempre.

    /*
    printf("%d\n", sizeof(int));
    printf("%d\n", sizeof(float));
    printf("%d\n", sizeof(char));
    printf("%d\n", sizeof(eEmpleado));

    *pPi = 3.1416;

    estatica = 10;

    printf("Ingrese sexo: ");
    fflush(stdin);
    scanf("%c", pSexo); // No se usa & porque pSexo ya es una direcci�n de memoria.

    // *pDinamica = 18; // Con el * es "El valor de tal direcci�n de memoria".

    printf("Ingrese un numero para guardar en la memoria dinamica: ");
    scanf("%d", pDinamica);

    printf("\n");
    printf("Estatica vale: %d\n", estatica);
    printf("Dinamica vale: %d\n", *pDinamica);
    printf("pPi vale: %f\n", *pPi);
    printf("pSexo vale: %c\n", *pSexo);
    */

    free(pDinamica); // Libero el espacio en memoria que ten�a ocupado con el malloc.
    //free(pPi);
    //free(pSexo);
    return 0;
}
