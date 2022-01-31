//Maria del Alba Pacheco Blas
// tarea 1 ejercicio 1 inciso i
//este programa genera caminatas aleatorias en una dimension para un caminante, con tantos pasos como num_tot le de en la terminal
//sin utilizar ningun if

#include<iostream>
#include<ctime>
#include<cstdlib>
#include "drand.h"

using namespace std;

int main(int argc, char *argv[]){
     
     srand(time(0));
     
	int num_tot = atoi(argv[1]); //en la terminal nos solicitara el numero de pasos que quiero dar
	double x;
	
	   for(int pasos=0; pasos <= num_tot; pasos++){	
	    
		double r = drand();
		int p;
	  
		    p=(r < 0.5);
		    x += 2*p -1;
  		
		cout<< pasos <<'\t'<< x << endl;
		
	       }
	
      return 0;
    }
