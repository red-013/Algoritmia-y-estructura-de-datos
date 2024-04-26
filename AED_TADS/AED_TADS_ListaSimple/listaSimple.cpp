#include "listaSimple.h"

// Inicializa la lista vacía
void inicializarLista(Lista &lista) {
    lista.cabeza = NULL;
    lista.longitud = 0;
}

// Retorna true si la lista está vacía, false en caso contrario
bool esListaVacia(Lista lista) {
    return lista.cabeza == NULL;
}

// Crea un nuevo nodo de la lista y retorna su dirección
Nodo* crearNodo(Elemento elemento, Nodo *siguiente) {
    Nodo *nuevoNodo;
    nuevoNodo = new Nodo;
    nuevoNodo->elem = elemento;
    nuevoNodo->sig = siguiente;
    return nuevoNodo;
}

// Retorna la longitud de la lista
int obtenerLongitud(Lista lista) {
    return lista.longitud;
}

// Inserta un nuevo nodo al inicio de la lista
void insertarAlInicio(Lista &lista, Elemento elemento) {
    Nodo *nuevoNodo;
    nuevoNodo = crearNodo(elemento, lista.cabeza);
    lista.cabeza = nuevoNodo;
    lista.longitud++;
}

// Muestra el contenido de los nodos de la lista
void mostrarLista(Lista lista) {
    Nodo *puntero;
    if (esListaVacia(lista))
        cout << "La lista está vacía" << endl;
    else {
        puntero = lista.cabeza;
        while (puntero != NULL) {
            cout << puntero->elem << " ";
            puntero = puntero->sig;
        }
        cout << endl;
    }
}

// Retorna la dirección del último nodo de la lista, si la lista está vacía retorna NULL
Nodo* ubicarUltimo(Lista lista) {
    Nodo *punteroUltimo;
    int i;
    if (esListaVacia(lista))
        return NULL;
    else {
        punteroUltimo = lista.cabeza;
        for (i = 1; i <= lista.longitud - 1; i++)
            punteroUltimo = punteroUltimo->sig;
        return punteroUltimo;
    }
}

// Inserta un nuevo nodo al final de la lista
void insertarAlFinal(Lista &lista, Elemento elemento) {
    Nodo *nuevoNodo, *punteroUltimo;
    nuevoNodo = crearNodo(elemento, NULL);
    if (esListaVacia(lista))
        lista.cabeza = nuevoNodo;
    else {
        punteroUltimo = ubicarUltimo(lista);
        punteroUltimo->sig = nuevoNodo;
    }
    lista.longitud++;
}

// Retorna la dirección del nodo que contiene el elemento, si no está en la lista retorna NULL
Nodo* ubicarElemento(Lista lista, Elemento elemento) {
    Nodo *puntero;
    if (esListaVacia(lista))
        return NULL;
    else {
        puntero = lista.cabeza;
        while (puntero != NULL) {
            if (puntero->elem == elemento)
                return puntero;
            puntero = puntero->sig;
        }
        return NULL;
    }
}

// Retorna la dirección del nodo anterior al nodo que contiene el elemento
Nodo* ubicarAnterior(Lista lista, Elemento elemento) {
    Nodo *puntero, *anterior;
    anterior = NULL;
    puntero = lista.cabeza;
    while (puntero != NULL) {
        if (puntero->elem == elemento)
            return anterior;
        anterior = puntero;
        puntero = puntero->sig;
    }
    return NULL;
}

// Elimina de la lista el nodo que contiene el elemento
void eliminarNodo(Lista &lista, Elemento elemento) {
    Nodo *puntero, *anterior;
    puntero = ubicarElemento(lista, elemento);
    if (puntero == NULL)
        cout << "No es posible eliminar un dato inexistente" << endl;
    else {
        anterior = ubicarAnterior(lista, elemento);
        if (anterior == NULL)
            lista.cabeza = puntero->sig;
        else
            anterior->sig = puntero->sig;
        lista.longitud--;
        delete puntero;
    }
}

// Elimina todos los nodos de la lista, dejándola vacía
void destruirLista(Lista &lista) {
    Nodo *puntero, *auxiliar;
    if (!esListaVacia(lista)) {
        puntero = lista.cabeza;
        while (puntero != NULL) {
            auxiliar = puntero->sig;
            delete puntero;
            puntero = auxiliar;
        }
        lista.cabeza = NULL;
        lista.longitud = 0;
    }
}
