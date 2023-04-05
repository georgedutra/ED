#include <iostream>

// using std::cout; // Aqui dizemos para buscar esse nome específico no namespace std
// using namespace std; // Aqui dizemos para buscar tudo que existe nesse namespace

// Criando nossos namespaces

/*
namespace EMAp
{
    int iValor = 42;

    void mockFunction()
    {
        cout << "Namespace: EMAp" << endl;
    }
}

namespace FGV
{
    int iValor = 666;

    void mockFunction()
    {
        cout << "Namespace: FGV" << endl;
    }
}
*/

/*
int main()
{
    // Chamamos uma função falando "namespace"::"função"
    // EMAp::mockFunction(); 
    // FGV::mockFunction();

    // mockFunction(); // Se tentarmos rodar assim, ele não encontrará uma função declarada com esse nome

    // Se designarmos um namespace, o código procurará funções nele com prioridade
    using namespace EMAp;
    EMAp::mockFunction(); 
    FGV::mockFunction();
    mockFunction();

    return 0;
}
*/

/*
int iValor = 100;

int main()
{
    int iValor = 1;

    // Perceba que declaramos a mesma variável em 4 lugares diferentes, mas o código NÃO dá erro
    // Para acessarmos cada variável, indicamos onde procurá-la:

    cout << "EMAp: " << EMAp::iValor <<endl;
    cout << "FGV: " << FGV::iValor <<endl;
    cout << "Local/Dentro da main: " << iValor <<endl;
    cout << "Global/Fora das funções: " << ::iValor <<endl;

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////

// Criando namespaces aninhados

/*
namespace FGV
{
    namespace EMAp
    {
        void mockFunction()
        {
            cout << "Namespace: EMAp" << endl;
        }
    }

    void mockFunction()
    {
        cout << "Namespace: FGV" << endl;
    }
}

// using namespace FGV; // Caso 1
using namespace FGV::EMAp; // Caso 2

int main()
{
    // Se usarmos o caso 1, podemos usar a função da FGV direto, e chamar o namespace EMAp direto
    // mockFunction();
    // EMAp::mockFunction();

    // Se usarmos o caso 2, podemos acessar o namespace EMAp direto, mas NÃO conseguimos usar o namespace externo FGV
    mockFunction();
    FGV::mockFunction;

    // Por isso evitamos usar using namespaces, pois pode haver muitas sobrecargas de funções

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////

// typedefs

/*
typedef unsigned int ui;

int main()
{
    ui uiInteiro = 1;
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////
