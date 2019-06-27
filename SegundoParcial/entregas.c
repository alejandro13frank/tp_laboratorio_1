#include <stdio.h>
#include <stdlib.h>
#include "entregas.h"
#include "utn.h"
#include "string.h"

static int idPer=0;

int entregas_generarId(void)
{
    return idPer++;
}
 void entregas_setIdInicial(int val)
{
    idPer= val;
}
void entregas_imprimirMasterId(void)
{
    printf("\n%d",idPer);
}

Entregas* entregas_new(void)
{
    return (Entregas*) malloc(sizeof(Entregas));
}

Entregas* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr , char* pesoStr)
{
    Entregas* pEntregas=entregas_new();
    if (pEntregas!=NULL)
    {
        entregas_setIdStr(pEntregas,idStr);
        entregas_setTipo(pEntregas,tipoStr);
        //entregas_setApellido(pEntregas,apellidoStr);
        entregas_setCantidadStr(pEntregas,cantidadStr);
        //entregas_setIntDosStr(pEntregas,intDosStr);
        entregas_setPesoStr(pEntregas,pesoStr);
        //entregas_setSumadedos(pEntregas,uno,el otro);
    }
    return pEntregas;
}

void entregas_delete(Entregas* this)
{
    free(this);
}

int entregas_setId(Entregas* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int entregas_getId(Entregas* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int entregas_setIdStr(Entregas* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        bufferInt= atoi(id);
        if (bufferInt>0)
        {
            entregas_setId(this,bufferInt);
        }
    }
    return retorno;
}

int entregas_setTipo(Entregas* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL && isValidName(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entregas_getTipo(Entregas* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entregas_setCantidad(Entregas* this,int cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad>0)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_getCantidad(Entregas* this,int* cantidad)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *cantidad = this->cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_setCantidadStr(Entregas* this,char* cantidadStr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL && isValidNumber(cantidadStr))
    {
        bufferHora= atoi(cantidadStr);
        if (bufferHora>0)
        {
            entregas_setCantidad(this,bufferHora);
        }
    }
    return retorno;
}

int entregas_setPeso(Entregas* this,float peso)
{
    int retorno=-1;
    if (this!=NULL && peso>0)
    {
        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int entregas_getPeso(Entregas* this,float* peso)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *peso = this->peso;
        retorno=0;
    }
    return retorno;
}

int entregas_setPesoStr(Entregas* this,char* pesoStr)
{
    int retorno=-1;
    float bufferHora;
    if (this!=NULL && isValidFloatNumber(pesoStr))
    {
        bufferHora= atof(pesoStr);
        if (bufferHora>0)
        {
            entregas_setPeso(this,bufferHora);
        }
    }
    return retorno;
}

int entregas_printNode(Entregas *this)
{
    int retorno=-1;
    char bufferTipo[TEXT_SIZE];
    int bufferCantidad;
    int bufferId;
    float bufferPeso;
    if (this!=NULL)
    {
        entregas_getId(this,&bufferId);
        printf("\n ID: %d",bufferId);
        entregas_getTipo(this,bufferTipo);
        printf("\f Tipo: %s",bufferTipo);
        entregas_getCantidad(this,&bufferCantidad);
        printf("\f cantidad: %d",bufferCantidad);
        entregas_getPeso(this,&bufferPeso);
        printf("\f Peso: %.2f",bufferPeso);
        retorno=0;
    }
    return retorno;
}

int entregas_comparaTipo(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Entregas*)this)->tipo,((Entregas*)that)->tipo);
    if (comparacion<0)
    {
        retorno=1;
    }
    else if (comparacion>0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}




/*
 int entregas_setPesoStr(Entregas* this,char* pesoStr, char* elotro)
{
    int retorno=-1;
    float bufferHora;
    int bufferOtro;
    if (this!=NULL && isValidFloatNumber(pesoStr) && isValidNumber(elotro))
    {
        bufferHora= atof(pesoStr);
        bufferOtro= atoi(elotro);
        if (bufferHora>0 bufferOtro>0)
        {
            bufferHora= (float)bufferHora*bufferOtro;
            entregas_setPeso(this,bufferHora);
        }
    }
    return retorno;

int entregas_setPeso(Entregas* this,float peso)
{
    int retorno=-1;
    if (this!=NULL && peso>0)
    {
        this->montoTotal=peso;
        retorno=0;
    }
    return retorno;
}

int entregas_getPeso(Entregas* this,float* peso)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *peso = this->peso;
        retorno=0;
    }
    return retorno;
}

*/
