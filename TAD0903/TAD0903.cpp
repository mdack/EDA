#include <iostream>
#include "Arbin.h"
using namespace std;


Arbin<int> leerArbolI(istream& sin) {
	int raiz;
	sin >> raiz;

	if (raiz == -1) return Arbin<int>();

	else {
		Arbin<int> iz = leerArbolI(sin);
		Arbin<int> dr = leerArbolI(sin);
		return Arbin<int>(iz, raiz, dr);
	}

}

Arbin<string> leerArbolS(istream& sin) {
	string raiz;
	sin >> raiz;

	if (raiz == "#") return Arbin<string>();

	else {
		Arbin<string> iz = leerArbolS(sin);
		Arbin<string> dr = leerArbolS(sin);
		return Arbin<string>(iz, raiz, dr);
	}

}

int main() {
	char tipo;

	cin >> tipo;

	while (!cin.fail()) {
		if (tipo == 'N') {
			Arbin<int> arbin = leerArbolI(cin);
			cout << arbin.getMinimo() << endl;
		}
		else {
			Arbin<string> arbin = leerArbolS(cin);
			cout << arbin.getMinimo() << endl;
		}
		cin >> tipo;

	}
}