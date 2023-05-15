#include <iostream> 
#include <chrono> 

using namespace std;
using namespace std::chrono;

void printArray(int array[], int iLenght)
{
    for (int i = 0; i < iLenght; i++) cout << array[i] << " ";
    cout << endl;
}

void swapValue(int& iValue1, int& iValue2)
{
    int iTemp = iValue1;
    iValue1 = iValue2;
    iValue2 = iTemp;
}

// Primeira versão: Forçamos o algoritmo a passar pelo vetor n-1 vezes. Altamente custoso computacionalmente!
void bubbleSort(int array[], int iLenght)
{
    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
        for (int iInnerLoop = 0; iInnerLoop < iLenght-1; iInnerLoop++)
        {
            if(array[iInnerLoop] > array[iInnerLoop+1]) 
                swapValue(array[iInnerLoop], array[iInnerLoop+1]);
        }
}

// Segunda versão:
void superBubble(int array[], int iLenght)
{
    bool bUnordered = false;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        bUnordered = false;

        // Cada vez que passamos pelo vetor, temos a garantia de que o último é o maior, logo otimizamos!
        for (int iInnerLoop = 0; iInnerLoop < iLenght - 1 - iOuterLoop; iInnerLoop++) 
        {
            if(array[iInnerLoop] > array[iInnerLoop+1]) 
            {
                swapValue(array[iInnerLoop], array[iInnerLoop+1]);
                bUnordered = true;
            }
        }
        
        if (bUnordered == false) break;
    }
}

int main()
{
    // Primeira versão
    int arriNumbers[] = {42, 7, 0, 666, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);

    cout << "Array original: ";
    printArray(arriNumbers, iArraySize);
    cout << "================================\n" << endl;
    
    // time_point<std::chrono::high_resolution_clock> // Tipo horroroso, então vamos usar auto
    auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    bubbleSort(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro
    
    cout << "Array original ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    ///////////////////////////////////////////////////////////
    // Segunda versão

    int arriNumbers2[] = {654, 82, 80, 0, 46, 72};
    int iArraySize2 = sizeof(arriNumbers2)/sizeof(arriNumbers2[0]);

    cout << "Array original 2: ";
    printArray(arriNumbers2, iArraySize2);
    cout << "================================\n" << endl;

    auto timeStart2 = high_resolution_clock::now(); // Iniciamos um cronômetro
    superBubble(arriNumbers2, iArraySize2);
    auto timeStop2 = high_resolution_clock::now(); // Paramos o cronômetro
    
    cout << "Array original ordenado 2: ";
    printArray(arriNumbers2, iArraySize2);

    auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);
    cout << "Tempo utilizado: " << timeDuration2.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    return 0;
}

// Dever de casa: Bubble Sort Otimizado em listas duplamente encadeadas