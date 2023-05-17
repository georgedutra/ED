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

int main()
{
    int arriNumbers[] = {42, 7, 0, 666, 13};
    int iArraySize = sizeof(arriNumbers)/sizeof(arriNumbers[0]);

    cout << "Array original: ";
    printArray(arriNumbers, iArraySize);
    cout << "================================\n" << endl;
    
    // time_point<std::chrono::high_resolution_clock> // Tipo horroroso, então vamos usar auto
    auto timeStart = high_resolution_clock::now(); // Iniciamos um cronômetro agora
    insertionSort(arriNumbers, iArraySize);
    auto timeStop = high_resolution_clock::now(); // Paramos o cronômetro
    
    cout << "Array original ordenado: ";
    printArray(arriNumbers, iArraySize);
    
    auto timeDuration = duration_cast<nanoseconds>(timeStop - timeStart);
    cout << "Tempo utilizado: " << timeDuration.count() << " nanossegundos" << endl;
    cout << "================================\n" << endl;

    return 0;
}

// Dever de casa: Bubble Sort Otimizado em listas duplamente encadeadas