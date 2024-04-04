/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.cpp
 * Autor: Jared Dalmiro Chávez Pozo
 * Codigo: 20213283
 * Created on 4 de abril de 2024, 8:36
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "Funciones.h"

// Definición de una matriz de movimientos posibles
int movimientos[8][2];

// Definición de constantes para el tamaño máximo del tablero
#define MAX_COLUMNAS 5
#define MAX_FILAS 4

// Función para inicializar la matriz de movimientos posibles
void inicializarMovimientos() {
    movimientos[0][0] = -1; movimientos[0][1] = 0;
    movimientos[1][0] = -1; movimientos[1][1] = 1;
    movimientos[2][0] = 0;  movimientos[2][1] = 1;
    movimientos[3][0] = 1;  movimientos[3][1] = 1 ;
    movimientos[4][0] = 1;  movimientos[4][1] = 0;
    movimientos[5][0] = 1;  movimientos[5][1] = -1;
    movimientos[6][0] = 0;  movimientos[6][1] = -1;
    movimientos[7][0] = -1; movimientos[7][1] = -1;
}

// Función para buscar una palabra en el tablero
int buscarPalabra(char tablero[][MAX_COLUMNAS], char palabra[], int fila,
        int columna, int longitud) {
    int nuevaFila, nuevaColumna, j;
    // Verificar si la primera letra de la palabra coincide con la letra en la posición (fila, columna) del tablero
    if (tablero[fila][columna] != palabra[0]) return 0;
    
    // Iterar sobre todas las direcciones posibles
    for (int i = 0; i < 8; i++) {
        nuevaFila = fila + movimientos[i][0];
        nuevaColumna = columna + movimientos[i][1];
        // Verificar si la palabra se puede formar en esta dirección
        for (j = 1; j < longitud; j++) {
            // Verificar si estamos dentro de los límites del tablero
            if (nuevaColumna < 0 || nuevaFila < 0 || nuevaColumna >= MAX_COLUMNAS || nuevaFila >= MAX_FILAS)
                break;
            // Verificar si la letra en la posición actual coincide con la letra correspondiente de la palabra
            if (tablero[nuevaFila][nuevaColumna] != palabra[j]) break;
            // Mover a la siguiente posición en la dirección actual
            nuevaFila += movimientos[i][0];
            nuevaColumna += movimientos[i][1];
        }
        // Si la longitud de la palabra coincide, se encontró la palabra en esta dirección
        if (j == longitud) return 1;
    }
    return 0;
}

// Función para buscar la palabra en todas las posiciones del tablero
void buscarPalabraEnTablero(char palabra[], char tablero[][MAX_COLUMNAS], int longitud) {
    // Iterar sobre todas las filas y columnas del tablero
    for (int fila = 0; fila < MAX_FILAS; fila++) {
        for (int columna = 0; columna < MAX_COLUMNAS; columna++) {
            // Si la palabra se encuentra en la posición (fila, columna), imprimir las coordenadas
            if (buscarPalabra(tablero, palabra, fila, columna, longitud)) {
                cout << "Encontré la palabra en: " << fila << " " << columna << endl;
            }
        }
    }
}
