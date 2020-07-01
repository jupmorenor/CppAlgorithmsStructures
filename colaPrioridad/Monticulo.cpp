/*
 * Monticulo.cpp
 *
 *  Created on: 23/10/2014
 *      Author: Juan pablo Moreno Rico - 20111020059
 *      Author: Diana Cristhina Pérez Pérez - 20111020069
 */
#include <iostream>
#include "Monticulo.h"

Monticulo::Monticulo(int _tam) {
	tam = _tam;
	posActiva = 0;
	arreglo = new int[_tam];
	for (int i=0; i<tam; i++) {
		arreglo[i] = 0;
	}
	arreglo[0] = 1;
}

Monticulo::~Monticulo() {
	delete [] arreglo;
}

int Monticulo::maxi(int a, int b){
	return (arreglo[a]>arreglo[b]) ? a : b;
}

int Monticulo::atender() {
	int i, z, at, r;
	at = arreglo[1];
	r = arreglo[posActiva];
	if (posActiva > 0) {
		arreglo[posActiva] = 0;
		posActiva--;
		i = 1;
		while (i < posActiva-1) {
			z = maxi(2 * i, 2 * i + 1);
			if (r > arreglo[z]) {
				arreglo[i] = r;
				break;
			} else if (r < arreglo[z]) {
				arreglo[i] = arreglo[z];
				arreglo[z] = r;
				i = z;
			}
		}
	}
	return at;
}

bool Monticulo::insertar(int prior) {
	int pos = ++posActiva;
	bool ok = false;
	if (posActiva == tam) {
		posActiva--;
		return false;
	}
	if (pos == 1) {
		arreglo[pos] = prior;
	}
	while(pos/2 > 0 && not ok) {
		if (arreglo[pos/2] > prior) {
			arreglo[pos] = prior;
			ok = true;
		} else {
			arreglo[pos] = arreglo[pos/2];
			pos/=2;
		}
	}
	arreglo[pos] = prior;
	return true;
}

void Monticulo::imprimir() {
	int i;
	for (i = 0; i <= posActiva; i++) {
		std::cout << arreglo[i] << "  ";
	}
	std::cout << std::endl;
}
