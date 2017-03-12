/*
 * Main.cpp
 *
 *  Created on: 02 mar. 2017
 *      Author: Milagros Peña Quineche
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "Set.h"

void casoInt();
void casoString();


template <class T>
void resuelve(const vector<T> v, int cont, int k)
{	
	Set<T> s = Set<T>(cont);
	T aux;
	for (size_t i = 0; i < cont; i++) {
		aux = v[i];
		if (k > 0) {
			s.add(aux);
			k--;
		}
		else {
			if (s.getMin() < aux && !s.contains(aux)) {
				s.removeMin();
				s.add(aux);
				
			}
		}
	}

	cout << s;
}


int main(){
	char caso;
	
	while (!cin.fail()) {
		cin >> caso;
		if (caso == 'N') {
			casoInt();
		}
		if(caso == 'P') {
			casoString();
		}
	}
	
	return 0;
}

void casoInt()
{	
	int k;
	int i = 0;
	int num = 0;
	int limit = 10;
	vector<int> arreglo(limit, 0);

	cin >> k;

	while (num != -1) {
		cin >> num;
		if (num != -1) {
			arreglo[i] = num;
			i++;
			if (i == limit) {
				limit = limit * 2;
				arreglo.resize(limit);
			}
		}
	}
	resuelve(arreglo, i, k);

}

void casoString()
{
	int k;
	int i = 0;
	string word = " ";
	int limit = 10;
	vector<string> arreglo(limit, " ");


	cin >> k;

	while (word != "FIN") {
		cin >> word;
		if (word != "FIN") {
			arreglo[i] = word;
			i++;
			if (i == limit) {
				limit = limit * 2;
				arreglo.resize(limit);
			}
		}
	}

	resuelve(arreglo, i,k);

}



