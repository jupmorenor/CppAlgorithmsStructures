/*
 * ListaStruct.cpp
 *
 *  Created on: 25/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */
#include <stddef.h>
#include "ListaStruct.h"

/* OK */
template <typename T> ListaS<T>::ListaS() {
	cabeza = NULL;
	tam = 0;
}

/* probar */
template <typename T> ListaS<T>::~ListaS() {
	Nodo<T> *Aux;
	if (! esta_vacia()) {
		for(Aux=cabeza->siguiente; Aux!=NULL; Aux=Aux->siguiente) {
			delete cabeza;
			cabeza = Aux;
		}
		delete Aux;
	}
}

/* OK */
template <typename T> bool ListaS<T>::insertar_inicio(T elm) {
	if (esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = NULL;
	} else {
		Nodo<T> *Aux = cabeza;
		cabeza = crear_nodo(elm);
		cabeza->siguiente = Aux;
	}
	tam++;
	return true;
}

/* OK */
template <typename T> bool ListaS<T>::insertar_final(T elm) {
	Nodo<T> *Aux, *nuevo;
	if (esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = NULL;
	} else {
		for(Aux=cabeza; Aux->siguiente!=NULL; Aux=Aux->siguiente);
		nuevo = crear_nodo(elm);
		nuevo->siguiente = NULL;
		Aux->siguiente = nuevo;
	}
	tam++;
	return true;
}

/* OK */
template <typename T> bool ListaS<T>::insertar_pos(T elm, int pos) {
	if (pos > tam) {
		insertar_final(elm);
	}else if (pos == 0) {
		insertar_inicio(elm);
	} else {
		Nodo<T> *Aux = cabeza;
		Nodo<T> *nuevo = crear_nodo(elm);
		for(int i=0; i<pos-1; i++) {
			Aux = Aux->siguiente;
		}
		nuevo->siguiente = Aux->siguiente;
		Aux->siguiente = nuevo;
		tam++;
	}
	return true;
}

/* probar */
template <typename T> bool ListaS<T>::suprimir(int pos) {
	Nodo<T> *Aux1=cabeza;
	Nodo<T> *Aux2;
	if (esta_vacia()) {
		return false;
	}

	for(int i=1; i<pos; i++) {
		Aux1=Aux1->siguiente;
	}
	Aux2 = Aux1;
	Aux1=Aux1->siguiente;
	Aux2->siguiente = Aux1->siguiente;
	delete Aux1;
	tam--;
	return true;
}

/* ok */
template <typename T> T ListaS<T>::buscar(int pos) {
	Nodo<T> *Aux;
	if (!esta_vacia()) {
		for(Aux=cabeza; Aux->siguiente!=NULL; Aux=Aux->siguiente) {
			if (pos == 0) {
				break;
			}
			pos--;
		}
		return Aux->dato;
	}
	//return NULL;//XXX aclarar
}

/* probar */
template <typename T> T ListaS<T>::primero() {
	if (!esta_vacia()) {
		return cabeza->dato;
	}
	//return NULL; //XXX aclarar
}

/* OK */
template <typename T> T ListaS<T>::ultimo() {
	Nodo<T> *Aux;
	for(Aux=cabeza; Aux->siguiente!=NULL; Aux=Aux->siguiente);
	return Aux->dato;
}

/* OK */
template <typename T> int ListaS<T>::long_lista() {
	return tam;
}

/* OK */
template <typename T> bool ListaS<T>::esta_vacia() {
	return tam == 0;
}

