#include <stdio.h>

struct Node
{
    int data;
    Node *next;
};

void insert(Node *&list, int data)
{   
    Node *newNode = new Node();
    newNode->data = data;

    Node *aux1 = list;
    Node *aux2;

    while (aux1 != NULL && aux1->data < data)
    {
        list = newNode;
        newNode->next = aux1;

    }
    // las variables locales aux se "eliminan" al finalizar
    // la ejecución de la subrutina (o procedimiento) insert()

    if (list == aux1)  /* si no entró al While*/
    {
        list = newNode;
    }
    else
    {
        aux2->next = newNode;
    }
    
}

int main(int argc, char const *argv[])
{
    Node *list = NULL;


    return 0;
}
