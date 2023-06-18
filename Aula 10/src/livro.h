// Continuando com structs

#pragma once // Impede que a header file seja incluída várias vezes

// Isso também funciona:
// #ifndef _LOG_H              // Diretiva "se _LOG_H não estiver definida"
// #define _LOG_H              // Defina _LOG_H
//                             // Execute o código aqui dentro
// #endif                      // E encerre o if

// Portanto se uma variável de compilação com o nome que decidimos ali já tiver sido definida antes, o compilador não lê a header duas vezes

using std::string; // Perceba que as vezes o arquivo não encontra o tipo string de cara, pois não incluímos iostream nele, 
                   // mas NÃO É NECESSÁRIO, pois não compilaremos este arquivo .h, ele só serve de apoio para a main

void funcaoOrganizada(int);

struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
};

