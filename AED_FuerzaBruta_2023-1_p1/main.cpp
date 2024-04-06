#include <iostream>
#include <cmath>

using namespace std;

// Función para cargar un cromosoma en base M
void cargarCromosoma(int numero, int M, int N, int cromosoma[]) {
    int res;
    for(int i = 0; i < N; ++i) 
        cromosoma[i] = 0;
    int i = 0;
    while(numero > 0) {
        res = numero % M;
        numero = numero / M;
        cromosoma[i] = res;
        i++;
    }
}

// Función para verificar si un número está presente en un arreglo
bool verificarNumero(int arreglo[], int longitud, int numero) {
    for (int i = 0; i < longitud; ++i) {
        if (arreglo[i] == numero) {
            return true;
        }
    }
    return false;
}

// Función para reiniciar los pesos cargados en los camiones
void reiniciarPesos(int pesosCargados[], int M){
	for(int i = 0; i < M; i++){
		pesosCargados[i] = 0;
	}
}

// Función principal
int main() {
    // Entrada de datos
    int M, N;
    cout << "Ingrese el número de camiones (M): ";
    cin >> M;
    cout << "Ingrese el número de paquetes (N): ";
    cin >> N;
    int capacidadesM[M], pesosN[N];
    cout << "Ingrese las capacidades de los camiones (M):" << endl;
    for (int i = 0; i < M; ++i) {
        cout << "Camión " << (i + 1) << ": ";
        cin >> capacidadesM[i];
    }

    cout << "Ingrese los pesos de los paquetes (N):" << endl;
    for (int j = 0; j < N; ++j) {
        cout << "Paquete " << (j + 1) << ": ";
        cin >> pesosN[j];
    }

    // Variables para almacenar la mejor combinación
    int mejorCombinacion[N];
    int mejorDiferencia = -1; // Inicializamos con un valor negativo para asegurarnos de actualizarlo en el primer caso válido

    // Variables para calcular la diferencia mínima entre los camiones
	int diferencia;
	int minEsp;
	int maxEsp;
	int resta;

    // Total de combinaciones posibles
    int totalCombinaciones = pow(M, N);

    // Bucle para iterar sobre todas las combinaciones posibles
    for(int k = 0; k < totalCombinaciones; k++) {
        // Cargamos el cromosoma actual
        int cromosoma[N];
        cargarCromosoma(k, M, N, cromosoma);

        // Verificamos que cada camión tenga al menos un paquete asignado
        bool verificar = true;
        for(int i = 0; i < M; i++){
        	verificar = verificarNumero(cromosoma, N, i);
        	if(verificar == false) break;
		}
		if (verificar == false) continue;

        // Reiniciamos los pesos cargados en los camiones
        int pesosCargados[M];
        reiniciarPesos(pesosCargados, M);

        // Variable para verificar si la combinación es válida
        bool esValida = true;

        // Calculamos los pesos cargados en cada camión
        for(int i = 0; i < N; i++){
            pesosCargados[cromosoma[i]] += pesosN[i];
        }

        // Verificamos si se supera la capacidad de algún camión
        for(int i = 0; i < M; i++){
            if(capacidadesM[i] < pesosCargados[i]){
                esValida = false;
                break;
            }
        }

        // Si la combinación es válida, calculamos la diferencia mínima entre los camiones
        if (esValida){
            minEsp = 0;
            maxEsp = 0;
            resta = 0;
            for(int i = 0; i < M; i++){
                resta = capacidadesM[i] - pesosCargados[i];
                if (i == 0){
                    minEsp = resta;
                    maxEsp = resta;
                }
                else{
                    if(resta < minEsp) minEsp = resta;
                    if(resta > maxEsp) maxEsp = resta;
                }
            }
            diferencia = maxEsp - minEsp;

            // Si la diferencia es menor que la mejor encontrada hasta ahora, actualizamos la mejor combinación y diferencia
            if (mejorDiferencia == -1 or diferencia < mejorDiferencia){
                mejorDiferencia = diferencia;
                for (int i = 0; i < N; ++i) {
                    mejorCombinacion[i] = cromosoma[i];
                }
            } 
        }
    }

    // Mostramos la mejor combinación encontrada
    cout << "Mejor combinación:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Paquete " << (i + 1) << ": Camión " << (mejorCombinacion[i] + 1) << endl;
    }
    
    // Mostramos la diferencia mínima entre los camiones
    cout << "Diferencia mínima: " << mejorDiferencia << endl;

    return 0;
}
