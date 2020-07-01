/*
 * pilaArbol.cpp
 *
 *  Created on: 19/10/2014
 *      Author: Juanpa y Yami
 */

#include "pilaArbol.h"

void Pila::push(int v) {
	nodoPila *t = new nodoPila;
	t->dato = v;
	t->sig = cab->sig;
	cab->sig = t;
}

int Pila::pop() {
	int x;
	nodoPila *t = cab->sig;
	cab->sig = t->sig;
	x = t->dato;
	delete t;
	return x;
}

bool Pila::pilaVacia() {
	return cab->sig == NULL;
}

Pila::~Pila() {
	nodoPila *t = cab;
	while (t != NULL) {
		cab = t;
		t = t->sig;
		delete cab;
	}
}
