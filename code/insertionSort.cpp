#include "insertionSort.h"
#include "listNodes.h"
#include <iostream>

using std::cout;

void insertionSort(Node* ptrFirstNode, int iNumNode)
{
    Node* ptrTempNode = ptrFirstNode->ptrNext;
    Node* ptrNodeReferencia = ptrTempNode;
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