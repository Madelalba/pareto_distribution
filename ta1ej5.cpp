//Maria del ALba Pacheco. Tarea 1 ejercicio 5.
//corresponde a un caminante aleatorio en una dimension. Empieza en 0 y queremos saber cual es el tiempo que tarda en cruzar cero de nuevo. 
//obtenenemos la distribucion de probs.

#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "drand.h"
#include "promedio.h"
#include "histograma.h"

using namespace std;

int main() {

  srand(time(0));  

  ofstream salida; 
  salida.open("ej5.dat");
  
  int pasos = 100000;
  int x = 0; 
  int limite = 1E6; // limite de tiempo

  vector<int> P; 

      while (P.size() <= pasos) { 
	      int i = 0;  
	      bool vuelta = true; 
		    while (vuelta) {
			    i++;
			    x += 2*(floor(2*drand())) - 1; //manera en que se evalua el paso
				if (x == 0) {
				    P.push_back(i);
				    vuelta = false;
				    }
				if (i > limite) break; 
			  }
	     // if (P.size()%(35000) == 0) 
	      //cout << 100.0*P.size()/pasos << " %" << endl; //porcentaje de los tiempos
	    }

  int tmin = pasos; 
  int tmax = 0;

      for (int i = 0; i < P.size(); i++) {
		if (P[i] < tmin) tmin = P[i];
		if (P[i] > tmax) tmax = P[i];
		}
  
  vector<double> h;
  h.resize(tmax-tmin+1);  
  HISTOGRAMA(P, h, tmin);  
  
      for (int i = 0; i < tmax+1; i+= 2) {
		double tmp = i + tmin;
		salida << tmp << " \t" << h[i] << endl;
		}
 
      salida.close();
  
      cout << "Promedio de los tiempos: " << promedio(P) << endl;

  return 0; 
}