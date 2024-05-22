#include "listNodes.h"

template <typename T>
void selectionSort(Node<T>* ptrFirstNode)
{
    // Inicializa o ponteiro para o nó inicial a ser comparado
    Node<T>* current = ptrFirstNode;
    // Loop para comparar todos os nós até chegar ao final
    while (current != nullptr)
    {
        // Ponteiro temporário para a comparação com os elementos adjascentes da lista
        Node<T>* tempNode = current->ptrNext;
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

template <typename T>
void selectionSortOtimizado(Node<T>* ptrFirstNode)
{
    // Inicializa o ponteiro para o nó inicial a ser comparado
    Node<T>* current = ptrFirstNode;
    // Loop para comparar todos os nós até chegar ao final, mas agora sem chegar ao
    // último nó, pois ele não possui ponteiros adjascentes então não precisa ser comparado
    while (current->ptrNext != nullptr)
    {
        // Ponteiro com o menor valor até o momento
        Node<T>* minNode = current;
        // Ponteiro temporário para a comparação com os elementos adjascentes da lista
        Node<T>* tempNode = current->ptrNext;
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