#include "iostream"
// Importamos el archivo Lista.cpp, donde declaramos nuestras estructuras y los metodos.
#include "Lista.cpp"
using namespace std;

int prueba()
{
    // creamos nuestra lista:
    List myList = NULL;
    // agregamos elementos:
    insert(myList, 2);
    insert(myList, 4);
    insert(myList, 5);

    // con free() liberamos espacio de memoria, asñi como con new creamos espacio de memoria
    // free(puntero);

    print(myList);
    insertInFirstPosition(myList, 0);
    print(myList);
    return 0;
}

/**
 * Algoritmos a implementar:
 */

/* retorna true si la lista esta ordenada (menor a mayor) */
bool isOrder(List &list);

/* retorna la suma de todos los elementos de la lista */
int sum(List &list);

/* retorna el total de elementos pares en la lista */
int pars(List &list);

/* retorna el minimo */
int min(List &list);

/* retorna true si el ultimo elemento es igual a la suma de todos los anteriores */
bool sumToEnd(List &list);


// implementaciones:

int pars(List &list)
{
    Node *aux = list;
    int totalPars = 0;
    while (aux->next != NULL)
        if (aux->data % 2 == 0) totalPars++;

    return totalPars;
}


bool isOrder(List &list)
{
    Node *aux = list;

    while (aux->next != NULL && aux->data < aux->next->data) 
        aux = aux->next;

    return aux->next != NULL;
}


int min(List &list)
{
    // empezamos a recorrer desde el segundo elemento
    List p = list->next;
    int min = list->data;

    while (p != NULL) {
        if (p->data < min)
            min = p->data;
        p = p->next;
    }

    return min;
}


bool sumToEnd(List &list)
{
    List p = list;
    Node *end = NULL;
    int sum = 0;

    while (p != NULL) {
        if (p->next == NULL) 
            end = p;
        else
            sum += p->data;
        p = p->next;
    }
    
    return end->data == sum;

}

int main()
{
    List list = NULL;
    insert(list, 1);
    insert(list, 11);
    insert(list, 12);

    print(list);
    cout << min(list) << endl;
    return 0;
}
