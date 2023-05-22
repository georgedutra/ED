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

void insertionSort(int array[], int iLenght)
{
    // Imaginemos que o vetor é separado em dois pedaços: à esquerda está ordenado, e à direita, desordenado
    for (int iOuterLoop = 1; iOuterLoop < iLenght; iOuterLoop++) // Começamos olhando para o segundo elemento, pois o primeiro já está ordenado
    {
        int iTemp = array[iOuterLoop]; // Essa variável temporária guarda o valor que será inserido na parte ordenada
        int iInnerLoop = iOuterLoop - 1; // Preparando o loop interno, que olha para a parte ordenada

        while (iTemp < array[iInnerLoop] && iInnerLoop >= 0) // Nosso loop quebra quando achamos um valor na parte ordenada menor que o guardado, ou quando chegarmos no fim do vetor
        {
            array[iInnerLoop+1] = array[iInnerLoop]; // Se o valor da parte ordenada não é maior que o guardado, passamos esse valor pra "frente", e seguimos
            iInnerLoop--;
        }
        // Quando chegamos aqui, o while deu falso, então temos duas opções: 
        // Ou o valor guardado em array[iInnerLoop] é menor que iTemp, ou chegamos no fim da parte ordenada (iInnerloop = -1) e não tem nenhum valor menor que o guardado. 
        // No primeiro caso, inserimos iTemp logo após o valor menor que ele. No segundo caso, inserimos o iTemp no início do vetor.
        // Em ambos os casos, a linha de código a seguir é válida:
        array[iInnerLoop+1] = iTemp; 
    }
}

// ShellSort com o incremento de Shell
void shellSort(int array[], int iLenght)
{
    for (int k = 2; trunc(iLenght/k) >= 1; k = k*2) // Para cada incremento, começando do maior, indo até 1, que é o insertionSort padrão
    {
        int inc = trunc(iLenght/k);
    
        for (int i = 0; i < inc; i++) 
        {
            // Imagine que estamos fazendo um insertion sort, mas cada elemento não olha para o anterior, e sim para o elemento que está a "inc" passos de distância
            for (int iOuterLoop = i+inc; iOuterLoop < iLenght; iOuterLoop += inc) // Começamos olhando para o segundo elemento, e o próximo está "inc" passos para frente
            {
                int iTemp = array[iOuterLoop];
                int iInnerLoop = iOuterLoop - inc; // Agora o loop interno começa no anterior, que está "inc" passos atrás

                while (iInnerLoop >= 0 && iTemp < array[iInnerLoop]) // Nosso loop quebra quando achamos um valor à esquerda menor que o guardado, ou quando chegarmos no fim do vetor
                {
                    array[iInnerLoop+inc] = array[iInnerLoop]; // Se o valor da esquerda não é menor que o guardado, passamos esse valor "inc" passos pra frente, e seguimos
                    iInnerLoop -= inc; // o iInnerLoop também caminha para trás em passos de tamanho "inc"
                }
                // Agora quando chegamos aqui, o iInnerLoop está "inc" passos antes do local ideal para inserir o iTemp
                array[iInnerLoop+inc] = iTemp; 
            }
        }
    }
}

// ShellSort utilizando o incremento de Hibbard, que aparentemente é bem ruim
void shellSortHibbard(int array[], int iLenght, int k0)
{
    // Antes eu calculava o incremento de Hibbard aqui dentro, mas por envolver potências, ele acaba sendo pesado, por isso passei para fora da função
    for (int k = k0; k>0; k--) // Para cada incremento, começando do maior, indo até 1, que é o insertionSort padrão
    {
        int inc = pow(2, k) - 1;
    
        for (int i = 0; i < inc; i++) 
        {
            // Imagine que estamos fazendo um insertion sort, mas cada elemento não olha para o anterior, e sim para o elemento que está a "inc" passos de distância
            for (int iOuterLoop = i+inc; iOuterLoop < iLenght; iOuterLoop += inc) // Começamos olhando para o segundo elemento, e o próximo está "inc" passos para frente
            {
                int iTemp = array[iOuterLoop];
                int iInnerLoop = iOuterLoop - inc; // Agora o loop interno começa no anterior, que está "inc" passos atrás

                while (iInnerLoop >= 0 && iTemp < array[iInnerLoop]) // Nosso loop quebra quando achamos um valor à esquerda menor que o guardado, ou quando chegarmos no fim do vetor
                {
                    array[iInnerLoop+inc] = array[iInnerLoop]; // Se o valor da esquerda não é menor que o guardado, passamos esse valor "inc" passos pra frente, e seguimos
                    iInnerLoop -= inc; // o iInnerLoop também caminha para trás em passos de tamanho "inc"
                }
                // Agora quando chegamos aqui, o iInnerLoop está "inc" passos antes do local ideal para inserir o iTemp
                array[iInnerLoop+inc] = iTemp; 
            }
        }
    }
}

int main()
{
    int iSize = 1000;
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
    insertionSort(randArray, iSize);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro

    ////////////////////////////////////////////////////////////////////////////////
    auto timeStart2 = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    shellSort(randArray2, iSize);
    auto timeStop2 = high_resolution_clock::now(); // Paramos o cronômetro

    ////////////////////////////////////////////////////////////////////////////////
    int k0 = 1;
    while ((pow(2, k0+1)-1) < iSize) k0++; // Procuramos qual o primeiro incremento de Hibbard que pode ser utilizado

    auto timeStart3 = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    shellSortHibbard(randArray3, iSize, k0);
    auto timeStop3 = high_resolution_clock::now(); // Paramos o cronômetro
    ////////////////////////////////////////////////////////////////////////////////

    cout << "Arrays originais ordenados: " << endl;
    printArray(randArray, iSize);
    printArray(randArray2, iSize);
    printArray(randArray3, iSize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado Insertion: " << timeDuration.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    auto time2Duration = duration_cast<nanoseconds>(timeStop2 - timeStart2);
    cout << "Tempo utilizado Shell: " << time2Duration.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    auto time3Duration = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    cout << "Tempo utilizado Hibbard: " << time3Duration.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    // Parece que o incremento de Shell ainda é mais rápido para vetores de até 1000 elementos
    return 0;
}