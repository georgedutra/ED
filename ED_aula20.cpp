// Root (Um elemento/nó que não descende de ninguém)
// Child Node (Um nó que possui um ancestral, ou seja, descende de alguém)
// Parent (Nó que possui descendentes. Complementar ao Child, ancestral de algum nó)
// Sibling (Nós que estão no mesmo nível e dividem o mesmo Parent)
// Ancestor Node (Partindo de um nó X, e indo para a raiz, se em algum momento passamos por um nó Y, dizemos que Y é ancestral de X)
// Leaf Node (Nó terminal, que não possui descendentes)

// Binary Tree: Árvores em que todo nó tem entre 0 e 2 filhos
// Full Binary Tree: Árvores Binárias em que todo nó tem ou 0, ou 2 filhos, mas nunca 1

// DFS: Depht First Search, um método de busca para atravessar uma árvore

#include <iostream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

// Três tipos de sequenciamento de árvores: pré-ordem, pós-ordem, e em ordem


struct Node* newNode(int iData)
{
    struct Node* newNodePtr = (struct Node*) malloc(sizeof(struct Node));
    newNodePtr->iPayload = iData;
    newNodePtr->ptrLeft = nullptr;
    newNodePtr->ptrRight = nullptr;

    return newNodePtr;
}

// Primeiro o nó atual, depois à esquerda, depois à direita
void traversePreOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return; // Caso base

    cout << " " << ptrStartingNode->iPayload;
    traversePreOrder(ptrStartingNode->ptrLeft);
    traversePreOrder(ptrStartingNode->ptrRight);
}

// Primeiro o nó à esquerda, depois o atual, depois à direita
void traverseInOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return;

    traverseInOrder(ptrStartingNode->ptrLeft);
    cout << " " << ptrStartingNode->iPayload;
    traverseInOrder(ptrStartingNode->ptrRight);
}

// Primeiro o nó à esquerda, depois à direita, depois o atual
void traversePostOrder(struct Node* ptrStartingNode)
{
    if (ptrStartingNode == nullptr) return; 

    traversePostOrder(ptrStartingNode->ptrLeft);
    traversePostOrder(ptrStartingNode->ptrRight);
    cout << " " << ptrStartingNode->iPayload;
}

struct Node* searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr; // Caso Base

    else if (node->iPayload == iData) return node; // Se encontrarmos o nó procurado

    else if (iData < node->iPayload) return searchNode(node->ptrLeft, iData);
    return searchNode(node->ptrRight, iData);
}

int main()
{
    struct Node* root = newNode(42);
    root->ptrLeft = newNode(7);
    root->ptrRight = newNode(666);
    root->ptrLeft->ptrLeft = newNode(1);
    root->ptrLeft->ptrRight = newNode(13);

    // cout << "Atravessando a árvore - PreOrder:";
    // traversePreOrder(root);
    // cout << endl;

    // cout << "Atravessando a árvore - InOrder:";
    // traverseInOrder(root);
    // cout << endl;

    // cout << "Atravessando a árvore - PostOrder:";
    // traversePostOrder(root);
    // cout << endl;

////////////////////////////////////////////////////

    string resultado;

    resultado = (nullptr == searchNode(nullptr, 42))? "OK":"Deu Ruim";
    cout << "Busca nullptr: " << resultado << endl;
    
    resultado = (root == searchNode(root, 42))? "OK":"Deu Ruim";
    cout << "Busca 42: " << resultado << endl;
    
    resultado = (root->ptrLeft == searchNode(root, 7))? "OK":"Deu Ruim";
    cout << "Busca 7: " << resultado << endl;
    
    resultado = (root->ptrLeft->ptrLeft == searchNode(root, 1))? "OK":"Deu Ruim";
    cout << "Busca 1: " << resultado << endl;
    
    resultado = (nullptr == searchNode(root, 10))? "OK":"Deu Ruim";;
    cout << "Busca Não-Existente: " << resultado << endl;

    return 0;
}