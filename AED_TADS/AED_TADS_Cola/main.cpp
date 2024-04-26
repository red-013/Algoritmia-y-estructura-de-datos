#include <iostream>
#include "cola.h"

using namespace std;

int main()
{
    Cola cola;
    Elemento elemento;
    
    construirCola(cola);
    mostrarCola(cola);
    
    encolar(cola, 28);
    mostrarCola(cola);
    
    encolar(cola, 71);
    mostrarCola(cola);
    
    encolar(cola, 46);
    mostrarCola(cola);
    
    encolar(cola, 84);
    mostrarCola(cola);
    
    while (!esColaVacia(cola))
    {
        elemento = desencolar(cola);
        cout << "Elemento desencolado: " << elemento << endl;
        mostrarCola(cola);
    }
    // destruirCola(cola);
    return 0;
}

