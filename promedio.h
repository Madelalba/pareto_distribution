#include<iostream>
#include<vector>

using namespace std;

template <class T>

double promedio(const vector<T> &x){

	T suma=0;
	      for(int i=0;i<x.size();i++){
		  suma+=x[i];
		   }
	return suma/double(x.size());
  }
