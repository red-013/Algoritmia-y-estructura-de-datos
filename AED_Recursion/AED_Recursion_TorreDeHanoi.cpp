#include <iostream>

using namespace std;

const int FILAS = 5;
const int COLUMNAS = 8;

void moverTorre(int matriz[FILAS][COLUMNAS], int limite, int inicio, int origen, int destino, int pivote) {
    if (inicio < limite) {
        // Mover n-1 discos de origen a pivote, usando destino como pivote temporal
        moverTorre(matriz, limite, inicio + 1, origen, pivote, destino);

        // Mover el disco restante de origen a destino
        int disco = matriz[origen][inicio];
        matriz[origen][inicio] = 0; // Eliminamos el disco del origen
        matriz[destino][inicio] = disco; // Movemos el disco al destino

        // Mostrar la matriz después de cada movimiento
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLUMNAS; ++j) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        // Mover los n-1 discos restantes de pivote a destino, usando origen como pivote temporal
        moverTorre(matriz, limite, inicio + 1, pivote, destino, origen);
    }
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {100, 90, 80, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    cout << "Primera matriz:" << endl;
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    moverTorre(matriz, 3, 0, 0, 4, 1); // Mover de la fila 0 a la fila 4 usando la fila 1 como pivote

    return 0;
}
