#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[100];
    char tipo[100];
    int tiempo;
}eBicicleta;

eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);
void bicicleta_delete(eBicicleta* p);
int bicicleta_setId(eBicicleta* this,int id);
int bicicleta_getId(eBicicleta* this,int* id);
int bicicleta_setNombre(eBicicleta* this,char* nombre);
int bicicleta_getNombre(eBicicleta* this,char* nombre);
int bicicleta_setTipo(eBicicleta* this,char* tipo);
int bicicleta_getTipo(eBicicleta* this,char* tipo);
int bicicleta_setTiempo(eBicicleta* this,int tiempo);
int bicicleta_getTiempo(eBicicleta* this,int* tiempo);
void* bicicleta_map(void* this);
int bicicleta_sort(void* bici1, void* bici2);
int menu();

#endif // BICICLETAS_H_INCLUDED
