#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
#define TEXT_SIZE 10

typedef struct
{
    int id;
    char tipo[TEXT_SIZE];//tipo
    float peso;//peso
    int cantidad;//cantidadr
}Entregas;

void entregas_setIdInicial(int val);
int entregas_generarId(void);
void entregas_imprimirMasterId(void);

Entregas* entregas_new(void);
Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* pesoStr);
void entregas_delete(Entregas* this);

int entregas_setId(Entregas* this,int id);
int entregas_getId(Entregas* this,int* id);
int entregas_setIdStr(Entregas* this,char* id);

int entregas_setTipo(Entregas* this,char* tipo);
int entregas_getTipo(Entregas* this,char* tipo);


int entregas_setCantidad(Entregas* this,int cantidad);
int entregas_getCantidad(Entregas* this,int* cantidad);
int entregas_setCantidadStr(Entregas* this,char* cantidadStr);

int entregas_setIntDos(Entregas* this,int intDos);
int entregas_getIntDos(Entregas* this,int* intDos);
int entregas_setIntDosStr(Entregas* this,char* intDos);

int entregas_setPeso(Entregas* this,float peso);
int entregas_getPeso(Entregas* this,float* peso);
int entregas_setPesoStr(Entregas* this,char* pesoStr);

int entregas_printNode(Entregas *this);
int entregas_comparaTipo(void *this,void *that);

 //int entregas_setPesoStr(Entregas* this,char* pesoStr, char* elotro);
#endif // ENTREGAS_H_INCLUDED
