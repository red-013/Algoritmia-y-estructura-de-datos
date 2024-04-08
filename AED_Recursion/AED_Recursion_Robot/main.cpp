#include <iostream>
#define M 3

using namespace std;

// Función recursiva para encontrar la suma máxima de valores en el tablero
int robot(int x, int y, int n, int m, int tablero[][M]) {
    // Variables para almacenar las sumas máximas hacia la derecha y hacia abajo
    int derecha = -999999; // Inicializamos con un valor muy bajo
    int abajo = -999999; // Inicializamos con un valor muy bajo
    
    // Caso base: si el robot está en la posición final, retornar el valor en esa posición
    if (x == n - 1 && y == m - 1)
        return tablero[x][y]; 

    // Verificar si el robot puede moverse hacia la derecha
    if (y + 1 < m)
        derecha = robot(x, y + 1, n, m, tablero);
    // Verificar si el robot puede moverse hacia abajo
    if (x + 1 < n)
        abajo = robot(x + 1, y, n, m, tablero);

    // Retornar la suma máxima de los valores hacia la derecha y hacia abajo, más el valor actual
    if (derecha > abajo)
        return derecha + tablero[x][y];
    return abajo + tablero[x][y];
}

int main(int argc, char** argv) {
    int n = 3, m = 3;
    int tablero[][M] = {{3, 8, 6},
                        {3, 10, 2},
                        {0, 9, 1}};
    
    // Llamar a la función robot con la posición inicial (0,0)
    cout << "El resultado es: " << robot(0, 0, n, m, tablero) << endl;

    return 0;
}


