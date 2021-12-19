#include "iostream"
#include <stdio.h>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

// definimos un tipo para los punteros a nodos (es decir, paras nuestras listas)
typedef struct Node *List;

// Insertar elemento a la lista (al final)
void insert(Node *&list, int data)
{
    // creamos un nodo auxiliar:
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    // Insertamos:
    // crear nodo aux:
    Node *aux = list;

    if (list == NULL) {
        list = newNode;
    } else {
        aux = list;
        // recorremos nuestra lista hasta llegar al final:
        while (aux->next != NULL) 
            aux = aux->next;

        aux->next = newNode;
    }
} 

// Insertar elemento a la lista (en la primera posición)
void insertInFirstPosition(Node *&list, int data)
{
    // crear nuestro nuevo nodo:
    Node *newNode = new Node();
    newNode->data = data;
    // crear un nodo auxiliar:
    Node *aux = list;
    // insertar:
    list = newNode;
    newNode->next = aux;
}


// devolver el tamaño de la lista
int lenght(List &list)
{
    int cont = 0;
    Node *aux = list;
    while (aux != NULL)
    {
        cont++; // incrementar en 1
        aux = aux->next;
    }

    return cont;
}


// imprimir por consola la lista:
void print(List &list)
{
    List p = list;
    while (p != NULL) {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;

}


/**
 * de aca para abajo
 * se debe hacer de cero en el video.-.
 */


// eliminamos un elemento especifico de la lista
void pop(List &list, int data)
{
    // si recibimos una lista en null no hacemos nada
    if (list == NULL)
        return;
    // puntero auxiliar:
    Node *aux = list;

    do
    {
        if (aux->data == data) {
            // si aux es el objetivo a eliminar:
            list = aux->next; 
            free(aux);
            break;
        } else if (aux->next != NULL && aux->next->data == data) {
            // el siguiente nodo es el que vamos a borrar:
            Node *next = aux->next;
            // enlazamos el nodo actual, al nodo que le sigue a next:
            aux->next = next->next;
            // liberamos el nodo next:
            free(next);
        }
    } while (aux->next != NULL);

}


// elimina el primer elemento de la lista
void shift(List &list)
{
    Node *aux = list;
    // hacemos que list apunte al elemento que apunta el primer elemento
    // es decir, al segundo elemento
    list = list->next;
    // liberamos el primer elemento:
    free(aux);
}


// eliminamos la lista completa (todos sus nodos)
void deleteList(List &list)
{
    Node *aux;

    while (list != NULL)
    {
        aux = list;
        list = list->next;
        // con free, borramos el espacio en memoria (así como con new lo creabamos)
        free(aux);
    }
}
// es importante usar free() para no dejar memoria colgada.-

// Búsqueda:

// retorna true si hay algun nodo con data = data, false caso contrario
bool find(List &list, int data)
{
    Node *aux = list;
    while (aux !=NULL && aux->next->data != data)
        aux = aux->next;
    
    return aux != NULL;

}
