#include <stdio.h>
#include <stdlib.h>
#include "fantasma.h"
#include "utn.h"
#include "string.h"

static int idPer=0;

int fantasma_generarId(void)
{
    return idPer++;
}
 void fantasma_setIdInicial(int val)
{
    idPer= val;
}
void fantasma_imprimirMasterId(void)
{
    printf("\n%d",idPer);
}

Fantasma* fantasma_new(void)
{
    return (Fantasma*) malloc(sizeof(Fantasma));
}

Fantasma* fantasma_newParametros(char* idStr,char* nombreStr,char* intUnoStr,char* intDosStr, char* apellidoStr, char* floatUnoStr)
{
    Fantasma* pFantasma=fantasma_new();
    if (pFantasma!=NULL)
    {
        fantasma_setIdStr(pFantasma,idStr);
        fantasma_setNombre(pFantasma,nombreStr);
        fantasma_setApellido(pFantasma,apellidoStr);
        fantasma_setIntUnoStr(pFantasma,intUnoStr);
        fantasma_setIntDosStr(pFantasma,intDosStr);
        fantasma_setFloatUnoStr(pFantasma,floatUnoStr);
        //fantasma_setSumadedos(pFantasma,uno,el otro);
    }
    return pFantasma;
}

void fantasma_delete(Fantasma* this)
{
    free(this);
}

int fantasma_setId(Fantasma* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int fantasma_getId(Fantasma* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int fantasma_setIdStr(Fantasma* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        bufferInt= atoi(id);
        if (bufferInt>0)
        {
            fantasma_setId(this,bufferInt);
        }
    }
    return retorno;
}

int fantasma_setNombre(Fantasma* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && isValidName(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int fantasma_getNombre(Fantasma* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int fantasma_setApellido(Fantasma* this,char* apellido)
{
    int retorno = -1;
    if(this!=NULL && isValidName(apellido))
    {
        strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int fantasma_getApellido(Fantasma* this,char* apellido)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(apellido,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int fantasma_setIntUno(Fantasma* this,int intUno)
{
    int retorno=-1;
    if (this!=NULL && intUno>0)
    {
        this->intUno=intUno;
        retorno=0;
    }
    return retorno;
}

int fantasma_getIntUno(Fantasma* this,int* intUno)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *intUno = this->intUno;
        retorno=0;
    }
    return retorno;
}

int fantasma_setIntUnoStr(Fantasma* this,char* intUnoStr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL && isValidNumber(intUnoStr))
    {
        bufferHora= atoi(intUnoStr);
        if (bufferHora>0)
        {
            fantasma_setIntUno(this,bufferHora);
        }
    }
    return retorno;
}

int fantasma_setFloatUno(Fantasma* this,float floatUno)
{
    int retorno=-1;
    if (this!=NULL && floatUno>0)
    {
        this->floatUno=floatUno;
        retorno=0;
    }
    return retorno;
}

int fantasma_getFloatUno(Fantasma* this,float* floatUno)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *floatUno = this->floatUno;
        retorno=0;
    }
    return retorno;
}

int fantasma_setFloatUnoStr(Fantasma* this,char* floatUnoStr)
{
    int retorno=-1;
    float bufferHora;
    if (this!=NULL && isValidFloatNumber(floatUnoStr))
    {
        bufferHora= atof(floatUnoStr);
        if (bufferHora>0)
        {
            fantasma_setFloatUno(this,bufferHora);
        }
    }
    return retorno;
}

int fantasma_setIntDos(Fantasma* this,int intDos)
{
    int retorno=-1;
    if (this!=NULL && intDos>0)
    {
        this->intDos=intDos;
        retorno=0;
    }
    return retorno;
}

int fantasma_getIntDos(Fantasma* this,int* intDos)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *intDos = this->intDos;
        retorno=0;
    }
    return retorno;
}

int fantasma_setIntDosStr(Fantasma* this,char* intDos)
{
    int retorno=-1;
    int bufferintDos;
    if (this!=NULL && isValidNumber(intDos))
    {
        bufferintDos=atoi(intDos);
        if (bufferintDos>0)
        {
            fantasma_setIntDos(this,bufferintDos);
        }
    }
    return retorno;
}

int fantasma_printNode(Fantasma *this)
{
    int retorno=-1;
    char bufferNombre[TEXT_SIZE];
    char bufferApellido[TEXT_SIZE];
    int bufferIntDos;
    int bufferIntUno;
    int bufferId;
    if (this!=NULL)
    {
        fantasma_getId(this,&bufferId);
        printf("\n ID: %d",bufferId);
        fantasma_getNombre(this,bufferNombre);
        printf("\f Nombre: %s",bufferNombre);
        fantasma_getNombre(this,bufferApellido);
        printf("\f Apellido: %s",bufferApellido);
        fantasma_getIntUno(this,&bufferIntUno);
        printf("\f Horas trabajadas: %d",bufferIntUno);
        fantasma_getIntDos(this,&bufferIntDos);
        printf("\f IntDos: %d",bufferIntDos);
        retorno=0;
    }
    return retorno;
}

int fantasma_comparaNombre(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Fantasma*)this)->nombre,((Fantasma*)that)->nombre);
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
 int fantasma_setFloatUnoStr(Fantasma* this,char* floatUnoStr, char* elotro)
{
    int retorno=-1;
    float bufferHora;
    int bufferOtro;
    if (this!=NULL && isValidFloatNumber(floatUnoStr) && isValidNumber(elotro))
    {
        bufferHora= atof(floatUnoStr);
        bufferOtro= atoi(elotro);
        if (bufferHora>0 bufferOtro>0)
        {
            bufferHora= (float)bufferHora*bufferOtro;
            fantasma_setFloatUno(this,bufferHora);
        }
    }
    return retorno;

int fantasma_setFloatUno(Fantasma* this,float floatUno)
{
    int retorno=-1;
    if (this!=NULL && floatUno>0)
    {
        this->montoTotal=floatUno;
        retorno=0;
    }
    return retorno;
}

int fantasma_getFloatUno(Fantasma* this,float* floatUno)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *floatUno = this->floatUno;
        retorno=0;
    }
    return retorno;
}

*/
