#include "listNodes.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "radixSort.h"

#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

namespace Tempo
{
    const int iNumeroIteracoes = 10;
    const int iNumeroDeElementos = 100;

    float tempoDeExecucao(Node<int>* head, int iMetodo, int iNumNode)
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
                break;
            case 6:
                radixSort(&head);
            default:
                break;
        }

        auto timeStop = high_resolution_clock::now();

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        return timeDuration.count();
    }
}

int main(){
    cout << "BUBBLESORT, BUBBLESORT_OT, SELECTIONSORT, SELECTIONSORT_OT, INSERTION, RADIX" << "\n";

    for(int i = 1; i <= Tempo::iNumeroIteracoes; i++)
    {
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 1, Tempo::iNumeroDeElementos) << ",";
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 2, Tempo::iNumeroDeElementos) << ",";
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 3, Tempo::iNumeroDeElementos) << ",";
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 4, Tempo::iNumeroDeElementos) << ",";
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 5, Tempo::iNumeroDeElementos) << "\n";
        cout << Tempo::tempoDeExecucao(geradorFilaMeioOrdenada<int>(Tempo::iNumeroDeElementos), 6, Tempo::iNumeroDeElementos) << "\n";
    }

    return 0;
}