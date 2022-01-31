//Maria del Alba Pacheco Blas
// tarea 1 ejercicio 1 inciso iv
//este programa genera una caminata aleatoria para 1000 caminantes en tres dimensiones

#include<ctime>
#include<fstream>
#include<vector>
#include<cmath>
#include "drand.h"
#include "promedio.h"
#include "desplazamientocuadratico.h"

using namespace std;

int main(){
     
     ofstream salida1,salida2;
     salida1.open("ej1iv.dat");
     salida2.open("promej1iv.dat");
     
     int d=3;
     int pasos=1050;
     int cam_tot=1000;
         
     vector< vector< vector<int> > > X;           //esta sera la posicion
     X.resize(d);                                // primera entrada indica coordenada x , y ,z 
	for (int i = 0; i < d; i++) {            // la segunda entrada es el numero de pasos 
	      X[i].resize(pasos);                      
	      for (int j = 0; j < pasos; j++) {   // la última entrada es el número de caminante.
		    X[i][j].resize(cam_tot);
		  }
	    }
     
     vector<double> distorigen;  //la distancia al origen me servira para conocer el desplazamiento cuadratico medio 
     distorigen.resize(cam_tot);     
      
     srand(time(0));
  
	for (int i = 0; i < pasos-1; i++) { 
	      for (int j = 0; j < cam_tot; j++) {
		    for (int k = 0; k < d; k++) {
			X[k][i+1][j] = X[k][i][j];
			}
		  int L = d*drand();
		  X[L][i+1][j] = X[L][i][j] + 2*int(2.0*drand())-1; 
		  }

	      for (int j = 0; j < cam_tot; j++) { 
		   distorigen[j] = 0.0;                           
		    for (int k = 0; k < d; k++) {
			distorigen[j] += X[k][i][j]*X[k][i][j];//elevamos al cuadrado las distancias al origen para hacerlas positivas
		      }
		   distorigen[j] = sqrt(distorigen[j]);//sacamos la raiz para conocer la verdadera distancia al origen 
		  }
    
	      if (0 == i%(pasos/100)) { //en el archivo promej1ii.dat tenemos que
		  salida2 << i;         //primer columna es el paso o tiempo   
		    for (int k = 0; k < d; k++) { 
			salida2 << " \t" << promedio(X[k][i]);  //segunda columna promedio en x para todos los caminantes
			}                                    //tercera columna promedio en y para todos los caminantes
		  salida2 << "  \t" << desplazamientocuadratico(distorigen); //cuarta columna promedio en z para todos los caminantes
		  salida2 << endl;                   //quinta columna desplazamiento cuadratico medio
		  }
	      
	      }

	
	for (int i = 0; i < cam_tot; i++) {  //en el archivo ej1ii.dat encontraremos, en la primer columna
	      for (int j = 0; j < pasos; j++) { //el paso que esta dando, en la segunda columna el caminante
		    salida1 << j << " \t" << i;  //en la tercer columna la posicion en x, en la cuarta columna la posicion en y
		    for (int k = 0; k < d; k++) { //k es el indice para saber que dimension
			  salida1 << " \t" << X[k][j][i]; //j es el indice para saber el paso, i es el indice para saber el caminante
			}
		    salida1 << endl;
		   }
	      salida1 << "\n"<<endl;
	      }

  
	salida1.close(); 
	salida2.close();
	return 0;
      }
