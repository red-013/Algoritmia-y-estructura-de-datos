#include <iostream>
#define FILAS 4
#define COLUMNAS 10

using namespace std;

// Función para verificar si la fórmula HSO se puede formar a partir de una posición dada
bool verificarHSO(char barco[][COLUMNAS], int fila, int columna) {
    // Verificar si la posición actual contiene un elemento al menos
    if (barco[fila][columna] != 'H' and barco[fila][columna] != 'S' and barco[fila][columna] != 'O') 
        return false;

    // Verificar las posiciones adyacentes para encontrar un 'S'
    // Arriba
    if(fila >= 2){
	    if(barco[fila][columna] == 'H'){
	    	if (barco[fila - 1][columna] == 'S'){
	    		if(barco[fila - 2][columna] == 'O') 
					return true;
			}
		    if (barco[fila - 1][columna] == 'O'){
	    		if(barco[fila - 2][columna] == 'S') 
					return true;
			}
		}
		if(barco[fila][columna] == 'S'){
	    	if (barco[fila - 1][columna] == 'H'){
	    		if(barco[fila - 2][columna] == 'O') 
					return true;
			}
		    if (barco[fila - 1][columna] == 'O'){
	    		if(barco[fila - 2][columna] == 'H') 
					return true;
			}
		}
		if(barco[fila][columna] == 'O'){
	    	if (barco[fila - 1][columna] == 'S'){
	    		if(barco[fila - 2][columna] == 'H') 
					return true;
			}
		    if (barco[fila - 1][columna] == 'H'){
	    		if(barco[fila - 2][columna] == 'S') 
					return true;
			}
		}
	}
	//Abajo
	if(fila < 2){
		if(barco[fila][columna] == 'H'){
	    	if (barco[fila + 1][columna] == 'S'){
	    		if(barco[fila + 2][columna] == 'O') 
					return true;
			}
		    if (barco[fila + 1][columna] == 'O'){
	    		if(barco[fila + 2][columna] == 'S') 
					return true;
			}
		}
		if(barco[fila][columna] == 'S'){
	    	if (barco[fila + 1][columna] == 'H'){
	    		if(barco[fila + 2][columna] == 'O') 
					return true;
			}
		    if (barco[fila + 1][columna] == 'O'){
	    		if(barco[fila + 2][columna] == 'H') 
					return true;
			}
		}
		if(barco[fila][columna] == 'O'){
	    	if (barco[fila + 1][columna] == 'S'){
	    		if(barco[fila + 2][columna] == 'H') 
					return true;
			}
		    if (barco[fila + 1][columna] == 'H'){
	    		if(barco[fila + 2][columna] == 'S') 
					return true;
			}
		}
	}
	//Derecha
	if(columna <= 7){
		if(barco[fila][columna] == 'H'){
	    	if (barco[fila][columna + 1] == 'S'){
	    		if(barco[fila][columna + 2] == 'O') 
					return true;
			}
		    if (barco[fila][columna + 1] == 'O'){
	    		if(barco[fila][columna + 2] == 'S') 
					return true;
			}
		}
		if(barco[fila][columna] == 'S'){
	    	if (barco[fila][columna + 1] == 'H'){
	    		if(barco[fila][columna + 2] == 'O') 
					return true;
			}
		    if (barco[fila][columna + 1] == 'O'){
	    		if(barco[fila][columna + 2] == 'H') 
					return true;
			}
		}
		if(barco[fila][columna] == 'O'){
	    	if (barco[fila][columna + 1] == 'S'){
	    		if(barco[fila][columna + 2] == 'H') 
					return true;
			}
		    if (barco[fila][columna + 1] == 'H'){
	    		if(barco[fila][columna + 2] == 'S') 
					return true;
			}
		}
	}
	//Izquierda
	if(columna >= 2){
		if(barco[fila][columna] == 'H'){
	    	if (barco[fila][columna - 1] == 'S'){
	    		if(barco[fila][columna - 2] == 'O') 
					return true;
			}
		    if (barco[fila][columna - 1] == 'O'){
	    		if(barco[fila][columna - 2] == 'S') 
					return true;
			}
		}
		if(barco[fila][columna] == 'S'){
	    	if (barco[fila][columna - 1] == 'H'){
	    		if(barco[fila][columna - 2] == 'O') 
					return true;
			}
		    if (barco[fila][columna - 1] == 'O'){
	    		if(barco[fila][columna - 2] == 'H') 
					return true;
			}
		}
		if(barco[fila][columna] == 'O'){
	    	if (barco[fila][columna - 1] == 'S'){
	    		if(barco[fila][columna - 2] == 'H') 
					return true;
			}
		    if (barco[fila][columna - 1] == 'H'){
	    		if(barco[fila][columna - 2] == 'S') 
					return true;
			}
		}
	}
    return false;
}

// Función para encontrar las ubicaciones donde se puede formar la fórmula HSO
void encontrarHSO(char barco[][COLUMNAS]) {
    cout << "Posiciones donde se puede formar la fórmula HSO:" << endl;
    // Recorremos toda la matriz
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            // Verificar si la fórmula HSO se puede formar a partir de esta posición
            if (verificarHSO(barco, i, j)) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    char barco[FILAS][COLUMNAS] = {
        {'H', 'C', 'H', 'B', 'Y', 'S', 'O', 'S', 'O', 'H'},
        {'S', 'C', 'S', 'S', 'Y', 'Q', 'O', 'S', 'Z', 'K'},
        {'O', 'P', 'N', 'Y', 'O', 'K', 'F', 'H', 'C', 'K'},
        {'O', 'B', 'N', 'I', 'Y', 'S', 'P', 'O', 'O', 'K'}
    };

    encontrarHSO(barco);
    return 0;
}

