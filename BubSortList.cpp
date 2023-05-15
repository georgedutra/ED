#include <iostream>
#include "DoubleChainList.cpp"

using namespace std;

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

// Função que troca de lugar dois Nodes na estrutura de lista encadeada
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

// Bubble Sort para listas duplamente encadeadas:
void megaBubble(struct List* list)
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

int main()
{
    // Criando lista e testando as funções:
    struct List* listinha = (struct List*) malloc(sizeof(struct List));
    listinha->head = nullptr;
    listinha->tail = nullptr;

    // displayList(listinha);
    // int listLenght = getLenght(listinha);
    // cout << listLenght << endl;
    // cout << "===============================" << endl;
    
    insertFront(listinha, 0);
    insertFront(listinha, 1);
    insertFront(listinha, 5);
    insertFront(listinha, 8);

    // displayList(listinha);
    // listLenght = getLenght(listinha);
    // cout << listLenght << endl;
    // cout << "===============================" << endl;

    insertEnd(listinha, 2);
    insertEnd(listinha, 3);
    insertEnd(listinha, -1);
    insertEnd(listinha, -3);
    // displayList(listinha);
    // cout << "===============================" << endl;
    
    // deleteFirst(listinha);
    // deleteLast(listinha);
    // deleteNode(listinha, listinha->head->ptrNext->ptrNext->ptrNext);
    // displayList(listinha);
    // cout << "===============================" << endl;

    insertAfter(listinha->head->ptrNext->ptrNext->ptrNext, -15);

    cout << "Listinha original:" << endl;
    displayList(listinha);
    cout << "===============================" << endl;

    ////////////////////////////////////////////////////////////////////

    // Testei a swapNodes para todos os casos válidos que consegui pensar
    // swapNodes(listinha,  listinha->head, listinha->head->ptrNext);
    
    // Finalmente, o algoritmo de BubbleSort:
    megaBubble(listinha);

    cout << "Listinha organizada:" << endl;

    displayList(listinha);
    cout << "===============================" << endl;

    return 0;
}
