#include <iostream>

using namespace std;

struct Node
{
    int iPayload;
    struct Node* ptrLeft;
    struct Node* ptrRight;
};

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

// Procura recursiva de nó
struct Node* searchNode(struct Node* node, int iData)
{
    if (node == nullptr) return nullptr; // Caso Base

    else if (node->iPayload == iData) return node; // Se encontrarmos o nó procurado

    else if (iData < node->iPayload) return searchNode(node->ptrLeft, iData);
    return searchNode(node->ptrRight, iData);
}

// Função recursiva de inserção de nós em árvores binárias de busca
struct Node* insertNode(struct Node* root, int iData)
{
    if (root == nullptr) return newNode(iData); // Caso base: se achamos nullptr, retornamos o novo nó

    // Se não achamos o local de inserção, navegamos para a sub-árvore ideal para a inserção
    if (iData < root->iPayload) root->ptrLeft = insertNode(root->ptrLeft, iData); 
    else root->ptrRight = insertNode(root->ptrRight, iData);

    // Se estamos num caso não-base, temos que retornar a sub-árvore para os nós superiores, agora modificada, pois o nó já foi inserido no caso base
    return root;
}

//////////////////// ^ Código da última aula ^ ////////////////////////////////////

struct Node* lesserLeaf(struct Node* node)
{
    struct Node* ptrCurrent = node;

    while(ptrCurrent && ptrCurrent->ptrLeft != nullptr) ptrCurrent = ptrCurrent->ptrLeft;

    return ptrCurrent;
}

// Função recursiva para deletar nós de árvores binárias de busca
struct Node* deleteNode(struct Node* root, int iData)
{
    if (root == nullptr) return root; 

    if (iData < root->iPayload) root->ptrLeft = deleteNode(root->ptrLeft, iData);
    else if (iData > root->iPayload) root->ptrRight = deleteNode(root->ptrRight, iData);

    else // Estamos no nó correto
    {  
        struct Node* temp = nullptr;

        if (root->ptrLeft == nullptr) // Quando o nó deletado só tem filhos à direita ou nenhum filho
        {
            temp = root->ptrRight; // Salvamos os filhos do nó deletado
            free(root); // Deletamos o nó
            
            return temp; // Reconectamos a árvore
        }
        else if (root->ptrRight == nullptr) // Quando o nó deletado só tem filhos à esquerda
        {
            temp = root->ptrLeft; // Salvamos os filhos do nó deletado
            free(root); // Deletamos o nó
            
            return temp; // Reconectamos a árvore
        }

        // Agora o bicho pega, pois o nó tem dois filhos, e matar pai de duas criança já é covardia
        temp = lesserLeaf(root->ptrRight);

        // Para casa: Crie uma função que troque os nós, e não o conteúdo
        root->iPayload = temp->iPayload;

        root->ptrRight = deleteNode(root->ptrRight, temp->iPayload);
    }

    return root;
}   

int main()
{
    Node* root = insertNode(root, 42); // Precisamos atribuir ele no primeiro nó
    insertNode(root, 7);
    insertNode(root, 666);
    insertNode(root, 1);
    insertNode(root, 13);

    cout << "Árvore original:" << endl;
    cout << "Atravessando a árvore - PreOrder:";
    traversePreOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - InOrder:";
    traverseInOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - PostOrder:";
    traversePostOrder(root);
    cout << "\n" << endl;

    ////////////////////////////////////////////////////
    // Deletando nós

    deleteNode(root, 42);

    cout << "Árvore após deletar:" << endl;

    cout << "Atravessando a árvore - PreOrder:";
    traversePreOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - InOrder:";
    traverseInOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - PostOrder:";
    traversePostOrder(root);
    cout << endl;

    return 0;
}