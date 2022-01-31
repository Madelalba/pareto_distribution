//Maria Pacheco. Tarea 1, ejercicio 4
//Este programa considera un caminante aleatorio sencillo en una dimension finita que va de 1 a L, si intenta brincar a las fronteras se queda
//donde estaba. Calculamos el tiempo de primer pasaje, es decir, el tiempo en el que alcanza a L
//Calaculamos el tiempo de recurrencia, el tiempo para qe regrese por primera vez a la posicion 1

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "drand.h"
#include "promedio.h"
#include "desvest.h"
#include "histograma.h"

using namespace std;

int main() {

  srand(time(0));
  
  ofstream salida1;
  ofstream salida2;
  salida1.open("promedios.dat");
  salida2.open("otro.dat");
  
  int Lmax = 10; //tamaño de la red
  int pasos = 1000; 
  
  vector<int> I; //vector de tiempos de primer pasaje
  vector<int> R; //vector de tiempos de recurrencia

	for (int L = 2; L < Lmax; L++) {

	    int x = 1; 
	    int s = 0; 
	    bool ida = true; //Una variable que dice si el caminante va de ida o de regreso.
  
	      for (int i = 0; i < pasos; i++) {
      
		   int l = 2*(floor(2*drand()))-1; //la manera en que se evalua al paso
      
		   if ((l<0)&&(x>1)) x += l; //iteracion
		   if ((l>0)&&(x<L)) x += l; 
			s++;
      
		   if ((x == L)&&(ida)) { //condicion reflejante al llegar a L 
			I.push_back(s);  
			s = 0;
			ida = false; 
		      }
		      
		  if ((x == 1)&&(!ida)) { // condicion reflejante al llegar a 1
			R.push_back(s); 
			s = 0;
			ida = true; 
		      }
		}	

	      salida1 << L << " \t" << promedio(I) << " \t" << promedio(R); 
	      salida1 << " \t" << StdDev(I) << " \t" << StdDev(R) << endl;
	    }
  

  int tmin = pasos;
  int tmax = 0;

	for (int i = 0; i < I.size(); i++) {
	      if (I[i] < tmin) tmin = I[i];
	      if (I[i] > tmax) tmax = I[i];
	    }
  
  vector<double> hI;
  hI.resize(tmax-tmin+1);  
  HISTOGRAMA(I, hI, tmin);  
  
	for (int i = 0; i < tmax+1; i+= 2) {
	      double tmp = i + tmin;
	      salida2 << tmp << " \t" << hI[i] << endl;
	     }
	    salida2 << "\n"<<endl;

	
	for (int i = 0; i < R.size(); i++) {
	      if (R[i] < tmin) tmin = R[i];
	      if (R[i] > tmax) tmax = R[i];
	    }
  
  vector<double> hR;
  hR.resize(tmax-tmin+1);  
  HISTOGRAMA(R, hR, tmin);  
  
	for (int i = 0; i < tmax+1; i+= 2) {
	      double tmp = i + tmin;
	      salida2 << tmp << " \t" << hR[i] << endl;
	    }
  
  salida1.close();
  salida2.close(); 
  return 0;
}