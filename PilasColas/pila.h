/*
 * pila.h
 *
 *  Created on: 10/10/2014
 *      Author: ---
 */
#include <cstdlib>
#include "estructura.h"
#ifndef PILA_H_
#define PILA_H_

class Pila {
	nodo<int> *cab;
public:
	Pila() {
		cab = new nodo<int>;
		cab->dato = 0;
		cab->sig = NULL;
	}
	void push(char v);
	char pop();
	bool pilaVacia();
	~Pila();
};

void Pila::push(char v) {
	nodo<int> *t = new nodo<int>;
	t->dato = v;
	t->sig = cab->sig;
	cab->sig = t;
}

char Pila::pop() {
	char x;
	nodo<int> *t = cab->sig;
	cab->sig = t->sig;
	x = t->dato;
	delete t;
	return x;
}

bool Pila::pilaVacia() {
	return cab->sig == NULL;
}

Pila::~Pila() {
	nodo<int> *t = cab;
	while (t != NULL) {
		cab = t;
		t = t->sig;
		delete cab;
	}
}

#endif /* PILA_H_ */
