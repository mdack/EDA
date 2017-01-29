#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void leerVector(int* v, int n, istream& sin) {
	for (int i = 0; i < n; i++)
		sin >> v[i];
}

int rec(int*v, int i, int n, int pot){
	if (i < n){
		int nN = n - 1;
		int nI = i + 1;
		int nPot = 2 * pot;
		int res = rec(v, nI, nN, nPot);
		int o = pot*v[i];
		int s = pot*v[n];
		return (o + s + res);
	}else  return 0;
}

void ingr(int*v, int n){
	int pot = 1;
	int inicN = n - 1;
	int res = rec(v, 0, inicN, pot);
	cout << res << endl;
}



int main() {
	int numCasos, n;
	int* v;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> n;
		// Lectura de otros parametros
		v = new int[n];
		leerVector(v, n, cin);
		ingr(v, n);
		delete[] v;
	}
}

