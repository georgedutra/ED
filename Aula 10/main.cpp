#include <iostream>
#include "livro.h" // Aqui nós incluímos nossa própria "biblioteca"
// Essa parte do código ainda não funciona, pois incluindo o livro.h que tem a referência da funcaoOrganizada,
// ele deveria referenciar o arquivo livro.cpp automaticamente, mas para funcionar na máquina local,  
// precisamos organizar o projeto nas pastas certas...

using std::cout;
using std::endl;

int main()
{
    struct Livro livro1;
    struct Livro livro2;
    
    // Sabia que o struct não é necessário em C++?
    // Livro livro1;
    // Livro livro2;

    funcaoOrganizada(42);
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
