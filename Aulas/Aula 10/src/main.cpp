#include <iostream>
#include "livro.h" 

/* Importante:
Para que isso funcione, é necessário que, no momento que pedimos para o compilador (g++, gpp, cl, etc.) buildar o projeto,
passemos todos os arquivos .cpp para serem compilados (nesse caso, tanto o main.cpp quanto o livro.cpp).
É possível configurar o CodeRunner para tal, ou faz~e-lo manualmente pelo terminal.
*/
using std::cout;
using std::cin;
using std::endl;
int main()
{
    struct Livro* livro1 = new(Livro);
    livro1->iPublicacao = 1970;
    struct Livro livro2;
    
    // Sabia que o struct não é necessário em C++?
    // Livro livro1;
    // Livro livro2;
    // cout << livro1->iPublicacao;
    int i = 42;
    funcaoOrganizada(i);


    return 0;
}


////////////////////////////////////////////////////////////////////////////////////

// Sizeof

/*
int main()
{
    struct Livro livro1;
    struct Livro livro2;

    // Vamos brincar perguntando o nome de algumas coisas...
    // cout << "Sizeof Livro: " << sizeof(struct Livro) << endl;
    // cout << "Sizeof livro1: " << sizeof(livro1) << endl;
    // cout << "Sizeof livro2: " << sizeof(livro2) << endl;
    
    // cout << "Sizeof livro1.strTitulo: " << sizeof(livro1.strTitulo) << endl;
    // cout << "Sizeof livro2.strTitulo: " << sizeof(livro2.strTitulo) << endl;
    // cout << "Sizeof livro1.strAutor: " << sizeof(livro1.strAutor) << endl;
    // cout << "Sizeof livro2.strAutor: " << sizeof(livro2.strAutor) << endl;

    // Espera, vamos verificar uma coisa 
    // cout << "Sizeof livro2: " << sizeof(livro2) << endl;
    // cout << "Sizeof livro2.strTitulo: " << sizeof(livro2.strTitulo) << endl;
    // cout << "Sizeof livro2.strAutor: " << sizeof(livro2.strAutor) << endl;
    // cout << "Sizeof livro2.iPublicacao: " << sizeof(livro2.iPublicacao) << endl;
    // Ué, a conta não fecha?? Isso é assunto de fora do nosso curso, e não vamos discutir isso
    // Se quiser ficar perigosamente perto da máquina, pesquise "The Lost Art of Structure Packing"
}
*/
