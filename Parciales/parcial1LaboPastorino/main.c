#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "informes.h"
#include "inputs.h"

#define TAMB 10
#define TAMTRABAJO 10
#define TAMTIPO 4
#define TAMCOLORES 5
#define TAMSER 4

int main()
{
    int nextIdBicicleta=100;
    int nextIdTrabajo=300;
    int contadorBicis=0;
    int contadorTrabajos=0;

    eTipo tipos[TAMTIPO]= {{1000, "Rutera"}, {1001, "Carrera"}, {1002, "Mountain"}, {1003, "BMX"}};
    eColor colores[TAMCOLORES]= {{5000, "Gris"}, {5001, "Negro"}, {5002, "Blanco"}, {5003, "Azul"},{5004, "Rojo"}};
    eServicio servicios[TAMSER]= {{20000, "Limpieza", 250}, {20001, "Parche", 300}, {20002, "Centrado", 400}, {20003, "Cadena", 350}};
    eBicicleta bicicletas[TAMB];
    eTrabajo trabajos[TAMTRABAJO];

    inicializarBicicletas(bicicletas, TAMB);
    inicializarTrabajos(trabajos, TAMTRABAJO);

    char salir = 'n';
    char regresar = 'n';
    do
    {
        switch(menu())
        {
        case 'a':
        case 'A':
            if(altaBicicleta(bicicletas, TAMB, tipos, colores, TAMTIPO, TAMCOLORES, &nextIdBicicleta))
            {
                printf("Alta exitosa!\n\n");
                contadorBicis++;
            }
            else
            {
                printf("No se pudo realizar el alta.\n\n");
            }
            break;
        case 'b':
        case 'B':
            if(contadorBicis!=0)
            {
                if(modificarBicicleta(bicicletas, TAMB, tipos, TAMTIPO, colores, TAMCOLORES))
                {
                    printf("Modificacion exitosa!\n\n");
                }
                else
                {
                    printf("No se pudo realizar la modificacion.\n\n");
                }
            }
            else
            {
                printf("Primero deberas dar de alta al menos una bicicleta.\n\n");
            }
            break;
        case 'c':
        case 'C':
            if(contadorBicis!=0)
            {
                if(bajaBicicleta(bicicletas, TAMB, tipos, TAMTIPO, colores, TAMCOLORES))
                {
                    printf("Baja exitosa!\n\n");
                    contadorBicis--;
                }
                else
                {
                    printf("No se pudo realizar la baja.\n\n");
                }
            }
            else
            {
                printf("Primero deberas dar de alta al menos una bicicleta.\n\n");
            }
            break;
        case 'd':
        case 'D':
            if(contadorBicis!=0)
            {
                system("cls");
                ordenarBicicletas(bicicletas, TAMB, tipos, TAMTIPO);
                mostrarBicicletas(bicicletas, TAMB, tipos, colores, TAMTIPO, TAMCOLORES);
            }
            else
            {
                printf("Primero deberas dar de alta al menos una bicicleta.\n\n");
            }
            break;
        case 'e':
        case 'E':
            system("cls");
            mostrarTipos(tipos, TAMTIPO);
            break;
        case 'f':
        case 'F':
            system("cls");
            mostrarColores(colores, TAMCOLORES);
            break;
        case 'g':
        case 'G':
            system("cls");
            mostrarServicios(servicios, TAMSER);
            break;
        case 'h':
        case 'H':
            if(contadorBicis!=0)
            {
                system("cls");
                if(altaTrabajo(trabajos, TAMTRABAJO, bicicletas, TAMB, servicios, TAMSER, tipos, TAMTIPO, colores, TAMCOLORES, &nextIdTrabajo))
                {
                    printf("Alta de tabajo exitosa!\n\n");
                    contadorTrabajos++;
                }
                else
                {
                    printf("No se pudo realizar el alta de trabajo.\n\n");
                }
            }
            else
            {
                printf("Primero deberas dar de alta al menos una bicicleta.\n\n");
            }
            break;
        case 'i':
        case 'I':
            if(contadorBicis!=0)
            {
                if(contadorTrabajos!=0)
                {
                    system("cls");
                    mostrarTrabajos(trabajos, TAMTRABAJO, servicios, TAMSER);
                }
                else
                {
                    printf("Primero deberas dar de alta al menos un trabajo.\n\n");
                }
            }
            else
            {
                printf("Primero deberas dar de alta al menos una bicicleta.\n\n");
            }
            break;
        case 'j':
        case 'J':
            do
            {
                switch(menuInformes())
                {
                case 1:
                    listarBicicletasColor(bicicletas, TAMB, colores, TAMCOLORES, tipos, TAMTIPO);
                    break;
                case 2:
                    listarBicicletasTipo(bicicletas, TAMB, colores, TAMCOLORES, tipos, TAMTIPO);
                    break;
                case 3:
                    bicicletaMenorRodado(bicicletas, TAMB, colores, TAMCOLORES, tipos, TAMTIPO);
                    break;
                case 4:
                    listarBicicletasPorTipos(bicicletas, TAMB, colores, TAMCOLORES, tipos, TAMTIPO);
                    break;
                case 5:
                    contarColorYTipo(bicicletas, TAMB, colores, TAMCOLORES, tipos, TAMTIPO);
                    break;
                case 6:
                    colorMasElegido(bicicletas, TAMB, colores, TAMCOLORES);
                    break;
                case 7:
                    trabajosABici(bicicletas, TAMB, trabajos, TAMTRABAJO, colores, TAMCOLORES, tipos, TAMTIPO, servicios, TAMSER);
                    break;
                case 8:
                    sumaImporteServiciosUnaBici(bicicletas, TAMB, trabajos, TAMTRABAJO, colores, TAMCOLORES, tipos, TAMTIPO, servicios, TAMSER);
                    break;
                case 9:
                    servicioHechoABicis(trabajos, TAMTRABAJO, servicios, TAMSER);
                    break;
                case 10:
                    mostrarServiciosEnFechaX(trabajos, TAMTRABAJO, servicios, TAMSER);
                    break;
                case 11:
                    regresar = confirmar();
                    break;
                default:
                    printf("Opcion invalida!\n");
                    break;
                }
                system("pause");
            }
            while(regresar=='n');
            break;
        case 'k':
        case 'K':
            salir = confirmar();
            break;
        default:
            printf("Opcion invalida!\n");
            break;
        }
        system("pause");
    }
    while(salir == 'n');
    return 0;
}
