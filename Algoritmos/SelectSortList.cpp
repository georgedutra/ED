#include <iostream>
#include <chrono> 
#include "DoubleChainList.cpp"

using namespace std;
using namespace std::chrono;

void selectSort(struct List* lista)
{
    struct Node* ptrOuter;
    struct Node* ptrInner;
    struct Node* ptrTemp;

    for (ptrOuter = lista->head; ptrOuter != nullptr; ptrOuter = ptrOuter->ptrNext)
    {
        for (ptrInner = ptrOuter->ptrNext; ptrInner != nullptr; ptrInner = ptrInner->ptrNext)
        {
            if (ptrOuter->iData > ptrInner->iData)
            {
                swapNodes(lista, ptrOuter, ptrInner);
                ptrTemp = ptrInner;
                ptrInner = ptrOuter;
                ptrOuter = ptrTemp;
            }
        }
    }
}

void selectSortRecursive(struct List* lista, struct Node* head)
{
    if (head->ptrNext == nullptr) return;
    
    struct Node* ptrInner;
    struct Node* ptrTemp;

    for (ptrInner = head->ptrNext; ptrInner != nullptr; ptrInner = ptrInner->ptrNext)
    {
        if (head->iData > ptrInner->iData)
        {
            swapNodes(lista, head, ptrInner);
            ptrTemp = ptrInner;
            ptrInner = head;
            head = ptrTemp;
        }
    }
    selectSortRecursive(lista, head->ptrNext);
}

void testSorts(int iTimes, int iSize)
{
    long long int iVal1 = 0, iVal2 = 0;

    for (int i=1; i<=iTimes; i++)
    {
        struct List* listinha = (struct List*) malloc(sizeof(struct List));
        listinha->head = nullptr;
        listinha->tail = nullptr;

        struct List* listinha2 = (struct List*) malloc(sizeof(struct List));
        listinha2->head = nullptr;
        listinha2->tail = nullptr;

        // Inserindo muita coisa...
        int j = 0;
        struct Node* newNode = nullptr; 
        
        while (true)
        {
            newNode = createNode(j);
            insertFront(listinha, newNode);

            newNode = createNode(j);
            insertFront(listinha2, newNode);
            j++;

            newNode = createNode(j);
            insertEnd(listinha, newNode);

            newNode = createNode(j);
            insertEnd(listinha2, newNode);
            j++;
            if (j >= iSize) break;
        }

        auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
        selectSort(listinha);
        auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

        ////////////////////////////////////////////////////////////////////////////////

        auto timeStart2 = high_resolution_clock::now(); // Iniciamos um cronômetro agora
        selectSortRecursive(listinha2, listinha2->head);
        auto timeStop2 = high_resolution_clock::now(); // Paramos o cronômetro
        
        ////////////////////////////////////////////////////////////////////////////////

        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        auto time2Duration = duration_cast<nanoseconds>(timeStop2 - timeStart2);

        iVal1 += timeDuration.count();
        iVal2 += time2Duration.count();
    }

    cout << "Média do Selection em nanossegundos: " << iVal1/iTimes << endl;
    cout << "Média do Selection Recursivo em nanossegundos: " << iVal2/iTimes << endl;
}

int main()
{
    testSorts(1000, 1000);

    return 0;
}
