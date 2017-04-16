#include "Arbin.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void frontera(Arbin<int> ar, vector<int>* v) {
	
	if (!ar.esVacio()) {
		if ((ar.hijoIz().esVacio()) && (ar.hijoDr().esVacio())) {
			v->push_back(ar.raiz());
		}
		else {
			frontera(ar.hijoIz(), v);
			frontera(ar.hijoDr(), v);
		}
	}
}

Arbin<int> leerArbol(istream& sin) {
	int raiz;
	sin >> raiz;
	if (raiz == -1) return Arbin<int>();
	else {
		Arbin<int> iz = leerArbol(sin);
		Arbin<int> dr = leerArbol(sin);
		return Arbin<int>(iz, raiz, dr);
	}

}

void resuelve() {
	Arbin<int> arbol = leerArbol(cin);
	vector<int>* v = new vector<int>();

	frontera(arbol, v);

	if (v->size() == 0) {
		cout << endl;
	}
	else {
		int elem = v->at(0);
		cout << elem;
		for (size_t i = 1; i < v->size(); i++) {
			elem = v->at(i);
			cout << " " << elem;
		}
		cout << endl;
	}
}

int main() {
	int numCasos;
	string cadena;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		resuelve();
	}
}