#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int controller_loadFromText(char* path, LinkedList* pListaBicicletas);
int controller_saveAsText(char* path, LinkedList* pListaBicicletas);
int controller_ListBicicletas(LinkedList* pListaPaises);

#endif // CONTROLLER_H_INCLUDED
