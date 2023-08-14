#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
void frasePreferida()
{
    cout << "Eu adoro a EMAp!" << endl;
}

void montarFrase(char chArtigo, string strPalavra)
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl;
}

void montarFrasePadrao(char chArtigo = 'a', string strPalavra = "EMAp")
{
    cout << "Eu adoro " << chArtigo << " " << strPalavra << "!" << endl;
}

int potenciacao(int iBase, int iExpoente)
{
    return pow(iBase, iExpoente);
}

int modulo(int iValor)
{
    return abs(iValor);
}

int main()
{
    frasePreferida();
    frasePreferida();
    frasePreferida();
    cout << "=======================\n" << endl;

    montarFrase('o', "Yuri");
    montarFrasePadrao();
    montarFrasePadrao('o');
    montarFrasePadrao('o', "Tio Rafa");
    cout << "=======================\n" << endl;

    cout << potenciacao(2, 10) << endl;
    cout << "=======================\n" << endl;
    
    float fNum = -42.42;

    cout << modulo(42) << endl;
    cout << modulo(-42) << endl;
    cout << modulo(42.5) << endl;
    cout << modulo(fNum) << endl;
    cout << "=======================\n" << endl;

    return 0;
}
*/

/*
void minhaFuncao(int arriNumeros[], int iTamanhoVetor)
{
    for (int i = 0; i < iTamanhoVetor; i++)
    {
        cout << arriNumeros[i] << endl;
    }
}

float soma(float iValor1, float iValor2)
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2)
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2, int iValor3)
{
    return iValor1 + iValor2 + iValor3;
}

int main()
{
    int arriVetorTeste[5] = {0 , 7, 13, 42, 666};
    int iTamanho = sizeof(arriVetorTeste)/sizeof(int);
    cout << iTamanho << endl;
    cout << "===========================\n" << endl;
    
    minhaFuncao(arriVetorTeste, iTamanho);
    cout << "===========================\n" << endl;

    int iNum1 = 7;
    int iNum2 = 42;
    int iNum3 = 666;

    float fNum1 = 7.7;
    float fNum2 = 42.666;

    cout << soma(fNum1, fNum2); //Sobrecarregamos uma função!!!!!!!
    cout << soma(iNum2, iNum3) << endl;
    cout << soma(iNum1, iNum2, iNum3) << endl;

    return 0;
}
*/

int soma(int, int);
int soma(int, int, int);

float soma(float iValor1, float iValor2)
{
    return iValor1 + iValor2;
}

int main()
{
    int iNum1 = 7;
    int iNum2 = 42;
    int iNum3 = 666;
    
    cout << soma(iNum1, iNum2) << endl;
    cout << soma(iNum1, iNum2, iNum3) << endl;

    return 0;
}

int soma(int iValor1, int iValor2)
{
    return iValor1 + iValor2;
}

int soma(int iValor1, int iValor2, int iValor3)
{
    return iValor1 + iValor2 + iValor3;
}

