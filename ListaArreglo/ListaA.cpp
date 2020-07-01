/*
 * ListaA.cpp
 *
 *  Created on: 24/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */
#include "ListaA.h"

ListaA::ListaA(int _tam=10) {
	L = new int [_tam];
	pos_libre = 0;
	tam = _tam;
}

ListaA::~ListaA() {
	delete [] L;
}

bool ListaA::insertar_inicio(int elm) {
	if (! esta_llena()) {
		if(pos_libre==0) {
			L[pos_libre] = elm;
		} else {
			for(int i=pos_libre; i>0; i--) {
				L[i] = L[i-1];
			}
			L[0] = elm;
		}
		pos_libre++;
		return true;
	}
	return false;
}

bool ListaA::insertar_final(int elm) {
	if (! esta_llena()) {
		L[pos_libre] = elm;
		pos_libre++;
		return true;
	}
	return false;
}

bool ListaA::insertar_pos(int elm, int pos) {
	if (! esta_llena()) {
		if (pos < pos_libre) {
			for(int i=pos_libre; i>pos; i--) {
				L[i] = L[i-1];
			}
			L[pos] = elm;
			pos_libre++;
			return true;
		}
	}
	return false;
}

bool ListaA::suprimir(int pos) {
	if (pos < pos_libre) {
		for(int i=pos; i<pos_libre-1; i++) {
			L[i] = L[i+1];
		}
		pos_libre--;
		return true;
	}
	return false;
}

int ListaA::buscar(int val) {
	int i;
	for (i=0; i<pos_libre; i++) {
		if (L[i]==val) {
			break;
		}
	}
	if (i==pos_libre) {
		i = -1;
	}
	return i;
}

int ListaA::primero() {
	return L[0];
}

int ListaA::ultimo() {
	return L[pos_libre-1];
}

int ListaA::long_lista() {
	return pos_libre;
}

bool ListaA::esta_llena() {
	return pos_libre == tam;
}

bool ListaA::esta_vacia() {
	return pos_libre == 0;
}



