#include <iostream>

using std::cout;
using std::endl;

// int main()
// {
//     int iNum = 42;
    
//     cout << "Valor: " << iNum << endl;
//     cout << "Endereço: " << &iNum << endl;

//     iNum = 7;

//     cout << "Valor: " << iNum << endl;
//     cout << "Endereço: " << &iNum << endl;
    
//     return 0;
// }

int main()
{
    //-2,147,483,648 a 2,147,483,647
    //4 bytes
    int iNum1 = 42, iNum2, iNum3 = 7;

    cout << "iNum1: " << iNum1 << "\nTamanho iNum1: " << sizeof(iNum1) << endl;
    cout << "iNum2: " << iNum2 << "\nTamanho iNum2: " << sizeof(iNum2) << endl;
    cout << "iNum3: " << iNum3 << "\nTamanho iNum3: " << sizeof(iNum3) << endl;

    //-32,768 a 32,767
    //2 bytes
    short sNum1 = 42;
    cout << "sNum1: " << sNum1 << "\nTamanho sNum1: " << sizeof(sNum1) << endl;
    
    //-9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
    //8 bytes
    long lNum1 = 42;
    cout << "lNum1: " << lNum1 << "\nTamanho lNum1: " << sizeof(lNum1) << endl;
    
    
    //-9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
    //8 bytes
    long long llNum1 = 42;
    cout << "llNum1: " << llNum1 << "\nTamanho llNum1: " << sizeof(llNum1) << endl;
    
    //-128 a 127
    //1 Byte
    char cValue = 'E';
    cout << "cValue: " << cValue << "\nTamanho cValue: " << sizeof(cValue) << endl;
    cout << "cValue mas como int: " << int(cValue) << endl;
    
    char cPalavraPreferida1 = 77;
    char cPalavraPreferida2 = 0x41;
    char cPalavraPreferida3 = 0b1110000;
    cout << cValue;
    cout << cPalavraPreferida1;
    cout << cPalavraPreferida2;
    cout << cPalavraPreferida3 << endl;

    return 0;
}