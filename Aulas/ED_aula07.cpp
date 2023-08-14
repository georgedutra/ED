#include <iostream>

// Uma função para cálculo do fatorial de um número utilizando o laço for
using std::cin;
using std::cout;
using std::endl;

// void ask_factorial();
// unsigned int factorial(int);
// unsigned int recFactorial(int);
// unsigned int recSum(int);
unsigned int fibonacci(int);

int main()
{
    // ask_factorial();
    // cout << factorial(7) << endl;
    // cout << recFactorial(7) << endl;
    // cout << recSum(10) << endl;

    cout << "===========================" << endl;
    cout << "Fibonacci [1]: " << fibonacci(1) << endl;
    cout << "===========================" << endl;
    cout << "Fibonacci [2]: " << fibonacci(2) << endl;
    cout << "===========================" << endl;
    cout << "Fibonacci [3]: " << fibonacci(3) << endl;
    cout << "===========================" << endl;
    cout << "Fibonacci [4]: " << fibonacci(4) << endl;

    return 0;
}

/*
void ask_factorial()
{
    int iFator, iFatorial = 1;
    cout << "Digite o número do qual devo calcular o fatorial: ";
    cin >> iFator;
    cout << endl;

    for (int num = iFator; num > 0; num--)
    {
        iFatorial *= num;
    }

    cout << "O resultado é: " << iFator << "! = " << iFatorial << endl;
}

unsigned int factorial(int iNum)
{
    unsigned int uiFatorial = 1;
    for (int num = iNum; num > 0; num--) uiFatorial *= num;

    return uiFatorial;
}
*/


/*
// Função recursiva!!!!!!!!!!
unsigned int recFactorial(int iNum)
{
    if (iNum == 1) return 1;

    return recFactorial(iNum - 1) * iNum;
}

unsigned int recSum(int iNum) // Somatório dos n primeiros naturais, dado iNum = n
{
    if (iNum == 1) return 1;

    return recSum(iNum - 1) + iNum;
}
*/

unsigned int fibonacci(int iNum) // Retornar n-ésimo número de Fibonacci, n = iNum
{
    if (iNum == 1) return 0;
    if (iNum == 2) return 1;

    int fibo = 1;
    int fiboAnterior = 1;
    int dummy;

    for (int contador = 3; contador < iNum; contador++)
    {
        dummy = fibo;
        fibo += fiboAnterior;
        fiboAnterior = dummy;
    }

    return fibo;
}