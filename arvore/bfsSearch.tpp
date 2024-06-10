#include "arvores.h"

template <typename T>
Leaf<T>* bfsSearch(Leaf<T>* ptrRoot, T iValor)
{
    Node<Leaf<T>*>* ptrHead = createNode(ptrRoot);
    Node<Leaf<T>*>* ptrTemp = ptrHead;

    while (ptrTemp != nullptr && ptrTemp->iPayload->iPayload != iValor) {
        if (ptrTemp->iPayload->ptrLeft != nullptr) {
            insertEnd(&ptrHead, ptrTemp->iPayload->ptrLeft);
        }
        if (ptrTemp->iPayload->ptrRight != nullptr) {
            insertEnd(&ptrHead, ptrTemp->iPayload->ptrRight);
        }
        ptrTemp = ptrTemp->ptrNext;
    }

    // caso ele encontre, vai retornar o ponteiro para o nó
    if (ptrTemp != nullptr && ptrTemp->iPayload->iPayload == iValor) {
        return ptrTemp->iPayload;
    }

    // caso ele não encontre, ou seja, chegue no final da lista
    return nullptr;
}