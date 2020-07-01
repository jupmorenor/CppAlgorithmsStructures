/*
 * ListaCircular.cpp
 *
 *  Created on: 28/09/2014
 *      Author: Juan Pablo Moreno Rico - 20111020059
 */

#include <stddef.h>
#include "ListaCircular.h"

template <typename T> ListaCircular<T>::ListaCircular() {
	cabeza = NULL;
	tam = 0;
}

template <typename T> ListaCircular<T>::~ListaCircular() {
	Nodo<T> *Aux;
	if (!esta_vacia()) {
		for(Aux=cabeza->siguiente; Aux->siguiente!=Aux; Aux=Aux->siguiente) {
			Aux->anterior = cabeza->anterior;
			(Aux->anterior)->siguiente = Aux;
			delete cabeza;
			cabeza = Aux;
		}
		delete Aux;
		delete cabeza;
	}
}

template <typename T> bool ListaCircular<T>::insertar_inicio(T elm) {
	if (esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = cabeza;
		cabeza->anterior = cabeza;
	} else {
		Nodo<T> *Aux = cabeza;
		cabeza = crear_nodo(elm);
		cabeza->siguiente = Aux;
		cabeza->anterior = Aux->anterior;
		Aux->anterior = cabeza;
		(cabeza->anterior)->siguiente = cabeza;
	}
	tam++;
	return true;
}

template <typename T> bool ListaCircular<T>::insertar_final(T elm) {
	if(esta_vacia()) {
		cabeza = crear_nodo(elm);
		cabeza->siguiente = cabeza;
		cabeza->anterior = cabeza;
	} else {
		Nodo<T> *Aux = crear_nodo(elm);
		Aux->siguiente = cabeza;
		Aux->anterior = cabeza->anterior;
		cabeza->anterior = Aux;
		(Aux->anterior)->siguiente = Aux;
	}
	tam++;
	return true;
}

template <typename T> bool ListaCircular<T>::insertar_pos(T elm, int pos) {
	while (pos > tam) {
		pos-=tam;
	}
	if (pos == tam) {
		insertar_final(elm);
	} else if (pos == 0) {
		insertar_inicio(elm);
	} else {
		Nodo<T> *Aux = cabeza;
		Nodo<T> *nuevo = crear_nodo(elm);
		for(int i=0; i<pos-1; i++) {
			Aux = Aux->siguiente;
		}
		nuevo->siguiente = Aux->siguiente;
		nuevo->anterior = Aux;
		Aux->siguiente = nuevo;
		(nuevo->siguiente)->anterior = nuevo;
	}
	tam++;
	return true;
}

template <typename T> bool ListaCircular<T>::suprimir(int pos) {
	Nodo<T> *Aux = cabeza;
	while (pos > tam) {
		pos-=tam;
	}
	if (esta_vacia()) {
		return false;
	} else if (tam == 1) {
		delete cabeza;
		//cabeza == NULL;
		tam--;
		return true;
	} else {
		for(int i=0; i<pos; i++) {
			Aux = Aux->siguiente;
		}
		(Aux->siguiente)->anterior = Aux->anterior;
		(Aux->anterior)->siguiente = Aux->siguiente;
		delete Aux;
	}
	tam--;
	return true;
}

template <typename T> T ListaCircular<T>::buscar(int pos) {
	Nodo<T> *Aux = cabeza;
	while (pos > tam) {
		pos-=tam;
	}
	if (!esta_vacia()) {
		if (pos == 0) {
			return primero();
		}else if (pos == tam-1) {
			return ultimo();
		} else {
			for(int i=0; i<pos; i++) {
				Aux = Aux->siguiente;
			}
			return Aux->dato;
		}
	}
}

template <typename T> T ListaCircular<T>::primero() {
	return cabeza->dato;
}

template <typename T> T ListaCircular<T>::ultimo() {
	return (cabeza->anterior)->dato;
}

template <typename T> int ListaCircular<T>::long_lista() {
	return tam;
}

template <typename T> bool ListaCircular<T>::esta_vacia() {
	return tam == 0;
}
