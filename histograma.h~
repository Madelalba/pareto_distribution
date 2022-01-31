template <class T>
  void HISTOGRAMA(const vector <T> & v, vector <double> & h, T xmin) {
	    for (int i = 0; i < h.size(); i++) {
		  h[i] = 0.0;
		  }
	    for (int i = 0; i < v.size(); i++) {
		  h[ floor(v[i] - xmin) ] += 1.0/v.size();
		  }
	}
