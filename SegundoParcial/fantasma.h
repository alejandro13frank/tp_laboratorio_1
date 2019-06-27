#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED
#define TEXT_SIZE 128

typedef struct
{
    int id;
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    char floatUno;
    int intUno;
    int intDos;
}Fantasma;

void fantasma_setIdInicial(int val);
int fantasma_generarId(void);
void fantasma_imprimirMasterId(void);

Fantasma* fantasma_new(void);
Fantasma* fantasma_newParametros(char* idStr,char* nombreStr,char* intUnoStr, char* intDosStr, char* apellidoStr, char* floatUnoStr);
void fantasma_delete(Fantasma* this);

int fantasma_setId(Fantasma* this,int id);
int fantasma_getId(Fantasma* this,int* id);
int fantasma_setIdStr(Fantasma* this,char* id);

int fantasma_setNombre(Fantasma* this,char* nombre);
int fantasma_getNombre(Fantasma* this,char* nombre);

int fantasma_setApellido(Fantasma* this,char* apellido);
int fantasma_getApellido(Fantasma* this,char* apellido);

int fantasma_setIntUno(Fantasma* this,int intUno);
int fantasma_getIntUno(Fantasma* this,int* intUno);
int fantasma_setIntUnoStr(Fantasma* this,char* intUnoStr);

int fantasma_setIntDos(Fantasma* this,int intDos);
int fantasma_getIntDos(Fantasma* this,int* intDos);
int fantasma_setIntDosStr(Fantasma* this,char* intDos);

int fantasma_setFloatUno(Fantasma* this,float floatUno);
int fantasma_getFloatUno(Fantasma* this,float* floatUno);
int fantasma_setFloatUnoStr(Fantasma* this,char* floatUnoStr);

int fantasma_printNode(Fantasma *this);
int fantasma_comparaNombre(void *this,void *that);

 //int fantasma_setFloatUnoStr(Fantasma* this,char* floatUnoStr, char* elotro);
#endif // FANTASMA_H_INCLUDED
