/*
*  Autor: Milagros Peña
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool estaEquilibrado(char c, stack<char>& s) {
	bool equilibrado = true;

	if (s.empty()) equilibrado = false;
	else {
		char aux = s.top();
		s.pop();
		if (c != aux) equilibrado = false;
	}

	return equilibrado;
}


void resuelve(string cadena) {
	bool equilibrado = true;
	unsigned int i = 0;
	stack<char> s = stack<char>();

	while (i < cadena.size() && equilibrado) {
		if (cadena[i] == '(') s.push(')');
		else if (cadena[i] == '{') s.push('}');
		else if (cadena[i] == '[') s.push(']');
		else if (cadena[i] == ')') equilibrado = estaEquilibrado(cadena[i], s);
		else if (cadena[i] == '}') equilibrado = estaEquilibrado(cadena[i], s);
		else if (cadena[i] == ']') equilibrado = estaEquilibrado(cadena[i], s);
		i++;
	}

	if (equilibrado && s.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	string cadena;

	getline(cin, cadena);
	while (cadena != ".") {
		resuelve(cadena);
		getline(cin, cadena);
	}
	return 0;
}