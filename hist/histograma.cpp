//Maria Pacheco. Tarea 1 ejercicios 2 y 3 condensados. 
//Histograma nos da las frecuencias de cierto evento, en este caso cuantas veces se repite un mismo dato de mi arreglo.
//Se crean 10000 caminantes y se encuentra la distirbucion de probabilidad de estos caminantes en distintos momentos de tiempo

#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "drand.h"

using namespace std;

template <class T>
void HISTOGRAMA(const vector<T>& v, vector<double>& h, T xmin) { //definimos una funcion vacia que regresara histograma
	  for (int i = 0; i < h.size(); i++) {		//v es el vector de las posiciones q se ingresan, 
		h[i] = 0.0;				//h es el vector que sera el resultado del histograma
		}					//xmin el valor minimo
	  for (int i = 0; i < v.size(); i++) {
		h[ floor(v[i] - xmin) ] += 1.0/v.size();	//sacamos las frecuencias
		}
	}

int main() {

  srand(time(0));
  
  ofstream salida;
  salida.open("histograma.dat");
  
  int pasos = 1000; 
  int cam_tot = 10000; 
  
  vector<int> X; 
  X.resize(cam_tot);
  
  for (int i = 0; i < cam_tot; i++) { //se inicializa el vector posicion en 0
	X[i] = 0;
	}

  for (int i = 0; i < pasos; i++) { // Se genera el caminante aleatorio 
	for (int j = 0; j < cam_tot; j++) { 
	      X[j] += 2*int(2*drand()) - 1; 
	      }
      }
 
  int tmin = pasos; 
  int tmax = -pasos; 
  
  for (int i = 0; i < cam_tot; i++) { //en este bucle se van buscando los valores maximo y minimo de mi arreglo
    if (X[i] < tmin) tmin = X[i]; 
    if (X[i] > tmax) tmax = X[i]; 
  }

  vector<double> h; 
  h.resize(tmax-tmin+1); //el tamaño de h es la longitud entre el valor maximo y minimo mas uno
  HISTOGRAMA(X, h, tmin);  
  
  for (int i = 0; i < h.size(); i++) { 
    double t = i + tmin;
    salida << t << "\t" << h[i] << endl;
  }
  salida.close();
  return 0;
}

