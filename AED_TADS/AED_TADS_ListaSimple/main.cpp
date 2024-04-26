#include <iostream>
#include "listaSimple.h"

using namespace std;

int main()
{
    Lista listaSimple;
    inicializarLista(listaSimple);
    mostrarLista(listaSimple);
    insertarAlInicio(listaSimple, 50);
    mostrarLista(listaSimple);
    insertarAlInicio(listaSimple, 87);
    mostrarLista(listaSimple);
    insertarAlInicio(listaSimple, 23);
    mostrarLista(listaSimple);
    cout << "La lista tiene " << obtenerLongitud(listaSimple) << " nodos" << endl;
    insertarAlFinal(listaSimple, 59);
    mostrarLista(listaSimple);
    insertarAlFinal(listaSimple, 104);
    mostrarLista(listaSimple);
    eliminarNodo(listaSimple, 49);
    mostrarLista(listaSimple);
    eliminarNodo(listaSimple, 50);
    mostrarLista(listaSimple);
    eliminarNodo(listaSimple, 23);
    mostrarLista(listaSimple);
    destruirLista(listaSimple);
    mostrarLista(listaSimple);
    return 0;
}
