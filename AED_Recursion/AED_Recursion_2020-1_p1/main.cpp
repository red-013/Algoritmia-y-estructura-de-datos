#include <iostream>
using namespace std;

// Tamaño máximo de la matriz
const int MAX_FILAS = 100;
const int MAX_COLUMNAS = 100;

// Función recursiva para recorrer los montículos
int recorrerMonticulos(int matriz[MAX_FILAS][MAX_COLUMNAS], int filas, int columnas, int inicioFila, int inicioColumna) {
    // Si la matriz está vacía o el inicio está fuera de los límites, regresar 0
    if (filas <= 0 || columnas <= 0 || inicioFila >= filas || inicioColumna >= columnas)
        return 0;

    // Recorrer el borde superior de la matriz
    for (int j = inicioColumna; j < columnas; ++j)
        cout << matriz[inicioFila][j] << " ";
    
    // Recorrer el borde derecho de la matriz
    for (int i = inicioFila + 1; i < filas; ++i)
        cout << matriz[i][columnas - 1] << " ";

    // Recorrer el borde inferior de la matriz si es necesario
    if ((filas - inicioFila) > 1) {
        for (int j = columnas - 2; j >= inicioColumna; --j)
            cout << matriz[filas - 1][j] << " ";
    }

    // Recorrer el borde izquierdo de la matriz si es necesario
    if ((columnas - inicioColumna) > 1) {
        for (int i = filas - 2; i > inicioFila; --i)
            cout << matriz[i][inicioColumna] << " ";
    }

    // Llamar recursivamente para el subproblema interno
    return 1 + recorrerMonticulos(matriz, filas - 1, columnas - 1, inicioFila + 1, inicioColumna + 1);
}

int main() {
    int filas, columnas;

    // Ingreso de dimensiones de la matriz
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;

    // Declaración de la matriz
    int matriz[MAX_FILAS][MAX_COLUMNAS];

    // Ingreso de los códigos de los montículos
    cout << "Ingrese los códigos de los montículos:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Llamar a la función recursiva para recorrer los montículos
    int cantidadMonticulos = recorrerMonticulos(matriz, filas, columnas, 0, 0);

    // Imprimir la cantidad de montículos recorridos
    cout << "\nLa cantidad de montículos recorridos es: " << cantidadMonticulos << endl;

    return 0;
}
