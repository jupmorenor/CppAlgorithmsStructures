/*
 * main.cpp
 *
 *  Created on: 11/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <iostream>
#include "arbolB.h"
using namespace std;


ArbolB *arbol;
int ord, dato;

void imprimir(int a[], int N) {
	for(int i=0; i<N; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	cout << "ingrese el orden del arbol: ";
	cin >> ord;
	arbol = new ArbolB(ord);
	do {
		cout << "ingrese un valor al arbol: ";
		cin >> dato;
	} while (arbol->insertarClave(dato));

	imprimir(arbol->darRaiz()->claves, arbol->darRaiz()->nClaves);

}



