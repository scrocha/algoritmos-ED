#include "bubbleSort.h"

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