#include "pila.h"

void construirPila(Pila &pila)
{
    pila.cima = NULL;
    pila.longitud = 0;
}

bool esPilaVacia(Pila pila)
{
    return pila.cima == NULL;
}

NodoP* crearNodoPila(Elemento elemento, NodoP *siguiente)
{
    NodoP *nuevoNodo;
    nuevoNodo = new NodoP;
    nuevoNodo->elem = elemento;
    nuevoNodo->sig = siguiente;
    return nuevoNodo;
}

void apilar(Pila &pila, Elemento elemento)
{
    NodoP *nuevoNodo;
    nuevoNodo = crearNodoPila(elemento, pila.cima);
    pila.cima = nuevoNodo;
    pila.longitud++;
}

void mostrarPila(Pila pila)
{
    NodoP *puntero;
    int i;
    if (esPilaVacia(pila))
        cout << "Pila vacía" << endl << endl;
    else
    {
        puntero = pila.cima;
        for(i = 1; i <= pila.longitud; i++)
        {
            cout << puntero->elem << endl;
            puntero = puntero->sig;
        }
        cout << endl;
    }
}

Elemento desapilar(Pila &pila)
{
    NodoP *puntero;
    Elemento elemento;
    puntero = pila.cima;
    elemento = puntero->elem;
    pila.cima = puntero->sig;
    pila.longitud--;
    delete puntero;
    return elemento;
}

void destruirPila(Pila &pila)
{
    NodoP *puntero, *auxiliar;
    if (!esPilaVacia(pila))
    {
        puntero = pila.cima;
        while (puntero != NULL)
        {
            auxiliar = puntero->sig;
            delete puntero;
            puntero = auxiliar;
        }
        pila.cima = NULL;
        pila.longitud = 0;
    }
}

Pila copiarPila(Pila &pila)
{
    Pila pilaCopiada, pilaAuxiliar;
    Elemento x;
    construirPila(pilaCopiada);
    construirPila(pilaAuxiliar);
    while (!esPilaVacia(pila))
    {
        x = desapilar(pila);
        apilar(pilaAuxiliar, x);
    }
    while (!esPilaVacia(pilaAuxiliar))
    {
        x = desapilar(pilaAuxiliar);
        apilar(pila, x);
        apilar(pilaCopiada, x);
    }
    return pilaCopiada;
}
