#include <iostream>

using namespace std;

// Función recursiva para imprimir un patrón de triángulo
void imprimirTriangulo(int fila_actual, int fila_final) {
    // Caso base: si la fila actual es mayor que la fila final, terminamos la recursión
    if (fila_actual > fila_final)
        return;
    // Imprimir asteriscos en la fila actual
    for (int i = 0; i < fila_actual; i++)
        cout << " * ";
    cout << endl;
    // Llamar recursivamente a la función para la siguiente fila
    imprimirTriangulo(fila_actual + 1, fila_final);
    // Imprimir asteriscos en la fila actual después de la llamada recursiva
    for (int i = 0; i < fila_actual; i++)
        cout << " * ";
    cout << endl;
}

int main(int argc, char** argv) {
    // Llamar a la función para imprimir un triángulo con 3 filas como mínimo y 5 filas como máximo
    imprimirTriangulo(1, 5);
    return 0;
}


