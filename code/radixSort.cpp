#include "radixSort.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void radixSort(Node** head)
{
    if ((*head) == nullptr) return;

    Node* current = (*head)->ptrNext;
    int iSize = 1;
    int iMax = (*head)->iPayload;

    // Primeiro conseguimos o tamanho e o valor máximo da nossa lista
    while (current != nullptr)
    {
        if (current->iPayload > iMax)
        {
            iMax = current->iPayload;
        }
        iSize++;
        current = current->ptrNext;
    }
    // Criamos um array com a lista
    int* arriList = listToArray(head, iSize);
    // Limpamos a lista original
    clearList(head);

    int potencia = 1;
    // Alocamos memória para o array ordenado
    int* arriResult = (int*) malloc(sizeof(int)*iSize);

    // Enquanato houver casas decimais da potência selecionada continuaremos com o algoritmo
    while (iMax/potencia > 0)
    {   
        // Definimos a contagem de cada algarismo da base como 0
        int arriCount[10] = {0};
        
        // Aumentamos a contagem de cada algarismo
        for (int i=0; i<iSize; i++)
        {
            arriCount[(arriList[i]/potencia) % 10]++;
        }

        // Fazemos a contagem acumulativa dos elementos
        for (int i=1; i<10; i++)
        {
            arriCount[i] += arriCount[i - 1];
        }

        // Checamos o dígito da base e usamos as posições pré-definidas na etapa anterior
        // Para armazenar os valores ordenadamente
        for (int i=iSize-1; i>=0 ; i--)
        {
            int iCurrentDigit = (arriList[i] / potencia) % 10;
            arriResult[arriCount[iCurrentDigit] - 1] = arriList[i];
            arriCount[iCurrentDigit]--;
        }
        // Salvamos a ordenação atual no array original
        for (int i=0; i<iSize; i++)
        {
            arriList[i] = arriResult[i];
        }
        // Atualizamos a potência de base
        potencia = potencia*10;
    }
    free(arriList);

    // Refazemos ela com base no array ordenado
    *head = arrayToList(arriResult, iSize);
    
    free(arriResult);
}
