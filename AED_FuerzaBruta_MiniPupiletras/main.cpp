
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#include "Funciones.h"

// Definición de constantes para el tamaño máximo del tablero
#define MAX_COLUMNAS 5
#define MAX_FILAS 4

int main(int argc, char** argv) {
    // Tablero de letras
    char tablero[MAX_FILAS][MAX_COLUMNAS] = {
        {'G', 'A', 'T', 'O', 'G'},
        {'O', 'G', 'O', 'A', 'O'},
        {'L', 'B', 'O', 'C', 'L'},
        {'R', 'A', 'T', 'L', 'N'}
    };
    // Longitud de la palabra a buscar
    int longitudPalabra = 3;
    // Palabra a buscar en el tablero
    char palabra[] = {'G', 'O', 'L'};
    
    // Inicializar los movimientos posibles
    inicializarMovimientos();
    // Buscar la palabra en el tablero
    buscarPalabraEnTablero(palabra, tablero, longitudPalabra);
    
    return 0;
}
