#include <iostream>

using namespace std;

// Definindo funções padrão de lista duplamente encadeada:
//////////////////////////////////////////////////////////////////////////////////////
// Definição de nó
struct Node
{
    int iData;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

//Definição de lista
struct List
{
    struct Node* head;
    struct Node* tail;
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

// Função que insere um nó no início da estrutura lista
void insertFront(struct List* list, int iVal)
{    
    struct Node* newNode = createNode(iVal, nullptr, list->head);
    // O primeiro nó sempre aponta para nullptr para a esquerda

    if (list->head != nullptr) list->head->ptrPrev = newNode; // Se existia algo na lista, agora o segundo aponta para o novo primeiro 
    else list->tail = newNode; // Se não existia nada, o novo Node é o primeiro e o último

    list->head = newNode; // Atualizando o head
}

// Função que insere um nó no final da estrutura lista
void insertEnd(struct List* list, int iVal)
{
    // O último nó sempre aponta para nullptr para a direita, mas vamos deixar para a esquerda também por enquanto
    struct Node* newNode = createNode(iVal, nullptr, nullptr);

    if (list->head == nullptr) list->head = newNode;  // Se a lista está vazia, o último também é o primeiro
    else // Se não está vazia:
    {
        list->tail->ptrNext = newNode; // O antigo último aponta para o novo
        newNode->ptrPrev = list->tail; // O novo último aponta para o antigo
    }
    list->tail = newNode; // Atualizando o tail
}

// Função que imprime a estrutura lista
void displayList(struct List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    if (list->head->ptrPrev != nullptr)
    {
        cout << "Alerta! Ponteiro passado está no meio da lista" << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Node* printer = list->head;

    cout << "Payload: ";
    while (printer != nullptr)
    {
        cout << printer->iData << " ";
        printer = printer->ptrNext;
    }
    cout << endl;
}

// Função que apaga o primeiro elemento da estrutura lista
void deleteFirst(struct List* list)
{
    if (list->head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = list->head; // É bom vigiar o cara que vamos apagar para liberar memória no final

    list->head = list->head->ptrNext; // Atualizamos a head
    if (list->head != nullptr)list->head->ptrPrev = nullptr; // Se a nova head não for vazia, atualiza o prev do primeiro nó
    else list->tail = nullptr; // Se for vazia, atualiza a tail também

    free(ptrTemp); // Libera memória
}

// Função que apaga o último elemento da estrutura lista
void deleteLast(struct List* list)
{
    if (list->head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = list->tail; // Vigiando para punir...

    if (list->tail->ptrPrev == nullptr) 
    {
        list->head = nullptr; // Se o removido era o único, head e tail viram nullptr
        list->tail = nullptr;
    }
    else 
    {
        list->tail = list->tail->ptrPrev; 
        list->tail->ptrNext = nullptr; // Se não, temos que atualizar o penúltimo
    }

    free(ptrTemp); // Liberando memória
}

// Função que recebe um nó de uma lista, e insere um novo logo após na estrutura
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
void deleteNode(struct List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return;
    }

    // Se o deletado for o primeiro ou o último, é só usar as outras funções!
    if (list->head == ptrDelete) 
    {
        deleteFirst(list);
        return;
    }
    if (list->tail == ptrDelete) 
    {
        deleteLast(list);
        return;
    }
    
    // Se não for o último nem o primeiro, ele certamente está entre dois Nodes
    ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev; 
    ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete); // Libera memória
}
//////////////////////////////////////////////////////////////////////////////////////