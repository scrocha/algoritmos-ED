#include "listNodes.h"

using std::cout;

template <typename T>
void insertionSort(Node<T>* ptrFirstNode, int iNumNode)
{
    Node<T>* ptrTempNode = ptrFirstNode->ptrNext;
    Node<T>* ptrNodeReferencia = ptrTempNode;
    for (int iOuterLoop = 1; iOuterLoop < iNumNode; iOuterLoop++)
    {
        while (ptrTempNode->ptrPrev != nullptr && ptrTempNode->iPayload < ptrTempNode->ptrPrev->iPayload)
        {
            int iPayloadTemp = ptrTempNode->ptrPrev->iPayload;
            ptrTempNode->ptrPrev->iPayload = ptrTempNode->iPayload;
            ptrTempNode->iPayload = iPayloadTemp;

            ptrTempNode = ptrTempNode->ptrPrev;
        }
        
        ptrTempNode = ptrNodeReferencia->ptrNext;
        ptrNodeReferencia = ptrNodeReferencia->ptrNext;
    }
}