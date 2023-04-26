// Tipos de estruturas de dados:

// Fila: Temos um primeiro elemento definido, e um último elemento definido
// Na fila, um elemento adicionado sempre entra no final, e um elemento removido sempre sai do início

// enQueue: adicione à fila / deQueue: remova da fila

// Pilha: Temos um ponteiro indicando a base da pilha (primeiro elemento) e um indicando o topo (último elemento)
// Na pilha, adicionamos e removemos o elemento sempre no final (topo) da fila


#include <iostream>

using namespace std;

struct Node
{
    int iData;
    struct Node* next;
};

struct Queue
{
    struct Node* front;
    struct Node* rear;
};

struct Queue* newQueue()
{
    struct Queue* temp = (struct Queue*) malloc(sizeof(struct Queue*));
    temp -> front = nullptr;
    temp -> rear = nullptr;

    return temp;
}

struct Node* newNode(int iValue)
{
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node*));
    temp -> iData = iValue;
    temp -> next = nullptr;

    return temp;
}

// Operadores ternários em uma linha, yay :D (Não fazer isso)
void firstElement(struct Queue* queue)
{//                                                           if          True          False          
    cout << "Primeiro da fila: " << ((queue->front != nullptr) ? (queue->front)->iData : -1) << endl;
}

void lastElement(struct Queue* queue)
{
    cout << "Último da fila5: " << ((queue->rear != nullptr) ? (queue->rear)->iData : -1) << endl;
}

void enQueue(struct Queue* queue, int iVal)
{
    struct Node* tempNode = newNode(iVal);

    if (queue->rear == nullptr) queue->front = tempNode;
    else queue->rear->next = tempNode;
     
    queue->rear = tempNode;
    return;
}

void deQueue(struct Queue* queue)
{
    if (queue->rear == nullptr) 
    {
        cout << "Fila Vazia" << endl;
        return;
    }
    else
    {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        if (queue->front == nullptr) queue->rear = nullptr; // Só garantindo caso aquele fosse o único elemento da queue

        cout << "deQueue: " << temp->iData << endl;
        free(temp); 
    }
     
    return;
}

// Dever de casa 2: Função de imprimir a queue.

int main ()
{
    struct Queue* queue = newQueue();
    firstElement(queue);
    lastElement(queue);
    cout << "===========================" << endl;
    
    enQueue(queue, 3);
    
    firstElement(queue);
    lastElement(queue);
    cout << "===========================" << endl;
    
    enQueue(queue, 7);
    enQueue(queue, 10);
    enQueue(queue, 42);
    enQueue(queue, 666);

    firstElement(queue);
    lastElement(queue);
    cout << "===========================" << endl;
    
    deQueue(queue);
    
    firstElement(queue);
    lastElement(queue);
    cout << "===========================" << endl;
    
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);
    deQueue(queue);

    firstElement(queue);
    lastElement(queue);
    cout << "===========================" << endl;
    
    return 0;
}

// Desafio: Torre de Hanói