#ifndef ARVORES_H
#define ARVORES_H

#include <iostream>
#include <random>

typedef struct Leaf
{
  int iPayload;
  
  Leaf* ptrLeft;
  Leaf* ptrRight;

} Leaf;

Leaf* newLeaf(int);
Leaf* insertLeaf(Leaf*, int);
Leaf* searchLeaf(Leaf*, int);
Leaf* lesserLeaf(Leaf*);
Leaf* deleteLeaf(Leaf*, int);
Leaf* createTree(int[], int);

void traversePreOrder(Leaf*);
void traverseInOrder(Leaf*);
void traversePostOrder(Leaf*);

void generateRandomArray(int*, int, int, int);

#endif