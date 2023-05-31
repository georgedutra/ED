#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Código base:

// Definição de nó
struct Node
{
    int arrMatrix[100][100];
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

//Definição de lista
struct List
{
    struct Node* head;
    struct Node* tail;
};

void createMatrix(struct Node* ptrNode)
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 100; j++)
            {
                ptrNode -> arrMatrix[i][j] = rand()%10;  //Generate number between 0 to 9
            }
    }
}

// Função que cria um nó
struct Node* createNode()
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->ptrNext = nullptr; 
    newNode->ptrPrev = nullptr;

    createMatrix(newNode);

    return newNode;
}

// Função que insere um nó no início da estrutura lista
void insertFront(struct List* list, struct Node* newNode)
{
    // O primeiro nó sempre aponta para nullptr para a esquerda
    newNode->ptrPrev = nullptr;
    newNode->ptrNext = list->head;

    if (list->head == nullptr) list->tail = newNode; // Se não existia nada na lista, o novo Node é o primeiro e o último
    else list->head->ptrPrev = newNode; // Se existia algo, agora o segundo aponta para o novo primeiro 

    list->head = newNode; // Atualizando o head
}

// Função que insere um nó no final da estrutura lista
void insertEnd(struct List* list, struct Node* newNode)
{
    // O último nó sempre aponta para nullptr para a direita
    newNode->ptrNext = nullptr;
    newNode->ptrPrev = list->tail;

    if (list->head == nullptr) list->head = newNode;  // Se a lista está vazia, o último também é o primeiro
    else list->tail->ptrNext = newNode;

    list->tail = newNode; // Atualizando o tail
}

void displayList(struct List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    if (list->head->ptrPrev != nullptr)
    {
        cout << "Alerta! Ponteiro passado está no meio da lista" << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Node* printer = list->head;

    cout << "Payload: ";
    while (printer != nullptr)
    {
        for (int column = 0; column < 100; column++)
        {
            for (int line = 0; line < 100; line++)
            {
                cout << printer->arrMatrix[line][column] << " ";
            }
            cout << endl;
        }
        printer = printer->ptrNext;
    }
    cout << endl;
}

// Função que apaga o primeiro elemento da estrutura lista
void deleteFirst(struct List* list)
{
    if (list->head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = list->head; // É bom vigiar o cara que vamos apagar para liberar memória no final

    list->head = list->head->ptrNext; // Atualizamos a head
    if (list->head != nullptr)list->head->ptrPrev = nullptr; // Se a nova head não for vazia, atualiza o prev do primeiro nó
    else list->tail = nullptr; // Se for vazia, atualiza a tail também

    free(ptrTemp); // Libera memória
}

// Função que apaga o último elemento da estrutura lista
void deleteLast(struct List* list)
{
    if (list->head == nullptr)
    {
        cout << "Não é possível remover: lista vazia" << endl;
        return;
    }

    struct Node* ptrTemp = list->tail; // Vigiando para punir...

    if (list->tail->ptrPrev == nullptr) 
    {
        list->head = nullptr; // Se o removido era o único, head e tail viram nullptr
        list->tail = nullptr;
    }
    else 
    {
        list->tail = list->tail->ptrPrev; 
        list->tail->ptrNext = nullptr; // Se não, temos que atualizar o penúltimo
    }

    free(ptrTemp); // Liberando memória
}

// Função que recebe um nó de uma lista, e insere um novo logo após na estrutura
void insertAfter(struct Node* ptrLoc, struct Node* newNode)
{
    if (ptrLoc == nullptr)
    {
        cout << "Não foi possível realizar a inserção" << endl;
        return;
    } 
    // Arrumando o newNode
    newNode->ptrNext = ptrLoc->ptrNext;
    newNode->ptrPrev = ptrLoc;

    // Corrigindo o next do ptrLoc
    ptrLoc->ptrNext = newNode;

    // Se havia alguém na frente do ptrLoc, corrige o previous dele
    if (newNode->ptrNext != nullptr) newNode->ptrNext->ptrPrev = newNode;
}

// Função que deleta um nó específico da lista
void deleteNode(struct List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return;
    }

    // Se o deletado for o primeiro ou o último, é só usar as outras funções!
    if (list->head == ptrDelete) 
    {
        deleteFirst(list);
        return;
    }
    if (list->tail == ptrDelete) 
    {
        deleteLast(list);
        return;
    }
    
    // Se não for o último nem o primeiro, ele certamente está entre dois Nodes
    ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev; 
    ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;

    free(ptrDelete); // Libera memória
}

// Função que remove um nó e o mantém existindo
struct Node* popNode(struct List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return nullptr;
    }
    
    if(ptrDelete->ptrNext != nullptr) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else list->tail = ptrDelete->ptrPrev;

    if(ptrDelete->ptrPrev != nullptr) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
    else list->head = ptrDelete->ptrNext;

    return ptrDelete;
}

// Função para saber o tamanho de uma lista duplamente encadeada
int getLenght(struct List* list)
{
    int counter = 0;
    struct Node* temp = list->head;
    while (temp!=nullptr)
    {
        counter++;
        temp = temp->ptrNext;
    }
    return counter;
}

// Função que troca de lugar dois Nodes na estrutura de lista encadeada
void swapNodes(struct List* list, struct Node* node1, struct Node* node2)
{
    struct Node* temp; // Criando um ponteiro temporário para utilidade

    // Casos Especiais: 
    
    // Aqui criei variáveis que indicam se os nodes 1 e 2 possuem prev ou next.
    bool prev1 = true, prev2 = true, next1 = true, next2 = true;
    
    // Se não possuem, significa que são head ou tail da lista
    if (node1 == list->head) prev1 = false;
    if (node2 == list->head) prev2 = false;
    if (node1 == list->tail) next1 = false;
    if (node2 == list->tail) next2 = false;

    // Casos em que os Nodes são adjacentes:

    // Se o node2 vem logo antes do 1, basta trocar os nomes e os indicadores de head/tail, pois queremos que o 1 venha antes do 2
    if (node2->ptrNext == node1)
    {
        temp = node1;
        node1 = node2;
        node2 = temp;
        
        if (prev2==false) prev1 = false;
        prev2 = true;

        if (next1==false) next2 = false;
        next1 = true;
    }

    // Se agora o node1 vem logo antes do 2, fazemos o necessário para Nodes adjacentes:
    if (node1->ptrNext == node2)
    {
        if(prev1==true) node1->ptrPrev->ptrNext = node2;    
        else list->head = node2;

        if(next2==true) node2->ptrNext->ptrPrev = node1;
        else list->tail = node1;

        node1->ptrNext = node2->ptrNext;
        node2->ptrPrev = node1->ptrPrev;

        node1->ptrPrev = node2;
        node2->ptrNext = node1;
        return;
    }

    // Se não são adjacentes, não importa mais quem vem antes ou depois, e partimos para os casos em que os Nodes estão separados:

    // Primeiro alteramos os nós ao redor dos trocados, se eles existem
    if(prev1==true) node1->ptrPrev->ptrNext = node2;
    if(next1==true) node1->ptrNext->ptrPrev = node2;
    
    if(prev2==true) node2->ptrPrev->ptrNext = node1;
    if(next2==true) node2->ptrNext->ptrPrev = node1;

    // Também alteramos os ponteiros da nossa lista caso sejam head ou tail
    if(prev1==false) list->head = node2;
    if(prev2==false) list->head = node1;

    if(next1==false) list->tail = node2;
    if(next2==false) list->tail = node1;

    // Por fim, atualizamos os ponteiros dos Nodes alterados, com ajuda do temp auxiliar
    temp = node1->ptrNext;
    node1->ptrNext = node2->ptrNext;
    node2->ptrNext = temp;

    temp = node1->ptrPrev;
    node1->ptrPrev = node2->ptrPrev;
    node2->ptrPrev = temp;
}

/////////////////////////////////////////////////////////////////////////////////
// Sorting:

int diagSum(int matrix[100][100])
{
    int iSum = 0;
        for (int i = 0; i < 100; i++)
        {
            if (matrix[i][i] < 0) iSum -= matrix[i][i];
            else iSum += matrix[i][i];
        }

    return iSum;
}

void displaySum(struct List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia, tururuuu..." << endl;
        return;
    }

    if (list->head->ptrPrev != nullptr)
    {
        cout << "Alerta! Ponteiro passado está no meio da lista" << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Node* printer = list->head;

    cout << "Payload: ";
    while (printer != nullptr)
    {
        cout << diagSum(printer->arrMatrix) << " ";
        printer = printer->ptrNext;
    }
    cout << endl;
}

void bubbleSort(struct List* list)
{
    int iLenght = getLenght(list);
    bool bUnordered;

    struct Node* ptrStart = list->head;
    struct Node* ptrEnd = list->tail;

    for (int iOuterLoop = 0; iOuterLoop < iLenght-1; iOuterLoop++) 
    {
        // Em cada loop externo, partimos do pressuposto de que a lista estará organizada
        bUnordered = false;
        int iSum = diagSum(ptrStart->arrMatrix);

        while (ptrStart != ptrEnd && ptrStart->ptrPrev != ptrEnd)
        {
            int iSumNext = diagSum(ptrStart->ptrNext->arrMatrix);
            if(iSum > iSumNext) 
            {
                swapNodes(list, ptrStart, ptrStart->ptrNext);
                bUnordered = true;
            }

            else 
            {
                iSum = iSumNext;
                ptrStart = ptrStart->ptrNext;
            }
        }

        // Ao fim de um loop externo, se a lista não tinha nada fora de ordem, saímos do loop
        if (bUnordered == false) break;

        // Se não quebramos o loop, otimizamos o loop interno reduzindo o fim do loop, e preparamos o próximo
        if (ptrStart != list->tail) ptrEnd = ptrStart;
        ptrStart = list->head;
    }
}

void insertSort(struct List* list)
{

}

int main()
{
    struct List* lista = (struct List*) malloc(sizeof(struct List));

    for (int i=0; i<10; i++)
    {
        struct Node* nozin = createNode();
        insertEnd(lista, nozin);
    }

    cout << "Lista Desordenada:" << endl;
    displaySum(lista);

    // bubbleSort(lista);
    cout << "\nLista Ordenada:" << endl;
    displaySum(lista);


    return 0;
}