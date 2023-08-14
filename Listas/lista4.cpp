#include <iostream>
#include "DoubleChainList.cpp" // Utilizei algumas funções auxiliares que eu já tenho prontas para manipular DChain Lists

using namespace std;

void insert(Node* head, int data) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode-> iData = data;
    newNode-> ptrNext = nullptr;

    Node* current = head;
    while(current -> ptrNext != nullptr) 
    {
        current = current -> ptrNext;
    }
    current -> ptrNext = newNode;
    newNode->ptrPrev = current;
}

void printList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->iData << " ";
        current = current->ptrNext;
    }
    cout << endl;
}

// Minhas questões funcionam sem a struct List, apesar de eu estar utilizando-a na main
//////////////////////////////////////////////////////////////////////////////////
// Questão 1

int sum(struct Node* head)
{
    int iResult = 0;

    while (head!=nullptr)
    {
        iResult += head->iData;
        head = head->ptrNext;
    }

    return iResult;   
}
//////////////////////////////////////////////////////////////////////////////////
// Questão 2

struct Node* concat(struct Node* head1, struct Node* head2)
{
    struct Node* newHead = createNode(head1->iData);
    head1 = head1->ptrNext;

    while (head1 != nullptr)
    {
        insert(newHead, head1->iData);
        head1 = head1->ptrNext;
    }
    while (head2!=nullptr)
    {
        insert(newHead, head2->iData);
        head2 = head2->ptrNext;
    }

    return newHead;
}
//////////////////////////////////////////////////////////////////////////////////
// Questão 3

// Bubble Sort para listas duplamente encadeadas:
void bubbleSort(struct List* list)
{
    int iLenght = getLenght(list);
    bool bUnordered;

    struct Node* ptrStart = list->head;
    struct Node* ptrEnd = list->tail;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        // Em cada loop externo, partimos do pressuposto de que a lista estará organizada
        bUnordered = false;

        while (ptrStart != ptrEnd && ptrStart->ptrPrev != ptrEnd)
        {
            if(ptrStart->iData > ptrStart->ptrNext->iData) 
            {
                swapNodes(list, ptrStart, ptrStart->ptrNext);
                bUnordered = true;
            }
            else ptrStart = ptrStart->ptrNext;
        }

        // Ao fim de um loop externo, se a lista não tinha nada fora de ordem, saímos do loop
        if (bUnordered == false) break;

        // Se não quebramos o loop, otimizamos o loop interno reduzindo o fim do loop, e preparamos o próximo
        if (ptrStart != list->tail) ptrEnd = ptrStart;
        ptrStart = list->head;
    }
}
//////////////////////////////////////////////////////////////////////////////////
// Questão 4

struct Node2
{
    struct Node2* next;
    struct Node* innerHead;
};

void insert2(struct Node2* outerHead, struct Node* innerHead)
{
    struct Node2* newOuter = (struct Node2*) malloc(sizeof(struct Node2));
    newOuter->innerHead = innerHead;

    Node2* current = outerHead;
    while(current -> next != nullptr) current = current -> next;
    
    current -> next = newOuter;
}

void printList2(Node2* head)
{
    Node2* current = head;
    while (current != nullptr)
    {
        printList(current->innerHead);
        current = current->next;
    }
    cout << endl;
}
//////////////////////////////////////////////////////////////////////////////////

int main () 
{
    struct List* listinha = (struct List*) malloc(sizeof(struct List));
    listinha->head = nullptr;
    listinha->tail = nullptr;

    int i = 0;
    struct Node* newNode = nullptr; 
    
    while (true)
    {
        newNode = createNode(i);
        insertFront(listinha, newNode);
        i++;

        newNode = createNode(i);
        insertEnd(listinha, newNode);
        i++;
        if (i >= 10) break;
    }
    cout << "Lista de testes: " << endl;
    displayList(listinha);

    cout << "\nQuestão 1: Soma dos elementos = " << sum(listinha->head) << "\n==============================================\n" << endl;

    //======================================//
    
    struct List* listinha2 = (struct List*) malloc(sizeof(struct List));
    listinha2->head = nullptr;
    listinha2->tail = nullptr;

    i = 0; 
    while (true)
    {
        newNode = createNode(i);
        insertFront(listinha2, newNode);
        i++;

        if (i >= 10) break;
    }
    cout << "Segunda lista de testes: " << endl;
    displayList(listinha2);

    struct List* listinha3 = (struct List*) malloc(sizeof(struct List));
    listinha3->head = concat(listinha->head, listinha2->head);
    listinha3->tail = listinha3->head;
    while(listinha3->tail->ptrNext != nullptr) listinha3->tail = listinha3->tail->ptrNext;

    cout << "\nQuestão 2: Lista 3 criada a partir da concatenação das duas primeiras: " << endl;
    displayList(listinha3);
    cout << "==============================================\n" << endl;

    //======================================//
    cout << "Questão 3: Lista 3 organizada com bubbleSort: " << endl;
    bubbleSort(listinha3);
    displayList(listinha3);
    cout << "==============================================\n" << endl;

    //======================================//
    struct Node2* headMatriz = (struct Node2*) malloc(sizeof(struct Node2));
    headMatriz->innerHead = listinha->head;

    insert2(headMatriz, listinha2->head);
    insert2(headMatriz, listinha->head);
    insert2(headMatriz, listinha2->head);
    
    cout << "Questão 4: Lista de listas: " << endl;
    printList2(headMatriz);

    return 0;
}