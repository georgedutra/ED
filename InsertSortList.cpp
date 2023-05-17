#include <iostream>
#include <chrono> 
#include "DoubleChainList.cpp"

using namespace std;
using namespace std::chrono;

// Inserting Sort para listas duplamente encadeadas (usando swap):
void insertSortSwapping(struct List* list)
{
    int iLenght = getLenght(list);

    struct Node* ptrOuter = list->head->ptrNext;
    struct Node* ptrInner = nullptr;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-2; iOuterLoop++) 
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->ptrNext;

        while (ptrInner->ptrPrev != nullptr)
        {
            if (ptrInner->ptrPrev->iData <= ptrInner->iData) break;
            swapNodes(list, ptrInner->ptrPrev, ptrInner);
        }
    }
}

// Inserting Sort para listas duplamente encadeadas (usando pop e insert):
void insertSortPop(struct List* list)
{
    int iLenght = getLenght(list);

    struct Node* ptrOuter = list->head->ptrNext;
    struct Node* ptrInner = nullptr;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-2; iOuterLoop++) 
    {
        ptrInner = ptrOuter;
        ptrOuter = ptrOuter->ptrNext;

        struct Node* ptrTemp = popNode(list, ptrInner);

        while (ptrInner->ptrPrev != nullptr)
        {
            if (ptrInner->ptrPrev->iData <= ptrTemp->iData) break;
            ptrInner = ptrInner->ptrPrev;
        }
        if (ptrInner == list->head) insertFront(list, ptrTemp);
        else insertAfter(ptrInner->ptrPrev, ptrTemp);
    }
}

int main()
{
    struct List* listinha = (struct List*) malloc(sizeof(struct List));
    listinha->head = nullptr;
    listinha->tail = nullptr;

    // Inserindo muita coisa...
    int i = 0;
    bool b = false;
    struct Node* newNode = nullptr; 
    
    while (b==false)
    {
        newNode = createNode(i);
        insertFront(listinha, newNode);
        i++;

        newNode = createNode(i);
        insertEnd(listinha, newNode);
        i++;
        if (i == 100) break;
    }

    cout << "Listinha original:" << endl;
    displayList(listinha);
    cout << "===============================" << endl;

    // InsertSort usando Swap:
    auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    insertSortSwapping(listinha);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

    /////////////////////////////////////////////

    // InsertSort usando Pop:
    // auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    // insertSortPop(listinha);
    // auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

    cout << "Listinha organizada:" << endl;
    displayList(listinha);

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanossegundos" << endl;
    cout << "===============================" << endl;

    return 0;
}
