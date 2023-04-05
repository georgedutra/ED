// Continuando com structs

using std::string; // Perceba que as vezes o arquivo não encontra o tipo string de cara, pois não incluímos iostream nele, 
                   // mas NÃO É NECESSÁRIO, pois não compilaremos este arquivo .h, ele só serve de apoio para a main

struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
};

void funcaoOrganizada(int);