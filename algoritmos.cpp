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
void bubbleSort(Node*, int);
void bubbleSortOtimizado(Node*, int);
void swapValues(Node*, Node*);
void selectionSort(Node*);
void selectionSortOtimizado(Node*);

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

void bubbleSort(Node* ptrFirstNode, int iNumNode)
{   
    // Inicializa um ponteiro temporário para percorrer a lista
    Node* tempNode = ptrFirstNode;

    // Percorre a lista 'iNumNode - 1' vezes, onde 'iNumNode' é o número de elementos na lista
    for (int i = 1; i < iNumNode; i++)
    {   
        // Enquanto não chegarmos ao final da lista
        while (tempNode->ptrNext != nullptr)
        {   
            // Se o elemento atual for maior que o próximo, troca suas posições
            if (tempNode->iPayload > tempNode->ptrNext->iPayload)
            {
                swapValues(tempNode, tempNode->ptrNext);
            }
            // Move para o próximo elemento na lista
            tempNode = tempNode->ptrNext;
        }
        // Reinicia o ponteiro temporário de volta para o primeiro elemento da lista
        tempNode = ptrFirstNode;
    }
}

void bubbleSortOtimizado(Node* ptrFirstNode, int iNumNode)
{   
    // Inicializa um ponteiro temporário para percorrer a lista
    Node* tempNode = ptrFirstNode;
    // Variável para indicar se a lista está desordenada
    bool bDesordenado = false;

    // Percorre a lista 'iNumNode - 1' vezes, onde 'iNumNode' é o número de elementos na lista
    for (int i = 1; i < iNumNode; i++)
    {   
        // Inicializa a flag de desordem como falso
        bDesordenado = false;

        // Percorre a lista, diminuindo o número de comparações a cada iteração
        for (int j = 1; j < iNumNode - i + 1 ; j++)
        {   
            // Se um elemento for maior que o próximo, troca suas posições
            if (tempNode->iPayload > tempNode->ptrNext->iPayload)
            {
                swapValues(tempNode, tempNode->ptrNext);
                // Atualiza a flag para indicar que a lista está desordenada
                bDesordenado = true;
            }

            // Move para o próximo elemento na lista
            tempNode = tempNode->ptrNext;
        }
        // Reinicia o ponteiro temporário de volta para o primeiro elemento da lista
        tempNode = ptrFirstNode;

        // Se percorreu a lista e não fez nenhuma troca, interrompe a iteração
        if (!bDesordenado) break;
    }
}

void selectionSort(Node* ptrFirstNode)
{
    // Inicializa o ponteiro para o nó inicial a ser comparado
    Node* current = ptrFirstNode;
    // Loop para comparar todos os nós até chegar ao final
    while (current != nullptr)
    {
        // Ponteiro temporário para a comparação com os elementos adjascentes da lista
        Node* tempNode = current->ptrNext;
        // Percorre os valores adjascentes da lista
        while (tempNode != nullptr)
        {
            // Compara se houve algum valor menor
            if (tempNode->iPayload < current->iPayload)
            {
                //  Troca os valores caso haja algum menor
                swapValues(current, tempNode);
            }
            // Atualiza o ponteiro temporário
            tempNode = tempNode->ptrNext;
        }
        // Atualiza o ponteiro a ser comparado
        current = current->ptrNext;
    }

}

void selectionSortOtimizado(Node* ptrFirstNode)
{
    // Inicializa o ponteiro para o nó inicial a ser comparado
    Node* current = ptrFirstNode;
    // Loop para comparar todos os nós até chegar ao final, mas agora sem chegar ao
    // último nó, pois ele não possui ponteiros adjascentes então não precisa ser comparado
    while (current->ptrNext != nullptr)
    {
        // Ponteiro com o menor valor até o momento
        Node* minNode = current;
        // Ponteiro temporário para a comparação com os elementos adjascentes da lista
        Node* tempNode = current->ptrNext;
        // Percorre os valores adjascentes da lista
        while (tempNode != nullptr)
        {
            // Se o valor comparado for menor que o menor valor atual então atualiza o menor valor
            if (tempNode->iPayload < minNode->iPayload)
            {
                minNode = tempNode;
            }
            // Atualiza o ponteiro temporário
            tempNode = tempNode->ptrNext;
        }
        // Realiza apenas a troca do ponteiro atual com o menor dos ponteiros adjascentes
        swapValues(current, minNode);
        // Atualiza o ponteiro atual para dar seguimento ao loop
        current = current->ptrNext;
    }

}
