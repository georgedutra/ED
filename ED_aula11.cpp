#include <iostream>

using namespace std;

/*
int main()
{
    int arriValores[5] = {0,7,42,666,1000};
    cout << "Endereço de V[0]:" << arriValores << endl;

    int* ptrArrayValores1 = arriValores;
    cout << "PTR 1: " << ptrArrayValores1 << endl;

    int* ptrArrayValores2 = &arriValores[0];
    cout << "PTR 2: " << ptrArrayValores1 << endl;

    if (ptrArrayValores1 == ptrArrayValores2) cout << "São iguais!" << endl;
    cout << "=============================================" << endl;

    cout << "Valor de ptrArrayValores1[0]: " << *ptrArrayValores1 << endl;
    cout << "Endereço de ptrArrayValores1[0]: " << ptrArrayValores1 << endl;
    cout << "\n" << endl;

    // Não sei o que rolou aqui
    cout << "Valor estranho: " << ++*ptrArrayValores1 << endl;
    cout << "Endereço estranho: " << ptrArrayValores1 << endl; // Ele não atualiza inplace 
    cout << "\n" << endl;

    ptrArrayValores1 += 1;
    cout << "Valor de ptrArrayValores1[0 + 1]: " << *ptrArrayValores1 << endl; 
    cout << "Endereço de ptrArrayValores1[0 + 1]: " << ptrArrayValores1 << endl;
    cout << "\n" << endl;

    ptrArrayValores1 += 2;
    cout << "Valor de ptrArrayValores1[0 + 3]: " << *ptrArrayValores1 << endl; 
    cout << "Endereço de ptrArrayValores1[0 + 3]: " << ptrArrayValores1 << endl;
    cout << "\n" << endl;

    ptrArrayValores1 -= 2;
    cout << "Valor de ptrArrayValores1[0 + 1]: " << *ptrArrayValores1 << endl; 
    cout << "Endereço de ptrArrayValores1[0 + 1]: " << ptrArrayValores1 << endl;
    cout << "\n" << endl;
    
    cout << "Valor estranho: " << ptrArrayValores1 - ptrArrayValores2 << endl; 
    // Aquele valor era a "distância" entre um ponteiro e outro
    
    cout << "=============================================" << endl;
   
    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Node
{
    int data;
    struct Node* next; // Esse objeto tem dentro de si um ponteiro que aponta para o próximo elemento
};

void printList(struct Node* sNode)
{
    while (sNode != nullptr)
    {
        cout << "Dado do nó: " << sNode -> data << endl;
        sNode = sNode -> next;
    }
}

void addToList(struct Node* head, int iValue)
{
    struct Node* proximo= nullptr;
    proximo = (struct Node*) malloc(sizeof(struct Node));
    proximo -> data = iValue;
    proximo -> next = nullptr; 

    while (head -> next != nullptr)
    {
        head = head -> next;
    }

    head -> next = proximo;
}

int main()
{
    struct Node* head = nullptr;
    struct Node* second = nullptr;
    struct Node* third = nullptr;

    // Isso é um cast, que converte o tipo de um elemento com a sintaxe: a = (new_type) new_type
    head = (struct Node*) malloc(sizeof(struct Node)); // malloc pede memória para o SO, vem de memory allocation
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // Se não tinha memória suficiente para o malloc, o SO te devolve um nullptr, e devemos tomar cuidado com isso! 
    // if (head == nullptr) resolve isso ae

    // Com o operador arrow, nós acessamos um membro de dados de uma struct
    head -> data = 7;
    second -> data = 42;
    third -> data = 666;

    // Por fim, fazemos nossos ponteiros apontarem um pro outro para construir uma lista!
    head -> next = second;
    second -> next = third;
    third -> next = nullptr; // O último item da lista não aponta pra ninguém

    printList(head);
    addToList(head, 1);
    printList(head);

    // Para não causar memory leak, precisamos liberar TODA memória que pedimos para ser alocada
    free(third); // É importante liberar de trás para frente
    free(second);
    free(head); // Cuidado! Quando liberamos a head, perdemos qualquer pista que tínhamos daquela estrutura, não sabemos mais onde ela está ou estava!

    return 0;
}