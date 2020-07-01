/*
 * cola.h
 *
 *  Created on: 10/10/2014
 *      Author: Juanpa y Yami
 */
#include <cstdlib>
#include <iostream>
#include "estructura.h"

#ifndef COLA_H_
#define COLA_H_

using namespace std;

class cola {
	nodo<char> *cab, *fin;
public:
	cola() {
		cab = fin = NULL;
	}
	void InsCola(char i);
	char AtenderCola();
	void ImprimirCola();
	bool ColaVacia();
	~cola();
};

void cola::InsCola(char i) {
	nodo<char> *nuevo;
	nuevo = new nodo<char>;
	nuevo->dato = i;
	nuevo->sig = NULL;
	if (cab == NULL) {
		cab = nuevo;
	} else {
		fin->sig = nuevo;
	}
	fin = nuevo;
}

char cola::AtenderCola() {
	char x;
	nodo<char> *aux = cab;
	cab = aux->sig;
	x = aux->dato;
	delete aux;
	return x;
}

void cola::ImprimirCola() {
	nodo<char> *aux;
	aux = cab;
	while (aux != NULL) {
		cout << aux->dato << " ";
		aux = aux->sig;
	}
}

bool cola::ColaVacia() {
	return (cab == NULL);
}

cola::~cola() {
	nodo<char> *aux;
	while (cab != NULL) {
		aux = cab;
		cab = aux->sig;
		delete aux;
	}
	delete cab;
}

#endif /* COLA_H_ */
