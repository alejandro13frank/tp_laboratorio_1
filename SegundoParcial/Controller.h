#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListEntregas);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntregas);
//int controller_addEntregas(LinkedList* pArrayListEntregas);
//int controller_editEntregas(LinkedList* pArrayListEntregas);
int controller_removeEntregas(LinkedList* pArrayListEntregas);
int controller_ListEntregas(LinkedList* pArrayListEntregas);
int controller_sortEntregas(LinkedList* pArrayListEntregas);
int controller_saveAsText(char* path , LinkedList* pArrayListEntregas);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntregas);
int controller_searchIdEntregas(LinkedList* pArrayListEntregas, int id);
int controller_ListEntregasMagia(LinkedList* this, LinkedList* that);
int controller_cantidadDeBultos(LinkedList* this,FILE* pFile);
int controller_cantidadDeEntregasPorTipo(LinkedList* this, FILE* pFile);
int controller_pesosTotales(LinkedList* this);
int controller_cantidadMaximaDeBultos(LinkedList* this,FILE* pFile);



#endif
