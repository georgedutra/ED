// Uma estrutura é uma área da memória que é designada para um coletivo de dados específicos

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// Declarando variáveis novas com struct, uma por vez
/*
int main()
{
    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp ; // Essa variável está alocada na memória, ela é especial :)

    alunoEMAp.iIdade = 19; // Membro de dados da variavel
    alunoEMAp.strNome = "Guilherme";

    cout << "Idade do aluno: " << alunoEMAp.iIdade << endl;
    cout << "Nome do aluno: " << alunoEMAp.strNome << endl;

    struct
    {
        int iIdade;
        string strNome;
    } alunoEMAp2, alunoEMAp3;

    alunoEMAp2.iIdade = 22; 
    alunoEMAp2.strNome = "Matheus";

    cout << "Idade do aluno 2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do aluno 2: " << alunoEMAp2.strNome << endl;


    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////

// Declarando tipos novos com struct

/*
struct Livro
{
    string strTitulo;
    string strAutor;
    int iDataPublicacao;
};

struct Dot
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

int main()
{
    struct Livro livro1;
    struct Livro livro2;

    livro1.strAutor = "Malcolm Gladwell";
    livro1.strTitulo = "Outliers: The Story of Success"; 
    livro1.iDataPublicacao = 2008;

    livro2.strAutor = "How to Grow Old";
    livro2.strTitulo = "Marcus Tullius Cicero"; 
    livro2.iDataPublicacao = -44;

    // cout << livro1.strTitulo << ", by " << livro1.strAutor << ". Published in " << livro1.iDataPublicacao << "." << endl;
    // cout << livro2.strTitulo << ", by " << livro2.strAutor << ". Published in " << livro2.iDataPublicacao << "." << endl;

    struct Dot screen[640][480];

    screen[0][0].usRed = 0;
    screen[0][0].usGreen = 0;
    screen[0][0].usBlue = 0;

    screen[0][1] = {255, 192, 203};

    cout << "RGB(" << screen[0][0].usRed << "," << screen[0][0].usGreen << "," << screen[0][0].usBlue << ")" << endl;
    cout << "RGB(" << screen[0][1].usRed << "," << screen[0][1].usGreen << "," << screen[0][1].usBlue << ")" << endl;



    return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////////////////


struct Livro
{
    string strTitulo;
    string strAutor;
    int iDataPublicacao;
};

struct Biblioteca
{
    string strNome;
    int iTamanhoAcervo;
    struct Livro livros[1000];
};

void adicionarLivros(struct Biblioteca&, struct Livro);
void listarLivros(struct Biblioteca);

int main()
{
    struct Biblioteca biblioteca;
    biblioteca.strNome = "Biblioteca do Tio Rafa";
    biblioteca.iTamanhoAcervo = 0;

    struct Livro livro1;
    struct Livro livro2;
    
    livro1.strAutor = "Malcolm Gladwell";
    livro1.strTitulo = "Outliers: The Story of Success"; 
    livro1.iDataPublicacao = 2008;

    biblioteca.livros[biblioteca.iTamanhoAcervo] = livro1;
    biblioteca.iTamanhoAcervo++;

    livro2.strAutor = "Marcus Tullius Cicero";
    livro2.strTitulo = "How to Grow Old"; 
    livro2.iDataPublicacao = -44;

    biblioteca.livros[biblioteca.iTamanhoAcervo] = livro2;
    biblioteca.iTamanhoAcervo++;

    cout << "Nome: " << biblioteca.strNome << endl; 
    cout << "Tamanho do Acervo: " << biblioteca.iTamanhoAcervo << endl; 

    listarLivros(biblioteca);

    struct Livro livro3;
    livro3.strAutor = "Emille Bronte";
    livro3.strTitulo = "Morro dos Ventos Uivantes"; 
    livro3.iDataPublicacao = 1847;

    adicionarLivros(biblioteca, livro3);
    listarLivros(biblioteca);

    return 0;
}

void listarLivros(struct Biblioteca biblioteca)
{
    cout << "Livros do Acervo: " << endl;
    for(int i = 0; i < biblioteca.iTamanhoAcervo; i++)
    {
        cout << "\t" << biblioteca.livros[i].strTitulo << ", by " << biblioteca.livros[i].strAutor << ". Published in " << biblioteca.livros[i].iDataPublicacao << "." << endl; 
    }
}

void adicionarLivros(struct Biblioteca& biblioteca, struct Livro livroNovo)
{
    biblioteca.livros[biblioteca.iTamanhoAcervo] = livroNovo;
    biblioteca.iTamanhoAcervo++;
}
