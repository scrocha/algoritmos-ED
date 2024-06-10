#include "arvores.h"

template <typename T>
Leaf<T>* dfsSearch(Leaf<T>* ptrRoot, T iVal)
{
    if (ptrRoot == nullptr || ptrRoot->iPayload == iVal)
        return ptrRoot;

    Leaf<T>* found = dfsSearch(ptrRoot->ptrLeft, iVal);
    if (found != nullptr) return found;

    return dfsSearch(ptrRoot->ptrRight, iVal);
}
