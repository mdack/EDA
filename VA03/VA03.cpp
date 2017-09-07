#include <iostream>
using namespace std;

void resuelve(int N, int **trabajos, int sol, int nivel, bool *ocupados, int &solMin) {

	for(int c = 0; c < N; c++) {
		if (!ocupados[c]) {
			sol += trabajos[nivel][c];
			ocupados[c] = true;
			if (nivel == N - 1) {
				if (sol < solMin) {
					solMin = sol;
				}
				sol -= trabajos[nivel][c];
				ocupados[c] = false;
			}
			else {
				resuelve(N, trabajos, sol, nivel + 1, ocupados, solMin);
				sol -= trabajos[nivel][c];
				ocupados[c] = false;
			}
		}
	}
}


int main() {
	int N;
	int sol = 100000;

	cin >> N;

	while (N != 0) {
		int **trabajos = new int*[N];
		bool *ocupados = new bool[N];

		for (int i = 0; i < N; i++) {
			trabajos[i] = new int[N];
			ocupados[i] = false;
		}

		for (int f = 0; f < N; f++) {
			for (int c = 0; c < N; c++) {
				cin >> trabajos[f][c];
			}
		}

		resuelve(N, trabajos, 0, 0, ocupados, sol);

		cout << sol << endl;

		delete[]trabajos;
		delete ocupados;
		sol = 100000;

		cin >> N;
	}

}