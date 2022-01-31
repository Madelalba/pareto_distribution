
template <class T>
	double desplazamientocuadratico(const vector<T>& v) { // se deine la función que calcula el promedio
		T suma = 0;                        // del cuadrado de las entradas de un vector, i.e.
		for (int i = 0; i < v.size(); i++) {  // el desplazamiento cuadrático promedio.
		    suma += v[i]*v[i];
		    }
	return suma/double(v.size());
	}
