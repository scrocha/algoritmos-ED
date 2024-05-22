#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T iPayload;
    Node<T>* ptrNext;
    Node<T>* ptrPrev;
};

#include "listNodes.tpp"

namespace basicNodeFuncs
{
    template <typename T>
    Node<T>* createNode(T);

    template <typename T>
    void displayList(Node<T>*);

    template <typename T>
    void insertFront(Node<T>**, T);

    template <typename T>
    void insertEnd(Node<T>**, T);

    template <typename T>
    void insertAfter(Node<T>*, T);

    template <typename T>
    void deleteNode(Node<T>**, Node<T>*);

    template <typename T>
    void insertBefore(Node<T>*, T);

    template <typename T>
    Node<T>* searchNodebyValue(Node<T>**, T);

    template <typename T>
    void deleteNodebyValue(Node<T>**, T);

    template <typename T>
    void clearList(Node<T>**);
}

template <typename T>
Node<T>* geradorFila(int);

template <typename T>
Node<T>* geradorFilaReversa(int);

template <typename T>
void swapValues(Node<T>*, Node<T>*);

template <typename T>
T* listToArray(Node<T>**, int);

template <typename T>
Node<T>* arrayToList(T*, int);

#endif
