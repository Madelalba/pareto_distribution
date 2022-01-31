template <class T>
double StdDev(const vector<T>& v) {
  double x = promedio(v);
  double suma = 0;
  for (int i = 0; i < v.size(); i++) {
    suma += v[i]*v[i];
  }
  return sqrt(suma/double(v.size()-1)-x*x);
}
