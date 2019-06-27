#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "entregas.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if (pFile!=NULL && parser_EntregasFromText(pFile , pArrayListEntregas)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if (pFile!=NULL && parser_EntregasFromBinary(pFile , pArrayListEntregas)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_removeEntregas(LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    int id;
    int bufferIdNode;
    if(pArrayListEntregas!=NULL)
    {
        controller_ListEntregas(pArrayListEntregas);
        utn_getUnsignedInt("\nID a eliminar: ","\nError",1,6,0,30000,1,&id);
        bufferIdNode=controller_searchIdEntregas(pArrayListEntregas,id);
        if(bufferIdNode==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEntregas,bufferIdNode);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_ListEntregas(LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    int i;
    int lenLista;
    if (pArrayListEntregas!=NULL && ll_len(pArrayListEntregas)!=0)
    {
        lenLista=ll_len(pArrayListEntregas);
        for (i=0;lenLista>i;i++)
        {
           entregas_printNode(ll_get(pArrayListEntregas,i));
        }
    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_sortEntregas(LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    if (pArrayListEntregas!=NULL)
    {
        ll_sort(pArrayListEntregas,entregas_comparaTipo,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferTipo[4096];
    int bufferCantidad;
    float bufferPeso;
    Entregas* pEntregas;
    FILE* fp = fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListEntregas);
        fprintf(fp,"id,tipo,Cantidad,Peso\n");
        for(i=0;i<size;i++)
        {
            pEntregas=ll_get(pArrayListEntregas,i);
            entregas_getId(pEntregas,&bufferId);
            entregas_getTipo(pEntregas,bufferTipo);
            entregas_getCantidad(pEntregas,&bufferCantidad);
            entregas_getPeso(pEntregas,&bufferPeso);
            //entregas_getIntDos(pEntregas,&bufferIntDos);

            fprintf(fp,"%d,%s,%d,%f\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    int i;
    int size;
    Entregas* pEntregas;
    FILE* fp = fopen(path,"w+b");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListEntregas);
        for(i=0;i<size;i++)
        {
            pEntregas=ll_get(pArrayListEntregas,i);
            fwrite(pEntregas,sizeof(Entregas),1,fp);
        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}
int controller_searchIdEntregas(LinkedList* pArrayListEntregas, int id)
{
    int retorno=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListEntregas!=NULL && id>0 && ll_len(pArrayListEntregas)!=0)
    {
        lenLista=ll_len(pArrayListEntregas);
        for (i=0;i<lenLista;i++)
        {
            entregas_getId(ll_get(pArrayListEntregas,i),&bufferId);
            if (id==bufferId)
            {
                retorno=i;
                break;
            }
        }

    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}

/*int controller_listByCOSA(LinkedList* this,int (*pFunc)(void*,void*))
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int i;
    char bufferCosa[1024];
    char bufferCodigo[1024];
    if (this!=NULL && pFunc!=NULL)
    {
        returnAux=0;
        utn_getAlfanumerico("\nIngrese Codigo de loque sea: ","\nError",0,60,1,bufferCosa);
        sscanf(bufferCosa,"%[^-]-",bufferCodigo);
        if (isValidNumber(bufferCodigo))
        {

            for(i=0;i<lenLista;i++)
            {
                auxElement=ll_iterNext(iterator);
                if (pFunc(auxElement,bufferCodigo)==-1)
                {
                    returnAux=-1*i;
                    break;
                }
            }
        }
    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int imprimoVenta(void* this, void* codigo)
{
    int retorno=-1;
    if (this!=NULL && codigo>0)
    {
        entregas_getCodigo((Entregas*)this,&bufferCodigo);
        if (codigo==bufferCodigo)
        {
            entregas_printNode(this);
            retorno=0;
        }
    }
    return retorno;
}
*/

/*int controller_ListEntregasMagia(LinkedList* this, LinkedList* that)
{
    int returnAux=-1;
    IterNode* iteratorA=ll_iterInit(this);
    IterNode* iteratorB;
    int lenListaA=ll_len(this);
    int lenListaB=ll_len(that);
    void* auxElementA;
    void* auxElementB;
    int idCliente;
    int idVenta;
    float monto;
    float montoTotal;
    int cantVentas;
    int i;
    int j;
    if (this!=NULL && that!=NULL)
    {
        //returnAux=0;
        for(i=0;i<lenListaA;i++)
        {
            cantVentas=0;
            auxElementA=ll_iterNext(iteratorA);
            entregas_getId(auxElementA,&idCliente);
            iteratorB =ll_iterInit(that);
            for(j=0;j<lenListaB;j++)
            {
                auxElementB=ll_iterNext(iteratorB);
                entregas_getId(auxElementB,&idVenta);
                entregas_getPeso(auxElementB,&monto);
                if (idCliente==idVenta)
                {
                    cantVentas++;
                    montoTotal+=monto;

                }
            }
            entregas_printNode(auxElementA);
            printf("cantidad de ventas= %d \f monto total= %f",cantVentas,montoTotal);
            ll_iterFinishIter(iteratorB);
        }
        returnAux=0;
    }
    ll_iterFinishIter(iteratorA);
    return returnAux;

}*/

int controller_cantidadDeEntregasPorTipo(LinkedList* this, FILE* pFile)
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int contadorSTD=0;
    int contadorEXP=0;
    int contadorECO=0;
    char tipo[10];
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_iterNext(iterator);
            entregas_getTipo(auxElement,tipo);
            if (strncmp(tipo,"STD",sizeof(tipo))==0)
            {
                contadorSTD++;
            }
            else if (strncmp(tipo,"EXP",sizeof(tipo))==0)
            {
                contadorEXP++;
            }else if (strncmp(tipo,"ECO",sizeof(tipo))==0)
            {
                contadorECO++;
            }
        }

        fprintf(pFile,"\nCantidad de entregas por tipo: (STD) - %d (EXP) - %d (ECO) - %d",contadorSTD,contadorEXP,contadorECO);

    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int controller_cantidadDeBultos(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int contador=0;
    int cantidad;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_iterNext(iterator);
            entregas_getCantidad(auxElement,&cantidad);
            contador+=cantidad;
        }
        returnAux=contador;
        fprintf(pFile,"\nCantidad de bultos Totales: %d",contador);

    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int controller_pesosTotales(LinkedList* this)
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    float contador=0;
    float peso;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_iterNext(iterator);
            entregas_getPeso(auxElement,&peso);
            contador+=peso;
        }
        returnAux=contador;
    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int controller_cantidadMaximaDeBultos(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int cantidad;
    int cantidadMaxima=0;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_iterNext(iterator);
            entregas_getCantidad(auxElement,&cantidad);
            if (cantidad>cantidadMaxima)
            {
                cantidadMaxima=cantidad;
            }
        }
        returnAux=0;
        fprintf(pFile,"\nCantidad de maxima de Bultos: %d",cantidadMaxima);

    }
    ll_iterFinishIter(iterator);
    return returnAux;
}
