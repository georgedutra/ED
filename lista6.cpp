#include <iostream>

using namespace std;

// Lista 6: Listas Circulares

// Definição de nó
struct Node
{
    int iData;
    struct Node* ptrNext;
};

//Definição de lista
struct List
{
    struct Node* head;
};

// Função que cria um nó
struct Node* createNode(int iVal)
{
    struct Node* newNode = new(Node);
    newNode->iData = iVal;
    newNode->ptrNext = nullptr;

    return newNode;
}

// Função que insere um nó no final da lista simples
void insertEnd(struct List* list, struct Node* newNode)
{
    // O último nó sempre aponta para nullptr para a direita
    newNode->ptrNext = nullptr;

    if (list->head == nullptr) list->head = newNode;  // Se a lista está vazia
    else
    {
    Node* temp = list->head; 
    while (temp->ptrNext!= nullptr) temp = temp->ptrNext;
    temp->ptrNext = newNode;
    }
}

// Função que imprime a lista simples
void printList(struct List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Node* printer = list->head;

    cout << "Payload: ";
    while (printer != nullptr)
    {
        cout << printer->iData << " ";
        printer = printer->ptrNext;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 1

// Função que recebe um nó, uma lista circular, e insere o nó no local correto de acordo com a ordem crescente do payload
void insertInOrder(struct Node* newNode, struct List* list)
{
    if (newNode == nullptr || list == nullptr) // Tratando problemas mais comuns
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    }


    if (list->head == nullptr) // Caso a lista esteja vazia
    {
        newNode->ptrNext = newNode;
        list->head = newNode;
        return;
    }

    if (list->head->ptrNext == list->head) // Tratando o caso da lista ter somente um nó
    {
        newNode->ptrNext = list->head;
        list->head->ptrNext = newNode;
        if (list->head->iData > newNode->iData) list->head = newNode;
        return;
    }

    // Ponteiro temporário auxiliar 
    struct Node* temp = list->head;
    
    while (temp->ptrNext->iData < newNode->iData && temp->ptrNext != list->head) temp = temp->ptrNext; // Tentamos caminhar até o local ideal entre dois nós

    // Caso o temp não possua valor menor que o novo nó, significa que o novo nó é a nova head
    if (temp->iData >= newNode->iData) 
    {
        while (temp->ptrNext != list->head) temp = temp->ptrNext;
        list->head = newNode;
    }
     
    // Essa parte roda em ambos os casos: se o novo nó for ou não a nova head
    newNode->ptrNext = temp->ptrNext;
    temp->ptrNext = newNode;
}

void printCircular(struct List* list)
{
    Node* temp = list->head;

    cout << "Carga da lista: ";

    do
    {
        cout << temp->iData << " "; 
        temp = temp->ptrNext;
    } while (temp != list->head);

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 2

// Função que verifica a partir de um ponteiro de lista se a respectiva lista é circular ou não
bool isCircular(Node* head)
{
    Node* temp = head->ptrNext;
    
    while (temp != nullptr) // Procuramos por um nullptr
    {
        if (temp == head) return true; // Se voltarmos para a head em algum momento, é circular
        temp = temp->ptrNext;
    }

    return false; // Se encontrarmos um nullptr, não é circular
}
// Não tratei loops internos, dado que eles são um erro e não uma lista válida

////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 3

// Função que recebe a head de uma lista encadeada, e faz uma rotação de iNumber elementos, retornando a nova head da lista
Node* listRotation(Node* head, int iNumber)
{
    Node* tail = head; // Primeiro vamos criar uma "tail" para nossa lista encadeada
    while (tail->ptrNext != nullptr) tail = tail->ptrNext;

    tail->ptrNext = head; // Agora a lista é circular
    for (int i = 0; i < iNumber; i++) head = head->ptrNext; // Fazemos nossa head avançar "iNumber" elementos para frente

    while (tail->ptrNext != head) tail = tail->ptrNext; // Reajustamos nossa tail
    tail->ptrNext = nullptr; // Agora ela voltou a ser uma lista simples :)

    return head;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 4

// Soldado do problema de Josefo
struct Soldier
{
    int id;
    bool is_alive;
    Soldier* next;
};

// Círculo de soldados
struct Circle
{
    Soldier* head;
};

// Cria um soldado com o ID passado
Soldier* createSoldier(int iID)
{
    struct Soldier* newSoldier = new(Soldier);
    newSoldier->id = iID;
    newSoldier->is_alive = true;
    newSoldier->next = nullptr;

    return newSoldier;
}

// Insere um soldado ao final de um círculo
void insertSoldier(struct Circle* circle, struct Soldier* newSoldier)
{
    // O último nó sempre aponta para nullptr para a direita
    Soldier* temp = circle->head;
    if (temp == nullptr) 
    {
        circle->head = newSoldier;
        newSoldier->next = newSoldier;
        return;
    }
    
    while (temp->next != circle->head) temp = temp->next;
    
    newSoldier->next = temp->next;
    temp->next = newSoldier;
}

// Função auxiliar de Josefo_Solver, conta quantos sobreviventes existem num círculo
int countSurvivors(Circle* circle)
{
    Soldier* temp = circle->head;
    int iSurvivors = 0;

    do
    {
        if (temp->is_alive == true) iSurvivors++;
        temp = temp->next;
    } 
    while(temp != circle->head); 

    return iSurvivors;
}

// Função auxiliar de Josefo_Solver, realiza o ato de um soldado matar outro
void kill(Soldier* soldier, int iInterval)
{
    Soldier* victim = soldier->next;
    do // Procuramos por outros soldados vivos no círculo para serem vítimas
    {
        if (victim->is_alive && victim != soldier) iInterval--; // Se encontramos um soldado vivo que não seja o atirador, este é uma vítima em potencial
        if (iInterval == 1) // Na iInterval-ésima vítima potencial, nosso atirador puxa o gatilho e encerra a função
        {
            cout << "O soldado " << soldier->id << " matou o soldado " << victim->id << " D:" << endl;
            victim->is_alive = false;
            return;
        }

        victim = victim->next;
    } while (iInterval > 1);
}

// Função auxiliar de Josefo_Solver, realiza um round de matança
void killingRound(Circle* circle, int iInterval)
{
    Soldier* temp = circle->head;
    do // Iteramos um a um pelos soldados na roda 
    {
        if (temp->is_alive == true) kill(temp, iInterval); // Se um soldado está vivo, pedimos para ele matar alguém
        temp = temp->next;
    } while (temp != circle->head); // Fazemos isso até rodar o círculo inteiro uma vez
}

// Função que resolve um Problema de Josefo, e retorna o id do soldado sobrevivente (também imprime no terminal o processo)
int Josefo_Solver(int iSoldiers, int iInterval)
{
    Circle* circle = new(Circle);
    circle->head = nullptr;

    // Criando nosso círculo de soldados...
    for (int i = 1; i <= iSoldiers; i++) insertSoldier(circle, createSoldier(i));

    int iRound = 0;

    while (countSurvivors(circle) > 1) // Enquanto houver mais de um sobrevivente, a matança continua
    {
        cout << "\nRound " << ++iRound << "\n" << endl;
        killingRound(circle, iInterval); // Chamamos a função que faz um round de matança
    }
    
    // Agora que sabemos que só há um sobrevivente, podmeos procurar por ele no círculo e encerrar a função
    Soldier* Survivor = circle->head;
    while (Survivor->is_alive != true) Survivor = Survivor->next;

    cout << "O soldado " << Survivor->id << " sobreviveu! :D\nE ele provavelmente está traumatizado pelo resto de sua vida D:" << endl; 
    return Survivor->id;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    struct List* circulo = new(List);

    //=======================================================//
    //Exemplo 1

    insertInOrder(createNode(0), circulo);
    insertInOrder(createNode(10), circulo);
    insertInOrder(createNode(17), circulo);
    insertInOrder(createNode(666), circulo);
    insertInOrder(createNode(42), circulo);
    insertInOrder(createNode(13), circulo);
    insertInOrder(createNode(999), circulo);
    insertInOrder(createNode(1), circulo);

    printCircular(circulo);
    //=======================================================//
    //Exemplo 2
    cout << isCircular(circulo->head) << endl;
    
    List* lista = new(List);
    insertEnd(lista, createNode(1));
    insertEnd(lista, createNode(2));
    insertEnd(lista, createNode(3));
    insertEnd(lista, createNode(4));
    insertEnd(lista, createNode(5));

    cout << isCircular(lista->head) << endl;
    //=======================================================//
    //Exemplo 3

    printList(lista);
    lista->head = listRotation(lista->head, 2);
    printList(lista);

    //=======================================================//
    //Exemplo 4

    Josefo_Solver(42, 7);

    return 0;
}

