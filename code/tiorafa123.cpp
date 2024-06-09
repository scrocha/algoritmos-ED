#include <iostream>

using namespace std;

typedef struct Node
{
  int iPayload;
  
  Node* ptrLeft;
  Node* ptrRight;

} Node;

Node* newNode(int);
Node* insertNode(Node*, int);
Node* searchNode(Node*, int);
Node* lesserLeaf(Node*);
Node* deleteNode(Node*, int);

void traversePreOrder(Node*);
void traverseInOrder(Node*);
void traversePostOrder(Node*);

int main()
{
    // Exemplo 1, árvore binária simples
    Node* root_1 = newNode(1);
    root_1->ptrLeft = newNode(7);
    root_1->ptrRight = newNode(13);
    root_1->ptrRight->ptrLeft = newNode(42);
    root_1->ptrRight->ptrRight = newNode(666);
    
    // Exemplo 2, árvore binária de busca (BST)
    Node* root_2 = newNode(42);
    root_2->ptrLeft = newNode(7);
    root_2->ptrRight = newNode(666);
    root_2->ptrLeft->ptrLeft = newNode(1);
    root_2->ptrLeft->ptrRight = newNode(13);
    
    // Teste: searchNode em Root 2
    string resultado;
    
    resultado = (nullptr == searchNode(nullptr, 42))? "OK" : "Deu Ruim";
    cout << "Busca nullptr: " << resultado << endl;
    
    resultado = (root_2 == searchNode(root_2, 42))? "OK" : "Deu Ruim";
    cout << "Busca 42: " << resultado << endl;
    
    resultado = (root_2->ptrLeft == searchNode(root_2, 7))? "OK" : "Deu Ruim";
    cout << "Busca 7: " << resultado << endl;

    resultado = (root_2->ptrLeft->ptrLeft == searchNode(root_2, 1))? "OK" : "Deu Ruim";
    cout << "Busca 1: " << resultado << endl;
    
    resultado = (nullptr == searchNode(root_2, 10))? "OK" : "Deu Ruim";
    cout << "Busca Não-Existente: " << resultado << endl;

    cout << "####################" << endl;

    //Exemplo 3, com insertNode
    Node* root = nullptr;
    root = insertNode(root, 42);
    root = insertNode(root, 7);
    root = insertNode(root, 666);
    root = insertNode(root, 1);
    root = insertNode(root, 13);
    
    // Traverse - Atravessar Root 2
    cout << "Atravessar - preorder: ";
    traversePreOrder(root_2);
    cout << endl;
    
    cout << "Atravessar - inorder: ";
    traverseInOrder(root_2);
    cout << endl;
    
    cout << "Atravessar - postorder: ";
    traversePostOrder(root_2);
    cout << endl;
    
    // Traverse - Atravessar Root
    cout << "Atravessar - preorder: ";
    traversePreOrder(root);
    cout << endl;
    
    cout << "Atravessar - inorder: ";
    traverseInOrder(root);
    cout << endl;
    
    cout << "Atravessar - postorder: ";
    traversePostOrder(root);
    cout << endl;
    
    cout << "####################" << endl;
    
    cout << "Atravessar - preorder: ";
    traversePreOrder(root);
    cout << endl;
    
    deleteNode(root, 7);
    
    cout << "Atravessar - preorder: ";
    traversePreOrder(root);
    cout << endl;
    
    return 0;
}

Node* newNode(int iData)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
  
    if (tmp != nullptr)
    {
        tmp->iPayload = iData;
        tmp->ptrLeft = nullptr;
        tmp->ptrRight = nullptr;
    }
  
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return newNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

Node* searchNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr) return nullptr;
    else if(iData == startingNode->iPayload) return startingNode;
    else if(iData < startingNode->iPayload) return searchNode(startingNode->ptrLeft, iData);
    else return searchNode(startingNode->ptrRight, iData);
}

Node* lesserLeaf(Node* startingNode)
{
    Node* ptrCurrent = startingNode;
 
    while (ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;
    
    return ptrCurrent;
}

Node* deleteNode(Node* startingNode, int iData)
{
    if (startingNode == nullptr) return nullptr;
    
    if (iData < startingNode->iPayload) startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
    else if (iData > startingNode->iPayload) startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
    else
    {
        Node* ptrTemp = nullptr;
        
        if (startingNode->ptrLeft == nullptr)
        {
            ptrTemp = startingNode->ptrRight;
            free(startingNode);
            return ptrTemp;
        }
        else if (startingNode->ptrRight == nullptr)
        {
            ptrTemp = startingNode->ptrLeft;
            free(startingNode);
            return ptrTemp;            
        }
        
        ptrTemp = lesserLeaf(startingNode->ptrRight);
        
        startingNode->iPayload = ptrTemp->iPayload;
        
        startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTemp->iPayload);
    }
    
    return startingNode;
}

void traversePreOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        cout << " " << ptrStartingNode->iPayload;
        traversePreOrder(ptrStartingNode->ptrLeft);
        traversePreOrder(ptrStartingNode->ptrRight);
    }
}

void traverseInOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traverseInOrder(ptrStartingNode->ptrLeft);
        cout << " " << ptrStartingNode->iPayload;
        traverseInOrder(ptrStartingNode->ptrRight);
    }
}

void traversePostOrder(Node* ptrStartingNode)
{
    if (ptrStartingNode != nullptr)
    {
        traversePostOrder(ptrStartingNode->ptrLeft);
        traversePostOrder(ptrStartingNode->ptrRight);
        cout << " " << ptrStartingNode->iPayload;
    }
}

##########################################################################################################################################
##########################################################################################################################################
##########################################################################################################################################

#include <iostream>

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);

int main()
{
    Node* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    return 0;
}

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

void bfsTraversal(Node* startingNode)
{
    cout << "Olá" << endl;
}

##########################################################################################################################################
##########################################################################################################################################
##########################################################################################################################################

#include <iostream>

using namespace std;

typedef struct Node
{
    int iPayload;
    Node* ptrLeft;
    Node* ptrRight;
} Node;

Node* createNode(int);
Node* insertNode(Node*, int);
void bfsTraversal(Node*);
int treeHeight(Node*);

int main()
{
    Node* root = nullptr;
    
    root = insertNode(root, 42);
    root = insertNode(root, 13);
    root = insertNode(root, 11);
    root = insertNode(root, 10);
    root = insertNode(root, 28);
    root = insertNode(root, 51);
    root = insertNode(root, 171);
    
    cout << "BFS Traversal: ";
    bfsTraversal(root);
    cout << endl;
    
    cout << "Tree Height: " << treeHeight(root) << endl;
    
    return 0;
}

Node* createNode(int iValue)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    
    if (tmp == nullptr)
    {
        cerr << "Erro em createNode: malloc" << endl;
        exit(1);
    }
    
    tmp->iPayload = iValue;
    tmp->ptrLeft = nullptr;
    tmp->ptrRight = nullptr;
    
    return tmp;
}

Node* insertNode(Node* startingNode, int iData)
{
    if(startingNode == nullptr)
    {
        return createNode(iData);
    }
    
    if(iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = insertNode(startingNode->ptrLeft, iData);
    }
    else
    {
        startingNode->ptrRight = insertNode(startingNode->ptrRight, iData);
    }
    
    return startingNode;
}

void bfsTraversal(Node* startingNode)
{
    if (startingNode == nullptr) return;
    
    // Parte 1 do Trabalho: Alterar para Lista Encadeada
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;	
    
    while (iQueueFront < iQueueRear)
    {
        Node* currentNode = nodeQueue[iQueueFront];
        iQueueFront++;
        
        cout << currentNode->iPayload << " ";
        
        if (currentNode->ptrLeft != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrLeft;
            iQueueRear++;
        }
        
        if (currentNode->ptrRight != nullptr)
        {
            nodeQueue[iQueueRear] = currentNode->ptrRight;
            iQueueRear++;
        }
        
    }
}

// Parte 2 do Trabalho: Elaborar busca utilizando BFS (vocês já fizeram o DFS)
// Parte 3 do Trabalho: Monitorar o desempenho de busca em árvore utilizando DFS e BFS
// Parte 4 do Trabalho: Monitorar o desempenho de criação de listas
// Parte 5 do Trabalho: Monitorar o desempenho de criação de árvores

int treeHeight(Node* startingNode)
{
    if (startingNode == nullptr) return 0;
    else
    {
        int iLeftHeight = treeHeight(startingNode->ptrLeft);
        int iRightHeight = treeHeight(startingNode->ptrRight);
        
        return max(iLeftHeight, iRightHeight) + 1;
    }
}

##########################################################################################################################################
##########################################################################################################################################
##########################################################################################################################################
