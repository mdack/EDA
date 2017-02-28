/*
 * Main.cpp
 *
 *  Created on: 23 feb. 2017
 *      Author: Milagros Peña Quineche
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "SetOfInts3.h"

void apartado2() {
	SetOfInts3 s1;
	SetOfInts3 s2;

	while (!cin.fail()) {
		cin >> s1;
		cin >> s2;

		if (s1 < s2) {
			cout << "Es subconjunto" << endl;
		}
		else {
			cout << "No es subconjunto" << endl;
		}
	}
}


void llenaSet(vector<int> v, SetOfInts3& set, int k) {
	size_t i = 0;
	bool enc = false;
	int cont = 0;

	while ((i < v.size()) && !enc) {
		if (v[i] == -1) { enc = true; }
		else {
			if (v[i] != v[i + 1]) {
				set.add(v[i]);
				cont++;
				if (cont == k) enc = true;
			}
			i++;
		}
	}
}

/*
*	La complejidad del algoritmo sería de O(k*log(n)), siendo n el tamaño del array del Set
*/
void apartado3() {
	unsigned int k = -1;
	int num=0,i = 0;
	int limit = 10;
	vector<int> arreglo(limit, 0);
	SetOfInts3 s;

	while (k != 0) {
		cin >> k;
		if (k != 0) {
			while (num != -1) {
				cin >> num;
				arreglo[i] = num;
				i++;
				if (i == limit) {
					limit = limit * 2;
					arreglo.resize( limit );
				}
			}
			i--;
			sort(arreglo.begin(), arreglo.begin() + i);
			s = SetOfInts3();
			llenaSet(arreglo, s, k);
			cout << s;
			i = 0;
			num = 0;
		}
	}

}

int main(){

	apartado3();
	
	return 0;
}



