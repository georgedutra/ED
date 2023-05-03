#include <iostream>

using namespace std;

// Hoje vamos criar uma pilha!!

struct Node
{
    int iData;
    struct Node* next;
};

// Variável global: TODO MUNDO consegue ver esse carinha
struct Node* ptrTop = nullptr;

// Função que imprime nossa pilha
void display()
{
    struct Node* ptrNode = nullptr;

    // Se a pilha estiver vazia, imprimimos isso
    if (ptrTop == nullptr) cout << "Nada aqui não brother..." << endl;
    // Se não, iteramos ao longo dela do topo até a base, imprimindo a payload
    else
    {
        ptrNode = ptrTop;
        cout << "Elementos da pilha: ";
    
        while(ptrNode != nullptr)
        {
            cout << ptrNode -> iData << " ";
            ptrNode = ptrNode -> next;
        }
    
    cout << endl;
    }
}

// Inserindo algo na pilha
void push(int iVal)
{
    // Perceba que ao contrário da fila, na pilha os Nodes apontam do TOPO para a BASE (do último adicionado para o primeiro)
    
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); // Alocamos memória
    newNode -> iData = iVal; // Inserimos o payload
    newNode -> next = ptrTop; // Mandamos o novo Node apontar para o Node abaixo dele na pilha

    ptrTop = newNode; // Por fim, atualizamos nosso topo
    // Curiosidade: Perceba que como temos uma variável global, podemos modificar ela em qualquer lugar. Virou bagunça!
}

void pop()
{
    if (ptrTop == nullptr) cout << "Nada aqui pra dar pop brother..." << endl;
    else
    {
        cout << "Elemento Removido: " << ptrTop -> iData << endl; 

        struct Node* tmpPTR = ptrTop; // Precisamos salvar o endereço do nosso elemento removido para não perdê-lo
        ptrTop = ptrTop -> next; // Atualizamos nosso topo, "tirando" o Node do topo
        free(tmpPTR); // Por fim removemos a memória do antigo Node do topo, para não causar vazamento de memória :D
    }
}

int main()
{
    display();
    cout << "==================" << endl;

    push(7);
    push(42);
    push(666);

    display();
    cout << "==================" << endl;
    
    pop();
    pop();
    display();
    cout << "==================" << endl;
    
    return 0;
}


