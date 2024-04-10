#include <iostream>
#include <cmath>

#define n 4 // Tamaño de la matriz (n x n)
#define P 100 // Peso máximo que puede soportar la embarcación

using namespace std;

// Función para cargar el cromosoma a partir de un valor entero
void cargarCromosoma(int cromosoma[][n], int valor){
    // Inicializar el cromosoma con ceros
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cromosoma[i][j] = 0;     
        } 
    }
    int i=0, j=0;
    int residuo;
    // Convertir el valor a binario y cargarlo en el cromosoma
    while(valor>0){
        residuo = valor%2;
        valor = valor/2;
        cromosoma[i][j] = residuo;
        j++;
        if(j == n){
            j=0;
            i++;
        }
    }
}

// Función para calcular la suma de los valores o pesos según el cromosoma
int calcularSuma(int cromosoma[][n], int referencia[][n]){
    int suma = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cromosoma[i][j] == 1) suma += referencia[i][j];     
        } 
    }
    return suma;
}

// Función para imprimir los valores o pesos referenciados por el cromosoma
void imprimirReferenciado(int cromosoma[][n], int referencia[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cromosoma[i][j] == 1){
                cout<<" "<<referencia[i][j]<<" "; // Imprimir el valor o peso
            }
            else{
                cout<<" 0 "; // Imprimir 0 si el elemento no está incluido en el cromosoma
            } 
        } 
        cout<<endl;
    }
}

int main(){
    // Definir los pesos y valores de los elementos
    int pesos[n][n] = {
        {20, 20, 20, 20},
        {10, 30, 10, 30},
        {10, 10, 10, 20},
        {15, 15, 15, 15}
    };

    int valores[n][n] = {
        {10, 10, 10, 50},
        {80, 10, 10, 20},
        {20, 20, 20, 20},
        {50, 50, 50, 50}
    };
    
    int cromosoma[n][n];
    int posiblesCombinaciones = pow(2, n*n);
    int mejorCombinacion[n][n] = {{0}};
    int mejorGanancia = -1;
    
    // Iterar sobre todas las posibles combinaciones de cromosomas
    for(int i = 0; i<posiblesCombinaciones; i++){
        cargarCromosoma(cromosoma, i);
        // Calcular el peso total y verificar si es menor o igual al peso máximo permitido
        int pesoTotal = calcularSuma(cromosoma, pesos);
        if(pesoTotal <= P){
            // Si el peso es válido, calcular el valor total
            int valorTotal = calcularSuma(cromosoma, valores);
            // Actualizar la mejor ganancia y la mejor combinación si se encuentra una ganancia mejor
            if(mejorGanancia == -1 or mejorGanancia < valorTotal){
                mejorGanancia = valorTotal;
                // Copiar la combinación actual en la mejor combinación
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        mejorCombinacion[i][j] = cromosoma[i][j];
                    }
                }
            }
        }
    }
    
    // Imprimir el resultado
    cout<<"Valor Máximo: "<<mejorGanancia<<" (en miles de $)"<<endl;
    cout<<"Pesos seleccionados:"<<endl;
    imprimirReferenciado(mejorCombinacion, pesos);
    cout<<endl;
    cout<<"Valores seleccionados:"<<endl;
    imprimirReferenciado(mejorCombinacion, valores);
    
    return 0;
}

