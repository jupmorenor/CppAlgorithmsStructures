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

void ordenRapido(int a[], int izq, int der) {
	int i, j, v;
	if (der > izq) {
		v = a[der];
		i = izq-1;
		j = der;
		for(;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) {
				break;
			}
			intercambio(a,i,j);
		}
		intercambio(a, i, der);
		ordenRapido(a, izq, i-1);
		ordenRapido(a, i+1, der);
	}
}

void mergeLists(int lista[], int inicio1, int fin1, int inicio2, int fin2) {
	int inicio = inicio1;
	int _final = fin2;
	int indice = 0;
	int i;
	int *resultado = new int[fin1-inicio1+1];
	while ((inicio1 <= fin1) and (inicio2 <= fin2)) {
		if (lista[inicio1] < lista[inicio2]) {
			resultado[indice] = lista[inicio1];
			inicio1++;
		} else {
			resultado[indice] = lista[inicio2];
			inicio2++;
		}
		indice++;
	}
	if (inicio1 <= fin1) {
		for(i=inicio1; i<fin1; i++) {
			resultado[indice] = lista[i];
			indice++;
		}
	} else {
		for(i=inicio2; i<=fin2; i++) {
			resultado[indice] = lista[i];
			indice++;
		}
	}
	indice = 0;
	for(i=inicio; i<=_final; i++) {
		lista[i] = resultado[indice];
		indice++;
	}
	//delete [] resultado;
}

void mergeSort(int a[], int primero, int ultimo) {
	if (primero < ultimo) {
		int mitad = (primero + ultimo)/2;
		mergeSort(a, primero, mitad);
		mergeSort(a, mitad+1, ultimo);
		mergeLists(a, primero, mitad, mitad+1, ultimo);
	}
}

void base(int arr[], int n) {
    int mx = arr[0];
	for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
	}
	int m =  mx;
	for (int exp = 1; m/exp > 0; exp *= 10) {
		int output[n];
    	int i, count[10] = {0};

    	for (i = 0; i < n; i++) {
    		count[ (arr[i]/exp)%10 ]++;
    	}

    	for (i = 1; i < 10; i++) {
    		count[i] += count[i - 1];
    	}

    	for (i = n - 1; i >= 0; i--){
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    	}

    	for (i = 0; i < n; i++) {
    		arr[i] = output[i];
    	}
	}
}

unsigned bits(unsigned x, int j, int k) {
	return (x>>k) & ~(~0<<j);
}

void residuos(int a[], int izq, int der, int b) {
	int i, j;
	if (der > izq && b > 0) {
		i = izq;
		j = der;
		while (j!=i) {
			while (!bits(a[i], b, 1) && i<j) {
				i++;
			}
			while (bits(a[j], b, 1) && j>i) {
				j--;
			}
			intercambio(a, i, j);
		}
		if (!bits(a[i], b, 1)) {
			j++;
		}
		residuos(a, izq, j-1, b-1);
		residuos(a, j, der, b-1);
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
	int tam, op;
	float tiempo;
	QueryPerformanceFrequency(&frecuencia);
	srand(time(NULL));
	resultados.open("resultados.txt");
	//cout << "ingrese el tamaño del arreglo: ";
	//cin >> tam;
	cout << "Seleccione el algoritmo a usar: \n1. QuickSort.\n2. MergeSort.\n3. Ordenamiento por residuos." << endl;
	cin >> op;

	srand(time(NULL));
	for(int i=1; i<=60; i++) {
		tam = i*10;
		int *arreglo = new int[tam];
		llenar(arreglo, tam);
		imprimir(arreglo, tam);
		switch (op) {
		case 1:
			QueryPerformanceCounter(&inicio);
			ordenRapido(arreglo, 0, tam-1);
			QueryPerformanceCounter(&finale);
			break;
		case 2:
			QueryPerformanceCounter(&inicio);
			mergeSort(arreglo, 0, tam-1);
			QueryPerformanceCounter(&finale);
			break;
		case 3:
			QueryPerformanceCounter(&inicio);
			residuos(arreglo, 0, tam-1, 11);
			QueryPerformanceCounter(&finale);
			break;
		}
		imprimir(arreglo, tam);
		delta.QuadPart = finale.QuadPart - inicio.QuadPart;
		tiempo = ((float)delta.QuadPart)/frecuencia.QuadPart;

		resultados << tiempo*1000 << "\n";
		delete [] arreglo;
	}
	resultados.close();
	cout << "terminado" << endl;
	//system("PAUSE");
	return 0;
}
