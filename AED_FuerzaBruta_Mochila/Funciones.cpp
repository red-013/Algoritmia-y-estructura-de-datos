/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Autor: Jared Dalmiro Chávez Pozo
 * Codigo: 20213283
 * Created on 3 de abril de 2024, 18:31
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

#include "Funciones.h"

// Función para convertir un número decimal en binario y cargarlo en un arreglo de cromosomas
void cargarCromosomas(int numero, int cantidadGenes, int* cromosomas) {
    int residuo;
    
    // Inicializar el arreglo de cromosomas con ceros
    for(int i = 0; i < cantidadGenes; i++) {
        cromosomas[i] = 0;
    }
    
    int indice = 0;
    while(numero > 0) {
        residuo = numero % 2;
        numero = numero / 2;
        cromosomas[indice] = residuo;
        indice++;
    }
}
