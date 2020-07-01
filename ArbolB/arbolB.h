/*
 * arbolB.h
 *
 *  Created on: 11/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */

#include <stdlib.h>

#ifndef ARBOLB_H_
#define ARBOLB_H_

struct NodoB {
	bool hoja;
	int nClaves;
	int *claves;
	NodoB **hijos;
};

class ArbolB {
	NodoB *raiz;
	int d;
	int maxClaves;
	int minClaves;
	int cantHijos;
	NodoB *crear_nodo() {
		NodoB *nodo = new NodoB;
		nodo->hoja = 1;
		nodo->nClaves = 0;
		nodo->claves = new int[maxClaves];
		nodo->hijos = NULL;
		return nodo;
	}
	void ordenamientoInsercion(int a[], int N);
public:
	ArbolB(int orden) {
		d = orden;
		raiz = crear_nodo();
		maxClaves = 2*d - 1;
		minClaves = d - 1;
		cantHijos = 2*d;
	}
	bool insertarClave(int clave);
	void eliminar_clave(int clave);
	NodoB *darRaiz();
};



#endif /* ARBOLB_H_ */
