/*
 * arbolB.cpp
 *
 *  Created on: 11/11/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include "arbolB.h"

void ArbolB::ordenamientoInsercion(int a[], int N) {
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

bool ArbolB::insertarClave(int clave) {
	bool res = true;
	if (raiz->nClaves < (maxClaves)) {
		raiz->claves[raiz->nClaves] = clave;
		ordenamientoInsercion(raiz->claves, ++raiz->nClaves);
	} else {
		res = false;
	}
	return res;
}

void ArbolB::eliminar_clave(int clave) {
	//TODO esto va a ser un completo camello XD
}

NodoB *ArbolB::darRaiz() {
	return raiz;
}
