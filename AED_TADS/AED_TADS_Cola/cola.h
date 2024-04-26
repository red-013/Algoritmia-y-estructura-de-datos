#ifndef COLA_H
#define COLA_H

#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodoC
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodoC *sig;  // sig es la dirección del siguiente nodo
} NodoC;

typedef struct
{
    NodoC *frente; // frente almacena la dirección del primer nodo de la cola
    NodoC *final; // final almacena la dirección del último nodo de la cola
    int longitud; // cantidad de nodos de la cola
} Cola;

void construirCola(Cola &cola);
bool esColaVacia(Cola cola);
int obtenerLongitud(Cola cola);
NodoC* crearNodoCola(Elemento elemento, NodoC *siguiente);
void encolar(Cola &cola, Elemento elemento);
void mostrarCola(Cola cola);
Elemento desencolar(Cola &cola);
void destruirCola(Cola &cola);

#endif /* COLA_H */
