#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    Pila pila1, pila2;
    Elemento x;
    
    construirPila(pila1);
    mostrarPila(pila1);
    
    apilar(pila1, 48);
    mostrarPila(pila1);
    
    apilar(pila1, 21);
    mostrarPila(pila1);
    
    apilar(pila1, 37);
    mostrarPila(pila1);
    
    apilar(pila1, 40);
    mostrarPila(pila1);
    
    /*while (!esPilaVacia(pila1))
    {
        x = desapilar(pila1);
        cout << "Dato desapilado: " << x << endl;
        mostrarPila(pila1);
    }
    // destruirPila(pila1);*/
    
    pila2 = copiarPila(pila1);
    cout << "Pila pila1" << endl;
    mostrarPila(pila1);
    
    cout << "Pila pila2" << endl;
    mostrarPila(pila2);
   
    return 0;
}
