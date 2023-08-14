#include <iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

// Funções auxiliares para listas duplamente encadeadas

// Definição de nó
struct Node
{
    string data;
    struct Node* ptrNext;
    struct Node* ptrPrev;
};

//Definição de lista
struct List
{
    struct Node* head;
    struct Node* tail;
};

// Função que cria um nó
struct Node* createNode(string str)
{
    // struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* newNode = new Node(); // Tive que trocar para new pois estava tendo problemas com malloc
    newNode->data = str;
    newNode->ptrNext = nullptr; 
    newNode->ptrPrev = nullptr; 

    return newNode;
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

    // free(ptrTemp); // Libera memória
    delete ptrTemp;
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

    // free(ptrTemp); // Liberando memória
    delete ptrTemp;
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

    // free(ptrDelete); // Libera memória
    delete ptrDelete;
}

// Função que remove um nó e o retorna
struct Node* popNode(struct List* list, struct Node* ptrDelete)
{   
    // Se algum dos dois for nulo, mensagem de erro!
    if (list->head == nullptr || ptrDelete == nullptr)
    {
        cout << "Não foi possível deletar :(" << endl;
        return nullptr;
    }
    
    if(ptrDelete != list->tail) ptrDelete->ptrNext->ptrPrev = ptrDelete->ptrPrev;
    else list->tail = ptrDelete->ptrPrev;

    if(ptrDelete != list->head) ptrDelete->ptrPrev->ptrNext = ptrDelete->ptrNext;
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

// Função que troca de lugar dois Nodes na estrutura de lista encadeada (a função está preparada para muitos casos, por isso é pesada e custosa)
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 1

// a)
bool is_valid(string word)
{
    bool cons;

    if (word.size() < 2 || word.size() > 8) return false;

    for (int i = 0; i < word.size(); i++)
    {
        switch (word[i])
        {
            case 'B':
                if (cons == true) return false;
                cons = true;
                break;
            case 'J':
                if (cons == true) return false;
                cons = true;
                break;
            case 'R':
                if (cons == true) return false;
                cons = true;
                break;
            case 'S':
                if (cons == true) return false;
                cons = true;
                break;
            case 'T':
                if (cons == true) return false;
                cons = true;
                break;
            case 'A':
                if (cons == false) return false;
                cons = false;
                break;
            case 'U':
                if (cons == false) return false;
                cons = false;
                break;
            case 'Y':
                if (cons == false) return false;
                cons = false;
                break;
            default:
                return false;
        }
    }
    return true;
}

// b)
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

// insertEnd que verifica a validade de uma palavra antes de inserí-la no final
void insert(string word, struct List* list)
{
    if (not is_valid(word))
    {
        cout << "Ei! Essa palavra não está escrita na bíblia (não respeita a linguagem definida) >:(" << endl;
        return;
    }

    struct Node* newNode = createNode(word);
    insertEnd(list, newNode);
}

// c)
bool find(string word, struct List* list)
{
    struct Node* temp = list->head;
    while (temp != nullptr)
    {
        if (temp->data == word) return true;
        temp = temp->ptrNext;
    }
    return false;
}

// d)
void delete_all(string word, struct List* list)
{
    struct Node* temp = list->head;
    while (temp != nullptr)
    {
        if (temp->data == word)
        {
            temp = temp->ptrPrev;
            deleteNode(list, temp->ptrNext);
        }
        temp = temp->ptrNext;
    }
}

// e)
void print(struct List* list)
{
    if (list->head == nullptr) 
    {
        cout << "Lista vazia." << endl;
        return;
    }

    if (list->head->ptrPrev != nullptr || list->tail->ptrNext != nullptr)
    {
        cout << "Cuidado! A lista passada é inválida." << endl;
        return;
    }

    // Se chegamos aqui, a lista é válida e não vazia
    struct Node* printer = list->head;

    cout << "Palavras: ";
    while (printer != nullptr)
    {
        cout << printer->data << " ";
        printer = printer->ptrNext;
    }
    cout << endl;
}

// f)
// Função auxiliar da leq
int transform(char letra)
{
    switch (letra)
        {
            case 'T':
                return 1;
            case 'R':
                return 2;
            case 'S':
                return 3;
            case 'J':
                return 4;
            case 'B':
                return 5;
            case 'Y':
                return 6;
            case 'U':
                return 7;
            case 'A':
                return 8;
            default:
                return -1;
        }
}

// Equivalente a um operador (Lesser or Equal to) de ordem alfabética para palavras do alfabeto estranho
bool leq(string word1, string word2)
{
    if (word1 == word2) return true;

    // Iteramos sob as letras, até o tamanho da menor string
    int n;
    if (word1.size() > word2.size()) n = word2.size();
    else n = word1.size();

    for (int i=0; i<n; i++)
    {
        int x = transform(word1[i]);
        int y = transform(word2[i]);

        if (x<y) return true;
        else if (x>y) return false;
    }

    // Se o código chegar aqui, significa que já terminou uma das palavras mas ainda não se decidiu, então vamos tratar a menor palavra como a antecessora alfabeticamente
    if (word1.size() < word2.size()) return true;
    return false;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 2

// Merge Sort recursiva para listas duplamente encadeadas com base na ordem alfabética da lista 5
void mergeSort(struct List* original)
{
    // Primeiro pegamos o tamanho da lista original
    int tamanho = getLenght(original);

    // Criamos duas sublistas, uma que vai do início da "original" até a metade, e outra que vai da metade até o fim
    struct List* left = (struct List*) malloc(sizeof(struct List));
    struct List* right = (struct List*) malloc(sizeof(struct List));

    left->head = original->head;
    left->tail = left->head;

    // Encontramos o meio da lista original, que marca a tail da lista à esquerda, e a head da lista à direita (em caso ímpar, usamos a metade truncada) 
    int i = 0;
    while (i < (tamanho-1)/2)
    {
        left->tail = left->tail->ptrNext;
        i++;
    }

    right->head = left->tail->ptrNext;
    left->tail->ptrNext = nullptr;

    right->head->ptrPrev = nullptr;
    right->tail = original->tail;
    
    // PONTO DE RECURSÃO
    // Aqui, caso uma das sublistas tenha mais de um elemento, chamamos a função recursivamente para reduzí-la ainda mais
    // Nosso objetivo é que o caso base da recursão seja as sublistas "left" e "right" tendo apenas um elemento cada
    // Perceba que a mergeSort não retorna nada, tudo que ela faz é organizar left e right individualmente in-place através do mergeSort
    if (getLenght(left) >= 2) mergeSort(left);
    if (getLenght(right) >= 2) mergeSort(right);
    // A partir daqui, devemos tomar cuidado com a recursão, pois o código trata tanto listas grandes quando listas de um elemento

    // Nesse ponto, com nossas sublistas prontas e ordenadas, podemos descartar os ponteiros da lista original
    original->head = nullptr;
    original->tail = nullptr;

    struct Node* temp;
    while (left->tail != nullptr && right->head != nullptr) // Enquanto pelo menos uma das sublistas não estiver vazia
    {
        // Retiramos a head da sublista que, dentre as duas, for a "menor" alfabeticamente
        if (leq(left->head->data, right->head->data)) temp = popNode(left, left->head);
        else temp = popNode(right, right->head);

        // Por fim, inserimos o elemento na lista original. Perceba que estamos "reconstruindo" a lista original do zero a partir das sublistas
        insertEnd(original, temp);
    }

    // Quando o while acima quebrar, uma das listas estará vazia, então basta "conectar" o resto da outra ao final da lista original
    if (left->head != nullptr) temp = left->head;
    else temp = right->head;

    original->tail->ptrNext = temp;
    temp->ptrPrev = original->tail;
    while (original->tail->ptrNext != nullptr) original->tail = original->tail->ptrNext;

    // Por fim, perceba que ao longo da recursão alocamos memória para inúmeras sublistas left e right, portanto é uma boa prática,
    // ao final de cada instância da recursão, liberar a memória dessas sublistas
    free(left);
    free(right);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 3

// Função que procura a palavra mais recorrente numa lista, e pune todas as ocorrências (em caso de empate, pune a que foi vigiada primeiro)
void vigiarEPunir(struct List* list)
{
    // Criarei uma lista com as palavras da lista original, mas essa lista só terá ocorrências únicas de cada palavra
    struct List* uniqueWords = (struct List*) malloc(sizeof(struct List));
    uniqueWords->head = nullptr;
    uniqueWords->tail = nullptr;

    // O número x na i-ésima posição do array wordCounter equivale ao número x de vezes que a i-ésima palavra da lista uniqueWords apareceu na lista original  
    int wordCounter[getLenght(list)];

    // Variáveis auxiliares
    struct Node* temp;
    int position;

    // foucault é o ponteiro que irá VIGIAR e PUNIR suas vítimas
    struct Node* foucault = list->head;

    // Primeiro, devemos VIGIAR
    while (foucault != nullptr) // Iterando sobre cada palavra na lista original
    {
        // Posicionamos nossos auxiliares
        temp = uniqueWords->head;
        position = 0;

        if (find(foucault->data, uniqueWords)) // Se uma palavra JÁ FOI VISTA ANTES
        {
            while (temp->data != foucault->data) // Procuramos essa palavra na uniqueWords, para saber sua posição equivalente em wordCounter
            {
                position++;
                temp = temp->ptrNext;
            }

            wordCounter[position]++; // Aumentamos em 1 o número de ocorrências da palavra vista
        }
        else // Se uma palavra NUNCA FOI VISTA ANTES, adicionamos ela na uniqueWords, e somamos sua primeira aparição na wordCounter
        {
            wordCounter[getLenght(uniqueWords)] = 1;     
            insert(foucault->data, uniqueWords);
        }
        foucault = foucault->ptrNext; // E com isso nosso foucault continua em frente para contabilizar suas potenciais vítimas
    }

    // Nesse ponto, temos uma lista completa de palavras e suas ocorrências, portanto vamos procurar a que mais se repete
    int pos_mais_repetida = 0;
    for (int i = 0; i < getLenght(uniqueWords); i++)
    {
        if (wordCounter[i] > wordCounter[pos_mais_repetida]) pos_mais_repetida = i;
    }

    // Perceba que se houver empate, eliminaremos a primeira que for observada
    struct Node* palavra_mais_repetida = uniqueWords->head;
    for (int pos = 0; pos < pos_mais_repetida; pos++) palavra_mais_repetida = palavra_mais_repetida->ptrNext;

    // Agora que já vigiamos, podemos começar A PUNIR MUAHAHAHHA
    delete_all(palavra_mais_repetida->data, list);

    // Por fim, perceba que alocamos memória para uma lista que não nos tem mais serventia... LOGO ELA TAMBÉM SERÁ PUNIDA (liberar memória)
    while (uniqueWords->head != nullptr) deleteLast(uniqueWords);
    free(uniqueWords);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Questão 4

// Bubble Sort adaptada para listas com palavras 
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

        while (ptrStart != ptrEnd && ptrStart->ptrPrev != ptrEnd)
        {
            if (not leq(ptrStart->data, ptrStart->ptrNext->data)) 
            {
                swapNodes(list, ptrStart, ptrStart->ptrNext);
                bUnordered = true;
            }
            else ptrStart = ptrStart->ptrNext;
        }

        // Ao fim de um loop externo, se a lista não tinha nada fora de ordem, saímos do loop
        if (bUnordered == false) break;

        // Se não quebramos o loop, otimizamos o loop interno reduzindo o fim do loop, e preparamos o próximo
        if (ptrStart != list->tail) ptrEnd = ptrStart;
        ptrStart = list->head;
    }
}

// Gera uma palavra aleatória dentro das regras da lista 5
string randomWord()
{
    char vogals[] = {'A', 'U', 'Y'};
    char consonants[] = {'B', 'J', 'S', 'T', 'R'};
    
    string strResult = "";

    int iLenght = rand()%7; // Tamanho da palavra resultante (num aleatório entre 2 e 8)
    iLenght += 2;

    int even = rand()%2; // Começa com consoante ou vogal?
    for (int i = 0; i < iLenght; i++)
    {
        if (even%2 == 0)
        {
            int letra = rand()%3;
            strResult.append(1u, vogals[letra]);
        }
        else
        {
            int letra = rand()%5;
            strResult.append(1u, consonants[letra]);
        }
        
        even++;
    }
    return strResult;
}

// Gera uma lista com iLenght palavras aleatoriamente geradas
struct List* randomList(int iLenght)
{
    struct List* newList = (struct List*) malloc(sizeof(struct List));
    newList->head = nullptr;
    newList->tail = nullptr;

    for (int i = 0; i < iLenght; i++)
    {
        string newWord = randomWord();
        insert(newWord, newList);
    }

    return newList;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main () 
{
    struct List* listinha = (struct List*) malloc(sizeof(struct List));
    listinha->head = nullptr;
    listinha->tail = nullptr;

    //=============================================//
    // Exemplo 1a
    string palavra1 = "ABUJY";
    string palavra2 = "AAAAAA";
    cout << "Palavra válida: " << is_valid(palavra1) << endl;
    cout << "Palavra inválida: " << is_valid(palavra2) << endl;
    
    // Exemplo 1b
    insert("ABUJY", listinha);
    insert("TURA", listinha);
    insert("SURATURY", listinha);
    insert("RASURA", listinha);
    insert("JURURU", listinha);
    insert("JURURU", listinha);
    insert("JURURU", listinha);
    insert("BAJUTY", listinha);
    insert("YTU", listinha);
    insert("YTU", listinha);
    insert("URARA", listinha);
    insert("URARA", listinha);
    insert("URARA", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("RASUR", listinha);
    insert("BAJAJA", listinha);
    insert("SURATUR", listinha);
    insert("George", listinha);

    // Exemplo 1c
    cout << "Palavra que está na lista: " << find("TURA", listinha) << endl;
    cout << "Palavra que não está na lista: " << find("George", listinha) << endl;

    // Exemplos 1d e 1e
    print(listinha);
    delete_all("SURATUR", listinha);
    print(listinha);

    // Exemplo 1f
    cout << "TURA vem antes de SURATUR? " << leq("TURA", "SURATUR") << endl;
    cout << "ABUJY vem antes de ABURA? " << leq("ABUJY", "ABURA") << endl;
    cout << "================================================\n" << endl;

    //=============================================//
    // Exemplo Questão 2
    mergeSort(listinha);
    bubbleSort(listinha);
    cout << "Lista organizada:" << endl;
    print(listinha);
    cout << "================================================\n" << endl;

    //=============================================//
    // Exemplo Questão 3
    cout << "Lista após a punição da mais repetida:"<<endl;
    vigiarEPunir(listinha);
    print(listinha);
    cout << "Lista após a segunda punição da mais repetida:"<<endl;
    vigiarEPunir(listinha);
    print(listinha);
    cout << "================================================\n" << endl;

    //=============================================//
    // Exemplo Questão 4
    
    cout << "Teste de 100 elementos:" << endl;

    struct List* lista1 = randomList(100);
    struct List* lista2 = randomList(100);

    auto timeStart1 = high_resolution_clock::now();
    bubbleSort(lista1);
    auto timeStop1 = high_resolution_clock::now();
    
    auto timeStart2 = high_resolution_clock::now();
    mergeSort(lista2);
    auto timeStop2 = high_resolution_clock::now();

    auto timeDuration1 = duration_cast<nanoseconds>(timeStop1 - timeStart1);
    auto timeDuration2 = duration_cast<nanoseconds>(timeStop2 - timeStart2);

    cout << "Tempo de execução do bubbleSort = " << timeDuration1.count() << " nanossegundos." << endl;
    cout << "Tempo de execução do mergeSort = " << timeDuration2.count() << " nanossegundos.\n" << endl;

    ///////////////////////

    cout << "Teste de 1000 elementos:" << endl;

    struct List* lista3 = randomList(1000);
    struct List* lista4 = randomList(1000);

    auto timeStart3 = high_resolution_clock::now();
    bubbleSort(lista3);
    auto timeStop3 = high_resolution_clock::now();
    
    auto timeStart4 = high_resolution_clock::now();
    mergeSort(lista4);
    auto timeStop4 = high_resolution_clock::now();

    auto timeDuration3 = duration_cast<nanoseconds>(timeStop3 - timeStart3);
    auto timeDuration4 = duration_cast<nanoseconds>(timeStop4 - timeStart4);

    cout << "Tempo de execução do bubbleSort = " << timeDuration3.count() << " nanossegundos." << endl;
    cout << "Tempo de execução do mergeSort = " << timeDuration4.count() << " nanossegundos.\n" << endl;

    ///////////////////////

    cout << "Teste de 10000 elementos:" << endl;

    struct List* lista5 = randomList(10000);
    struct List* lista6 = randomList(10000);

    auto timeStart5 = high_resolution_clock::now();
    bubbleSort(lista5);
    auto timeStop5 = high_resolution_clock::now();
    
    auto timeStart6 = high_resolution_clock::now();
    mergeSort(lista6);
    auto timeStop6 = high_resolution_clock::now();

    auto timeDuration5 = duration_cast<milliseconds>(timeStop5 - timeStart5);
    auto timeDuration6 = duration_cast<milliseconds>(timeStop6 - timeStart6);

    cout << "Tempo de execução do bubbleSort = " << timeDuration5.count() << " milissegundos." << endl;
    cout << "Tempo de execução do mergeSort = " << timeDuration6.count() << " milissegundos.\n" << endl;

    return 0;
}