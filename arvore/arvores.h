#ifndef ARVORES_H
#define ARVORES_H

template <typename T>
struct Leaf {
    T iPayload;
    Leaf<T>* ptrLeft;
    Leaf<T>* ptrRight;
};

template <typename T>
Leaf<T>* newLeaf(T);

template <typename T>
Leaf<T>* insertLeaf(Leaf<T>*, T);

template <typename T>
Leaf<T>* searchLeaf(Leaf<T>*, T);

template <typename T>
Leaf<T>* lesserLeaf(Leaf<T>*);

template <typename T>
Leaf<T>* deleteLeaf(Leaf<T>*, T);

template <typename T>
Leaf<T>* createTree(T*, int);

template <typename T>
void traversePreOrder(Leaf<T>*);

template <typename T>
void traverseInOrder(Leaf<T>*);

template <typename T>
void traversePostOrder(Leaf<T>*);

template <typename T>
void generateRandomArray(T*, int, int, int);

template <typename T>
struct Node {
    T iPayload;
    Node<T>* ptrNext;
};

template <typename T>
Node<T>* createNode(T);

template <typename T>
void insertEnd(Node<T>**, T);

#include "arvores.tpp"

#endif