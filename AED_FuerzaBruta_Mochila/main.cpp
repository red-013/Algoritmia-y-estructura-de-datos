
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

#include "Funciones.h"

int main(int argc, char** argv) {
    // Peso y valor de cada paquete
    int pesos[] = {1, 2, 4, 12, 1};
    int pesoMaximo = 15;
    int cantidadPaquetes = 5;

    int mejorPeso = 0, mejorCombinacion, pesoParcial;
    int combinacionActual;
    int* cromosomas = new int[cantidadPaquetes]; // Cambio a un puntero

    // Calcular el número total de combinaciones posibles
    int totalCombinaciones = (int)pow(2, cantidadPaquetes);
    
    // Iterar sobre todas las posibles combinaciones
    for(int i = 0; i < totalCombinaciones; i++) {
        // Convertir el número actual en binario y cargarlo en el arreglo de cromosomas
        cargarCromosomas(i, cantidadPaquetes, cromosomas);
        
        // Calcular el peso parcial de la combinación actual
        pesoParcial = 0;
        for(int j = 0; j < cantidadPaquetes; j++) {
            pesoParcial += cromosomas[j] * pesos[j];
        }
        
        // Actualizar el mejor peso si el peso parcial es menor o igual al peso máximo y es mayor que el mejor peso encontrado hasta ahora
        if(pesoParcial <= pesoMaximo && mejorPeso <= pesoParcial) {
            mejorPeso = pesoParcial;
            mejorCombinacion = i;
        }
    }  
    
    cout << "Mejor peso: " << mejorPeso << endl;
    cout << "Mejor combinacion: " << mejorCombinacion << endl;
 
    return 0;
}

