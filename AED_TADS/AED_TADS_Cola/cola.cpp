#include "cola.h"

void construirCola(Cola &cola)
{
    cola.frente = NULL;
    cola.final = NULL;
    cola.longitud = 0;
}

bool esColaVacia(Cola cola)
{
    return cola.frente == NULL;
}

int obtenerLongitud(Cola cola)
{
    return cola.longitud;
}

NodoC* crearNodoCola(Elemento elemento, NodoC *siguiente)
{
    NodoC *nuevoNodo;
    nuevoNodo = new NodoC;
    nuevoNodo->elem = elemento;
    nuevoNodo->sig = siguiente;
    return nuevoNodo;
}

void encolar(Cola &cola, Elemento elemento)
{
    NodoC *nuevoNodo, *ultimoNodo;
    nuevoNodo = crearNodoCola(elemento, NULL);
    if (esColaVacia(cola))
        cola.frente = nuevoNodo;
    else
    {
        ultimoNodo = cola.final;
        ultimoNodo->sig = nuevoNodo;
    }
    cola.final = nuevoNodo;
    cola.longitud++;
}

void mostrarCola(Cola cola)
{
    NodoC *puntero;
    if (esColaVacia(cola))
        cout << "La cola está vacía" << endl;
    else
    {
        puntero = cola.frente;
        while (puntero != NULL)
        {
            cout << puntero->elem << " ";
            puntero = puntero->sig;
        }
        cout << endl;
    }
}

Elemento desencolar(Cola &cola)
{
    Elemento x;
    NodoC *puntero;
    puntero = cola.frente;
    if (puntero->sig == NULL)
        cola.final = NULL;
    cola.frente = puntero->sig;
    x = puntero->elem;
    cola.longitud--;
    delete puntero;
    return x;
}

void destruirCola(Cola &cola)
{
    NodoC *puntero, *auxiliar;
    if (!esColaVacia(cola))
    {
        puntero = cola.frente;
        while (puntero != NULL)
        {
            auxiliar = puntero->sig;
            delete puntero;
            puntero = auxiliar;
        }
        cola.frente = NULL;
        cola.final = NULL;
        cola.longitud = 0;
    }
}
