/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesPila.cpp
 * Autor: Jared Dalmiro Chávez Pozo
 * Codigo: 20213283
 * Created on 26 de mayo de 2024, 19:03
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Pila.h"
#include "FuncionesLista.h"
#include "FuncionesPila.h"
#include "NodoArbol.h"
using namespace std;

void construir(struct Pila & pila){
    construir(pila.lista);
}

/*Determina si la pila está vacía*/
bool esPilaVacia(const struct Pila & pila){
    return esListaVacia(pila.lista);
}

/* push, añade un elemento a la parte superior de la pila */
void apilar(struct Pila & pila, struct ArbolBinario elemento){
    insertarAlInicio(pila.lista, elemento);
}

/* pop, elimina un elemento de la parte superior de la pila*/
struct ArbolBinario desapilar(struct Pila & pila){
    
    if (esPilaVacia(pila)){
        cout<<"La pila está vacía, por lo tanto no se puede desapilar"<<endl;
    }	
    else{
        struct ArbolBinario elemento = cima(pila);
        eliminaCabeza(pila.lista);
        return elemento;
    }
}

struct ArbolBinario cima(const struct Pila & pila){
    
    if (esPilaVacia(pila)){
	cout<<"La pila está vacía por lo tanto no posee cima"<<endl;
    }		
    return retornaCabeza(pila.lista);
}

