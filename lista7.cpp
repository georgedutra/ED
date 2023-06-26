// Escolhi para essa atividade a lista duplamente encadeada, pois com ela tenho mais ferramentas para trabalhar livremente
#include <iostream>
#include <math.h>
#include <chrono> 

using namespace std;
using namespace std::chrono;

//////////////////////////////////////////////////////////////////////////////////////
// Definindo funções padrão de lista duplamente encadeada:

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

// Função que cria uma lista
struct List* createList()
{
    struct List* newList = new(List);
    newList->head = nullptr;
    newList->tail = nullptr;

    return newList;
}

// Função que cria um nó
struct Node* createNode(int iVal)
{
    struct Node* newNode = new(Node);
    newNode->iData = iVal;
    newNode->ptrNext = nullptr; 
    newNode->ptrPrev = nullptr; 

    return newNode;
}

// Função que insere um nó no início da estrutura lista
void insertFront(struct List* list, struct Node* newNode)
{
    // O primeiro nó sempre aponta para nullptr para a esquerda
    newNode->ptrPrev = nullptr;
    newNode->ptrNext = list->head;

    if (list->head == nullptr) list->tail = newNode; // Se não existia nada na lista, o novo Node é o primeiro e o último
    else list->head->ptrPrev = newNode; // Se existia algo, agora o segundo aponta para o novo primeiro 

    list->head = newNode; // Atualizando o head
}

// Função que insere um nó no final da estrutura lista
void insertEnd(struct List* list, struct Node* newNode)
{
    // O último nó sempre aponta para nullptr para a direita
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = list->tail;

    if (list->head == nullptr) list->head = newNode;  // Se a lista está vazia, o último também é o primeiro
    else list->tail->ptrNext = newNode;

    list->tail = newNode; // Atualizando o tail
}

// Função que imprime a estrutura lista
void printList(struct List* list)
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
void insertAfter(struct Node* ptrLoc, struct Node* newNode)
{
    if (ptrLoc == nullptr)
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    } 
    // Arrumando o newNode
    newNode->ptrNext = ptrLoc->ptrNext;
    newNode->ptrPrev = ptrLoc;

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

// Função que remove um nó e o retorna
struct Node* popNode(struct List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return nullptr;
    }
    
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else list->tail = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    else list->head = ptrDelete->ptrNext;

    return ptrDelete;
}

// Função para saber o tamanho de uma lista duplamente encadeada
int getLenght(struct List* list)
{
    int counter = 0;
    struct Node* temp = list->head;
    while (temp!=nullptr)
    {
        counter++;
        temp = temp->ptrNext;
    }
    return counter;
}

// Função que troca de lugar dois Nodes na estrutura de lista duplamente encadeada
void swapNodes(struct List* list, struct Node* node1, struct Node* node2)
{
    struct Node* temp; // Criando um ponteiro temporário para utilidade

    // Casos Especiais: 
    
    // Aqui criei variáveis que indicam se os nodes 1 e 2 possuem prev ou next.
    bool prev1 = true, prev2 = true, next1 = true, next2 = true;
    
    // Se não possuem, significa que são head ou tail da lista
    if (node1 == list->head) prev1 = false;
    if (node2 == list->head) prev2 = false;
    if (node1 == list->tail) next1 = false;
    if (node2 == list->tail) next2 = false;

    // Casos em que os Nodes são adjacentes:

    // Se o node2 vem logo antes do 1, basta trocar os nomes e os indicadores de head/tail, pois queremos que o 1 venha antes do 2
    if (node2->ptrNext == node1)
    {
        temp = node1;
        node1 = node2;
        node2 = temp;
        
        if (prev2==false) prev1 = false;
        prev2 = true;

        if (next1==false) next2 = false;
        next1 = true;
    }

    // Se agora o node1 vem logo antes do 2, fazemos o necessário para Nodes adjacentes:
    if (node1->ptrNext == node2)
    {
        if(prev1==true) node1->ptrPrev->ptrNext = node2;    
        else list->head = node2;

        if(next2==true) node2->ptrNext->ptrPrev = node1;
        else list->tail = node1;

        node1->ptrNext = node2->ptrNext;
        node2->ptrPrev = node1->ptrPrev;

        node1->ptrPrev = node2;
        node2->ptrNext = node1;
        return;
    }

    // Se não são adjacentes, não importa mais quem vem antes ou depois, e partimos para os casos em que os Nodes estão separados:

    // Primeiro alteramos os nós ao redor dos trocados, se eles existem
    if(prev1==true) node1->ptrPrev->ptrNext = node2;
    if(next1==true) node1->ptrNext->ptrPrev = node2;
    
    if(prev2==true) node2->ptrPrev->ptrNext = node1;
    if(next2==true) node2->ptrNext->ptrPrev = node1;

    // Também alteramos os ponteiros da nossa lista caso sejam head ou tail
    if(prev1==false) list->head = node2;
    if(prev2==false) list->head = node1;

    if(next1==false) list->tail = node2;
    if(next2==false) list->tail = node1;

    // Por fim, atualizamos os ponteiros dos Nodes alterados, com ajuda do temp auxiliar
    temp = node1->ptrNext;
    node1->ptrNext = node2->ptrNext;
    node2->ptrNext = temp;

    temp = node1->ptrPrev;
    node1->ptrPrev = node2->ptrPrev;
    node2->ptrPrev = temp;
}

// Função que cria uma lista de 'iQuant' inteiros aleatórios entre 0 e 99 
struct List* randList(int iQuant)
{
    List* newList = createList();

    for (int i = 0; i < iQuant; i++)
    {
        insertEnd(newList, createNode(rand()%100));
    }

    return newList;
}

//////////////////////////////////////////////////////////////////////////////////////
// Questão 1

bool isOrdered(Node* head, string order)
{
    Node* temp = head;

    while (temp->ptrNext != nullptr )
    {
        if (order == "crescente" && temp->iData > temp->ptrNext->iData) return false;
        else if (order == "decrescente" && temp->iData < temp->ptrNext->iData) return false;
        temp = temp->ptrNext;
    }
    return true;
}
//////////////////////////////////////////////////////////////////////////////////////
// Questão 2

//Escolhi para essa questão o Insertion e o Shell Sorts de listas duplamente encadeadas
void insertionSort(struct List* list)
{
    int iLenght = getLenght(list);

    struct Node* ptrOuter = list->head->ptrNext; // Começa no segundo elemento, pois o primeiro já está ordenado
    struct Node* ptrInner;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->ptrNext; // Avançamos o outer preventivamente para preparar a próxima iteração, dessa forma grantimos que ele aponta para o lugar certo

        struct Node* ptrTemp = popNode(list, ptrInner);

        while (ptrInner->ptrPrev != nullptr && ptrInner->ptrPrev->iData > ptrTemp->iData)
        {
            ptrInner = ptrInner->ptrPrev;
        }
        if (ptrInner == list->head) insertFront(list, ptrTemp);
        else insertAfter(ptrInner->ptrPrev, ptrTemp);
    }
}

// ShellSort com o incremento de Shell
void shellSort(List* list)
{
    int iLenght = getLenght(list);
    struct Node* ptrOuter; // Ponteiro que guarda a referência do loop externo
    struct Node* ptrInner; // Ponteiro que guarda a referência do loop interno
    struct Node* ptrTemp; // Ponteiro que guarda o nó removido e inserido na lista

    for (int k = 2; trunc(iLenght/k) >= 1; k = k*2) // Para cada incremento, começando do maior, indo até 1, que é o insertionSort padrão
    {
        int inc = trunc(iLenght/k);

        for (int i = 0; i < inc; i++) // Para cada "sublista" dentro da lista original 
        {
            ptrOuter = list->head; // Reseta o ptrOuter
            for (int j = 0; j < i+inc; j++) ptrOuter = ptrOuter->ptrNext; // ptrOuter começa no segundo elemento da sublista
            
            // Imagine que estamos fazendo um insertion sort, mas cada nó não olha para o anterior, e sim para o nó que está 'inc' passos atrás
            for (int iOuterLoop = i+inc; iOuterLoop < iLenght; iOuterLoop += inc) // Loop externo
            {
                ptrInner = ptrOuter; // Reseta o ptrInner
                for (int j = 0; j < inc && ptrOuter != nullptr; j++) ptrOuter = ptrOuter->ptrNext; // Outer caminha 'inc' nós para frente

                ptrTemp = ptrInner; // Esse é o nó que "sai" da parte desordenada, e quer entrar na parte ordenada 

                for (int iInnerLoop = iOuterLoop; iInnerLoop>i; iInnerLoop-=inc) // Loop Interno
                {
                    for (int j = 0; j < inc; j++) ptrInner = ptrInner->ptrPrev; // Inner caminha 'inc' passos para trás
                    if (ptrInner->iData <= ptrTemp->iData) break; // Se essa sublista está ordenada, quebra o loop interno

                    swapNodes(list, ptrInner, ptrTemp); // Caso contrário, trocamos o temp com o nó que está 'inc' passos atrás dele 
                    ptrInner = ptrTemp; // E resetamos Inner para o próximo passo
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////
// Questão 3

////////////////////////////////////////////
// Funções para construir matrizes:
struct Inner_List
{
    Node* head;
    Node* tail;

    Inner_List* next;
    Inner_List* prev;
};

struct Outer_List
{
    Inner_List* head;
    Inner_List* tail;
};

Outer_List* createOuter()
{
    struct Outer_List* newOuter = new(Outer_List);
    newOuter->head = nullptr;
    newOuter->tail = nullptr;

    return newOuter;
}

Inner_List* createInner()
{
    struct Inner_List* newInner = new(Inner_List);
    newInner->head = nullptr;
    newInner->tail = nullptr;
    newInner->next = nullptr;
    newInner->prev = nullptr;

    return newInner;
}

// Sobrecarga para inserir Inner_List em uma Outer_List
void insertEnd(Outer_List* Outer, Inner_List* newInner)
{
    // O último sempre aponta para nullptr para a direita
    newInner->next = nullptr;
    newInner->prev = Outer->tail;

    if (Outer->head == nullptr) Outer->head = newInner;  // Se a lista está vazia, o último também é o primeiro
    else Outer->tail->next = newInner;

    Outer->tail = newInner; // Atualizando o tail
}

/* Sobrecarga para inserir Node em uma Inner_List */
void insertEnd(Inner_List* Inner, Node* newNode)
{
    // O último nó sempre aponta para nullptr para a direita
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = Inner->tail;

    if (Inner->head == nullptr) Inner->head = newNode;  // Se a lista está vazia, o último também é o primeiro
    else Inner->tail->ptrNext = newNode;

    Inner->tail = newNode; // Atualizando o tail
}

struct Inner_List* randInner(int iQuant)
{
    Inner_List* newInner = createInner();

    for (int i = 0; i < iQuant; i++)
    {
        insertEnd(newInner, createNode(rand()%100));
    }

    return newInner;
}

struct Outer_List* randOuter(int outerLen, int innerLen)
{
    Outer_List* newOuter = createOuter();

    for (int i = 0; i < outerLen; i++)
    {
        insertEnd(newOuter, randInner(innerLen));
    }

    return newOuter;
}

void printList(struct Inner_List* list)
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

    while (printer != nullptr)
    {
        cout << printer->iData << " ";
        printer = printer->ptrNext;
    }
    cout << endl;
}

void printList(struct Outer_List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    if (list->head->prev != nullptr)
    {
        cout << "Alerta! Ponteiro passado está no meio da lista" << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Inner_List* printer = list->head;

    int i = 0;
    while (printer != nullptr)
    {
        cout << "Sub-Lista (" << ++i << "): ";
        printList(printer);
        printer = printer->next;
    }
    cout << endl;
}

////////////////////////////////////////////
// Funções para ordenar Inners
int getLenght(struct Inner_List* list)
{
    int counter = 0;
    struct Node* temp = list->head;
    while (temp!=nullptr)
    {
        counter++;
        temp = temp->ptrNext;
    }
    return counter;
}

Node* popNode(struct Inner_List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return nullptr;
    }
    
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else list->tail = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    else list->head = ptrDelete->ptrNext;

    return ptrDelete;
}

void insertFront(struct Inner_List* list, struct Node* newNode)
{
    // O primeiro nó sempre aponta para nullptr para a esquerda
    newNode->ptrPrev = nullptr;
    newNode->ptrNext = list->head;

    if (list->head == nullptr) list->tail = newNode; // Se não existia nada na lista, o novo Node é o primeiro e o último
    else list->head->ptrPrev = newNode; // Se existia algo, agora o segundo aponta para o novo primeiro 

    list->head = newNode; // Atualizando o head
}

void insertionSort(Inner_List* list)
{
    int iLenght = getLenght(list);

    struct Node* ptrOuter = list->head->ptrNext; // Começa no segundo elemento, pois o primeiro já está ordenado
    struct Node* ptrInner;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->ptrNext; // Avançamos o outer preventivamente para preparar a próxima iteração, dessa forma grantimos que ele aponta para o lugar certo

        struct Node* ptrTemp = popNode(list, ptrInner);

        while (ptrInner->ptrPrev != nullptr && ptrInner->ptrPrev->iData > ptrTemp->iData)
        {
            ptrInner = ptrInner->ptrPrev;
        }
        if (ptrInner == list->head) insertFront(list, ptrTemp);
        else insertAfter(ptrInner->ptrPrev, ptrTemp);
    }
}
////////////////////////////////////////////
// Funções para ordenar Outers

int getLenght(struct Outer_List* list)
{
    int counter = 0;
    struct Inner_List* temp = list->head;
    while (temp!=nullptr)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

Inner_List* popInner(struct Outer_List* list, struct Inner_List* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return nullptr;
    }
    
    if(ptrDelete->next != nullptr) ptrDelete->next->prev = ptrDelete->prev;
    else list->tail = ptrDelete->prev;

    if(ptrDelete->prev != nullptr) ptrDelete->prev->next = ptrDelete->next;
    else list->head = ptrDelete->next;

    return ptrDelete;
}

void insertFront(struct Outer_List* list, struct Inner_List* newNode)
{
    // O primeiro nó sempre aponta para nullptr para a esquerda
    newNode->prev = nullptr;
    newNode->next = list->head;

    if (list->head == nullptr) list->tail = newNode; // Se não existia nada na lista, o novo Node é o primeiro e o último
    else list->head->prev = newNode; // Se existia algo, agora o segundo aponta para o novo primeiro 

    list->head = newNode; // Atualizando o head
}

void insertAfter(struct Inner_List* ptrLoc, struct Inner_List* newNode)
{
    if (ptrLoc == nullptr)
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    } 
    // Arrumando o newNode
    newNode->next = ptrLoc->next;
    newNode->prev = ptrLoc;

    // Corrigindo o next do ptrLoc
    ptrLoc->next = newNode;

    // Se havia alguém na frente do ptrLoc, corrige o previous dele
    if (newNode->next != nullptr) newNode->next->prev = newNode;
}

void insertionSort(Outer_List* list)
{
    int iLenght = getLenght(list);

    struct Inner_List* ptrOuter = list->head->next; // Começa no segundo elemento, pois o primeiro já está ordenado
    struct Inner_List* ptrInner;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->next; // Avançamos o outer preventivamente para preparar a próxima iteração, dessa forma grantimos que ele aponta para o lugar certo

        struct Inner_List* ptrTemp = popInner(list, ptrInner);

        while (ptrInner->prev != nullptr && ptrInner->prev->head->iData > ptrTemp->head->iData)
        {
            ptrInner = ptrInner->prev;
        }
        if (ptrInner == list->head) insertFront(list, ptrTemp);
        else insertAfter(ptrInner->prev, ptrTemp);
    }
}

void sortMatrix(Outer_List* list)
{
    Inner_List* temp = list->head;
    while (temp != nullptr) 
    {
        insertionSort(temp);
        temp = temp->next;
    }

    insertionSort(list);
}

//////////////////////////////////////////////////////////////////////////////////////
int main()
{
    List* listinha = randList(20);
    printList(listinha);

    // Questão 1
    cout << "A lista está ordenada em ordem crescente? " << isOrdered(listinha->head, "crescente") << endl; 
    cout << "A lista está ordenada em ordem decrescente? " << isOrdered(listinha->head, "decrescente") << endl; 

    // Questão 2
    cout << "Organizando lista..." << endl;
    
    auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    insertionSort(listinha);
    shellSort(listinha);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);

    printList(listinha);
    // cout << timeDuration.count() << endl;
    cout << "A lista está ordenada em ordem crescente? " << isOrdered(listinha->head, "crescente") << endl; 

    // Questão 3
    cout << "\nMatriz aleatória:" << endl;
    Outer_List* Out = randOuter(10, 10);
    printList(Out);

    cout << "Organizando Matriz..." << endl;
    sortMatrix(Out);

    printList(Out);

    return 0;
}

