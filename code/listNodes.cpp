#include "listNodes.h"
#include <iostream>

using std::cout;
using std::endl;

// Cria um novo nó com o payload especificado
Node* createNode(int iPayload){
    Node* temp = new Node();
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

// Exibe os payloads dos nós da lista
void displayList(Node* node){
    if(node == nullptr)
    {
        cout << "Lista Vazia: não é possível realizar displayList" << endl;
        return;
    }
    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    // Percorre a lista até seu fim (ptrNext do último nó é NULL)
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

// Insere um novo nó no início da lista
void insertFront(Node** head, int iPayload){
    Node* newNode = createNode(iPayload);
    
    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }

    (*head) = newNode;
}

// Insere um novo nó no final da lista
void insertEnd(Node** head, int iPayload){
    Node* newNode = createNode(iPayload);
    
    if(*head == nullptr)
    {
        (*head) = newNode;
        return;
    }
    Node* temp = (*head);

    // Percorre a lista até seu fim (ptrNext do último nó é NULL)
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp;
    temp->ptrNext = newNode;
}

// Insere um novo nó após o local especificado
void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    Node* newNode = createNode(iPayload);

    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    ptrLocation->ptrNext = newNode;

    if(newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

// Deleta um nó específico da lista
void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }

    if(*head == ptrDelete) (*head) = ptrDelete->ptrNext;

    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    delete ptrDelete;
}

// Insere um novo nó antes do local especificado
void insertBefore(Node* ptrLocation, int iPayload) {
    if (ptrLocation == nullptr) {
        cout << "Location é NULL." << endl;
        return;
    }

    Node* newNode = createNode(iPayload);

    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;

    if (ptrLocation->ptrPrev != nullptr) {
        ptrLocation->ptrPrev->ptrNext = newNode;
    }
    ptrLocation->ptrPrev = newNode;
}

// Procura um nó com um valor específico na lista
Node* searchNodebyValue(Node** head, int iValue)
{
    if (*head == nullptr)
    {
        cout << "Fila vazia, não foi possível achar o nó." << endl;
        return nullptr;
    }
    Node* current = *head;
    while (current != nullptr && current->iPayload != iValue) current = current->ptrNext;
    if (current == nullptr)
    {
        cout << "Não foi possível achar o nó de valor " << iValue << "." << endl;
        return nullptr;
    }
    return current;
}

// Deleta um nó com um valor específico da lista
void deleteNodebyValue(Node** head, int iValue)
{
    Node* selected = searchNodebyValue(head, iValue);
    if (selected == nullptr) return;

    deleteNode(head, selected);
    return;
}

// Limpa todos os nós da lista
void clearList(Node** head)
{
    Node* current = *head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->ptrNext;
        delete current;
        current = next;
    }
    
    *head = nullptr;
}

// Gera uma lista com valores ascendentes ou descendentes
Node* geradorFila(int iSize, bool bAscending)
{
    Node* head = nullptr;

    if (bAscending)
    {
        for (int i=0; i<iSize; i++)
        {
            insertEnd(&head, i);
        }
    }
    else
    {
        for (int i=0; i<iSize; i++)
        {
            insertEnd(&head, iSize-i-1);
        }        
    }    

    return head;
}

// Gera uma lista com a primeira metade em ordem crescente e a segunda metade em ordem decrescente
Node* geradorFilaMeioOrdenada(int iSize)
{
    Node* head = nullptr;
    
    int iSize2 = (iSize+1)/2;

    for (int i=0; i<iSize2; i++)
    {
        insertFront(&head, i);
        insertEnd(&head, iSize2+i);
    }
    
    return head;
}

// Troca os valores de dois nós
void swapValues(Node* node1, Node* node2)
{
    if (node1->iPayload == node2->iPayload)
    {
        return;
    }
    else if (node1 != nullptr && node2 !=nullptr)
    {
        int iTemp = node1->iPayload;

        node1->iPayload = node2->iPayload;
        node2->iPayload = iTemp;
    }
    else
    {
        cout << "Operação inválida, verifique os nós inseridos." << endl;
    }

    return;
}
