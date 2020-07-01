#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <windows.h>
using namespace std;

ofstream resultados;
LARGE_INTEGER frecuencia;
LARGE_INTEGER inicio;
LARGE_INTEGER finale;
LARGE_INTEGER delta;

float matriz[3][3];

float ecuacionChapmanKolmogorov(float P[3][3], int i, int j, int n, int m, int M) {
	int Pij;
	if(n==1) {
		return P[i][j];
	} else {
		Pij = 0;
		for (int k=0; k<M; k++) {
			Pij += ecuacionChapmanKolmogorov(P, i, k, n-m, n-m-1, M)
					* ecuacionChapmanKolmogorov(P, k, j, m, m-1, M);
		}
	}
	return Pij;
}

int main() {
	matriz[3][3] = {{0.1, 0.8, 0.1}, {0.9, 0, 0.1}, {0.2, 0.2, 0.6}};

	float resultado, tiempo;
	QueryPerformanceFrequency(&frecuencia);
	resultados.open("resultados.txt");
	for(int i=0; i<=15; i++) {
		QueryPerformanceCounter(&inicio);
		resultado = ecuacionChapmanKolmogorov(matriz, 0, 2, i+1, i, 3);
		QueryPerformanceCounter(&finale);
		cout << resultado << endl;
		delta.QuadPart = finale.QuadPart - inicio.QuadPart;
		tiempo = ((float)delta.QuadPart)/frecuencia.QuadPart;

		resultados << tiempo*1000 << "\n";
	}
	resultados.close();
	cout << "terminado" << endl;
	return 0;
}
