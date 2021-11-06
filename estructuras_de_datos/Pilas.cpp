#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};

// Prototipos:
void printPila(Node *&);
void agregarPila(Node *&, int);

// Implementacion:

void agregarPila(Node *&pila, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = pila;

    pila = newNode;
}

// Método Main:
int main(int argc, char const *argv[])
{
    Node *pila = NULL;
    
    agregarPila(pila, 23);
    agregarPila(pila, 42);
    agregarPila(pila, 12);

    return 0;
}
