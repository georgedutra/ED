#include <iostream>

using std::cout;
using std::endl;
using std::string;

// Criando um tipo da classe enum, e usando flags
/*
int main()
{
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, HBO, Netflix};
    
    Streaming streamingSub = AppleTV;

    // switch(streamingSub) // C e C++ atribuirá automaticamente um valor numérico à variável criada no tipo enum
    // {
    //     case AppleTV:
    //         cout << "É tudo muito esquisito... [" << streamingSub << "]" << endl;
    //         break;
    //     case DisneyPlus:
    //         cout << "É tudo muito ruim... [" << streamingSub << "]" << endl;
    //         break;
    //     default:
    //         cout << "É melhor ler um gibi [" << streamingSub << "]" << endl;
    // }
    
    // Flag
    // enum Meses {Janeiro = 1, Fevereiro, Março, Abril, Maio}; // C++ usa autoincremento para enumerar os itens, a partir da flag dada
    // Meses mes = Maio;
    // cout << mes << endl;

    // enum Dias {Segunda = 10, Terça, Quarta, Quinta = 15, Sexta};
    // Dias dia = Sexta;
    // cout << dia << endl;

    return 0;
}
*/

void troca1(int&, int&);
void troca2(int&, int&);

int main()
{
    string strNome = "Yuri Saporito";
    int iValor = 42;

    // cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    // cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    // cout << "=================" << endl;

    string& strrefNome = strNome;
    int& irefValor = iValor;

    // cout << "Valor da refString: " << strrefNome << ". Endereço da refString: " << &strrefNome << endl;
    // cout << "Valor do refInteiro: " << irefValor << ". Endereço do refInteiro: " << &irefValor << endl;
    // cout << "=================" << endl;

    strrefNome = "César Camacho";
    irefValor = 666;

    // cout << "Valor da String: " << strNome << ". Endereço da String: " << &strNome << endl;
    // cout << "Valor do Inteiro: " << iValor << ". Endereço do Inteiro: " << &iValor << endl;
    // cout << "=================" << endl;
    // Perceba que mudar o valor de uma variável referência mudou também o valor da variável original

    int iNum1 = 7;
    int iNum2 = 42;

    cout << "iNum1 antes de trocar: " << iNum1 << endl;
    cout << "iNum2 antes de trocar: " << iNum2 << endl;

    // troca1(iNum1, iNum2);

    // cout << "iNum1 depois de troca1: " << iNum1 << endl;
    // cout << "iNum2 depois de troca1: " << iNum2 << endl;
    
    troca2(iNum1, iNum2);

    cout << "iNum1 depois de troca2: " << iNum1 << endl;
    cout << "iNum2 depois de troca2: " << iNum2 << endl;

    return 0;
}

void troca1(int& irefValor1, int& irefValor2)
{
    int iTemp = irefValor1;
    irefValor1 = irefValor2;
    irefValor2 = iTemp;
}

void troca2(int& irefValor1, int& irefValor2)
{
    irefValor1 = irefValor1 + irefValor2; //irefValor 1 = 49
    irefValor2 = irefValor1 - irefValor2; //irefValor 2 = 42
    irefValor1 = irefValor1 - irefValor2; //irefValor 1 = 7
}




