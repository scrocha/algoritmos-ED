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
    
    cout << "Atravessar - inorder: ";
    traversePreOrder(root);
    cout << endl;
    
    deleteNode(root, 42);
    
    cout << "Atravessar - inorder: ";
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

Node* deleteNode(Node* startingNode, int iData) {
    if (startingNode == nullptr)
    {
        return nullptr;
    }
    
    if (iData < startingNode->iPayload)
    {
        startingNode->ptrLeft = deleteNode(startingNode->ptrLeft, iData);
    }
    else if (iData > startingNode->iPayload)
    {
        startingNode->ptrRight = deleteNode(startingNode->ptrRight, iData);
    }
    else
    {
        Node* ptrTempNode = nullptr;
        // ou ele tem um filho a direita, ou ele não tem nenhum
        if (startingNode->ptrLeft == nullptr)
        {
            ptrTempNode = startingNode->ptrRight;
            free(startingNode);
            return ptrTempNode;
        }
        // ou ele tem um filho a esquerda, ou não tem nenhum
        else if (startingNode->ptrRight == nullptr)
        {
            ptrTempNode = startingNode->ptrLeft;
            free(startingNode);
            return ptrTempNode;
        }
        // ele tem dois filhos (caso grave) - vou buscar o menor nó, maior que o nó em questão
        ptrTempNode = lesserLeaf(startingNode->ptrRight);
        startingNode->iPayload = ptrTempNode->iPayload;
        
        // vou buscar o elemento e apagá-lo
        startingNode->ptrRight = deleteNode(startingNode->ptrRight, ptrTempNode->iPayload);
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