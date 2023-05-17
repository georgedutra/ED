#include <iostream>
#include <chrono> 
#include "DoubleChainList.cpp"

using namespace std;
using namespace std::chrono;

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


    // Testei a swapNodes para todos os casos válidos que consegui pensar
    // swapNodes(listinha,  listinha->head, listinha->head->ptrNext);
    
    // Finalmente, o algoritmo de BubbleSort:
    auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    megaBubble(listinha);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

    cout << "Listinha organizada:" << endl;

    displayList(listinha);

    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanossegundos" << endl;
    cout << "===============================" << endl;

    return 0;
}
