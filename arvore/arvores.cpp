#include "arvores.h"

using namespace std;

Leaf* createTree(int* iarrLeaf, int iNumLeafs)
{
    Leaf* ptrRoot = newLeaf(iarrLeaf[0]);

    for(int i = 1; i < iNumLeafs; i++)
    {
        ptrRoot = insertLeaf(ptrRoot, iarrLeaf[i]);
    }

    return ptrRoot;
}

Leaf* newLeaf(int iData)
{
    Leaf* ptrTemp = (Leaf*) malloc(sizeof(Leaf));
    
    if (ptrTemp == nullptr)
    {
        cerr << "Erro em createLeaf: malloc." << endl;
        exit(1);
    }
    
    ptrTemp->iPayload = iData;
    ptrTemp->ptrRight = nullptr;
    ptrTemp->ptrLeft = nullptr;
    
    return ptrTemp;
}

Leaf* insertLeaf(Leaf* startingLeaf, int iData)
{
    if(startingLeaf == nullptr)
    {
        return newLeaf(iData);
    }
    
    if(iData < startingLeaf->iPayload)
    {
        startingLeaf->ptrLeft = insertLeaf(startingLeaf->ptrLeft, iData);
    }
    else
    {
        startingLeaf->ptrRight = insertLeaf(startingLeaf->ptrRight, iData);
    }
    
    return startingLeaf;
}

Leaf* searchLeaf(Leaf* startingLeaf, int iData)
{
    if (startingLeaf == nullptr) return nullptr;
    else if(iData == startingLeaf->iPayload) return startingLeaf;
    else if(iData < startingLeaf->iPayload) return searchLeaf(startingLeaf->ptrLeft, iData);
    else return searchLeaf(startingLeaf->ptrRight, iData);
}

Leaf* lesserLeaf(Leaf* startingLeaf)
{
    Leaf* ptrCurrent = startingLeaf;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

Leaf* deleteLeaf(Leaf* startingLeaf, int iData) {
    if (startingLeaf == nullptr) return nullptr;
    
    if (iData < startingLeaf->iPayload)
    {
        startingLeaf->ptrLeft = deleteLeaf(startingLeaf->ptrLeft, iData);
    }
    else if (iData > startingLeaf->iPayload)
    {
        startingLeaf->ptrRight = deleteLeaf(startingLeaf->ptrRight, iData);
    }
    else
    {
        Leaf* ptrTempLeaf = nullptr;
        // ou ele tem um filho a direita, ou ele não tem nenhum
        if (startingLeaf->ptrLeft == nullptr)
        {
            ptrTempLeaf = startingLeaf->ptrRight;
            free(startingLeaf);
            return ptrTempLeaf;
        }
        // ou ele tem um filho a esquerda, ou não tem nenhum
        else if (startingLeaf->ptrRight == nullptr)
        {
            ptrTempLeaf = startingLeaf->ptrLeft;
            free(startingLeaf);
            return ptrTempLeaf;
        }
        // ele tem dois filhos (caso grave) - vou buscar o menor nó, maior que o nó em questão
        ptrTempLeaf = lesserLeaf(startingLeaf->ptrRight);
        startingLeaf->iPayload = ptrTempLeaf->iPayload;
        
        // vou buscar o elemento e apagá-lo
        startingLeaf->ptrRight = deleteLeaf(startingLeaf->ptrRight, ptrTempLeaf->iPayload);
    }
    
    return startingLeaf;
}

void traversePreOrder(Leaf* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        cout << " " << ptrStartingLeaf->iPayload;
        traversePreOrder(ptrStartingLeaf->ptrLeft);
        traversePreOrder(ptrStartingLeaf->ptrRight);
    }
}

void traverseInOrder(Leaf* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        traverseInOrder(ptrStartingLeaf->ptrLeft);
        cout << " " << ptrStartingLeaf->iPayload;
        traverseInOrder(ptrStartingLeaf->ptrRight);
    }
}

void traversePostOrder(Leaf* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        traversePostOrder(ptrStartingLeaf->ptrLeft);
        traversePostOrder(ptrStartingLeaf->ptrRight);
        cout << " " << ptrStartingLeaf->iPayload;
    }
}