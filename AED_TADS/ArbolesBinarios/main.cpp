/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Pila.h"
#include "FuncionesLista.h"
#include "FuncionesPila.h"
#include "NodoArbol.h"
using namespace std;

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */

int main(int argc, char** argv) {

    struct ArbolBinario arbol;
    construir(arbol);
    
    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
    plantarArbolBinario(arbol, nullptr, '1', nullptr);
    imprimeRaiz(arbol); cout<<endl;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4, arbol5, arbol6;
    plantarArbolBinario(arbol1, nullptr, '2', nullptr);
    plantarArbolBinario(arbol2, nullptr, '3', nullptr);
    plantarArbolBinario(arbol3, arbol1, '4', arbol2);
   
    
    
    struct Pila pila1;
    construir(pila1);
    apilar(pila1, arbol1);
    apilar(pila1, arbol2);
    apilar(pila1, arbol3);
    
    struct ArbolBinario arbol7;
    
    arbol7 = desapilar(pila1);
    
    plantarArbolBinario(arbol, arbol7, '7' ,  arbol3);
    
    cout<<"Es árbol vacío: "<<esArbolVacio(arbol)<<endl;
    
    cout<<"Recorrer en pre orden: "<<endl;
    recorrerPreOrden(arbol); cout<<endl;
    cout<<"Recorrer en orden: "<<endl;
    recorrerEnOrden(arbol); cout<<endl;
    cout<<"Recorrer en post orden: "<<endl;
    recorrerPostOrden(arbol); cout<<endl;

    cout<<"ALTURA árbol: "<<altura(arbol)<<endl;
    cout<<"NúMERO DE HOJAS: "<<numeroHojas(arbol)<<endl;
    cout<<"NúMERO DE NODOS: "<<numeroNodos(arbol)<<endl;
    cout<<"ES EQUILIBRADO: "<<esEquilibrado(arbol)<<endl;
    
    
    
    return 0;
}

