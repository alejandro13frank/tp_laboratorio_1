#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    Node* pNode=NULL;
    if (this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        pNode=this->pFirstNode;
        for(i=0;i<nodeIndex;i++)
        {
           pNode=pNode->pNextNode;
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode = (Node*) malloc(sizeof(Node));
    Node* pAuxNode;
    int lenLista;
    lenLista=ll_len(this);
    if (this!=NULL && nodeIndex>=0 && nodeIndex<=lenLista &&
        pNode!=NULL)
    {

        if (nodeIndex==0)
        {
            pNode->pElement=pElement;
            pNode->pNextNode=this->pFirstNode;
            this->pFirstNode=pNode;
            this->size++;
            returnAux=0;
        }
        else
        {
            pAuxNode = getNode(this,nodeIndex-1);
            pNode->pNextNode=pAuxNode->pNextNode;
            pNode->pElement=pElement;
            pAuxNode->pNextNode=pNode;
            this->size++;
            returnAux=0;
        }
    }
    else
    {
        free(pNode);
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lenLista;
    if (this!=NULL)
    {
        lenLista=ll_len(this);
        returnAux=addNode(this,lenLista,pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pAuxNode;
    if (this!=NULL)
    {
        pAuxNode=getNode(this,index);
        if (pAuxNode!=NULL)
        {
            returnAux=pAuxNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAuxNode;
    if (this!=NULL)
    {
        pAuxNode=getNode(this,index);
        if (pAuxNode!=NULL)
        {
            pAuxNode->pElement=pElement;
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pAuxNode;
    Node* pAuxNodeBorrar;
    if (this!=NULL)
    {
        pAuxNode=getNode(this,index);
        if (pAuxNode!=NULL)
        {
            if (index==0)
            {
                pAuxNodeBorrar=this->pFirstNode;
                this->pFirstNode=pAuxNodeBorrar;
                free(pAuxNodeBorrar);
                returnAux=0;
                this->size--;
            }
            else
            {
                pAuxNode=getNode(this,index-1);
                pAuxNodeBorrar=pAuxNode->pNextNode;
                pAuxNode->pNextNode=pAuxNodeBorrar->pNextNode;
                free(pAuxNodeBorrar);
                returnAux=0;
                this->size--;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int i;
    int returnAux = -1;
    int lenLista;
    if (this!=NULL)
    {
        lenLista=ll_len(this);
        for(i=0;i<lenLista;i++)
        {
            ll_remove(this,0);
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL && ll_clear(this)==0)
    {
        free(this);
        returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int lenLista;
    Node *pAuxNode;
    if (this!=NULL)
    {
        lenLista=ll_len(this);
        pAuxNode=this->pFirstNode;
        for(i=0;i<lenLista;i++)
        {
            if(pAuxNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
            pAuxNode=pAuxNode->pNextNode;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if (this!=NULL)
    {
        if (this->size==0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pAuxNode;
    Node* pAuxNodeBorrar;
    if (this!=NULL)
    {
        pAuxNode=getNode(this,index);
        if (pAuxNode!=NULL)
        {
            if (index==0)
            {
                pAuxNodeBorrar=this->pFirstNode;
                this->pFirstNode=pAuxNodeBorrar;
                returnAux=pAuxNodeBorrar->pElement;
                free(pAuxNodeBorrar);
                this->size--;
            }
            else
            {
                pAuxNode=getNode(this,index-1);
                pAuxNodeBorrar=pAuxNode->pNextNode;
                pAuxNode->pNextNode=pAuxNodeBorrar->pNextNode;
                returnAux=pAuxNodeBorrar->pElement;
                free(pAuxNodeBorrar);
                this->size--;
            }
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int buffer;
    if(this!=NULL)
    {
        buffer=ll_indexOf(this,pElement);
        if (buffer>=0)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int lenLista;
    int i;
    Node *auxNodeThis2;
    if (this!=NULL && this2!=NULL)
    {
        lenLista=ll_len(this2);
        if (ll_len(this)<lenLista)
        {
            returnAux=0;
        }
        else
        {
            auxNodeThis2=this->pFirstNode;
            for(i=0;i<lenLista;i++)
            {
                if (!ll_contains(this,auxNodeThis2->pElement))
                {
                    break;
                }
                auxNodeThis2=auxNodeThis2->pNextNode;
            }
            if(i==lenLista)
            {
                returnAux=1;
            }
            else
            {
                returnAux=0;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int lenLista=ll_len(this);
    Node *pAuxNode;
    if (this!=NULL && from>=0 && from<lenLista && to>from && to<=lenLista)
    {
        cloneArray=ll_newLinkedList();
        if (cloneArray!=NULL)
        {
            for(i=from;i<to;i++)
            {
                pAuxNode=getNode(this,i);
                addNode(cloneArray,i,pAuxNode->pElement);
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this,0,ll_len(this));
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int flagNoEstaOrdenado=1;
    int lenLista=ll_len(this);
    Node *pNodeA;
    Node *pNodeB;
    void *pAuxElement;
    if (this!=NULL && pFunc!=NULL && (order==0 || order==1))
    {
        if(lenLista>=2)
        {
            while(flagNoEstaOrdenado==1)
            {
                flagNoEstaOrdenado=0;
                pNodeA=this->pFirstNode->pNextNode;
                pNodeB=this->pFirstNode;
                for(i=1;i<lenLista;i++)
                {
                    if (order==0 && pFunc(pNodeA->pElement,pNodeB->pElement)>0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    if(order==1 && pFunc(pNodeA->pElement,pNodeB->pElement)<0)
                    {
                        pAuxElement=pNodeA->pElement;
                        pNodeA->pElement=pNodeB->pElement;
                        pNodeB->pElement=pAuxElement;
                        flagNoEstaOrdenado=1;
                    }
                    pNodeA=pNodeA->pNextNode;
                    pNodeB=pNodeB->pNextNode;
                }
            }
            returnAux=0;
        }
        else
        {
            returnAux=0;
        }
    }
    return returnAux;
}

