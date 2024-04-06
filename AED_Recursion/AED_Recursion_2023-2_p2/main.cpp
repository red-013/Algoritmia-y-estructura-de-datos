#include <iostream>
#define nServers 7

using namespace std;

// Función para verificar si la fila y columna están vacías
bool verificarFilaColumnaVacias(int servers[][nServers], int indice, int limite) {
    // Verificar si la fila y la columna están vacías (contienen solo 0)
    for(int i = 0; i < limite; i++) {
        if(servers[i][indice] != 0) return false; // Si algún elemento de la columna no es 0, retornar falso
    }
    for(int i = 0; i < limite; i++) {
        if(servers[indice][i] != 0) return false; // Si algún elemento de la fila no es 0, retornar falso
    }
    return true; // Si ambas la fila y la columna están vacías, retornar verdadero
}

// Función recursiva para buscar a SKYNERD en la red
int buscarSKYNERD(int servers[][nServers], int N, int fila, int columna) {
    int ubicacion = -1; // Inicializar ubicación con un valor por defecto

    // Caso base: si mi fila es mayor o igual al número de servidores
    if(fila >= N) {
        return ubicacion;
    }

    // Si el servidor actual es 0, verificar si toda la fila y columna son 0
    if(servers[fila][columna] == 0) {
        bool filaColumnaVacias = verificarFilaColumnaVacias(servers, fila, N);
        if(filaColumnaVacias) {
            ubicacion = fila + 1; // Ubicación del servidor encontrado
        }
    }

    // Si no se encontró SKYNERD en la fila actual, buscar en la siguiente fila
    if(ubicacion == -1 && fila < N - 1) {
        ubicacion = buscarSKYNERD(servers, N, fila + 1, columna);
    }

    return ubicacion;
}

int main() {
    int ubicacion;
    int servers[nServers][nServers] = {
        {0, 10, 0, 30, 40, 50, 0},
        {10, 0, 0, 20, 30, 0, 0},
        {0, 0, 20, 0, 0, 0, 0},
        {30, 0, 0, 0, 0, 0, 0},
        {40, 0, 0, 0, 0, 0, 0},
        {50, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 40}
    };
    
    ubicacion = buscarSKYNERD(servers, nServers, 0, 0);
    if(ubicacion != -1) {
        cout << "SkyNerd ha sido detectado en el servidor: " << ubicacion << endl;
    } else {
        cout << "SKYNERD no está en la red" << endl;
    }
    return 0;
}
