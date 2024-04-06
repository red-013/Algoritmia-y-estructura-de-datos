#include <iostream>
using namespace std;

// Definición de la estructura para representar un robot
struct Robot {
    int poder; // Poder del robot
    char direccion; // Dirección de movimiento del robot
};

// Definición de la estructura para representar una ciudad
struct Ciudad {
    int matriz[10][10]; // Matriz que representa la ciudad
};

// Función para leer los poderes de los robots
void leerPoderes(Robot robots[], int n) {
    if(n == 1) {
        cout << "Poder del Robot Leonardo: ";
        cin >> robots[n-1].poder;
    }
    else if(n == 2) {
        cout << "Poder del Robot Rafael: ";
        cin >> robots[n-1].poder;
    }
    else if(n == 3) {
        cout << "Poder del Robot Donatello: ";
        cin >> robots[n-1].poder;
    }
    else if(n == 4) {
        cout << "Poder del Robot Ángel: ";
        cin >> robots[n-1].poder;
    }
    // Llamada recursiva para leer los poderes de los siguientes robots
    if(n < 4) {
        leerPoderes(robots, n+1);
    }
}

// Función para leer los movimientos de los robots
void leerMovimientos(Robot robots[], int n) {
    if(n == 1) {
        cout << "Movimiento del Robot Leonardo (D/A): ";
        cin >> robots[n-1].direccion;
    }
    else if(n == 2) {
        cout << "Movimiento del Robot Rafael (D/A): ";
        cin >> robots[n-1].direccion;
    }
    else if(n == 3) {
        cout << "Movimiento del Robot Donatello (D/A): ";
        cin >> robots[n-1].direccion;
    }
    else if(n == 4) {
        cout << "Movimiento del Robot Ángel (D/A): ";
        cin >> robots[n-1].direccion;
    }
    // Llamada recursiva para leer los movimientos de los siguientes robots
    if(n < 4) {
        leerMovimientos(robots, n+1);
    }
}

// Función para leer una fila de la matriz que representa la ciudad
void leerFilaCiudad(Ciudad &ciudad, int fila, int columna) {
    if(columna == 10) {
        if(fila < 9) {
            cout << endl;
            leerFilaCiudad(ciudad, fila + 1, 0);
        }
        return;
    }
    cin >> ciudad.matriz[fila][columna];
    cout << "    ";
    leerFilaCiudad(ciudad, fila, columna + 1);
}

// Función para leer la matriz que representa la ciudad
void leerCiudad(Ciudad &ciudad) {
    cout << "Ingrese la matriz que representa la ciudad (10x10):" << endl;
    leerFilaCiudad(ciudad, 0, 0);
}

// Función recursiva para vencer al enemigo SuperFly en la ciudad
bool vencerEnemigo(Robot robots[], Ciudad &ciudad, int fila, int columna, int actualRobot) {
    // Si todos los robots han sido destruidos, retornar falso
    if(actualRobot > 3) return false;
    
    if(robots[actualRobot].direccion == 'D') {
        if(columna <= 8) {
            if(ciudad.matriz[fila][columna + 1] == 50) {
                ciudad.matriz[fila][columna + 1] = 1;
                return true;
            }
            if(ciudad.matriz[fila][columna + 1] == 0) {
                ciudad.matriz[fila][columna + 1] = 1;
                return vencerEnemigo(robots, ciudad, fila, columna + 1, actualRobot);
            }
            else {
                if(robots[actualRobot].poder >= ciudad.matriz[fila][columna + 1]) {
                    robots[actualRobot].poder -= ciudad.matriz[fila][columna + 1];
                    ciudad.matriz[fila][columna + 1] = 1;
                    return vencerEnemigo(robots, ciudad, fila, columna + 1, actualRobot);
                }
                else {
                    return vencerEnemigo(robots, ciudad, fila, columna, actualRobot + 1);
                }
            }
        }
        else return false;
    }
    else if(robots[actualRobot].direccion == 'A') {
        if(fila <= 8) {
            if(ciudad.matriz[fila + 1][columna] == 50) {
                ciudad.matriz[fila][columna + 1] = 1;
                return true;
            }
            if(ciudad.matriz[fila + 1][columna] == 0) {
                ciudad.matriz[fila][columna + 1] = 1;
                return vencerEnemigo(robots, ciudad, fila + 1, columna, actualRobot);
            }
            else {
                if(robots[actualRobot].poder >= ciudad.matriz[fila + 1][columna]) {
                    robots[actualRobot].poder -= ciudad.matriz[fila + 1][columna];
                    ciudad.matriz[fila][columna + 1] = 1;
                    return vencerEnemigo(robots, ciudad, fila + 1, columna, actualRobot);
                }
                else {
                    return vencerEnemigo(robots, ciudad, fila, columna, actualRobot + 1);
                }
            }
        }
        else return false;
    }
    return false; // Retornar falso si no se cumplen las condiciones anteriores
}

int main() {
    Robot robots[4]; 
    Ciudad ciudad; 
    ciudad = {
        {{0, 0, 42, 0, 35, 0, 0, 10, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 27, 0, 0, 0, 0, 50, 0, 0, 0},
         {0, 0, 30, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 38, 0, 0, 42, 0, 0},
         {15, 0, 0, 50, 0, 0, 0, 50, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 50, 0, 37, 0, 0, 0},
         {0, 18, 0, 17, 0, 0, 0, 0, 50, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}}};
    leerPoderes(robots, 1);
    leerMovimientos(robots, 1);
    // Comentar esto si no se desea leer la ciudad
    // leerCiudad(ciudad);
    if(vencerEnemigo(robots, ciudad, 0, 0, 0)) {
        cout << "¡Las Tortuninjas lograron vencer a SuperFly!" << endl;
    }

    return 0;
}

