#include <iostream>
#include "Arbin.h"
#include "List.h"
using namespace std;

template <class T>
Arbin<T> leerArbol(const T& repVacio) {
	T elem;
	cin >> elem;
	if (elem == repVacio)
		return Arbin<T>();
	else {
		Arbin<T> hi = leerArbol(repVacio);
		Arbin<T> hd = leerArbol(repVacio);
		return Arbin<T>(hi, elem, hd);
	}
}

void recorrerPreorden(Arbin<int> ar, int& dragones, int& mejorDrag, Arbin<int>& hoja, Arbin<int>& ultVisto) {
	
	if (ar.esVacio()) {
		return;
	}

	if (ar.raiz() == 1) {
		dragones++;
	}

	if (ar.hijoIz().esVacio() && ar.hijoDr().esVacio()) {
		if (dragones >= 0 && dragones < mejorDrag) {
			mejorDrag = dragones;
			hoja = ar;
		}
		ultVisto = ar;
		return;
	}

	recorrerPreorden(ar.hijoIz(), dragones, mejorDrag, hoja, ultVisto);
	recorrerPreorden(ar.hijoDr(), dragones, mejorDrag, hoja, ultVisto);

	if (ar.raiz() == 1) {
		if (ar.hijoIz() == ultVisto || ar.hijoDr() == ultVisto) {
			dragones--;
		}
	}
	ultVisto = ar;
}

void resuelveCaso(){
	Arbin<int> arbol = leerArbol(-1);
	Arbin<int> hoja = Arbin<int>();
	Arbin<int> ult = Arbin<int>();
	int dra = 0;
	int mejor = 10000;

	recorrerPreorden(arbol, dra, mejor, hoja, ult);

	cout << hoja.raiz() << endl;
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();
}