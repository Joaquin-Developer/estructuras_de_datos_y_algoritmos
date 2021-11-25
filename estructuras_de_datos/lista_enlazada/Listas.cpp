#include "iostream"
#include <stdio.h>
using namespace std;

struct Node 
{
    int data;
    Node *next;
};


void insertInFirstPosition(Node *list, int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = list;

    list = node;
}

void printList(Node *list)
{
    Node *n = list;

    while (n != NULL)
    {
        printf(n->data + " \n");
        // cout << n->data << endl;
    }
}

int main()
{
    Node *list;
    insertInFirstPosition(list, 3);
    printList(list);
    return 0;
}
