#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /*
    int iValor = 42, iValorLido = 0, iResultado = 0;
    cin >> iValorLido;

    iResultado = (iValorLido < iValor) ? 0 : 1; // Operador ternário

    cout << "Resultado: " << iResultado << endl;
    cout << "------------------------" << endl;

    int iDia = 1;

    switch (iDia) // Avalia a expressão e avalia a partir da encontrada
    {
        case 1:
            cout << "Segunda" << endl;
            break;
        case 2:
            cout << "Terça" << endl;
            break;
        case 3:
            cout << "Quarta" << endl;    
            break;
        case 4:
            cout << "Quinta" << endl;
            break;
        case 5:
            cout << "Sexta" << endl;
            break;
        case 6:
            cout << "Sábado" << endl;
            break;
        case 7:
            cout << "Domingo" << endl;
            break;
        default:
            cout << "Que estranho!" << endl;
    } 

    int iContador = 0;
    do
    {
        cout<< iContador << endl;
        iContador++;
    }
    while (iContador < 5);
    cout << "------------------------" << endl;
    */

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; i <= 2 ; j++)
        {
            cout << "(" << i << ", " << j << ")" << endl;
        }
    }

    return 0;
}