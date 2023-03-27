#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
1. Solicitar um numero do usuario, e imprimir essa quantidade de ímpares (primos)
2. Solicitar um numero do usuario, e imprimir o módulo desse número sem a biblioteca math 
3. Solicitar palavra ao usuário, imprimir ao contrário sem usar bibliotecas
4. Solicitar um número, imprimir quantos dígitos tem o número
*/

// Questão 1 (fácil)
// int main()
// {
//     int iQuantidade;
//     cout << "Digite quantos números ímpares você quer: ";
//     cin >> iQuantidade;
//     cout << endl;

//     for (int i = 0; i < iQuantidade; i++)
//     {
//         cout << 2*i +1 << endl;
//     } 

//     return 0;
// }

// Questão 2
// int main()
// {
//     int iNumero;
//     cout << "Digite o número inteiro do qual você quer o módulo: ";
//     cin >> iNumero;
//     cout << endl;

//     if (iNumero < 0)
//     {
//         cout << "O módulo é: " <<iNumero * -1 << endl;
//     } 
//     else
//     {
//         cout << "O módulo é: " << iNumero << endl;
//     }

//     return 0;
// }

// // Questão 1 (difícil)
// int main()
// {
//     int iQuantidadePrimos, iUltimoPrimo = 0, iContador = 1;
//     cout << "Digite quantos números primos você quer: ";
//     cin >> iQuantidadePrimos;
//     cout << endl;

//     for (int i = 0; i < iQuantidadePrimos; i++)
//     {
//         while (iContador != 0)
//         {
//             iContador = 0;
//             iUltimoPrimo++;
//             if (iUltimoPrimo != 1 and iUltimoPrimo != 2 and iUltimoPrimo != 3)
//             {
//                 for (int j = 2; j < iUltimoPrimo; j++)
//                 {
//                     if (iUltimoPrimo % j != 0)
//                     {
//                         iContador++;
//                     }
//                 }
//             }
//         }
//         cout << iUltimoPrimo << endl;
//         iContador = 1;
//     } 

//     return 0;
// }

// Questão 3
// int main()
// {
//     string strPalavra;

//     cout << "Digite a palavra: " << endl;
//     cin >> strPalavra;

//     for (int i = strPalavra.length()-1; i >= 0; i--)
//     {
//         cout << strPalavra[i];
//     }
//     cout << endl;
//     return 0;
// }

// Questão 4
int main()
{
    int iContador = 0;
    int iNum;
    cout << "Digite um número inteiro: ";
    cin >> iNum;
    cout << endl;

    while (iNum > 1 or iNum < -1)
    {
        iNum /= 10;
        iContador++;
    }

    cout << "Seu número tem " << iContador << " dígitos!" << endl;

    return 0;
}