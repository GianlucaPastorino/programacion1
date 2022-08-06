#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CANT_REP 5
/*
Debemos realizar la carga de una compra de 5(cinco) productos de prevención de contagio
De cada uno debo obtener los siguientes datos:
el nombre del producto
el tipo de producto (validar "ALCOHOL" , "IAC" o "QUAT") ,
el precio (validar entre 100 y 300),
la cantidad de unidades (no puede ser 0 o negativo y no debe superar las 1000 unidades),
el tipo de inflamable("ignífugo", "combustible", "explosivo" )
y la Marca
Se debe informar al usuario lo siguiente:

a) El promedio de cantidad por tipo de producto
b) El tipo de inflamable con más cantidad de unidades en total de la compra
c) Cuántas unidades de IAC con precios menores a 200 (inclusive) se compraron en total
d) La marca y tipo del más caro de los productos
*/

int main()
{
    char nombre;
    char tipo;
    float precio;
    int cantidad;
    char inflamable;
    float promA = 0;
    float promI = 0;
    float pormQ = 0;
    int acumA = 0;
    int acumI = 0;
    int acumQ = 0;
    int contA = 0;
    int contI = 0;
    int contQ = 0;
    int acumIg = 0;
    int acumCob = 0;
    int acumExp = 0;
    int contIACBarato = 0;
    float mayorPrecio;
    char mayorMarca;
    char mayorTipo;
    int flag = 1;


    for(int i=0; i<CANT_REP; i++) //el CANT_REP está definido arriba de todo en el #define
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%c", &nombre);

        printf("Ingrese tipo A/I/Q: ");
        fflush(stdin);
        scanf("%c", &tipo);
        tipo=toupper(tipo);
        while(tipo!='A' && tipo!='I' && tipo!='Q')
        {
            printf("Error, tipo invalido. Reingrese tipo A/I/Q: ");
            fflush(stdin);
            scanf("%c", &tipo);
        }

        printf("Ingrese cantidad: ");
        scanf("%d", &cantidad);
        while(cantidad <= 0 || cantidad>1000)
        {
            printf("Error. Reingrese cantidad: ");
            scanf("%d", &cantidad);
        }



    }
    return 0;
}
