#include <iostream>
#define cOrigen 6 //definimos un espacio extra para el año de fabricación
#define fOrigen 7 //numero de pilas
#define cDestino 5 //definimos un espacio extra para el año de fabricación
#define fDestino 6 //agregamos una pila extra para representar la "puerta"
using namespace std;

// Función recursiva para encontrar el índice de la fila con el menor elemento mayor que el límite
int menorLimitado(int arr[][cOrigen], int fila, int limite, int indiceMinimo) {
    // Caso base: si hemos recorrido todas las filas
    if (fila < 0) {
        return indiceMinimo; // Retornar el índice de la fila con el menor elemento mayor que el límite
    }

    // Verificar si el elemento en la columna 0 es mayor que el límite
    if (arr[fila][0] > limite) {
        if (indiceMinimo == -1 || arr[fila][0] < arr[indiceMinimo][0]) {
            indiceMinimo = fila;
        }
    }
    // Llamada recursiva para continuar con la siguiente fila
    return menorLimitado(arr, fila - 1, limite, indiceMinimo);
}

// Función para determinar la altura de una pila en la matriz
int determinarAltura(int arr[][cOrigen], int fila, int columna){
    if (columna == cOrigen) return cOrigen; //caso base: se recorrieron todas las columnas y todas estaban llenas
    if(arr[fila][columna] == 0) return columna;
    return determinarAltura(arr, fila, columna+1);
}   

// Función recursiva para mover barriles desde la matriz de origen hacia la puerta
void moverHaciaPuerta(int origen[][cOrigen], int destino[][cDestino], int indice, int altura){
    if(altura == -1) return; //caso base: cuando ya movimos todos los barriles
    destino[0][altura] = origen[indice][altura];
    origen[indice][altura] = 0;
    moverHaciaPuerta(origen, destino, indice, altura-1);
    return;
}

// Función para trasladar barriles desde la matriz de origen hacia la matriz de destino
void trasladarBarriles(int origen[][cOrigen], int destino[][cDestino],int limitante,int posicionVaciaDestino){
    if (posicionVaciaDestino == 0) return; // caso base: si vamos a asignar barriles a la primera fila de destino ya que esta solo se usa de pivote y debe estar vacía
    int indice = menorLimitado(origen, fOrigen-1, limitante, -1);
    //caso base: ya no hay más años que evaluar
    if(indice == -1) return;
    else{
        limitante = origen[indice][0];
        int altura = determinarAltura(origen, indice, 0);
        if (altura <= cDestino){
            moverHaciaPuerta(origen, destino, indice, altura-1);
            // aquí debería ir la función moverDesdePuerta
            trasladarBarriles(origen, destino, limitante, posicionVaciaDestino-1);
        }
        else trasladarBarriles(origen, destino, limitante, posicionVaciaDestino);
    }
    return;
}

void mostrarMatrizDestino(int matriz[][cDestino], int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int origen[fOrigen][cOrigen] = {
        {2010, 100, 50, 50, 0, 0},
        {2021, 100, 100, 50, 50, 0},
        {2018, 50, 50, 25, 25, 25},
        {2015, 100, 50, 25, 0, 0},
        {2020, 100, 100, 0, 0, 0},
        {2019, 100, 50, 50, 25, 0},
        {2022, 100, 100, 0, 0, 0}
    };
    
    int destino[fDestino][cDestino] = {{0}};
    trasladarBarriles(origen, destino, 0, cDestino-1);
    mostrarMatrizDestino(destino, fDestino, cDestino);
    return 0;
}



