#include <iostream>
#include <chrono>

#include "arvores.h"
#include "bfsSearch.h"
#include "dfsSearch.h"

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;

int main()
{
    cout << "TEMPO_CRIACAO, TEMPO_BFS, TEMPO_DFS" << "\n"; 
    for (int i = 0; i < 100; i++)
    {
        int* arr = new int[10000];
        generateRandomArray(arr, 10000, 1, 1000);

        auto timeStart0 = high_resolution_clock::now();
        Leaf* ptrTree = createTree(arr, 10000);
        auto timeStop0 = high_resolution_clock::now();
        auto timeDuration0 = duration_cast<nanoseconds>(timeStop0 - timeStart0);
        cout << timeDuration0.count() << ",";

        auto timeStart1 = high_resolution_clock::now();
        Leaf* ptrTarget1 = bfsSearch(ptrTree, 42);
        auto timeStop1 = high_resolution_clock::now();
        auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
        cout << timeDuration1.count() << ",";

        auto timeStart2 = high_resolution_clock::now();
        Leaf* ptrTarget2 = dfsSearch(ptrTree, 42);
        auto timeStop2 = high_resolution_clock::now();
        auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);
        cout << timeDuration2.count() << endl;
    }

    return 0;
}