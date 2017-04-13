#include "Arbin.h"
#include <iostream>
#include <string>
using namespace std;

Arbin<char> leerArbol(istream& sin) {
	char raiz;
	sin >> raiz;
	if (raiz == '.') return Arbin<char>();
	else {
		Arbin<char> iz = leerArbol(sin);
		Arbin<char> dr = leerArbol(sin);
		return Arbin<char>(iz, raiz, dr);
	}

}

int main() {
	int numCasos;
	string cadena;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		Arbin<char> arbol = leerArbol(cin);

		cout << arbol.contN() << " " << arbol.contH() << " " << arbol.contA() << endl;
	}
}