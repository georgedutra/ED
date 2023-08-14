#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Questão 1: Função que imprime os elementos de um array na mesma sintaxe que nós os definimos.

void printArray(int arriArray[], int iTamanho)
{
    cout << "{";
    for (int i = 0; i < iTamanho - 1; i++) cout << arriArray[i] << ", ";
    cout << arriArray[iTamanho - 1] << "}" << endl;   
}

/*
int main()
{
    int arriSeiLa[5] = {0, 1, 2, 3, 4};
    printArray(arriSeiLa, 20);

    return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Questão 2: função que recebe dois arrays, um char ('+' ou '-'), e o tamanho dos arrays, e substitui no primeiro array a soma ou subtração
// element-wise dos arrays passados

void operarArrays(int arrArray1[], int arrArray2[], char charOper, int iTamanho)
{
    switch(charOper)
    {
    case '+':
        for (int i = 0; i < iTamanho; i++) arrArray1[i] = arrArray1[i] + arrArray2[i];
        break;
    case '-':
        for (int i = 0; i < iTamanho; i++) arrArray1[i] = arrArray1[i] - arrArray2[i];
        break;
    default: cout << "Sinto muito, operação desconhecida :(" << endl;
    }
}
/*
int main()
{
    int arriSeiLa[5] = {0, 1, 2, 3, 4};
    int arriSeiLa2[5] = {0, 1, 2, 3, 4};
    operarArrays(arriSeiLa, arriSeiLa2, '+', 5);
    printArray(arriSeiLa, 5);
    return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 3: Jogo de pedra-papel-tesoura-lagarto-Spock

int codificarJogada(string Jogada)
{
    int iNum;
    if(Jogada == "pedra") iNum = 1;
    else if(Jogada == "papel") iNum = 10;
    else if(Jogada == "tesoura") iNum = 100;
    else if(Jogada == "lagarto") iNum = 1000;
    else if(Jogada == "Spock") iNum = 10000;
    return iNum;
}

int jogo_Spock(string Player1, string Player2)
{   
    int result = codificarJogada(Player1) - codificarJogada(Player2);
    if (result == 0) return 0;
    else if (result == -99 || result == -999 || result == 9 || result == 9990 || result == 90 || result == 900 || result == -9000 || result == 990 || result == 9900 || result == 9999) 
    return 1;
    else return 2;
} 
/*
int main()
{
    int iPontos1 = 0, iPontos2;
    string strPlay1, strPlay2;

    while (iPontos1 != 2 && iPontos2 != 2)
    {
        cout << "\nEscolha sua jogada digitando uma das palavras abaixo:\n(pedra) (papel) (tesoura) (lagarto) (Spock)\n\nJogador 1 digite aqui: ";
        cin >> strPlay1;
        cout << "Jogador 2 digite aqui: "; 
        cin >> strPlay2;
        cout << endl;

        switch (jogo_Spock(strPlay1, strPlay2))
        {
            case 0: 
                cout << "Empatou!\nJogador 1 [" << iPontos1 <<"] X [" << iPontos2 << "] Jogador 2" << endl;
                break;
            case 1: 
                iPontos1++;
                cout << "Jogador 1 [" << iPontos1 <<"] X [" << iPontos2 << "] Jogador 2" << endl;
                break;
            case 2:
                iPontos2++;
                cout << "Jogador 1 [" << iPontos1 <<"] X [" << iPontos2 << "] Jogador 2" << endl;
                break;
        }
    }
    if (iPontos1 == 2) cout << "============================\nBazinga! O Jogador 1 venceu!\n============================" << endl;
    else cout << "============================\nBazinga! O Jogador 2 venceu!\n============================"<< endl;

    return 0;
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 4

void jogar(char arrchTabuleiro[], int iPos, char chJogada)
{
    bool Ganhou = false;
    if (arrchTabuleiro[iPos] != '?') cout << "Jogada Inválida!" << endl;
    else
    {
        arrchTabuleiro[iPos] = chJogada;

        // Desenha o tabuleiro
        cout << "=====\n"
        << arrchTabuleiro[0] << " " << arrchTabuleiro[1] << " " << arrchTabuleiro[2] << "\n" 
        << arrchTabuleiro[3] << " " << arrchTabuleiro[4] << " " << arrchTabuleiro[5] << "\n"
        << arrchTabuleiro[6] << " " << arrchTabuleiro[7] << " " << arrchTabuleiro[8] << "\n=====" << endl;

        // Verifica vitória na linha marcada
        switch (iPos % 3)
        {
            case 0:
                if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos+1] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos+2]) Ganhou = true; 
                break;
            case 1: 
                if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos-1] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos+1]) Ganhou = true;
                break;
            case 2:
                if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos-1] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos-2]) Ganhou = true;    
        }

        // Verifica vitória na coluna marcada
        if (iPos < 3) if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos+3] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos+6]) Ganhou = true;
        else if (iPos < 6) if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos-3] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos+3]) Ganhou = true;
        else if (arrchTabuleiro[iPos] == arrchTabuleiro[iPos-3] && arrchTabuleiro[iPos] == arrchTabuleiro[iPos-6]) Ganhou = true;

        // Verifica vitória na diagonal marcada
        if (iPos == 0 || iPos == 4 || iPos == 8) if (arrchTabuleiro[0] == arrchTabuleiro[4] && arrchTabuleiro[0] == arrchTabuleiro[8]) Ganhou = true;
        if (iPos == 2 || iPos == 4 || iPos == 6) if (arrchTabuleiro[2] == arrchTabuleiro[4] && arrchTabuleiro[2] == arrchTabuleiro[6]) Ganhou = true;
    
        if (Ganhou == true) cout << "Parabéns! O jogador " << chJogada << " ganhou!" << endl; 
    }
}

int main()
{
    char tabuleiro[9] = {'?','?','?','?','?','?','?','?','?'};
    jogar(tabuleiro, 0, 'X');
    jogar(tabuleiro, 1, 'O');
    jogar(tabuleiro, 0, 'X');
    jogar(tabuleiro, 4, 'X');
    jogar(tabuleiro, 2, 'O');
    jogar(tabuleiro, 8, 'X');
    return 0;
}