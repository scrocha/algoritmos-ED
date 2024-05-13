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

float tempoDeExecucao(Node*, int, int);

int main(){
    int iNumeroIteracoes = 10;
    int iNumeroDeElementos = 10000;
    Node* ptrHead = nullptr;
    float tempo = 0;

    cout << "BUBBLESORT, BUBBLESORT_OT, SELECTIONSORT, SELECTIONSORT_OT, INSERTION" << "\n";

    for(int i = 1; i <= 100; i++)
    {
        cout << tempoDeExecucao(geradorFilaMeioOrdenada(iNumeroDeElementos), 1, iNumeroDeElementos) << ",";
        cout << tempoDeExecucao(geradorFilaMeioOrdenada(iNumeroDeElementos), 2, iNumeroDeElementos) << ",";
        cout << tempoDeExecucao(geradorFilaMeioOrdenada(iNumeroDeElementos), 3, iNumeroDeElementos) << ",";
        cout << tempoDeExecucao(geradorFilaMeioOrdenada(iNumeroDeElementos), 4, iNumeroDeElementos) << ",";
        cout << tempoDeExecucao(geradorFilaMeioOrdenada(iNumeroDeElementos), 5, iNumeroDeElementos) << "\n";
    }
    
    return 0;
}

float tempoDeExecucao(Node* head, int iMetodo, int iNumNode)
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
            break;
    }

    auto timeStop = high_resolution_clock::now();

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    return timeDuration.count();
}