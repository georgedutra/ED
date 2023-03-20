#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /*
    int arriExemplo1[100]; // Essa é uma forma de declarar um array de inteiros, passando o tamanho dele entre colchetes
    int arriExemplo2[4];
    
    arriExemplo2[0] = 8;
    arriExemplo2[1] = 64;
    arriExemplo2[2] = 256;
    arriExemplo2[3] = 512;

    // <Endereço Base> + <Offset> (<Índice * sizeoff(type)>)
    cout << "Valor: " << arriExemplo2[0]
        << "\nEndereço: " << &arriExemplo2[0] << endl;

    cout << "Valor: " << arriExemplo2[1]
        << "\nEndereço: " << &arriExemplo2[1] << endl;

    cout << "Valor: " << arriExemplo2[2]
        << "\nEndereço: " << &arriExemplo2[2] << endl;

    cout << "Valor: " << arriExemplo2[3]
        << "\nEndereço: " << &arriExemplo2[3] << endl;

    cout << "Valor: " << arriExemplo2[1000]
        << "\nEndereço: " << &arriExemplo2[1000] << endl;

    if (&arriExemplo2[0] == arriExemplo2) cout << "EMAp!" << endl;
    */

    // int arriExemplo3[2][3] = {7, 1, 4, 71, 0, 92};
    int arriExemplo3[2][3] = {{7, 1, 4}, {71, 0, 92}};

    for (int i = 0; i < 2; i++) // Para cada linha
    {
        for (int j = 0; j < 3; j++) // Para cada coluna
        {
            cout << "(" << i << ", " << j << "): " // Imprima os índices (linha, coluna)
                << arriExemplo3[i][j] // Imprima o conteúdo nesse índice
                << "\tEndereço: " << &arriExemplo3[i][j] << endl; // Imprima o endereço desse pedaço
        }
    }

    cout << "================================" << endl;

    // Aqui nós vamos errar de propósito o tamanho o tamanho das linhas e colunas, e perceba que vamos acessar lixo
    // O tamanho das linhas foi definido na criação, portanto o C++ já decidiu quantos bytes ele pula de uma linha pra outra
    // Se você manda ele pular um número de linhas X, ele vai pular X * Offset pré-definido
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            cout << "(" << i << ", " << j << "): " 
                << arriExemplo3[i][j] 
                << "\tEndereço: " << &arriExemplo3[i][j] << endl; 
        }
    }

    return 0;
}