#include "iostream"
#include <stdio.h>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// definimos un tipo para los punteros a Nodos 
// es decir, para nuestras Listas
typedef struct Node *List;

/**
 * Insertar elemento a la lista en la primera posición
 **/ 
void insertInFirstPosition(Node *&list, int data) {
    // creamos el nuevo nodo (para agregarlo a nuestra lista):
    Node *newNode = new Node();
    newNode->data = data;
    // Crear dos nodos auxiliares:
    Node *aux1 = list;
    // Insertamos:
    list = newNode;
    newNode->next = aux1;
}

/**
 * INSERTAR ELEMENTO AL FINAL DE LA LISTA
 **/
void insert(Node *&list, int data) {
    // creamos el nuevo nodo (para agregarlo a nuestra lista):
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    // Crear dos nodos auxiliares:
    Node *aux = list;
    // Insertamos:
    if (list == NULL) {
        list = newNode;
    } else {
        aux = list;
        while (aux->next != NULL)
            aux = aux->next;

        aux->next = newNode;
    }

}

int length(List &list) 
{
    int cont = 0;
    // variable auxiliar:
    // aux es un Puntero.
    Node *aux = list;

    while (aux != NULL) 
    {
        cont++;
        aux = aux->next;
    }

    return cont;
}

void print(List &list) {
    List p;
    p = list;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

}


int main() {
    List myList = NULL;
    insert(myList, 2);
    insert(myList, 5);
    insert(myList, 12);
    insert(myList, 16);
    insertInFirstPosition(myList, 0);
    print(myList);
    cout << "Tamaño es " << length(myList) << endl;
    return 0;
}