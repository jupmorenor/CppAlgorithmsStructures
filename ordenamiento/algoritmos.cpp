/**
 * Juan Pablo Moreno Rico 20111020059
 * Ciencias de la computacion 1 grupo 82 2014-2
 */

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

void intercambio(int a[], int pos1, int pos2) {
	int aux = a[pos1];
	a[pos1] = a[pos2];
	a[pos2] = aux;
}

void seleccion(int a[], int N) {
	int i, j, min;
	for(i=0; i<N-1; i++) {
		min = i;
		for(j=i+1; j<N; j++) {
			if (a[j]<a[min]) {
				min = j;
			}
		}
		intercambio(a, min, i);
	}
}

void insercion(int a[], int N) {
	int i, j, v;
	for(i=1; i<N; i++) {
		j=i;
		v=a[j];
		while (a[j-1]>v && j>0) {
			a[j] = a[j-1];
			j--;
		}
		a[j] = v;
	}
}

void burbuja(int a[], int N) { 
	int i, j;
	for(i=N-1; i>=0; i--) {
		for(j=1; j<=i; j++) {
			if (a[j-1]>a[j]) {
				intercambio(a, j-1, j);
			}
		}
	}
}

void shell(int a[], int N) {
	int i, j, h, v;
	for(h=1; h<=N/9; h=3*h+1);
	for( ; h>0; h/=3) {
		for(i=h+1; i<=N; i++) {
			v = a[i];
			j = i;
			while (j>=h && a[j-h]>=v) {
				a[j] = a[j-h];
				j-=h;
			}
			a[j] = v;
		}
	}
}

void busquedaSecuencial(int a[], int N, int val) {
	for(int i=0; i<N; i++) {
		if (a[i]==val) {
			break;
		}
	}
}

void busquedaBinaria(int a[], int N, int val) {
	int primero = 0;
	int mitad;
	int ultimo = N-1;
	while (primero <= ultimo) {
		mitad = (primero + ultimo)/2;
		if (val == a[mitad]) {
			break;
		} else {
			if (a[mitad] > val) {
				ultimo = mitad - 1;
			} else {
				primero = mitad + 1;
			}
		}
	}
}

void llenar(int a[], int N) {
	for(int j=0; j<N; j++) {
		a[j] = j;// j es ordenado, N-j es invertido, rand()%N es aleatorio
	}
}

void imprimir(int a[], int N) {
	for(int i=0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int *arreglo;
	int i, N, x, op;
	float tiempo;
	resultados.open("resultados.txt");
	QueryPerformanceFrequency(&frecuencia);
	srand(time(NULL));
	cout << "Elija el algoritmo a utilizar: " << endl;
	cout << "1. Seleccion.\n2. Insercion.\n3. Burbuja.\n4. Shell.\n5. Busqueda Secuelcial.\n"
			"6. Busqueda Binaria." << endl;
	cin >> op;
	for(i=1; i<=60; i++) {
		switch (op) {
		case 1:
		case 2:
		case 3:
		case 5:
		case 6:
			N = i*5;
			break;
		case 4:
			N = i*15;
			break;
		}

		arreglo = new int[N];
		llenar(arreglo, N);
		//imprimir(arreglo, N);// ver antes de ordenar

		switch (op) {
		case 1:
			QueryPerformanceCounter(&inicio);
			seleccion(arreglo, N);
			QueryPerformanceCounter(&finale);
			break;
		case 2:
			QueryPerformanceCounter(&inicio);
			insercion(arreglo, N);
			QueryPerformanceCounter(&finale);
			break;
		case 3:
			QueryPerformanceCounter(&inicio);
			burbuja(arreglo, N);
			QueryPerformanceCounter(&finale);
			break;
		case 4:
			QueryPerformanceCounter(&inicio);
			shell(arreglo, N);
			QueryPerformanceCounter(&finale);
			break;
		case 5:
			x = N-1;
			insercion(arreglo, N);
			QueryPerformanceCounter(&inicio);
			busquedaSecuencial(arreglo, N, x);
			QueryPerformanceCounter(&finale);
			break;
		case 6:
			x = N-1;
			seleccion(arreglo, N);
			QueryPerformanceCounter(&inicio);
			busquedaBinaria(arreglo, N, x);
			QueryPerformanceCounter(&finale);
			break;
		}
		//imprimir(arreglo, N); //ver despues de ordenar

		delta.QuadPart = finale.QuadPart - inicio.QuadPart;
		tiempo = ((float)delta.QuadPart)/frecuencia.QuadPart;

		resultados << tiempo*1000 << "\n";
		delete [] arreglo;
	}
	resultados.close();
	cout << "terminado" << endl;
	return 0;
}


