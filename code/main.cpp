#include "listNodes.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"

#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

float tempoMedioDeExecucao(Node*, int, int);

int main(){
    int iNumeroIteracoes = 10;
    int iNumeroDeElementos = 10000;
    Node* ptrHead = nullptr;
    float tempo = 0;
    
    cout << "\nLista Invertida: \n" << endl;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFila(iNumeroDeElementos, false);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 1, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (bubble sort): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFila(iNumeroDeElementos, false);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 2, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (bubble sort otimizado): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFila(iNumeroDeElementos, false);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 3, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (selection): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFila(iNumeroDeElementos, false);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 4, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (selection otimizado): " << tempo/iNumeroIteracoes << " nanosegundos.\n";

    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 5, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (insertion): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    cout << "\nLista Meio Ordenada: \n" << endl;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 1, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (bubble sort): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 2, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (bubble sort otimizado): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 3, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (selection): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 4, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (selection otimizado): " << tempo/iNumeroIteracoes << " nanosegundos.\n";

    tempo = 0;
    for (int i = 0; i < iNumeroIteracoes; i++)
    {
        ptrHead = geradorFilaMeioOrdenada(iNumeroDeElementos);
        tempo = tempo + tempoMedioDeExecucao(ptrHead, 5, iNumeroDeElementos);
    }
    cout << "Tempo de execução médio (insertion): " << tempo/iNumeroIteracoes << " nanosegundos.\n";
    
    return 0;
}

float tempoMedioDeExecucao(Node* head, int iMetodo, int iNumNode)
{
    auto timeStart = high_resolution_clock::now();
    
    switch (iMetodo)
    {
        case 1:
            bubbleSort(head, iNumNode);
            break;
        case 2:
            bubbleSortOtimizado(head, iNumNode);
            break;
        case 3:
            selectionSort(head);
            break;
        case 4:
            selectionSortOtimizado(head);
            break;
        case 5:
            insertionSort(head, iNumNode);
        default:
            cout << "\nMétodo Inválido\n" << endl;
            break;
    }

    auto timeStop = high_resolution_clock::now();

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    return timeDuration.count();
}