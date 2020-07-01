/*
 * pilaArbol.h
 *
 *  Created on: 10/10/2014
 *      Author: ---
 */

#ifndef PILAARBOL_H_
#define PILAARBOL_H_

#include <cstdlib>

struct nodoPila {
	int dato;
	nodoPila *sig;
};

class Pila {
	nodoPila *cab;
public:
	Pila() {
		cab = new nodoPila;
		cab->dato = 0;
		cab->sig = NULL;
	}
	void push(int v);
	int pop();
	bool pilaVacia();
	~Pila();
};

#endif /* PILAARBOL_H_ */
