/*
 * main.cpp
 *
 *  Created on: 24/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */
#include <iostream>
#include <cstdlib>
#include "ListaA.h"
using namespace std;

int main() {

	int tam, op, dato;
	cout << "Ingrese el tamaño del arreglo: ";
	cin >> tam;
	ListaA lista(tam);
	while (true) {
		cout << "Elija una opcion: " << endl;
		cout << "0.Salir\n1.insertar de primero\n2.insertar de ultimo\n3.tamaño";
		cin >> op;
		switch (op) {
		case 0:
			break;
		case 1:
			cout << "ingrese un valor: ";
			cin >> dato;
			lista.insertar_inicio(dato);
			break;
		case 2:
			cout << "ingrese un valor: ";
			cin >> dato;
			lista.insertar_final(dato);
			break;
		case 3:
			cout << "el tamaño de la lista es " << lista.long_lista() << endl;
			break;
		}
		if (op==0) break;
	}


	return EXIT_SUCCESS;
}



