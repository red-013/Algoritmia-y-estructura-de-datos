#include <iostream>
#include <cmath>
#define MAX_NIVELES 10
#define MAX_ROBOTS 10

using namespace std;

struct Puente {
    int niveles;
    int pesos[MAX_NIVELES][2]; // 0 para la izquierda, 1 para la derecha
};

struct Robot {
    int cantidad;
    int pesos[MAX_ROBOTS];
};

void cargarCromosoma(int cromosoma[], int valor, int tam){
    for(int i=0; i<tam; i++){
            cromosoma[i]=0;
    }
    int residuo = 0;
    int i = 0;
    while(valor>0){
            residuo = valor%2;
            valor = valor/2;
            cromosoma[i]=residuo;
            i++;
    }
}

void verificarRobots(Robot robots,Puente puente){
    int rValidos = 0;
    Robot robotsValidos;
    for(int i = 0; i < robots.cantidad; i++) {
        bool validar = true;
        for(int j = 0; j < puente.niveles; j++) {
            if(robots.pesos[i] > puente.pesos[j][0] || robots.pesos[i] > puente.pesos[j][1]) {
                validar = false; 
                break; // Detener la iteraci�n despu�s de encontrar una violaci�n
            }
        }
        if(!validar){
            cout << "Se deber�a eliminar al robot " << i + 1 << " de peso: " << robots.pesos[i] <<
                " porque supera la capacidad de los puentes" << endl;
        }
	if(validar){
            robotsValidos.pesos[rValidos] = robots.pesos[i];
            rValidos++;	
	} 
    }
    robotsValidos.cantidad = rValidos;
    int cromosoma[rValidos];
    int posiblesSoluciones = pow(2, puente.niveles);
    int cantSoluciones = 0;
    if(rValidos != 0){
        cout<<"Las soluciones para los robots restantes son: "<<endl;
        for(int i=0; i<posiblesSoluciones; i++){
            cargarCromosoma(cromosoma, i, puente.niveles);
            bool verificador = true;
            for(int j = 0; j<puente.niveles; j++){
                for(int k = 0; k<robotsValidos.cantidad; k++){
                    if(robotsValidos.pesos[k] >= puente.pesos[j][cromosoma[j]]){
                        verificador = false;
                        break;
                    }
                }
                if(!verificador) break;
            }	
            if(verificador){
                cantSoluciones++;
                cout<<"Solucion "<<cantSoluciones<<":"<<endl;
                for(int j=0; j<puente.niveles; j++){
                    cout<<"Nivel "<<i+1<<" : ";
                    if(cromosoma[j]==0) cout<<"Izquierda";
                    if(cromosoma[j]==1) cout<<"Derecha";
                    cout<<endl;
                }
                cout<<endl;
            }
        }
    }
    else{
        cout<<"Ningun robot cumple con un peso valido"<<endl;
    }
}


int main() {
    Puente puente;
    Robot robots;

    // Ingresar datos del puente
    cout << "Ingrese la cantidad de niveles del puente (maximo " << MAX_NIVELES << "): ";
    cin >> puente.niveles;

    cout << "Ingrese los pesos de los vidrios para cada nivel (izquierda derecha):" << endl;
    for (int i = 0; i < puente.niveles; ++i) {
        cout<<"Ingrese los pesos de los puentes del "<<i+1<<" nivel: ";
        cin >> puente.pesos[i][0] >> puente.pesos[i][1];
    }

    // Ingresar datos de los robots
    cout << "Ingrese la cantidad de robots (maximo " << MAX_ROBOTS << "): ";
    cin >> robots.cantidad;

    cout << "Ingrese los pesos de los robots:" << endl;
    for (int i = 0; i < robots.cantidad; ++i) {
        cout<<"Ingrese el peso del robot "<<i+1<<" : ";
        cin >> robots.pesos[i];
    }

    int posiblesSoluciones = pow(2, puente.niveles);    
    int cromosoma[puente.niveles];
    int cantSoluciones = 0;
    for(int i=0; i<posiblesSoluciones; i++){
    	cargarCromosoma(cromosoma, i, puente.niveles);
    	bool verificador = true;
    	for(int j = 0; j<puente.niveles; j++){
            for(int k = 0; k<robots.cantidad; k++){
                if(robots.pesos[k] >= puente.pesos[j][cromosoma[j]]){
                    verificador = false;
                    break;
                }
            }
            if(!verificador) break;
        }	
        if(verificador){
            cantSoluciones++;
            cout<<"Solucion "<<cantSoluciones<<":"<<endl;
            for(int j=0; j<puente.niveles; j++){
                cout<<"Nivel "<<i+1<<" : ";
                if(cromosoma[j]==0) cout<<"Izquierda";
                if(cromosoma[j]==1) cout<<"Derecha";
                cout<<endl;
            }
            cout<<endl;
        }
    }
    if(cantSoluciones == 0){
        verificarRobots(robots, puente);
    }
    return 0;
}
