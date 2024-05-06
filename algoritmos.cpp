#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

typedef struct Node{
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

void swapValues(Node*, Node*);

int main(){
    Node* head = nullptr;
    // displayList(head);
    // cout << "=================================" << endl;

    return 0;
}

Node* createNode(int iPayload){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

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

    // Percorremos a lista até seu fim (ptrNext do último nó é NULL)
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }

    cout << endl;
}

void insertFront(Node** head, int iPayload){
    Node* newNode = createNode(iPayload);
    //newNode->ptrPrev = nullptr;

    if (*head != nullptr)
    {
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }

    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload){
    Node* newNode = createNode(iPayload);
    //newNode->ptrNext = nullptr;

    if(*head == nullptr)
    {
        //newNode->ptrPrev = nullptr;
        (*head) = newNode;
        return;
    }
    Node* temp = (*head);

    // Prercorremos a lista até seu fim (ptrNext do último nó é NULL)
    while(temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev = temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; // antigo último elemento aponta para o novo nó
}

void insertAfter(Node* ptrLocation, int iPayload)
{
    if (ptrLocation == nullptr)
    {
        cout << "Location é NULL." << endl;
        return;
    }
    Node* newNode = createNode(iPayload);

    //Corrigir nó a ser inserido
    newNode->ptrNext = ptrLocation->ptrNext;
    newNode->ptrPrev = ptrLocation;

    //Corrigir o ponto de inserção
    ptrLocation->ptrNext = newNode;

    if(newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

void deleteNode(Node** head, Node* ptrDelete)
{
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível remover." << endl;
        return;
    }

    //Caso o ptrDelete seja o primeiro elemento da lista
    if(*head == ptrDelete) (*head) = ptrDelete->ptrNext;

    //Se o ptrDelete não é o último nó
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;

    //Se o ptrDelete não é o primeiro nó
    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete);
}

void insertBefore(Node* ptrLocation, int iPayload) {
    if (ptrLocation == nullptr) {
        cout << "Location é NULL." << endl;
        return;
    }

    Node* newNode = createNode(iPayload); // Cria um novo nó com o payload fornecido

    // Configura os ponteiros do novo nó para inseri-lo antes de ptrLocation
    newNode->ptrNext = ptrLocation;
    newNode->ptrPrev = ptrLocation->ptrPrev;

    // Se o ptrLocation é o primeiro nó da lista
    if (ptrLocation->ptrPrev != nullptr) {
        ptrLocation->ptrPrev->ptrNext = newNode; // Atualiza o próximo do anterior para o novo nó
    }
    ptrLocation->ptrPrev = newNode; // Atualiza o anterior do ptrLocation para o novo nó
}

Node* searchNodebyValue(Node** head, int iValue)
{
    // Verifica se a fila é vazia
    if (*head == nullptr)
    {
        cout << "Fila vazia, não foi possível achar o nó." << endl;
        return nullptr;
    }
    // Percorre a lista até encontrar o nó procurado ou chegar ao fim da fila
    Node* current = *head;
    while (current != nullptr && current->iPayload != iValue) current = current->ptrNext;
    // Verifica se não achou o nó na fila
    if (current == nullptr)
    {
        cout << "Não foi possível achar o nó de valor " << iValue << "." << endl;
        return nullptr;
    }
    // Se já foi encontrado apenas o retorna
    return current;
}

void deleteNodebyValue(Node** head, int iValue)
{
    // Faz a busca do nó
    Node* selected = searchNodebyValue(head, iValue); // Aqui usamos a implementação do exercício 3

    // Verifica se ele foi encontrado
    if (selected == nullptr) return;

    // Por fim, deleta o nó
    deleteNode(head, selected); // Aqui usamos a função já implementada deleteNode
    return;
}

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
