#include <iostream>

using namespace std;

// Continuação de Lista duplamente encadeada! (Doubly Linked List)

////////////////////////////////////////////////////
// Código da aula passada

struct Node
{
    int iData;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

// Função que cria um nó
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

//////////////////////////////////////////////////////
// Aula de hoje :)

// Função que recebe um nó de uma lista, e insere um novo logo após
void insertAfter(struct Node* ptrLoc, int iPayload)
{
    if (ptrLoc == nullptr)
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    } 
    
    // Criando o novo nó
    struct Node* newNode = createNode(iPayload, ptrLoc, ptrLoc->ptrNext);

    // Corrigindo o next do ptrLoc
    ptrLoc->ptrNext = newNode;
    // Se havia alguém na frente do ptrLoc, corrige o previous dele
    if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

// Função que deleta um nó específico da lista
void deleteNode(struct Node** head, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (*head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return;
    }

    // Se o deletado for o primeiro, temos que atualizar a Head!
    if (*head == ptrDelete) *head = ptrDelete -> ptrNext;
    // Obs.: Perceba que quando isso acontece, poderíamos só reutilizar a função deleteFirst()

    // Se houver alguém antes ou depois do deletado, temos que atualizá-los
    if (ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev; 
    if (ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete); // Libera memória
}

int main()
{
    // Inicializando a lista
    struct Node* head = nullptr;
    cout << "===============================" << endl;

    displayList(head);
    cout << "===============================" << endl;

    insertAfter(head, 1); // Erro proposital
    cout << "===============================" << endl;

    insertFront(&head, 0);
    insertFront(&head, 7);
    insertFront(&head, 42);
    insertEnd(&head, 666);
    insertEnd(&head, 2023);
    displayList(head);
    cout << "===============================" << endl;

    insertAfter(head->ptrNext->ptrNext, 1); // Inserindo no meio
    insertAfter(head->ptrNext->ptrNext, 5);
    insertAfter(head->ptrNext->ptrNext, 10);
    insertAfter(head->ptrNext->ptrNext, 15);
    displayList(head);
    cout << "===============================" << endl;

    deleteNode(&head, head); // Deletando no início
    deleteNode(&head, head->ptrNext->ptrNext); // Deletando no meio
    deleteNode(&head, head);
    deleteNode(&head, head);

    // deleteNode(&head, head->ptrNext->ptrNext); // Deletando além do fim
    deleteNode(&head, head);
    
    displayList(head);
    cout << "===============================" << endl;
    
    return 0;
}
