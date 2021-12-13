#include "iostream"
#include <stdio.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};

typedef struct Node *List;


void insertInFirstPosition(List &list, int data)
{
    List q;
    q = new(struct Node);
    q->data = data;
    q->next = list;

    list = q;
}

void printList(Node *list)
{
    Node *n = list;

    while (n != NULL)
    {
        // printf(n->data + ' \n');
        cout << n->data << "\n" << endl;
    }
}

int length(Node *list) 
{
    int cont = 0;
    // variable auxiliar:
    // p es un Puntero.
    Node *p = list;

    while (p != NULL) 
    {
        cont++;
        *p = *p->next;
    }

    return cont;
}

int main()
{
    List list = NULL;
    insertInFirstPosition(list, 3);
    // printList(list);
    insertInFirstPosition(list, 2);
    cout << "Tamaño es " << length(list) << endl;
    return 0;
}
