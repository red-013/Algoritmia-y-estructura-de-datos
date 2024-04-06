/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funciones.h
 * Autor: Jared Dalmiro Chávez Pozo
 * Codigo: 20213283
 * Creado el 4 de abril de 2024, 8:37
 */


#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "Funciones.h"

// Definición de constantes para el tamaño máximo del tablero
#define MAX_COLUMNAS 5
#define MAX_FILAS 4

void inicializarMovimientos();
int buscarPalabra(char tablero[][MAX_COLUMNAS], char palabra[], int fila,
        int columna, int longitud);
void buscarPalabraEnTablero(char palabra[], char tablero[][MAX_COLUMNAS], int longitud);

#endif /* FUNCIONES_H */

