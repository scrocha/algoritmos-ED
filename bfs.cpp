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
void bfsTrasversal(Node*);

int main()
{
    Node* root = nullptr;
    
    root = insertNode(root, 7);
    root = insertNode(root, 15);
    root = insertNode(root, 16);
    root = insertNode(root, 8);
    root = insertNode(root, 1);
    root = insertNode(root, 45);
    root = insertNode(root, 89);
    root = insertNode(root, 2);
    root = insertNode(root, 11);
    
    cout << "BFS Traversal:" << endl;
    bfsTrasversal(root);
    cout << endl;
}

void bfsTrasversal(Node* startingNode)
{
    if (startingNode == nullptr)
    {
        return;
    }
    
    Node* nodeQueue[100];
    int iQueueFront = 0;
    int iQueueRear = 0;
    
    nodeQueue[iQueueRear] = startingNode;
    iQueueRear++;
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

Node* createNode(int iPayload)
{
    Node* ptrTemp = (Node*) malloc(sizeof(Node));
    
    // quer dizer que o malloc deu errado (temos que tratar)
    if (ptrTemp == nullptr)
    {
        // maneira de printar erro
        cerr << "Erro em createNode: malloc." << endl;
        // ao passar o 1, você informa que houve um problema e quebra o programa inteiro
        exit(1);
    }
    
    ptrTemp->iPayload = iPayload;
    ptrTemp->ptrRight = nullptr;
    ptrTemp->ptrLeft = nullptr;
    
    return ptrTemp;
}
