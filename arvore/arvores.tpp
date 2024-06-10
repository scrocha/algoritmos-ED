#include <iostream>
#include <random>

using namespace std;

template <typename T>
Leaf<T>* newLeaf(T iData) {
    Leaf<T>* ptrTemp = (Leaf<T>*) malloc(sizeof(Leaf<T>));
    
    if (ptrTemp == nullptr) {
        cerr << "Erro em newLeaf: malloc." << endl;
        exit(1);
    }
    
    ptrTemp->iPayload = iData;
    ptrTemp->ptrRight = nullptr;
    ptrTemp->ptrLeft = nullptr;
    
    return ptrTemp;
}

template <typename T>
Leaf<T>* createTree(T* iarrLeaf, int iNumLeafs)
{
    Leaf<T>* ptrRoot = newLeaf(iarrLeaf[0]);

    for(int i = 1; i < iNumLeafs; i++)
    {
        ptrRoot = insertLeaf(ptrRoot, iarrLeaf[i]);
    }

    return ptrRoot;
}


template <typename T>
Leaf<T>* insertLeaf(Leaf<T>* startingLeaf, T iData)
{
    if(startingLeaf == nullptr)
    {
        return newLeaf(iData);
    }
    
    if(iData < startingLeaf->iPayload)
    {
        startingLeaf->ptrLeft = insertLeaf(startingLeaf->ptrLeft, iData);
    }
    else
    {
        startingLeaf->ptrRight = insertLeaf(startingLeaf->ptrRight, iData);
    }
    
    return startingLeaf;
}

template <typename T>
Leaf<T>* searchLeaf(Leaf<T>* startingLeaf, T iData)
{
    if (startingLeaf == nullptr) return nullptr;
    else if(iData == startingLeaf->iPayload) return startingLeaf;
    else if(iData < startingLeaf->iPayload) return searchLeaf(startingLeaf->ptrLeft, iData);
    else return searchLeaf(startingLeaf->ptrRight, iData);
}

template <typename T>
Leaf<T>* lesserLeaf(Leaf<T>* startingLeaf)
{
    Leaf<T>* ptrCurrent = startingLeaf;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

template <typename T>
Leaf<T>* deleteLeaf(Leaf<T>* startingLeaf, T iData)
{
    if (startingLeaf == nullptr) return nullptr;
    
    if (iData < startingLeaf->iPayload)
    {
        startingLeaf->ptrLeft = deleteLeaf(startingLeaf->ptrLeft, iData);
    }
    else if (iData > startingLeaf->iPayload)
    {
        startingLeaf->ptrRight = deleteLeaf(startingLeaf->ptrRight, iData);
    }
    else
    {
        Leaf<T>* ptrTempLeaf = nullptr;
        // ou ele tem um filho a direita, ou ele não tem nenhum
        if (startingLeaf->ptrLeft == nullptr)
        {
            ptrTempLeaf = startingLeaf->ptrRight;
            free(startingLeaf);
            return ptrTempLeaf;
        }
        // ou ele tem um filho a esquerda, ou não tem nenhum
        else if (startingLeaf->ptrRight == nullptr)
        {
            ptrTempLeaf = startingLeaf->ptrLeft;
            free(startingLeaf);
            return ptrTempLeaf;
        }
        // ele tem dois filhos (caso grave) - vou buscar o menor nó, maior que o nó em questão
        ptrTempLeaf = lesserLeaf(startingLeaf->ptrRight);
        startingLeaf->iPayload = ptrTempLeaf->iPayload;
        
        // vou buscar o elemento e apagá-lo
        startingLeaf->ptrRight = deleteLeaf(startingLeaf->ptrRight, ptrTempLeaf->iPayload);
    }
    
    return startingLeaf;
}

template <typename T>
void traversePreOrder(Leaf<T>* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        cout << " " << ptrStartingLeaf->iPayload;
        traversePreOrder(ptrStartingLeaf->ptrLeft);
        traversePreOrder(ptrStartingLeaf->ptrRight);
    }
}

template <typename T>
void traverseInOrder(Leaf<T>* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        traverseInOrder(ptrStartingLeaf->ptrLeft);
        cout << " " << ptrStartingLeaf->iPayload;
        traverseInOrder(ptrStartingLeaf->ptrRight);
    }
}

template <typename T>
void traversePostOrder(Leaf<T>* ptrStartingLeaf)
{
    if (ptrStartingLeaf != nullptr)
    {
        traversePostOrder(ptrStartingLeaf->ptrLeft);
        traversePostOrder(ptrStartingLeaf->ptrRight);
        cout << " " << ptrStartingLeaf->iPayload;
    }
}

template <typename T>
void generateRandomArray(T* arr, int size, int minValue, int maxValue)
{
    // Usando random_device para gerar uma semente
    std::random_device rd;
    // Usando mt19937 como engine para geração de números aleatórios
    std::mt19937 gen(rd());
    // Distribuição uniforme entre minValue e maxValue
    std::uniform_int_distribution<> dis(minValue, maxValue);

    for (int i = 0; i < size; ++i) {
        arr[i] = dis(gen);
    }
}

template <typename T>
Node<T>* createNode(T iPayload)
{
    Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
    newNode->iPayload = iPayload;
    newNode->ptrNext = nullptr;
    return newNode;
}

template <typename T>
void insertEnd(Node<T>** head, T iPayload)
{
    Node<T>* newNode = createNode(iPayload);
    if (*head == nullptr) *head = newNode;
    
    else {
        Node<T>* temp = *head;
        while (temp->ptrNext != nullptr) temp = temp->ptrNext;

        temp->ptrNext = newNode;
    }
}
