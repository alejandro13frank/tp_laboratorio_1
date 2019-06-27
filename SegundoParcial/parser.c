#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entregas.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromText(FILE* pFile , LinkedList* pArrayListEntregas)
{
    char bufferId[4096];
    char bufferTipo[4096];
    //char bufferApellido[4096];
    char bufferCantidad[4096];
    //char bufferIntDos[4096];
    char bufferPeso[4096];
    int bufferInt;
    int maxId=-1;
    int retorno=-1;
    Entregas *pEntregas;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferTipo,
                                                  bufferCantidad,
                                                  bufferPeso);

            pEntregas = entregas_newParametros(     bufferId,
                                                    bufferTipo,
                                                    bufferCantidad,
                                                    bufferPeso);



            if(pEntregas!=NULL &&
                ll_add(pArrayListEntregas,pEntregas)==0)
            {
                entregas_getId(pEntregas,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
        }
        entregas_setIdInicial(maxId+1);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEntregas LinkedList*
 * \return int
 *
 */
int parser_EntregasFromBinary(FILE* pFile , LinkedList* pArrayListEntregas)
{
    int retorno=-1;
    Entregas *pEntregas;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEntregas=entregas_new();
            if(pEntregas!=NULL &&
                fread(pEntregas,sizeof(Entregas),1,pFile)&&
                ll_add(pArrayListEntregas,pEntregas)==0)
            {
                entregas_getId(pEntregas,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
            else
            {
                entregas_delete(pEntregas);
            }
        }
        entregas_setIdInicial(maxId+1);
    }
    return retorno;
}
