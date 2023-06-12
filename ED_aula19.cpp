#include <iostream> 
#include <chrono> 
#include <math.h>

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

void selectSort(int arriNumbers[], int iLenght)
{
    if (iLenght == 1) return;

    int iMenor;
    for (int i = 1; i < iLenght; i++) // Comparamos
    {
        iMenor = arriNumbers[0];
        if (arriNumbers[i] < iMenor) swapValue(arriNumbers[0], arriNumbers[i]);
    }

    int* arriMenor = &arriNumbers[1];
    selectSort(arriMenor, iLenght-1);
}

// Essa função só serve pra testar cada sort varias vezes e tirar uma média do tempo
void testSorts(int iTimes)
{
    long long int iVal1 = 0;
    int iSize = 10;

    for (int i=1; i<=iTimes; i++)
    {
        int randArray[iSize];
        int randArray2[iSize];
        int randArray3[iSize];

        for(int i=0; i<iSize; i++)
        {
            randArray[i] = rand()%1000;  //Generate number between 0 to 999
            randArray2[i] = rand()%1000;  //Generate number between 0 to 999
            randArray3[i] = rand()%1000;  //Generate number between 0 to 999
        }

        cout << "Array original: ";
        printArray(randArray, iSize);
        cout << "================================\n" << endl;
        
        auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
        selectSort(randArray, iSize);
        auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

        cout << "Arrays originais ordenados: " << endl;
        printArray(randArray, iSize);
        
        auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
        iVal1 += timeDuration.count();
    }

    cout << "Média do Selection em nanossegundos: " << iVal1/iTimes << endl;
}

int main()
{
    testSorts(1);
    return 0;
}