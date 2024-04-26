#ifndef PILA_H
#define PILA_H

#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodoP
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoP *sig;  // sig es la dirección del siguiente nodo
} NodoP;

typedef struct
{
    NodoP *cima; // cima almacena la dirección del primer nodo de la pila
    int longitud; // cantidad de nodos de la pila
} Pila;

void construirPila(Pila &pila);
bool esPilaVacia(Pila pila);
NodoP* crearNodoPila(Elemento e, NodoP *s);
void apilar(Pila &pila, Elemento e);
void mostrarPila(Pila pila);
Elemento desapilar(Pila &pila);
void destruirPila(Pila &pila);
Pila copiarPila(Pila &pila);

#endif /* PILA_H */


