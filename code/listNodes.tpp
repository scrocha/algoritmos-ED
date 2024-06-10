#include <iostream>

using std::cout;
using std::endl;

namespace basicNodeFuncs
{
    // Cria um novo nó com o payload especificado
    template <typename T>
    Node<T>* createNode(T iPayload)
    {
        Node<T>* temp = (Node<T>*) malloc(sizeof(Node<T>));
        temp->iPayload = iPayload;
        temp->ptrNext = nullptr;
        temp->ptrPrev = nullptr;

        return temp;
    }

    // Exibe os payloads dos nós da lista
    template <typename T>
    void displayList(Node<T>* node)
    {
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

        Node<T>* temp = node;

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
    template <typename T>
    void insertFront(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = createNode(iPayload);
        
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
    template <typename T>
    void insertEnd(Node<T>** head, T iPayload)
    {
        Node<T>* newNode = createNode(iPayload);
        
        if(*head == nullptr)
        {
            (*head) = newNode;
            return;
        }
        Node<T>* temp = (*head);

        // Percorre a lista até seu fim (ptrNext do último nó é NULL)
        while(temp->ptrNext != nullptr) temp = temp->ptrNext;

        newNode->ptrPrev = temp;
        temp->ptrNext = newNode;
    }

    // Insere um novo nó após o local especificado
    template <typename T>
    void insertAfter(Node<T>* ptrLocation, T iPayload)
    {
        if (ptrLocation == nullptr)
        {
            cout << "Location é NULL." << endl;
            return;
        }
        Node<T>* newNode = createNode(iPayload);

        newNode->ptrNext = ptrLocation->ptrNext;
        newNode->ptrPrev = ptrLocation;

        ptrLocation->ptrNext = newNode;

        if(newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
    }

    // Deleta um nó específico da lista
    template <typename T>
    void deleteNode(Node<T>** head, Node<T>* ptrDelete)
    {
        if (*head == nullptr || ptrDelete == nullptr)
        {
            cout << "Não foi possível remover." << endl;
            return;
        }

        if(*head == ptrDelete) (*head) = ptrDelete->ptrNext;

        if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

        if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

        free(ptrDelete);
    }

    // Insere um novo nó antes do local especificado
    template <typename T>
    void insertBefore(Node<T>* ptrLocation, T iPayload)
    {
        if (ptrLocation == nullptr) {
            cout << "Location é NULL." << endl;
            return;
        }

        Node<T>* newNode = createNode(iPayload);

        newNode->ptrNext = ptrLocation;
        newNode->ptrPrev = ptrLocation->ptrPrev;

        if (ptrLocation->ptrPrev != nullptr) {
            ptrLocation->ptrPrev->ptrNext = newNode;
        }
        ptrLocation->ptrPrev = newNode;
    }

    // Procura um nó com um valor específico na lista
    template <typename T>
    Node<T>* searchNodebyValue(Node<T>** head, T iValue)
    {
        if (*head == nullptr)
        {
            cout << "Fila vazia, não foi possível achar o nó." << endl;
            return nullptr;
        }
        Node<T>* current = *head;
        while (current != nullptr && current->iPayload != iValue) current = current->ptrNext;
        if (current == nullptr)
        {
            cout << "Não foi possível achar o nó de valor " << iValue << "." << endl;
            return nullptr;
        }
        return current;
    }

    // Deleta um nó com um valor específico da lista
    template <typename T>
    void deleteNodebyValue(Node<T>** head, T iValue)
    {
        Node<T>* selected = searchNodebyValue(head, iValue);
        if (selected == nullptr) return;

        deleteNode(head, selected);
        return;
    }

    // Limpa todos os nós da lista
    template <typename T>
    void clearList(Node<T>** head)
    {
        Node<T>* current = *head;
        Node<T>* next = nullptr;

        while (current != nullptr)
        {
            next = current->ptrNext;
            free(current);
            current = next;
        }
        
        *head = nullptr;
    }
}
// Gera uma lista com valores ascendentes ou descendentes
template <typename T>
Node<T>* geradorFila(int iSize)
{
    Node<T>* head = nullptr;

    for (int i=0; i<iSize; i++)
    {
        basicNodeFuncs::insertEnd(&head, i%100 + 1);
    }

    return head;
}

// Gera uma lista com a primeira metade em ordem crescente e a segunda metade em ordem decrescente
template <typename T>
Node<T>* geradorFilaReversa(int iSize)
{
    Node<T>* head = nullptr;
    
    for (int i=0; i<iSize; i++)
    {
        basicNodeFuncs::insertEnd(&head, iSize - i % 100 - 1);
    }
    
    return head;
}

// Troca os valores de dois nós
template <typename T>
void swapValues(Node<T>* node1, Node<T>* node2)
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

template <typename T>
T* listToArray(Node<T>** head, int iSize)
{
    T *arriValores = (T*) malloc(sizeof(T)*iSize);
    Node<T>* current = (*head);

    for (int i=0; i<iSize; i++)
    {
        arriValores[i] = current->iPayload;
        current = current->ptrNext;
    }

    return arriValores;
}

template <typename T>
Node<T>* arrayToList(T* arriValores, int iSize)
{
    Node<T>* head = nullptr;

    for (int i=0; i<iSize; i++)
    {
        basicNodeFuncs::insertEnd(&head, arriValores[i]);
    }

    return head;
}
