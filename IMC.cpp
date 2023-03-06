#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    float fAltura;
    float fPeso;
    
    cout << "\nVamos calcular o seu IMC!\n" << "Digite aqui sua altura em metros: ";
    cin >> fAltura;
    cout << "Agora digite seu peso em quilogramas: ";
    cin >> fPeso;
    cout << endl;

    float fIMC = (fPeso)/(pow(fAltura, 2));
    cout << "Seu IMC é: " << fIMC << endl;

    if (fIMC < 18.5)
    {
        cout << "Segundo os parâmetros mais recentes, você está na classificação de magreza!" << endl;
    }
    else if (fIMC < 24.9)
    {
        cout << "Segundo os parâmetros mais recentes, você está saudável!" << endl;
    }
    else if (fIMC < 29.9)
    {
        cout << "Segundo os parâmetros mais recentes, você está na classificação de sobrepeso!" << endl;
    }
    else if (fIMC < 39.9)
    {
        cout << "Segundo os parâmetros mais recentes, você está na classificação de obesidade!" << endl;
    }
    else
    {
        cout << "Segundo os parâmetros mais recentes, você está na classificação de obesidade grave!" << endl;
    };

    return 0;
}