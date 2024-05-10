#ifndef NODE_H
#define NODE_H

typedef struct Node {
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void insertAfter(Node*, int);
void deleteNode(Node**, Node*);
void displayList(Node*);
void insertBefore(Node*, int);
void deleteNodebyValue(Node**, int);
Node* searchNodebyValue(Node**, int);
void clearList(Node**);
void swapValues(Node*, Node*);
Node* geradorFila(int, bool);
Node* geradorFilaMeioOrdenada(int);

#endif
