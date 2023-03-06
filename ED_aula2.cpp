#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
int main()
{
    string strValue1 = "Eu adoro bastante, tipo pra caramba a";
    string strValue2 = "EMAp";

    cout << "strValue1: " << strValue1 << "\nTamanho strValue1: " << sizeof(strValue1) << endl; 
    cout << "strValue1: " << strValue2 << "\nTamanho strValue2: " << sizeof(strValue2) << endl;

    bool bValue1 = true;
    bool bValue2 = false;
    bool bValue3 = 42;
    bool bValue4 = 0;
    
    cout << "bValue1: " << bValue1 << "\nTamanho bValue1: " << sizeof(bValue1) << endl; 
    cout << "bValue2: " << bValue1 << "\nTamanho bValue1: " << sizeof(bValue1) << endl; 
    cout << "bValue3: " << bValue1 << "\nTamanho bValue1: " << sizeof(bValue1) << endl; 
    cout << "bValue4: " << bValue1 << "\nTamanho bValue1: " << sizeof(bValue1) << endl; 

    const int iValue1 = 42;


    return 0;
}
*/

int main()
{
    string strNome;
    int iIdade = 0;

    float fAltura = 0.0;
    float fPeso = 0.0;

    float fIMC = 0.0;

    cin >> strNome >> iIdade;
    cout << "Nome: " << strNome << endl; 
    cout << "Peso: " << iIdade << endl; 

    // if (fIMC <= 18.5)
    // {
    //     cout <<
    // }

    return 0;
}