#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);



/** \brief Incrementa en 1 el size de la lista
 *
 * \param this LinkedList* Lista
 * \return int -1 si el puntero es NULL, 0 si pudo hacerlo.
 *
 */
int ll_increase_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size +=1;
        retVal = 0;
    }
    return retVal;
}
/** \brief Decrementa el size de la lista
 *
 * \param this LinkedList* Lista
 * \return int -1 si el puntero es NULL, 0 si pudo hacerlo.
 *
 */
int ll_decrease_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size--;
        retVal = 0;
    }
    return retVal;
}

/** \brief
 *
 * \param this LinkedList*
 * \param pNode Node*
 * \return int
 *
 */
int ll_setFirstNode(LinkedList* this, Node* pNode)
{
    int retorno = -1;

    if(this !=NULL && pNode != NULL)
    {
        this->pFirstNode = pNode;
        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param this LinkedList*
 * \param pNode Node*
 * \return int
 *
 */
int ll_setNextNode(Node* this, Node* nextNode)
{
    int retorno = -1;

    if(this !=NULL && nextNode != NULL)
    {
        this->pNextNode = nextNode;
        retorno = 0;
    }
    return retorno;
}

/** \brief
 *
 * \param this Node*
 * \param pElement void*
 * \return int
 *
 */
int ll_set_NodeElement(Node* this, void* pElement)
{
    int retorno = -1;
    if (this!=NULL)
    {
        this->pElement = pElement;
        retorno = 0;
    }
    return retorno;
}

int ll_set_Size(LinkedList* this, int size)
{
    int retorno = -1;
    if (this!=NULL)
    {
        this->size = size;
        retorno = 0;
    }
    return retorno;
}



/** \brief
 *
 * \param this LinkedList*
 * \return Node*
 *
 */
Node* ll_get_firstNode(LinkedList* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pFirstNode;
    }
    return retornoNode;

}

/** \brief
 *
 * \param this LinkedList*
 * \return Node*
 *
 */
Node* ll_get_LastNode(LinkedList* this)
{

    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        if (ll_isEmpty(this)==0)
        {
            Node* lastNode = ll_get_firstNode(this);
            while (lastNode!=NULL)
            {
                retornoNode = lastNode;
                lastNode = ll_get_NextNode(retornoNode);
            }
        }
    }
    return retornoNode;
}

/** \brief
 *
 * \param this Node*
 * \return Node*
 *
 */
Node* ll_get_NextNode(Node* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pNextNode;
    }
    return retornoNode;


}

Node* ll_get_NodeElement(Node* this)
{
   void* ret = NULL;
    if (this!=NULL)
    {
        ret = this->pElement;
    }
    return ret;


}

Node* ll_get_Size(LinkedList* this)
{
    void* retorno = NULL;
    if (this!=NULL)
    {
        retorno = this->size;
    }
    return retorno;

}


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
        ll_set_Size(this, 0);
       // this->size=0;
        ll_setFirstNode(this, NULL);
        //this->pFirstNode = NULL;
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
    if(this != NULL)
    {
        returnAux = ll_get_Size(this);
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor o igual al len de la lista)
 *                   (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

    if(this == NULL || nodeIndex < 0 || nodeIndex >=ll_len(this))
    {
        return NULL;
    }

    Node *pNode = this->pFirstNode;
    int actualIndex = 0;

    while(pNode != NULL)
    {
        if(actualIndex == nodeIndex)
        {
            return pNode;
        }

        actualIndex++;

        pNode = pNode->pNextNode;

    }

    return NULL;

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
{/*
    Node* pNewNode;

    if(this == NULL || nodeIndex < 0 || nodeIndex >=ll_len(this))
    {
        return -1;
    }

    pNewNode = (Node*)malloc(sizeof(Node));
    if(pNewNode != NULL)
    {
        ll_set
        pNewNode->pElement = pElement;
        ll_setNextNode(pNewNode, NULL);
        //pNewNode->pNextNode = NULL;
        if(nodeIndex == 0)
        {
            pNewNode->pNextNode = this->pFirstNode;
            this->pFirstNode = pNewNode;
        }


    }*/
    return 0;

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

    if(this == NULL)
    {
        return -1;
    }



    return 0;
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
    int returnAux = -1;

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
        Node* firstNode = ll_get_firstNode(this);
        if (firstNode!=NULL)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
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
    int returnAux = -1;

    return returnAux;
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
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

