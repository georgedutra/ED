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

//////////////////// ^ Código da última aula ^ ////////////////////////////////////

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

// Função recursiva para deletar nós de árvores binárias de busca (INCOMPLETA NESSA AULA)
// struct Node* deleteNode(struct Node* root, int iData)
// {
//     if (root == nullptr) return root; 

//     if (iData < root->iPayload) root->ptrLeft = deleteNode(root->ptrLeft, iData);
//     else if (iData > root->iPayload) root->ptrRight = deleteNode(root->ptrRight, iData);

//     else
//     {  
//         struct Node* temp = nullptr;

//         if (root->ptrLeft == nullptr) // Quando o nó deletado só tem filhos à direita ou nenhum filho
//         {
//             temp = root->ptrRight; // Salvamos os filhos do nó deletado
//             free(root); // Deletamos o nó
            
//             return temp; // Reconectamos a árvore
//         }
//         else if (root->ptrRight == nullptr) // Quando o nó deletado só tem filhos à esquerda
//         {
//             temp = root->ptrLeft; // Salvamos os filhos do nó deletado
//             free(root); // Deletamos o nó
            
//             return temp; // Reconectamos a árvore
//         }
//         else // Agora o bicho pega, pois o nó tem dois filhos, e matar pai de duas criança já é covardia
//         {

//         }
//     }

//     return root;
// }   

int main()
{
    struct Node* root = newNode(42);
    root->ptrLeft = newNode(7);
    root->ptrRight = newNode(666);
    root->ptrLeft->ptrLeft = newNode(1);
    root->ptrLeft->ptrRight = newNode(13);

    cout << "Atravessando a árvore - PreOrder:";
    traversePreOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - InOrder:";
    traverseInOrder(root);
    cout << endl;

    cout << "Atravessando a árvore - PostOrder:";
    traversePostOrder(root);
    cout << endl;

////////////////////////////////////////////////////

    root = insertNode(root, 42); // Precisamos atribuir ele no primeiro nó
    insertNode(root, 7);
    insertNode(root, 666);
    insertNode(root, 1);
    insertNode(root, 13);

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