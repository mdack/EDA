#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

long long resuelve(long long n) {
	long long d1 = 1, d2 = 1, res = 2, d3 = 0;
	long long cont = 2;
	
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else {
		while (res < n) {
			d3 = (d1 * 2) + d2;
			res = res + d3;
			d1 = d2;
			d2 = d3;
			cont++;
		}
	}

	return cont;
}

int main() {
	int numCasos;
	long long n;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		cin >> n;
		cout << resuelve(n) << endl;
	}
}