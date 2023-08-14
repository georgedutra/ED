#include <iostream>

using namespace std;

// Lista duplamente encadeada! (Doubly Linked List)

struct Node
{
    int iData;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

// Dever de casa 1: Elabore uma função que cria um nó
struct Node* createNode(int iVal, struct Node* previous, struct Node* next)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->iData = iVal;
    newNode->ptrNext = next; 
    newNode->ptrPrev = previous; 

    return newNode;
}

// Função que insere um nó no início da lista
void insertFront(struct Node** head, int iVal)
{
    // Perceba que a função recebe um ponteiro para ponteiro, logo precisamos de-referenciá-lo, mas isso é útil pois podemos alterar o head diretamente
    struct Node* newNode = createNode(iVal, nullptr, *head);
    // O primeiro nó sempre aponta para nullptr para a esquerda

    if ((*head) != nullptr) (*head)->ptrPrev = newNode; // Se existia algo na lista, agora o segundo aponta para o novo primeiro 

    *head = newNode; // Atualizando o head
}

// Função que insere um nó no final da lista
void insertEnd(struct Node** head, int iVal)
{
    // O último nó sempre aponta para nullptr para a direita, mas vamos deixar para a esquerda também por enquanto
    struct Node* newNode = createNode(iVal, nullptr, nullptr);

    if ((*head) == nullptr) // Se a lista está vazia, o último também é o primeiro
    {
       (*head) = newNode;
       return; 
    }
    
    // Agora caminhamos até o final da lista
    struct Node* ptrTemp = (*head);
    while (ptrTemp->ptrNext != nullptr) ptrTemp = ptrTemp->ptrNext;
    // Agora, ptrTemp é o último nó da lista

    ptrTemp->ptrNext = newNode; // O antigo último aponta para o novo
    newNode->ptrPrev = ptrTemp; // O novo último aponta para o antigo
}

// Função que imprime a lista
void displayList(struct Node* head)
{
    if (head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    if (head->ptrPrev != nullptr)
    {
        cout << "Alerta! Ponteiro passado está no meio da lista";
        return;
    }

    cout << "Payload: ";
    // Se chegamos aqui, a lista é válida e não vazia
    while (head != nullptr)
    {
        cout << head->iData << " ";
        head = head->ptrNext;
    }
    cout << endl;
}

// Função que apaga o primeiro elemento
void deleteFirst(struct Node** head)
{
    if (*head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = *head; // É bom vigiar o cara que vamos apagar para liberar memória no final

    (*head) = (*head)->ptrNext;
    if (*head != nullptr)(*head)->ptrPrev = nullptr;

    free(ptrTemp);
}

// Função que apaga o último elemento
void deleteLast(struct Node** head)
{
    if (*head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = *head;
    while (ptrTemp->ptrNext != nullptr) ptrTemp = ptrTemp->ptrNext;
    // Agora ptrTemp vigia o último

    if (ptrTemp->ptrPrev == nullptr) (*head) = nullptr; // Se o removido era o único, head vira nullptr
    else ptrTemp->ptrPrev->ptrNext = nullptr; // Se não, temos que atualizar o penúltimo

    free(ptrTemp);
}

int main()
{
    // Inicializando a lista
    struct Node* head = nullptr;
    cout << "===============================" << endl;

    displayList(head);
    cout << "===============================" << endl;

    insertFront(&head, 0);
    insertFront(&head, 7);
    insertFront(&head, 42);
    displayList(head);
    cout << "===============================" << endl;
    
    insertEnd(&head, 666);
    insertEnd(&head, 2023);
    displayList(head);
    cout << "===============================" << endl;
    
    deleteFirst(&head);
    displayList(head);
    deleteFirst(&head);
    displayList(head);
    cout << "===============================" << endl;
    
    deleteLast(&head);
    displayList(head);
    deleteLast(&head);
    displayList(head);
    cout << "===============================" << endl;
    
    // Esvaziando a lista
    deleteLast(&head);
    displayList(head);

    // Verificando as deletes para listas vazias
    deleteFirst(&head); 
    deleteLast(&head);
    cout << "===============================" << endl;

    return 0;
}
