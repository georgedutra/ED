#include <iostream>

using namespace std;

// Built-in Array (C-Style) vs Array/Vector
// string vs. C-Style

/*
int main()
{   
    // Variável: referência direta para um valor na memória; aponta diretamente para o valor
    // Ponteiro: referência indireta para um valor; aponta para um endereço específico na memória
    // Ponteiros são um tipo

    // É essencial inicializar um ponteiro na criação! Um ponteiro não inicializado aponta aleatoriamente.
    // int* ptrInt = 0;
    // int* ptrInt = NULL;
    int* ptrInt = nullptr; 
    
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço do PTR: " << &ptrInt << endl; // Posso ter um ponteiro pra um ponteiro? Sim e usamos muito! E assim por diante..
    cout << "===================================" << endl;
    
    int iNumMagico = 42;
    cout << "iNumMagico: " << iNumMagico << endl;
    cout << "Endereço do iNumMagico: " << &iNumMagico << endl;

    // ptrInt = iNumMagico; // Não funciona >:(
    ptrInt = &iNumMagico; 
    cout << "PTR: " << ptrInt << endl;
    cout << "Endereço do PTR: " << &ptrInt << endl; 
    cout << "===================================" << endl;
    // O ponteiro agora aponta para o iNumMagico, seu conteúdo é o endereço da variável, e seu endereço também!

    cout << "Tamanhos de Tipos: " << endl; 
    cout << "Tamanhos de char - " << sizeof(char) << endl; 
    cout << "Tamanhos de int - " << sizeof(int) << endl; 
    cout << "Tamanhos de double - " << sizeof(double) << endl; 
    cout << "===================================" << endl;

    cout << "Tamanhos de Ponteiros para Tipos: " << endl; 
    cout << "Tamanhos de char - " << sizeof(char*) << endl; 
    cout << "Tamanhos de int - " << sizeof(int*) << endl; 
    cout << "Tamanhos de double - " << sizeof(double*) << endl; 
    cout << "===================================" << endl;
    // Perceba que o tamanho de um ponteiro é o tamanho padrão do sistema operacional: 64 bits (8 bytes)

    cout << "PTR: " << ptrInt << endl;
    cout << "Valor do PTR do iNumMagico: " << *ptrInt << endl; // O asterisco é um operador unário (operador de dereferência) 
    cout << "===================================" << endl;

    return 0;
}
*/

/*
int main()
{
    int iNum1 = 42;
    int iNum2 = 666;

    // Ponteiro constante 
    int* const ptrNum1 = &iNum1;
    *ptrNum1 = 7; // Podemos mudar um valor através do ponteiro
    // ptrNum1 = &iNum2; // Não funciona, o ponteiro é constante D:<

    cout << "PTR1: " << ptrNum1 << endl;
    cout << "Valor do PTR1: " << *ptrNum1 << endl;
    cout << "===================================" << endl;

    const int* ptrNum2 = &iNum2;
    ptrNum2 = &iNum1;
    // *ptrNum2 = 7; // Não funciona, o ponteiro aponta pra uma constante >:(

    cout << "PTR2: " << ptrNum2 << endl;
    cout << "Valor do PTR2: " << *ptrNum2 << endl;
    cout << "===================================" << endl;

    const int* const ptrNum3 = &iNum1; // Esse é um ponteiro constante apontando pra uma constante!
    cout << "Endereço de iNum1: " << ptrNum3 << endl;
    cout << "PTR3: " << ptrNum3 << endl;
    cout << "Valor do iNum1: " << iNum1 << endl;
    cout << "Valor do PTR3: " << *ptrNum3 << endl;
    cout << "===================================" << endl;

    return 0;
}
*/

int cubo(int*);

// int somaVetor(const int[], const size_t);
int somaVetor(const int*, const size_t);

int main()
{
    int iNum1 = 3;
    int iResultado = 0;

    iResultado = cubo(&iNum1);
    cout << "Resultado: " << iResultado << endl;
    cout << "===================================" << endl;

    int arriValores[3] = {0,1,2};
    iResultado = somaVetor(arriValores, 3);
    cout << "Resultado: " << iResultado << endl;
    cout << "===================================" << endl;

    return 0;
}

int cubo(int* ptrNum)
{
    return (*ptrNum) * (*ptrNum) * (*ptrNum);
}

// Se passamos um vetor raiz para uma função, o C++ passa secretamente um ponteiro constante para o primeiro elemento...
// int somaVetor(const int valores[] , const size_t tamVetor) 
// {
//     return -1;
// }

int somaVetor(const int* valores, const size_t tamVetor)
{
    return -1;

}
