#include "dfsSearch.h"

Leaf* dfsSearch(Leaf* ptrRoot, int iVal)
{
    if (ptrRoot == nullptr || ptrRoot->iPayload == iVal)
        return ptrRoot;

    Leaf* found = dfsSearch(ptrRoot->ptrLeft, iVal);
    if (found != nullptr) return found;

    return dfsSearch(ptrRoot->ptrRight, iVal);
}
