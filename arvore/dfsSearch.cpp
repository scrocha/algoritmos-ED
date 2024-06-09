#include "dfsSearch.h"

Leaf* dfsSearch(Leaf* startingLeaf, int iData)
{
    if (startingLeaf == nullptr) return nullptr;
    else if(iData == startingLeaf->iPayload) return startingLeaf;
    else if(iData < startingLeaf->iPayload) return searchLeaf(startingLeaf->ptrLeft, iData);
    else return searchLeaf(startingLeaf->ptrRight, iData);
}
