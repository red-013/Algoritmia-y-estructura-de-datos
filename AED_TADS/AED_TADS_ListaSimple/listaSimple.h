#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include<iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodo *sig;  // sig es la dirección del siguiente nodo
} Nodo;

typedef struct
{
    Nodo *cabeza; // cabeza almacena la direccion del primer nodo de la lista
    int longitud; // cantidad de nodos de la lista
} Lista;

void inicializarLista(Lista &lista);
// inicializa la lista vacía
bool esListaVacia(Lista lista);
// retorna true si la lista L es vacía, false en caso contrario
Nodo* crearNodo(Elemento elemento, Nodo *siguiente);
// crea un nuevo nodo de la lista y retorna su dirección
int obtenerLongitud(Lista lista);
// retorna la longitud de la lista
void insertarAlInicio(Lista &lista, Elemento elemento);
// inserta un nuevo nodo al comienzo de la lista
void mostrarLista(Lista lista);
// muestra el contenido de los nodos de la lista
Nodo* ubicarUltimo(Lista lista);
// retorna la dirección del último nodo de la lista, si lista es vacía retorna NULL
void insertarAlFinal(Lista &lista, Elemento elemento);
// inserta un nuevo nodo al final de la lista
Nodo* ubicarElemento(Lista lista, Elemento elemento);
// retorna la dirección del nodo que contiene el elemento e
// si la lista es vacía o si e no está en la lista, retorna NULL
Nodo* ubicarAnterior(Lista lista, Elemento elemento);
// retorna la dirección del nodo anterior al nodo que contiene el elemento e
void eliminarNodo(Lista &lista, Elemento elemento);
// elimina de la lista el nodo que contiene el elemento e
void destruirLista(Lista &lista);
// elimina todos los nodos de la lista, quedando esta vacía

#endif /* LISTASIMPLE_H */

