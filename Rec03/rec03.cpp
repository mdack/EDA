#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


void leerVector(int* v, int n, istream& sin) {
	for (int i = 0; i < n; i++)
		sin >> v[i];
}

int rec(int*v, int i, int n, int pot){
	int nN = n-1;
	int nI = i+1;
	int nPot = 2 * pot;
	int res;

	if (i>n) return 0;
	else{
		int res = pot*v[i] + pot*v[n] + rec(v, nI, nN, nPot);
		return res;
	}
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

